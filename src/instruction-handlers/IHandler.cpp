#include "IHandler.h"
#include "../Memory.h"

void IHandler::Handle(IType & instruction, Register rs, Register & rd)
{
	if (instruction.opcode == 0b0000011) {
		switch (instruction.funct3) {
			case 000:
			{
				LB(instruction, rs, rd);
				break;
			}
			case 001:
			{
				LH(instruction, rs, rd);
				break;
			}
			case 010:
			{
				LW(instruction, rs, rd);
				break;
			}
			case 011:
			{
				//id
				break;
			}
			case 100:
			{
				LBU(instruction, rs, rd);
				break;
			}
			case 101:
			{
				LHU(instruction, rs, rd);
				break;
			}
			case 110:
			{
				LW(instruction, rs, rd);
				break;
			}
		}
	}
	else if (instruction.opcode == 0b0010011)
	{
		switch (instruction.funct3) 
		{
			case 000:
			{
				// addi
				ADDI(instruction, rs, rd);	
				break;
			}
			case 001:
			{
				// slli
				SLLI(instruction, rs, rd);
				break;
			}
			case 100:
			{
				XORI(instruction, rs, rd);
				break;
			}
			case 101:
			{
				assert(false && "TODO: Find out which instruction to use");
				SRLI(instruction, rs, rd);
				SRAI(instruction, rs, rd);
				break;
			}
			case 110:
			{
				ORI(instruction, rs, rd);
				break;
			}
			case 111:
			{
				ANDI(instruction, rs, rd);
				break;
			}
			default:
			{
				assert(false && "Unknown instruction");
			}
		}
	}
	
}


void IHandler::ADDI(const uint16_t imm, const Register rs, Register & rd)
{
	rd = imm + rs;
}

void IHandler::SUBI(const uint16_t imm, const Register rs, Register & rd)
{
	rd = rs - imm;
}

void IHandler::SLLI(const uint16_t imm, const Register rs, Register& rd)
{
	rd = rs << imm;
}

void IHandler::SRLI(const uint16_t imm, const Register rs, Register& rd)
{
	rd = rs >> imm;
}

void IHandler::SRAI(const uint16_t imm, const Register rs, Register& rd)
{

}

// Load byte
void IHandler::LB(const uint16_t imm, const Register rs, Register& rd)
{
	rd = Memory::mem.Load<int8_t>(rs + imm);
}

// Load halfword 
void IHandler::LH(const uint16_t imm, const Register rs, Register& rd)
{
	rd = Memory::mem.Load<int16_t>(rs + imm);
}

void IHandler::LW(const uint16_t imm, const Register rs, Register& rd)
{
	rd = Memory::mem.Load<int32_t>(rs + imm);
}

void IHandler::LBU(const uint16_t imm, const Register rs, Register& rd)
{
	rd = Memory::mem.Load<uint8_t>(rs + imm);
}

void IHandler::LHU(const uint16_t imm, const Register rs, Register& rd)
{
	rd = Memory::mem.Load<uint16_t>(rs + imm);
}

void IHandler::XORI(const uint16_t imm, const Register rs, Register& rd)
{
	rd = rs ^ imm;
}

void IHandler::ORI(const uint16_t imm, const Register rs, Register& rd)
{
	rd = rs | imm;
}

void IHandler::ANDI(const uint16_t imm, const Register rs, Register& rd)
{
	rd = rs & imm;
}
