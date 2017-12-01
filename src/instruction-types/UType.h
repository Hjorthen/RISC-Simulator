#include "BitReader.h"
#include "../Types.h"

struct UType{
	uint8_t reg;
	int32_t upper;
		
	UType(Instruction i){
		BitReader reader(i);
		// First 7 bits are the opcode, skip it
		reader.Read(reg, 7);
		reg = 0;
		// Read the register offset
		reader.Read(reg, 5);
		reader.Read(upper, 20);	
		upper = upper << 12;
		extendSign(upper, 13);
	}
};
