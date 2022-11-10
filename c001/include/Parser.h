#pragma once

#include "Lexer.h"
#include "AstNode.h"
namespace C100
{
    class Parser
    {
    public:
        Parser(Lexer &lexer);
        ~Parser();
        std::shared_ptr<AstNode> Parse();

    private:
        Lexer &lexer;
        std::shared_ptr<AstNode> ParseExpr();
        std::shared_ptr<AstNode> ParseAddExpr();
        std::shared_ptr<AstNode> ParseMultiExpr();
        std::shared_ptr<AstNode> ParsePrimaryExpr();
    };

} // namespace C100