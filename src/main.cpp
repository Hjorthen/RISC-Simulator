#include "Simulator.h"
#include "Types.h"
#include <fstream>
#include <iostream>
#include <cstring>


int main(int argc, char** argv) {
	if(argc < 2){
		std::cout << "No file specified to load";
		std::cin.get();
		return -1;	
	}
	std::ifstream dataStream;
	dataStream.open(argv[1], std::ios::binary);
	if (dataStream.is_open()) {
		Instruction ins;
		Simulator simulator;
		while (!dataStream.eof() && simulator.Running()) {
			dataStream.read(reinterpret_cast<char*>(&ins), sizeof(ins));
			simulator.execute(ins);
				for (Simulator::RegisterIterator itr = simulator.RegisterBegin();itr != simulator.RegisterEnd();++itr) {
					int i = 0;
					std::cout << "x" << i << ": " << *itr << '\t';
					i++;
				}
				std::cout << '\n';	
		}
		if(argc > 2){
			std::ifstream expected;
			expected.open(argv[2], std::ios::binary | std::ios::ate);
			if(!expected.is_open()){
				std::cout << "Failed to open result file";
				std::cin.get();
				return -1;
			}
			std::streamsize fileSize = expected.tellg();
			Register * expectedResult = new Register[fileSize];
			expected.read(reinterpret_cast<char*>(&expectedResult), fileSize);
			if(memcmp(simulator.RegisterBegin(), expectedResult, fileSize) == 0){
				std::cin.get();
				return 0;
			}
			else{
				std::cin.get();
				return -1;
			}
		}
		else{	
			std::ofstream dump;
			dump.open("result.bin", std::ios::binary);
			for (Simulator::RegisterIterator itr = simulator.RegisterBegin();itr != simulator.RegisterEnd();++itr) {
				dump << *itr;
			}
			std::cin.get();
			return 0;
		}
	}
}
