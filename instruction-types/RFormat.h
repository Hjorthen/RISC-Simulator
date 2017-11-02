#include <stdint.h>
#include "BitReader.h"

struct {
	uint8_t = funct7;
	uint8_t = rs2;
	uint8_t = rs1;
	uint8_t = funct3;
	uint8_t = rd;
	uint8_t = opcode;

	RType(uint32_t instruction) {
		BitReader reader(instruction);
		reader.Read(funct7, 7);
		reader.Read(rs2, 5);
		reader.Read(rs1, 5);
		reader.Read(funct3, 3);
		reader.Read(rd, 5);
		reader.Read(opcode, 7);
	};
};


