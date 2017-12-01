#include "RHandler.h"
#include "../Memory.h"
#include <iostream>

void RHandler::Handle(RType& instruction, Register& rd, Register rs1, Register rs2) {
	switch (instruction.funct3) {
		case 000: 
		{
			switch (instruction.funct7) {
				case 0b0000000: 
				{
					ADD(rd, rs1, rs2);
					break;
				}
				case 0b0100000:
				{
					SUB(rd, rs1, rs2);
					break;
				}
				case 0b0000001:
				{
					MUL(rd, rs1, rs2);
					break;
				}
			}
			break;
		}
		case 0b001:
		{
			switch (instruction.funct7) {
				case 0b0000000:
				{
					SLL(rd, rs1, rs2);
					break;
				}
				case 0b0000001:
				{
					MULH(rd, rs1, rs2);
					break;
				}
			}
			break;
		}
		case 0b010:
		{
			switch (instruction.funct7) {
				case 0b0000000:
				{
					SLT(rd, rs1, rs2);
					break;
				}
				case 0b0000001:
				{
					MULHSU(rd, rs1, rs2);
					break;
				}
			}
			break;
		}
		case 0b011:
		{
			switch (instruction.funct7) {
				case 0b0000000:
				{
					SLTU(rd, rs1, rs2);
					break;
				}
				case 0b0000001:
				{
					MULHU(rd, rs1, rs2);
					break;
				}
			}
			break;
		}
		case 0b100:
		{
			switch (instruction.funct7) {
				case 0b0000000:
				{
					XOR(rd, rs1, rs2);
					break;
				}
				case 0b0000001:
				{
					DIV(rd, rs1, rs2);
					break;
				}
			}
			break;
		}
		case 0b101:
		{
			switch (instruction.funct7) {
				case 0b0000000:
				{
					SRL(rd, rs1, rs2);
					break;
				}
				case 0b0100000:
				{
					SRA(rd, rs1, rs2);
					break;
				}
				case 0b0000001:
				{
					DIVU(rd, rs1, rs2);
					break;
				}
			}
			break;
		}
		case 0b110:
		{
			switch (instruction.funct7) {
				case 0b0000000:
				{
					OR(rd, rs1, rs2);
					break;
				}
				case 0b0000001:
				{
					REM(rd, rs1, rs2);
					break;
				}
			}
			break;
		}
		case 0b111:
		{
			switch (instruction.funct7) {
				case 0b0000000:
				{
					AND(rd, rs1, rs2);
					break;
				}
				case 0b0000001:
					REMU(rd, rs1, rs2);
					break;
			}
			break;
		}
		default:
		{
			assert(false && "Unknown instruction");
		}
	}
}

void RHandler::ADD(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "ADD" << '\n';
	rd = rs1 + rs2;
}

void RHandler::SUB(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "SUB" << '\n';
	rd = rs1 - rs2;
}

void RHandler::SLL(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "SLL" << '\n';
	rd = rs1 << rs2;
}

void RHandler::SRL(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "SRL" << '\n';
	rd = rs1 >> rs2;
}

void RHandler::SRA(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "SRA" << '\n';
	rd = (signed int) rs1 >> (signed int) rs2;
}

void RHandler::XOR(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "XOR" << '\n';
	rd = rs1^rs2;
}

void RHandler::OR(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "OR" << '\n';
	rd = rs1 | rs2;
}

void RHandler::AND(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "AND" << '\n';
	rd = rs1&rs2;
}

void RHandler::SLT(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "SLT" << '\n';
	rd = rs1 < rs2;
}

void RHandler::SLTU(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "SLTU" << '\n';
	rd = (unsigned int) rs1 < (unsigned int) rs2;
}

void RHandler::MUL(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "MUL" << '\n';
	rd = static_cast<SRegister>(rs1) * static_cast<SRegister>(rs2);
}

void RHandler::MULH(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "MULH" << '\n';
	rd = static_cast<SRegister>(rs1) * static_cast<SRegister>(rs2) >> 32;
}

void RHandler::MULHSU(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "MULHSU" << '\n';
	rd = static_cast<SRegister>(rs1) * rs2 >> 32;
}

void RHandler::MULHU(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "MULHU" << '\n';
	rd = rs1 * rs2 >> 32;
}

void RHandler::DIV(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "DIV" << '\n';
	rd = static_cast<SRegister>(rs1) / static_cast<SRegister>(rs2);
}

void RHandler::DIVU(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "DIVU" << '\n';
	rd = rs1 / rs2;
}

void RHandler::REM(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "REM" << '\n';
	rd = static_cast<SRegister>(rs1) % static_cast<SRegister>(rs2);
}

void RHandler::REMU(Register& rd, const Register rs1, const Register rs2) {
	std::cout << "REMU" << '\n';
	rd = rs1 % rs2;
}
