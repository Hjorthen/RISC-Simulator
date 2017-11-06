#include "../include/Simulator.h"

void Simulator::execute(Instruction i) {
	uint32_t opcode = i & opcodeMask;
	switch (opcode) {

		// R-instruction
	case 0b0110011:

		break;

		// I-instruction
	case 0b0000011:
	case 0b0010011:
		break;

		// S-instruction
	case 0b0100011:
		break;

	}
}
