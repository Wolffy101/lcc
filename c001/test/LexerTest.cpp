#include "catch.hpp"
#include "Lexer.h"
TEST_CASE("C100::Lexer", "5+(1-3)*4/2")
{
   const char *code = "5+(1-3)*4/2";
   C100::Lexer lex(code);
   lex.GetNextToken();
   REQUIRE("5" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE("+" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE("(" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE("1" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE("-" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE("3" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE(")" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE("*" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE("4" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE("/" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE("2" == lex.CurrentToken->Content);
   lex.GetNextToken();
   REQUIRE(C100::TokenKind::Eof == lex.CurrentToken->Kind);
}