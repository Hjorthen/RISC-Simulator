#include <string>
#include "Types.h"

struct Context {

};

class Simulator{
	constexpr static uint32_t opcodeMask = 0x7f;
	Context context;
	public: 
		void execute(Instruction i);
};
