#include "Simulator.h"
#include "Types.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include "Program.h"

int main(int argc, char** argv) {
	if(argc < 2){
		std::cout << "No file specified to load";
		return -1;	
	}
	Program program(argv[1]);
	
	Instruction ins;
	Simulator simulator;
	simulator.LoadProgram(&program);	
	while (simulator.Running() && simulator.ExecuteNext()){
			for (Simulator::RegisterIterator itr = simulator.RegisterBegin();itr != simulator.RegisterEnd();++itr) {
				std::cout << *itr << '\t';
			}
			std::cout << '\n';	
	}
	if(argc > 2){
		std::ifstream expected;
		expected.open(argv[2], std::ios::binary | std::ios::ate);
		if(!expected.is_open()){
			std::cout << "Failed to open result file: " << argv[2];
			return -1;
		}
		std::streamsize fileSize = expected.tellg();
		uint32_t registerCount = fileSize / sizeof(Register);
		Register * expectedResult = new Register[registerCount];
		expected.seekg(std::ios::beg);
		expected.read(reinterpret_cast<char*>(expectedResult), fileSize);
		if(memcmp(simulator.RegisterBegin(), expectedResult, fileSize) == 0){
			delete[] expectedResult;
			return 0;
		}
		else{
			delete[] expectedResult;
			return -1;
		}
	}
	else{	
		std::ofstream dump;
		dump.open("result.bin", std::ios::binary);
		for (Simulator::RegisterIterator itr = simulator.RegisterBegin();itr != simulator.RegisterEnd();++itr) {
			dump.write(reinterpret_cast<char*>(&(*itr)), sizeof(*itr));
		}
		dump.flush();
		return 0;
	}
}
