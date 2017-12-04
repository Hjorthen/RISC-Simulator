#include "Simulator.h"
#include "instruction-types/IType.h"
#include "instruction-types/BitReader.h"
#include <assert.h>
#include "instruction-types/BType.h"
#include "instruction-types/RType.h"
#include <iostream>
#include "instruction-types/UType.h"

void Simulator::execute(Instruction i) {
	uint32_t opcode = i & opcodeMask;
	int32_t branch = 0;
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
		UType u(i);
		Register& dst = context.regi[u.reg];
		dst = dst | u.upper;
		std::cout << "LUI " << dst << " " << u.upper << '\n';
		break;
	}
	//AUPC
	case 0b0010111:
	{
		UType u(i);
		Register& dst = context.regi[u.reg];
	    dst = PC*4 + u.upper;	
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
	// B-instruction
	case 0b1100011:
	{
		BType bType(i);
		Register r1 = context.regi[bType.rs1];
		Register r2 = context.regi[bType.rs2];
		branch = bHandler.Handle(bType, r1, r2);
		break;		
	}
	// ECALL
	case 0b1110011:
	{
		std::cout << "ECALL" << '\n';
		isRunning = false;
		break;
	}	
	// JALR
	case 0b1100111:
	{
		std::cout << "JALR" << '\n';
		IType iType(i);
		int32_t jumpTarget = iType.imm + context.regi[iType.rs1];
		// Set least significant bit to 0
		jumpTarget = ~1 & jumpTarget;
		context.regi[iType.rd] = (PC+1)*4;
		PC = jumpTarget/4;
		// We have to subtract because we increment PC at the end of the cycle regardless of jumping
		PC -= 1;
		break;
	}
	// JAL
	case 0b1101111:
	{
		std::cout << "JAL" << '\n';
		int32_t imm;
		uint8_t rd;
		{
			uint8_t opcode;
			BitReader reader(i);
			reader.Read(opcode, 7);
			reader.Read(rd, 5);
			uint32_t part;
			reader.Read(part, 8);
			imm = part << 11;
			reader.Read(part, 1);
			imm |= part << 10;
			reader.Read(part, 10);
			imm |= part << 1;
			reader.Read(part, 1);
			imm |= part << 19;		
			extendSign(imm, 20);
		}
		branch = imm;
		// Convert PC to bytes and store it
		context.regi[rd] = (PC+1)*4;
		break;
	}
		// S-instruction
	case 0b0100011:
	{
		SType ins(i);
		Register src = context.regi[ins.src];
		Register base = context.regi[ins.base];
		sHandler.Handle(ins, src, base);
		break;
	}
	default:
		{
			assert(false && "unknown instruction");
		}	
	}	
	if(branch != 0){
		// Must be a multiple of 4
		assert(branch%4 == 0);
		PC += branch / 4;
	}
	else{
		++PC;
	}
	// Regi 0 is read-only, reset value in case it was written to. 
	context.regi[0] = 0;	
}

bool Simulator::ExecuteNext(){

	Instruction* ins = program->FetchInstruction(PC);
	if(ins != NULL){
		execute(*ins);
		return true;
	}
	return false;
}
