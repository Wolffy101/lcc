#include <iostream>
#include "Lexer.h"
namespace C100
{
  Lexer::Lexer(const char *code)
  {
    sourceCode = code;
  }

  Lexer::~Lexer() {}
  void Lexer::GetNextToken()
  {
    while (iswspace(curChar))
    {
      GetNextChar();
    }
    TokenKind kind;
    auto value = 0;
    auto startPos = cursor - 1;
    if (curChar == '\0')
    {
      kind = TokenKind::Eof;
    }
    else if (curChar == '+')
    {
      AssignToken(kind, TokenKind::Add); 
    }
    else if (curChar == '-')
    {
      AssignToken(kind, TokenKind::Sub);
    }
    else if (curChar == '(')
    {

      AssignToken(kind, TokenKind::LParent);
    }
    else if (curChar == ')')
    {
      AssignToken(kind, TokenKind::RParent);
    }
    else if (curChar == '*')
    {
      AssignToken(kind, TokenKind::Mul);
    }
    else if (curChar == '/')
    {
      AssignToken(kind, TokenKind::Div);
    }
    else if (isdigit(curChar))
    {
      value = 0;
      do
      {
        value = value * 10 + (curChar - '0');
        GetNextChar();
      } while (isdigit(curChar));
    }
    else
    {
      std::cout << "not support " << curChar << std::endl;
    }
    CurrentToken = std::make_shared<Token>();
    CurrentToken->Kind = kind;
    CurrentToken->Value = value;
    CurrentToken->Content = sourceCode.substr(startPos, cursor - 1 - startPos);
  }
  void Lexer::GetNextChar()
  {
    if (cursor == sourceCode.size())
    {
      cursor++;
      curChar = '\0';
    }
    else
    {
      curChar = sourceCode[cursor++];
    }
  }

  void Lexer::AssignToken(TokenKind &left, TokenKind tokenKind)
  {
    left = tokenKind;
    GetNextChar();
  }
} // namespace C100