#include <stdint.h>
#include "BitReader.h"

struct {
	uint8_t = imm11_5;
	uint8_t = rs2;
	uint8_t = rs1;
	uint8_t = funct3;
	uint8_t = imm4_0;
	uint8_t = opcode;

	SType(uint32_t instruction) {
		BitReader reader(instruction);
		reader.Read(imm11_5, 7);
		reader.Read(rs2, 5);
		reader.Read(rs1, 5);
		reader.Read(funct3, 3);
		reader.Read(imm4_0, 5);
		reader.Read(opcode, 7);
	}
};