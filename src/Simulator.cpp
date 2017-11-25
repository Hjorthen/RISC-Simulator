#include "Simulator.h"
#include "instruction-types/IType.h"
#include "instruction-types/BitReader.h"
#include <assert.h>
#include "instruction-types/BType.h"
#include "instruction-types/RType.h"
void Simulator::execute(Instruction i) {
	uint32_t opcode = i & opcodeMask;
	switch (opcode) {

		// R-instruction
	case 0b0110011:
	{
		RType rType(i);
		Register& rd = context.regi[rType.rd];
		Register r1 = context.regi[rType.rs1];
		Register r2 = context.regi[rType.rs2];	
		rHandler.Handle(rType, rd, r1, r2);
		break;
	}
	// LUI
	case 0b0110111:
	{
		BitReader reader(i);
		uint8_t reg;
		int32_t upper;
		reader.Read(reg, 7);
		reg = 0;
		reader.Read(reg, 5);
		reader.Read(upper, 20);	
		Register& dst = context.regi[reg];
		upper = upper << 12;
		dst = dst & upper;
		break;
	}
	// I-instruction
	case 0b0000011:
	case 0b0010011:
	{
		IType iType(i);
		Register& rd = context.regi[iType.rd];
		Register wd = context.regi[iType.rs1];
		iHandler.Handle(iType, wd, rd);
		break;
	}
	case 0b1100011:
	{
		BType bType(i);
		Register r1 = context.regi[bType.rs1];
		Register r2 = context.regi[bType.rs2];
		bHandler.Handle(bType, r1, r2);
		break;		
	}
	// ECALL
	case 0b1110011:
	{
		isRunning = false;
		break;
	}	
		// S-instruction
	case 0b0100011:
		break;

	default:
		{
			assert(false && "unknown instruction");
		}	
	}	
	// Regi 0 is read-only, reset value in case it was written to. 
	context.regi[0] = 0;	
}
