#ifndef COLOR_CONSTEXPR_UTIL_HPP
#define COLOR_CONSTEXPR_UTIL_HPP

#include <array>
#include <string_view>

namespace color {
    template<typename T, typename U>
    constexpr auto find(const T &begin, const T &end, const U &key) {
        auto it = begin;
        while (it != end) {
            if (*it == key) break;
            ++it;
        }
        return it;
    }

    constexpr char tolower(char c) {
        if (c >= 65 && c <= 90) {
            c += 97 - 65;
        }
        return c;
    }

    constexpr bool is_digit(char c) {
        std::array digits = {'0', '1', '2', '3',
                             '4', '5', '6', '7',
                             '8', '9', 'a', 'b',
                             'c', 'd', 'e', 'f'};
        return find(std::begin(digits), std::end(digits), tolower(c)) != std::end(digits);
    }

    constexpr uint8_t hex_ctou8(char c) {
        c = tolower(c);
        if (!is_digit(c)) throw std::logic_error("c must be a hexadecimal digit");
        return (c >= 'a' && c <= 'f') ? c - 97 + 10 : c - 48;
    }

    constexpr uint8_t hex_stou8(std::string_view str) {
        if (str.length() != 2) throw std::logic_error("str must be 2 characters long");
        uint8_t first = hex_ctou8(str[0]) * 16;
        uint8_t second = hex_ctou8(str[1]);
        return first + second;
    }
}

#endif //COLOR_CONSTEXPR_UTIL_HPP
