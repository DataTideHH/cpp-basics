#include "subnet.h"

#include <iostream>
#include <string_view>

namespace {

    void print_usage(std::string_view program_name) {
        std::cout
            << "IPv4 Subnet Calculator\n\n"
            << "Usage:\n"
            << "  " << program_name << " <IPv4/CIDR>\n\n"
            << "Examples:\n"
            << "  " << program_name << " 192.168.10.42/24\n"
            << "  " << program_name << " 10.0.0.5/30\n"
            << "  " << program_name << " 172.16.1.1/16\n";
    }

    void print_result(const subnet::Calculation& result) {
        std::cout
            << "Input IP:          " << result.input_ip << '\n'
            << "CIDR prefix:       /" << result.prefix << '\n'
            << "Subnet mask:       " << result.subnet_mask << '\n'
            << "Wildcard mask:     " << result.wildcard_mask << '\n'
            << "Network address:   " << result.network_address << '\n'
            << "Broadcast address: " << result.broadcast_address << '\n'
            << "Total addresses:   " << result.total_addresses << '\n'
            << "Usable hosts:      " << result.usable_hosts << '\n'
            << "First usable host: " << result.first_usable_host << '\n'
            << "Last usable host:  " << result.last_usable_host << '\n'
            << "Note:              " << result.note << '\n';
    }

} // namespace

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return 1;
    }

    const auto result = subnet::calculate(argv[1]);

    if (!result) {
        std::cerr
            << "Error: invalid input.\n"
            << "Expected format: IPv4/CIDR, for example 192.168.10.42/24\n";
        return 1;
    }

    print_result(*result);
    return 0;
}