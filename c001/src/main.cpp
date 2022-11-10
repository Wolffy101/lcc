#include <iostream>
#include "Parser.h"
#include "Lexer.h"
#include "PrintVisitor.h"
const auto *code = " 5 + 1 - 3*4/2";
void TestLex()
{
  C100::Lexer lexer(code);
  do
  {
    lexer.GetNextToken();
    std::cout << lexer.CurrentToken->Content << std::endl;
  } while (lexer.CurrentToken->Kind != C100::TokenKind::Eof);
}
int main(int argc, char const *argv[])
{
  // TestLex();
  C100::Lexer lex(code);
  lex.GetNextToken();
  C100::Parser parser(lex);
  C100::PrintVisitor visitor;
  auto parse = parser.Parse();
  parse->Accept(&visitor);
  return 0;
}
