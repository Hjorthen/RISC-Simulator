#include "Simulator.h"
#include "instruction-types\IType.h"

void Simulator::execute(Instruction i) {
	uint32_t opcode = i & opcodeMask;
	switch (opcode) {

		// R-instruction
	case 0b0110011:

		break;

		// I-instruction
	case 0b0000011:
	case 0b0010011:
	{
		IType iType(i);
		Register& rd = context.regi[iType.rd];
		Register wd = context.regi[iType.rs1];
		handler.Handle(iType, wd, rd);
		break;
	}
		
		// S-instruction
	case 0b0100011:
		break;

	}
}
