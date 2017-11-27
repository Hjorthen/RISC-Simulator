#include "BHandler.h"
#include <iostream>

uint32_t BHandler::Handle(BType& instruction, Register rs1, Register rs2){
	switch(instruction.funct3){
		case 0b000:
			return BEQ(instruction.imm, rs1, rs2);
		case 0b001:
			return BNE(instruction.imm, rs1, rs2);
		case 0b100:
			return BLT(instruction.imm, rs1, rs2);
		case 0b101:
			return BGE(instruction.imm, rs1, rs2);
		default:
			assert(false && "Unknown instruction");
	}
	return 0;
}

uint32_t BHandler::BEQ(const int16_t branchAddress, Register rs1, Register rs2){
	std::cout << "BEQ" << '\n';
	if (rs1 == rs2)
		return branchAddress;
	else
		return 0;
}


uint32_t BHandler::BNE(const int16_t branchAddress, Register rs1, Register rs2){
	std::cout << "BNE" << '\n';
	if(rs1 != rs2)
		return branchAddress;
	else
		return 0;

}


uint32_t BHandler::BLT(const int16_t branchAddress, Register rs1, Register rs2){
	std::cout << "BLT" << '\n';
	if(rs1 < rs2)
		return branchAddress;
	else
		return 0;

}


uint32_t BHandler::BGE(const int16_t branchAddress, Register rs1, Register rs2){
	std::cout << "BGE" << '\n';
	if(rs1 >= rs2)
		return branchAddress;
	else
		return 0;

}


