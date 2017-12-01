#include <stdint.h>
#include "BitReader.h"
#include "../Types.h"

struct SType{
	uint8_t src;
	uint8_t base;
	uint8_t funct3;
	int16_t imm;
	uint8_t opcode;

	SType(uint32_t instruction) {
		BitReader reader(instruction);
		reader.Read(opcode, 7);
		reader.Read(imm, 5);
		reader.Read(funct3, 3);
		reader.Read(base, 5);
		reader.Read(src, 5);
		uint16_t immUpper;
		reader.Read(immUpper, 7);
		imm  = imm | (immUpper << 5);
		extendSign(imm, 12);
	}
};
