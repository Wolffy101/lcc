#include "CodeGen.h"
#include <iostream>
#include <cassert>
namespace C100
{
    CodeGen::CodeGen()
    {
    }

    CodeGen::~CodeGen()
    {
    }

    void CodeGen::VisitorProgramNode(ProgramNode *node)
    {
        std::cout << "\t.text" << std::endl;
#ifdef __linux__
        std::cout << "\t.globl prog" << std::endl;
        std::cout << "prog:" << std::endl;
#else
        /// macos
        std::cout << "\t.globl _prog" << std::endl;
        std::cout << "_prog:" << std::endl;
#endif
        std::cout << "\tpush %rbp" << std::endl;
        std::cout << "\tmov %rsp, %rbp" << std::endl;
        std::cout << "\tsub $32, %rsp" << std::endl;

        node->Lhs->Accept(this);

        std::cout << "\tmov %rbp, %rsp" << std::endl;
        std::cout << "\tpop %rbp" << std::endl;
        std::cout << "\tret" << std::endl;
    }

    void CodeGen::VisitorBinaryNode(BinaryNode *node)
    {
        node->Rhs->Accept(this);
        Push();
        node->Lhs->Accept(this);
        Pop("%rdi");
        switch (node->BinOp)
        {
        case BinaryOperator::Add:
            std::cout << "\tadd %rdi, %rax" << std::endl;
            break;
        case BinaryOperator::Sub:
            std::cout << "\tsub %rdi, %rax" << std::endl;
            break;
        case BinaryOperator::Mul:
            std::cout << "\timul %rdi, %rax" << std::endl;
            break;
        case BinaryOperator::Div:
            std::cout << "\tcqo" << std::endl;
            std::cout << "\tidiv %rdi" << std::endl;
            break;
        default:
            assert(0);
            break;
        }
    }

    void CodeGen::VisitorConstantNode(ConstantNode *node)
    {
        std::cout << "\tmov $" << node->Value << ", %rax" << std::endl;
    }
    void CodeGen::Push()
    {
        std::cout << "\tpush %rax" << std::endl;
        stackLevel++;
    }
    void CodeGen::Pop(const char *reg)
    {
        std::cout << "\tpop " << reg << std::endl;
        stackLevel--;
    }
} // namespace C100