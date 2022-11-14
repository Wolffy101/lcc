#pragma once
#include "AstNode.h"
#include "string"
namespace C100
{
    class PrintVisitor : public AstVisitor
    {
    public:
        std::string Content;

    public:
        PrintVisitor(/* args */) {}
        ~PrintVisitor() {}
        virtual void VisitorProgramNode(ProgramNode *programNode) override;

    private:
        virtual void VisitorBinaryNode(BinaryNode *binaryNode) override;
        virtual void VisitorConstantNode(ConstantNode *constanNode) override;
    };
} // namespace C100
