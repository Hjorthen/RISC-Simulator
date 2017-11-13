#include "RHandler.h"
#include "../Memory.h"

void RHandler::Handle(RType& instruction, Register& rd, Register rs1, Register rs2) {
	switch (instruction.funct3) {
		case 000: 
		{
			switch (instruction.funct7) {
				case 0000000: 
				{
					ADD(rd, rs1, rs2);
					break;
				}
				case 0100000:
				{
					SUB(rd, rs1, rs2);
					break;
				}
			}
			break;
		}
		case 001:
		{
			SLL(rd, rs1, rs2);
			break;
		}
		case 010:
		{
			SLT(rd, rs1, rs2);
			break;
		}
		case 011:
		{
			SLTU(rd, rs1, rs2);
			break;
		}
		case 100:
		{
			XOR(rd, rs1, rs2);
			break;
		}
		case 101:
		{
			switch (instruction.funct7) {
				case 0000000:
				{
					SRL(rd, rs1, rs2);
					break;
				}
				case 0100000:
				{
					SRA(rd, rs1, rs2);
					break;
				}
			}
			break;
		}
		case 110:
		{
			OR(rd, rs1, rs2);
			break;
		}
		case 111:
		{
			AND(rd, rs1, rs2);
			break;
		}
	}
}

void RHandler::ADD(Register& rd, const Register rs1, const Register rs2) {
	rd = rs1 + rs2;
}

void RHandler::SUB(Register& rd, const Register rs1, const Register rs2) {
	rd = rs1 - rs2;
}

void RHandler::SLL(Register& rd, const Register rs1, const Register rs2) {
	rd = rs1 << rs2;
}

void RHandler::SRL(Register& rd, const Register rs1, const Register rs2) {
	rd = rs1 >> rs2;
}

void RHandler::SRA(Register& rd, const Register rs1, const Register rs2) {
	rd = rs1 - rs2;
}

void RHandler::XOR(Register& rd, const Register rs1, const Register rs2) {
	rd = rs1^rs2;
}

void RHandler::OR(Register& rd, const Register rs1, const Register rs2) {
	rd = rs1|rs2;
}

void RHandler::AND(Register& rd, const Register rs1, const Register rs2) {
	rd = rs1&rs2;
}

void RHandler::SLT(Register& rd, const Register rs1, const Register rs2) {
	rd = rs1 < rs2;
}

void RHandler::SLTU(Register& rd, const Register rs1, const Register rs2) {
	rd = rs1 - rs2;
}