#pragma once
#include "../Types.h"
#include "BitReader.h"

struct BType{
	// 12 bits
	int16_t imm;
	// 5 bits
	uint8_t rs1;
	// 5 bits
	uint8_t rs2;
	// 7 bits
	uint8_t opcode;
	// 3 bits
	uint8_t funct3;
	BType(Instruction in){
		BitReader reader(in);
		reader.Read(opcode, 7);
		uint16_t imm11;
		reader.Read(imm11, 1);
		imm11 = imm11 << 10;
		reader.Read(imm, 4);
		// the field goes from 1:4, not 0:3
		imm = imm << 1;
		reader.Read(funct3, 3);
		reader.Read(rs1, 5);
		reader.Read(rs2, 5);
		uint16_t immUpper;
		reader.Read(immUpper, 6);
		immUpper = immUpper << 5;
		imm = imm | immUpper;
		uint16_t imm12;
		reader.Read(imm12, 1);
		imm12 = imm12 << 11; 
		imm = imm | imm12 | imm11;
		extendSign(imm, 12);
	}



};

