#pragma once

#include <memory>
#include <string_view>
#include <cstdio>

namespace C100
{
    enum class TokenKind
    {
        Add,
        Sub,
        LParent,
        RParent,
        Mul,
        Div,
        Num,
        Eof,
    };
    class Token
    {
    public:
        TokenKind Kind;
        int Value;
        std::string_view Content;
    };
    class Lexer
    {

    public:
        Lexer(const char *code);
        ~Lexer();
        std::shared_ptr<Token> CurrentToken;
        void GetNextToken();
        void GetNextChar();

    private:
        std::string_view sourceCode;
        char curChar{' '};
        int cursor{0};

    private:
        void AssignToken(TokenKind &left, TokenKind tokenKind);
    };

} // namespace name