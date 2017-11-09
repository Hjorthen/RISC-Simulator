#include "IHandler.h"
#include "../Memory.h"

void IHandler::Handle(IType & instruction, Register rs, Register & rd)
{
	switch (instruction.funct3) {
		
	}
}


void IHandler::ADDI(IType & instruction, const Register rs, Register & rd)
{
	rd = instruction.imm + rs;
}

void IHandler::SUBI(IType & instruction, const Register rs, Register & rd)
{
	rd = rs - instruction.imm;
}

void IHandler::SLLI(IType& instruction, const Register rs, Register& rd)
{
	rd = rs << instruction.imm;
}

void IHandler::SRLI(IType& instruction, const Register rs, Register& rd)
{
	rd = rs >> instruction.imm;
}

void IHandler::SRAI(IType& instruction, const Register rs, Register& rd)
{

}

void IHandler::LB(IType& instruction, const Register rs, Register& rd)
{
	rs = Memory::mem.Load(rd + instruction.imm);
}

void IHandler::LHW(IType& instruction, const Register rs, Register& rd)
{

}

void IHandler::LW(IType& instruction, const Register rs, Register& rd)
{

}

void IHandler::LBU(IType& instruction, const Register rs, Register& rd)
{

}

void IHandler::LHWU(IType& instruction, const Register rs, Register& rd)
{

}

void IHandler::XORIM(IType& instruction, const Register rs, Register& rd)
{

}

void IHandler::ORIM(IType& instruction, const Register rs, Register& rd)
{

}

void IHandler::ANDIM(IType& instruction, const Register rs, Register& rd)
{

}

