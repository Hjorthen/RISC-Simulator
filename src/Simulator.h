#pragma once
#include <string>
#include "Types.h"
#include "instruction-handlers/IHandler.h"
#include "instruction-handlers/BHandler.h"
#include "instruction-handlers/RHandler.h"
#include "Memory.h"
#include "instruction-handlers/SHandler.h"
#include "Program.h"

struct Context {
	Context(){
		for(int i = 0; i < 32; ++i){
			regi[i] = 0;
		}
	};	
	Register regi[32];
};

class Simulator{
	constexpr static uint32_t opcodeMask = 0x7f;
	Context context;
	IHandler iHandler;
	BHandler bHandler;
	RHandler rHandler;
	SHandler sHandler;
	Program * program;
	uint32_t PC;
	bool isRunning;

	public: 	
		typedef Register* RegisterIterator;
		Simulator() : isRunning(true) {
			context.regi[0x2] = 0x7ffffff0; 
		};
		uint32_t GetPC() { return PC; }
		bool Running() { return isRunning; }
		void LoadProgram(Program * prog) { program = prog; PC = 0;}
		void execute(Instruction i);
		bool ExecuteNext();
		RegisterIterator RegisterBegin() { return context.regi; }
		RegisterIterator RegisterEnd() { return context.regi + 32; }
};
