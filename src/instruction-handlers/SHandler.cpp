#include "SHandler.h"
#include "../Memory.h"
#include "../Types.h"
#include <assert.h>
#include <iostream>

void SHandler::Handle(SType& instruction, Register src, Register base){
	unsigned int position = base + instruction.imm;
	switch(instruction.funct3){
		case 0b000:
		{
			std::cout << "SB\n";
			Memory::mem.Store<uint8_t>(position, src);	
			break;
		}
		case 0b001:
		{
			std::cout << "SH\n";
			Memory::mem.Store<uint16_t>(position, src);	
			break;
		}
		case 0b010:
		{
			std::cout << "SW\n";
			Memory::mem.Store<uint32_t>(position, src);
			break;
		}
		default:
		{
			assert(false && "Unknown instruction");				
		}
	}
}





