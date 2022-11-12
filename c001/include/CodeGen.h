#pragma once
#include "Parser.h"
namespace C100
{

    class CodeGen : public AstVisitor
    {
    private:
        int stackLevel{0};

    public:
        CodeGen();
        ~CodeGen();
        void VisitorProgramNode(ProgramNode *node) override;

    private:
        void VisitorBinaryNode(BinaryNode *node) override;
        void VisitorConstantNode(ConstantNode *node) override;

        void Push();
        void Pop(const char *reg);
    };

} // namespace C100