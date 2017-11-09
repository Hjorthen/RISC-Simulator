#pragma once
#include <string>
#include "Types.h"
#include "instruction-handlers\IHandler.h"
#include "Memory.h"
struct Context {
	Register regi[32];
};

class Simulator{
	constexpr static uint32_t opcodeMask = 0x7f;
	Context context;
	IHandler handler;
	public: 
		void execute(Instruction i);
};
