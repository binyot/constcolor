#ifndef COLOR_COLOR_HPP
#define COLOR_COLOR_HPP

#include "constexpr_util.hpp"

#include <cctype>
#include <string_view>

namespace color {

    struct rgb {
        uint8_t r, g, b;
    };

    constexpr rgb from_hex(std::string_view hex) {
        if (hex.length() != 6) throw std::logic_error("hex must be 6 characters long");
        rgb result{
                hex_stou8(hex.substr(0, 2)),
                hex_stou8(hex.substr(2, 2)),
                hex_stou8(hex.substr(4, 2))
        };
        return result;
    }
}

#endif