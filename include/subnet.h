#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>

namespace subnet {

struct Calculation {
    std::string input_ip;
    int prefix;

    std::string subnet_mask;
    std::string wildcard_mask;
    std::string network_address;
    std::string broadcast_address;
    std::string first_usable_host;
    std::string last_usable_host;

    std::uint64_t total_addresses;
    std::uint64_t usable_hosts;

    std::string note;
};

std::optional<Calculation> calculate(std::string_view cidr);
std::optional<std::uint32_t> parse_ipv4(std::string_view ip);
std::string to_ipv4(std::uint32_t value);

} // namespace subnet
