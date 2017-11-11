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

// Load byte
void IHandler::LB(IType& instruction, const Register rs, Register& rd)
{
	rd = Memory::mem.Load<int8_t>(rs + instruction.imm);
}

// Load halfword 
void IHandler::LH(IType& instruction, const Register rs, Register& rd)
{
	rd = Memory::mem.Load<int16_t>(rs + instruction.imm);
}

void IHandler::LW(IType& instruction, const Register rs, Register& rd)
{
	rd = Memory::mem.Load<int32_t>(rs + instruction.imm);
}

void IHandler::LBU(IType& instruction, const Register rs, Register& rd)
{
	rd = Memory::mem.Load<uint8_t>(rs + instruction.imm);
}

void IHandler::LHU(IType& instruction, const Register rs, Register& rd)
{
	rd = Memory::mem.Load<uint16_t>(rs + instruction.imm);
}

void IHandler::XORI(IType& instruction, const Register rs, Register& rd)
{
	rd = rs ^ instruction.imm;
}

void IHandler::ORI(IType& instruction, const Register rs, Register& rd)
{
	rd = rs | instruction.imm;
}

void IHandler::ANDI(IType& instruction, const Register rs, Register& rd)
{
	rd = rs & instruction.imm;
}

