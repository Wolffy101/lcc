#pragma once
#include <memory>
namespace C100
{
    class AstVisitor;
    class AstNode
    {
    public:
        AstNode() {}
        ~AstNode() {}
        virtual void Accept(AstVisitor *visitor){};

    private:
    };
    class ProgramNode : public AstNode
    {
    private:
        /* data */
    public:
        ProgramNode(/* args */) {}
        ~ProgramNode() {}
        std::shared_ptr<AstNode> Lhs;
        void Accept(AstVisitor *visitor) override;
    };
    enum class BinaryOperator
    {
        Add,
        Sub,
        Mul,
        Div,
    };
    class BinaryNode : public AstNode
    {
    private:
        /* data */
    public:
        BinaryNode() {}
        ~BinaryNode() {}
        BinaryOperator BinOp;
        std::shared_ptr<AstNode> Lhs;
        std::shared_ptr<AstNode> Rhs;
        void Accept(AstVisitor *visitor) override;
    };
    class ConstantNode : public AstNode
    {
    private:
        /* data */
    public:
        ConstantNode(/* args */) {}
        ~ConstantNode() {}
        void Accept(AstVisitor *visitor) override;
        int Value;
    };
    class AstVisitor
    {
    private:
        /* data */
    public:
        AstVisitor(/* args */) {}
        ~AstVisitor() {}
        virtual void VisitorProgramNode(ProgramNode *programNode){};
        virtual void VisitorBinaryNode(BinaryNode *binaryNode){};
        virtual void VisitorConstantNode(ConstantNode *constanNode){};
    };
} // namespace C100