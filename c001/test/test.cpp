#include "catch.hpp"
#include "Lexer.h"
TEST_CASE("C100", "1+2")
{
    C100::Lexer lex("123");
    REQUIRE(3 == 1 + 2);
}
TEST_CASE("parser2", "1+2+3")
{
    REQUIRE(6 == 1 + 2 + 3);
}