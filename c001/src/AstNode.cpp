#include "AstNode.h"
namespace C100
{
    void ProgramNode::Accept(AstVisitor *visitor)
    {
        visitor->VisitorProgramNode(this);
    }
    void BinaryNode::Accept(AstVisitor *visitor)
    {
        visitor->VisitorBinaryNode(this);
    }

    void ConstantNode::Accept(AstVisitor *visitor)
    {
        visitor->VisitorConstantNode(this);
    }
} // namespace C100
