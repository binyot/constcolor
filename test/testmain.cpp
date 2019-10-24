#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include <color.hpp>
#include <constexpr_util.hpp>

TEST_CASE("color::is_digit is tested", "color::is_digit") {
    REQUIRE(color::is_digit('A'));
    REQUIRE(color::is_digit('F'));
    REQUIRE(color::is_digit('a'));
    REQUIRE(color::is_digit('f'));
    REQUIRE(color::is_digit('0'));
    REQUIRE(color::is_digit('9'));
}

TEST_CASE("color::hex_ctou8 is tested", "color::hex_ctou8") {
    REQUIRE(color::hex_ctou8('0') == 0);
    REQUIRE(color::hex_ctou8('9') == 9);
    REQUIRE(color::hex_ctou8('A') == 10);
    REQUIRE(color::hex_ctou8('F') == 15);
}

TEST_CASE("color::hex_stou8 is tested", "color::hex_stou8") {
    REQUIRE(color::hex_stou8("00") == 0);
    REQUIRE(color::hex_stou8("11") == 17);
    REQUIRE(color::hex_stou8("7F") == 127);
    REQUIRE(color::hex_stou8("FF") == 255);
}

TEST_CASE("color::from_hex", "color::from_hex") {
    auto[r, g, b] = color::from_hex("0077FF");
    REQUIRE(r == 0);
    REQUIRE(g == 119);
    REQUIRE(b == 255);
}