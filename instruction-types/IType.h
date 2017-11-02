#include <stdint.h>
#include "BitReader.h"
struct IType{
	// 12 bits
	uint16_t imm;
	// 5 bits
	uint8_t rs1;
	// 3 bits
	uint8_t funct3;
	// 5 bits
	uint8_t rd;
	// 7 bits
	uint8_t opcode;	

	IType(uint32_t instruction){
		BitReader reader(instruction);
		reader.Read(imm, 12);
		reader.Read(rs1, 5);
		reader.Read(funct3, 3);
		reader.Read(rd, 5);
		reader.Read(opcode, 7);
	};
};
