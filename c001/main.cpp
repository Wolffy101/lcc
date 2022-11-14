#include <iostream>
#include "Parser.h"
#include "Lexer.h"
#include "PrintVisitor.h"
#include "CodeGen.h"
const auto *code = " 5 + (1 - 3)*4/2";
void TestLex()
{
  C100::Lexer lexer(code);
  do
  {
    lexer.GetNextToken();
    std::cout << lexer.CurrentToken->Content << std::endl;
  } while (lexer.CurrentToken->Kind != C100::TokenKind::Eof);
}
void TestParse()
{
  C100::Lexer lex(code);
  lex.GetNextToken();
  C100::Parser parser(lex);
  C100::PrintVisitor visitor;
  auto parse = parser.Parse();
  parse->Accept(&visitor);
}
void TestCodeGen()
{
  C100::Lexer lex(code);
  lex.GetNextToken();
  C100::Parser parser(lex);
  C100::CodeGen codeGen;
  auto root = parser.Parse();
  root->Accept(&codeGen);
}
int main(int argc, char const *argv[])
{
  // TestLex();
  TestParse();
  // TestCodeGen();
  if (argc != 2)
  {
    std::cout << "please input: ./c100 code" << std::endl;
    return 0;
  }
  const char *source = argv[1];
  C100::Lexer lex(source);
  lex.GetNextToken();

  C100::Parser parser(lex);
  C100::CodeGen codeGen;
  auto root = parser.Parse();
  root->Accept(&codeGen);
  return 0;
}
