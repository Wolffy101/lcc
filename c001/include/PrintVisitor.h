#pragma once
#include "AstNode.h"
namespace C100
{
    class PrintVisitor : public AstVisitor
    {
    private:
        /* data */
    public:
        PrintVisitor(/* args */) {}
        ~PrintVisitor() {}
        virtual void VisitorProgramNode(ProgramNode *programNode) override;

    private:
        virtual void VisitorBinaryNode(BinaryNode *binaryNode) override;
        virtual void VisitorConstantNode(ConstantNode *constanNode) override;
    };
} // namespace C100
