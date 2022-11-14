#include "PrintVisitor.h"
#include <iostream>
#include <cassert>
namespace C100
{
    void PrintVisitor::VisitorProgramNode(ProgramNode *node)
    {
        node->Lhs->Accept(this);
        // std::cout << std::endl;
    }

    void PrintVisitor::VisitorBinaryNode(BinaryNode *node)
    {
        node->Rhs->Accept(this);
        node->Lhs->Accept(this);
        switch (node->BinOp)
        {
        case BinaryOperator::Add:
            Content.append("+ ");
            // std::cout << " + ";
            break;
        case BinaryOperator::Sub:
            Content.append("- ");
            // std::cout << " - ";
            break;

        case BinaryOperator::Mul:
            Content.append("* ");
            // std::cout << " * ";
            break;
        case BinaryOperator::Div:
            Content.append("/ ");
            // std::cout << " / ";
            break;
        default:
            assert(0);
            break;
        }
    }
    void PrintVisitor::VisitorConstantNode(ConstantNode *node)
    {
        Content.append(std::to_string(node->Value));
        Content.push_back(' ');
        // std::cout << " " << node->Value << " ";
    }
} // namespace C100
