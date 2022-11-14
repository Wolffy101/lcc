#include <iostream>
#include "Parser.h"
namespace C100
{
    Parser::Parser(C100::Lexer &lexer) : lexer(lexer)
    {
    }

    Parser::~Parser()
    {
    }
    std::shared_ptr<AstNode> Parser::Parse()
    {
        auto node = std::make_shared<ProgramNode>();
        node->Lhs = ParseExpr();
        return node;
    }

    std::shared_ptr<AstNode> Parser::ParseExpr()
    {
        return ParseAddExpr();
    }

    std::shared_ptr<AstNode> Parser::ParseAddExpr()
    {
        auto left = ParseMultiExpr();
        while (lexer.CurrentToken->Kind == TokenKind::Add || lexer.CurrentToken->Kind == TokenKind::Sub)
        {
            auto anOperator = BinaryOperator::Add;
            if (lexer.CurrentToken->Kind == TokenKind::Sub)
            {
                anOperator = BinaryOperator::Sub;
            }
            lexer.GetNextToken();
            auto node = std::make_shared<BinaryNode>();
            node->Lhs = left;
            node->Rhs = ParseMultiExpr();
            node->BinOp = anOperator;
            left = node;
        }
        return left;
    }
    std::shared_ptr<AstNode> Parser::ParseMultiExpr()
    {
        auto left = ParsePrimaryExpr();
        while (lexer.CurrentToken->Kind == TokenKind::Mul || lexer.CurrentToken->Kind == TokenKind::Div)
        {
            auto anOperator = BinaryOperator::Mul;
            if (lexer.CurrentToken->Kind == TokenKind::Div)
            {
                anOperator = BinaryOperator::Div;
            }
            lexer.GetNextToken();
            auto node = std::make_shared<BinaryNode>();
            node->Lhs = left;
            node->Rhs = ParsePrimaryExpr();
            node->BinOp = anOperator;
            left = node;
        }
        return left;
    }
    std::shared_ptr<AstNode> Parser::ParsePrimaryExpr()
    {
        if (lexer.CurrentToken->Kind == TokenKind::LParent)
        {
            lexer.GetNextToken();
            auto node = ParseExpr();
            lexer.GetNextToken();
            return node;
        }
        else
        {
            auto node = std::make_shared<ConstantNode>();
            node->Value = lexer.CurrentToken->Value;
            lexer.GetNextToken();
            return node;
        }
    }
}