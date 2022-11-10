#include "PrintVisitor.h"
#include <iostream>
namespace C100
{
    void PrintVisitor::VisitorProgramNode(ProgramNode *node)
    {
        node->Lhs->Accept(this);
        std::cout << std::endl;
    }

    void PrintVisitor::VisitorBinaryNode(BinaryNode *node)
    {
        node->Rhs->Accept(this);
        node->Lhs->Accept(this);
        switch (node->BinOp)
        {
        case BinaryOperator::Add:
            std::cout << " + ";
            break;
        case BinaryOperator::Sub:
            std::cout << " - ";
            break;

        case BinaryOperator::Mul:
            std::cout << " * ";
            break;
        case BinaryOperator::Div:
            std::cout << " / ";
            break;
        default:
            // assert(0);
            break;
        }
    }
    void PrintVisitor::VisitorConstantNode(ConstantNode *node)
    {
        std::cout << " " << node->Value << " ";
    }
} // namespace C100
