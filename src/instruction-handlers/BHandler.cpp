#include "BHandler.h"



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


	}
}

uint32_t BHandler::BEQ(const uint16_t branchAddress, Register rs1, Register rs2){
	if(rs1 == rs2)
		return branchAddress;
	else
		return 0;
}


uint32_t BHandler::BNE(const uint16_t branchAddress, Register rs1, Register rs2){
	if(rs1 != rs2)
		return branchAddress;
	else
		return 0;

}


uint32_t BHandler::BLT(const uint16_t branchAddress, Register rs1, Register rs2){
	if(rs1 < rs2)
		return branchAddress;
	else
		return 0;

}


uint32_t BHandler::BGE(const uint16_t branchAddress, Register rs1, Register rs2){
	if(rs1 >= rs2)
		return branchAddress;
	else
		return 0;

}


