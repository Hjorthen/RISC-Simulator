#pragma once
#include <stdint.h>
#include "BitReader.h"
#include "../Types.h"


struct IShift{
	// 6 bits
	uint8_t shiftAmount;
	
	// 6 bits
	uint8_t shiftType;

	IShift(uint16_t imm){
		BitReader reader(imm);
		reader.Read(shiftAmount, 6);
		reader.Read(shiftType, 6); 
	}

};

struct IType{
	// 12 bits
	int16_t imm;
	// 5 bits
	uint8_t rs1;
	// 3 bits
	uint8_t funct3;
	// 5 bits
	uint8_t rd;
	// 7 bits
	uint8_t opcode;	

	IType(Instruction instruction){
		BitReader reader(instruction);
		reader.Read(opcode, 7);
		reader.Read(rd, 5);
		reader.Read(funct3, 3);
		reader.Read(rs1, 5);
		reader.Read(imm, 12);
		//Sign extend
	    uint16_t mask = -1 << 12;
		uint8_t sign = (imm & (1 << 11)) >> 11;
		imm = imm | (mask*sign);
				
	};
};
