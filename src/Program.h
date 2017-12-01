#pragma once
#include <assert.h>
#include "Types.h"
#include <fstream>


class Program{

  	Instruction* end;
	Instruction* begin;
	public:

		Program(char* filePath){
			std::ifstream dataStream;
			dataStream.open(filePath, std::ios::binary | std::ios::ate);	
			//Find size of file
			std::streamsize fileSize = dataStream.tellg();
			uint32_t instructionCount = fileSize / sizeof(Instruction);
			begin = new Instruction[instructionCount];
			end = begin + instructionCount;
			
			dataStream.seekg(std::ios::beg);
			dataStream.read(reinterpret_cast<char*>(begin), fileSize);
			dataStream.close();
		}
		Program(Instruction* program, uint32_t size)
		: begin(program)
		, end(program + size)
		{};
		~Program(){
			delete[] begin;
		}
		
	Instruction* FetchInstruction(uint32_t offset){
		if(begin + offset > end)
			return NULL;
		return begin + offset;
	}
};	
