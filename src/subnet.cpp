#include "subnet.h"
#include <charconv>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

namespace subnet {

namespace {

bool parse_number(std::string_view text, int min_value, int max_value, int& result) {
    if (text.empty()) {
        return false;
    }

    int value = 0;
    const auto* begin = text.data();
    const auto* end = text.data() + text.size();

    auto [ptr, error] = std::from_chars(begin, end, value);

    if (error != std::errc{} || ptr != end) {
        return false;
    }

    if (value < min_value || value > max_value) {
        return false;
    }

    result = value;
    return true;
}

std::vector<std::string_view> split(std::string_view text, char delimiter) {
    std::vector<std::string_view> parts;
    std::size_t start = 0;

    while (start <= text.size()) {
        std::size_t end = text.find(delimiter, start);

        if (end == std::string_view::npos) {
            parts.push_back(text.substr(start));
            break;
        }

        parts.push_back(text.substr(start, end - start));
        start = end + 1;
    }

    return parts;
}

std::optional<int> parse_prefix(std::string_view prefix_text) {
    int prefix = 0;

    if (!parse_number(prefix_text, 0, 32, prefix)) {
        return std::nullopt;
    }

    return prefix;
}

std::uint32_t prefix_to_mask(int prefix) {
    if (prefix == 0) {
        return 0;
    }

    return std::numeric_limits<std::uint32_t>::max() << (32 - prefix);
}

} // namespace

std::optional<std::uint32_t> parse_ipv4(std::string_view ip) {
    const auto parts = split(ip, '.');

    if (parts.size() != 4) {
        return std::nullopt;
    }

    std::uint32_t result = 0;

    for (const auto part : parts) {
        int octet = 0;

        if (!parse_number(part, 0, 255, octet)) {
            return std::nullopt;
        }

        result = (result << 8) | static_cast<std::uint32_t>(octet);
    }

    return result;
}

std::string to_ipv4(std::uint32_t value) {
    std::ostringstream output;

    output
        << ((value >> 24) & 0xFF) << '.'
        << ((value >> 16) & 0xFF) << '.'
        << ((value >> 8) & 0xFF) << '.'
        << (value & 0xFF);

    return output.str();
}

std::optional<Calculation> calculate(std::string_view cidr) {
    const auto slash_position = cidr.find('/');

    if (slash_position == std::string_view::npos) {
        return std::nullopt;
    }

    const auto ip_text = cidr.substr(0, slash_position);
    const auto prefix_text = cidr.substr(slash_position + 1);

    const auto ip = parse_ipv4(ip_text);
    const auto prefix = parse_prefix(prefix_text);

    if (!ip || !prefix) {
        return std::nullopt;
    }

    const std::uint32_t mask = prefix_to_mask(*prefix);
    const std::uint32_t wildcard = ~mask;
    const std::uint32_t network = *ip & mask;
    const std::uint32_t broadcast = network | wildcard;

    const std::uint64_t total_addresses = 1ULL << (32 - *prefix);

    std::uint64_t usable_hosts = 0;
    std::uint32_t first_usable = network;
    std::uint32_t last_usable = broadcast;
    std::string note;

    if (*prefix <= 30) {
        usable_hosts = total_addresses - 2;
        first_usable = network + 1;
        last_usable = broadcast - 1;
        note = "Standard subnet with network and broadcast addresses excluded.";
    } else if (*prefix == 31) {
        usable_hosts = 2;
        first_usable = network;
        last_usable = broadcast;
        note = "/31 subnet: both addresses are usable for point-to-point links.";
    } else {
        usable_hosts = 1;
        first_usable = network;
        last_usable = network;
        note = "/32 host route: single usable address.";
    }

    return Calculation{
        .input_ip = std::string(ip_text),
        .prefix = *prefix,
        .subnet_mask = to_ipv4(mask),
        .wildcard_mask = to_ipv4(wildcard),
        .network_address = to_ipv4(network),
        .broadcast_address = to_ipv4(broadcast),
        .first_usable_host = to_ipv4(first_usable),
        .last_usable_host = to_ipv4(last_usable),
        .total_addresses = total_addresses,
        .usable_hosts = usable_hosts,
        .note = note
    };
}

} // namespace subnet
