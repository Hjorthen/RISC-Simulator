#pragma once
#include <string>
#include "Types.h"
#include "instruction-handlers/IHandler.h"
#include "instruction-handlers/BHandler.h"
#include "instruction-handlers/RHandler.h"
#include "Memory.h"
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
	bool isRunning;
	public: 	
		typedef Register* RegisterIterator;
		Simulator() : isRunning(true) {};
		bool Running() { return isRunning; }
		void execute(Instruction i);
		RegisterIterator RegisterBegin() { return context.regi; }
		RegisterIterator RegisterEnd() { return context.regi + 32; }
};
