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
		typedef Register* RegisterIterator;
		void execute(Instruction i);
		RegisterIterator RegisterBegin() { return context.regi; }
		RegisterIterator RegisterEnd() { return context.regi + 32; }
};
