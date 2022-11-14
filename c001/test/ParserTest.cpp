#include "catch.hpp"
#include "Parser.h"
#include "PrintVisitor.h"
TEST_CASE("Parse", "5+(1-3)*4/2")
{
    const char *code = "5+(1-3)*4/2";
    C100::Lexer lexer(code);
    lexer.GetNextToken();
    C100::Parser parser(lexer);

    auto root = parser.Parse();
    C100::PrintVisitor visitor;
    root->Accept(&visitor);
    REQUIRE(visitor.Content == "2 4 3 1 - * / 5 + ");
}