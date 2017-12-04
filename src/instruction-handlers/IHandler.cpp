#include "IHandler.h"
#include "../Types.h"
#include "../Memory.h"
#include <iostream>

void IHandler::Handle(IType & instruction, Register rs, Register & rd)
{
	if (instruction.opcode == 0b0000011) {
		switch (instruction.funct3) {
			case 0b000:
			{
				LB(instruction.imm, rs, rd);
				break;
			}
			case 0b001:
			{
				LH(instruction.imm, rs, rd);
				break;
			}
			case 0b010:
			{
				LW(instruction.imm, rs, rd);
				break;
			}
			case 0b100:
			{
				LBU(instruction.imm, rs, rd);
				break;
			}
			case 0b101:
			{
				LHU(instruction.imm, rs, rd);
				break;
			}
			case 0b110:
			{
				LW(instruction.imm, rs, rd);
				break;
			}
		}
	}
	else if (instruction.opcode == 0b0010011)
	{
		switch (instruction.funct3) 
		{
			case 0b000:
			{
				// addi
				ADDI(instruction.imm, rs, rd);	
				break;
			}
			case 0b001:
			{
				// slli
				SLLI(instruction.imm, rs, rd);
				break;
			}
			case 0b100:
			{
				XORI(instruction.imm, rs, rd);
				break;
			}
			case 0b101:
			{
				IShift shiftIns(instruction.imm);
				if(shiftIns.shiftType){
					SRAI(shiftIns.shiftAmount, rs, rd);
				}
				else{ 
					SRLI(shiftIns.shiftAmount, rs, rd);
				}
				break;
			}
			case 0b110:
			{
				ORI(instruction.imm, rs, rd);
				break;
			}
			case 0b111:
			{
				ANDI(instruction.imm, rs, rd);
				break;
			}
			case 0b010:
			{
				SLTI(instruction.imm, rs, rd);
				break;
			}
			case 0b011:
			{
				SLTIU(instruction.imm, rs, rd);
				break;
			}
			default:
			{
				assert(false && "Unknown instruction");
			}
		}
	}
	
}

void IHandler::SLTI(const int16_t imm, const Register rs, Register & rd)
{
	rd = (*reinterpret_cast<const SRegister*>(&rs) < imm);
}

void IHandler::SLTIU(const int16_t imm, const Register rs, Register & rd)
{
	rd = (rs < *reinterpret_cast<const uint16_t*>(&imm));
}

void IHandler::ADDI(const int16_t imm, const Register rs, Register & rd)
{
	uint32_t simm = imm;
	extendSign(simm, 12);
	std::cout << "ADDI" << '\n';
	rd = (simm) + rs;
}

void IHandler::SUBI(const int16_t imm, const Register rs, Register & rd)
{
	std::cout << "SUBI" << '\n';
	rd = rs - imm;
}

void IHandler::SLLI(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "SLLI" << '\n';
	rd = rs << imm;
}

void IHandler::SRLI(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "SRLI" << '\n';
	rd = rs >> imm;
}

void IHandler::SRAI(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "SRAI" << '\n';
	rd = static_cast<SRegister>(rs) >> imm;
}

// Load byte
void IHandler::LB(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "LB" << '\n';
	rd = Memory::mem.Load<int8_t>(rs + imm);
	extendSign<int8_t>(rd);
}

// Load halfword 
void IHandler::LH(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "LH" << '\n';
	rd = Memory::mem.Load<int16_t>(rs + imm);
	extendSign<uint16_t>(rd);
}

void IHandler::LW(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "LW" << '\n';
	rd = Memory::mem.Load<int32_t>(rs + imm);
}

void IHandler::LBU(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "LBU" << '\n';
	rd = Memory::mem.Load<uint8_t>(rs + imm);
}

void IHandler::LHU(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "LHU" << '\n';
	rd = Memory::mem.Load<uint16_t>(rs + imm);
}

void IHandler::XORI(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "XORI" << '\n';
	rd = rs ^ imm;
}

void IHandler::ORI(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "ORI" << '\n';
	rd = rs | imm;
}

void IHandler::ANDI(const int16_t imm, const Register rs, Register& rd)
{
	std::cout << "ANDI" << '\n';
	rd = rs & imm;
}

