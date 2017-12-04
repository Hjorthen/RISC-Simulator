#include "Simulator.h"
#include "Types.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Program.h"

int main(int argc, char** argv) {
	if(argc < 2){
		std::cout << "No file specified to load";
		std::cin.get();
		return -1;	
	}

	Program program(argv[1]);
	
	Instruction ins;
	Simulator simulator;
	simulator.LoadProgram(&program);
	int cycle_count = 0;
	while (simulator.Running() && simulator.ExecuteNext()){
		int i = 0;
		++cycle_count;
			for (Simulator::RegisterIterator itr = simulator.RegisterBegin();itr != simulator.RegisterEnd();++itr) {
				std::cout << std::setfill('0') << std::setw(1) << "x" << std::setw(2) << std::dec << i << " : " << "0x"  << std::setw(8) << std::hex << *itr << std::setw(1) << std::setfill(' ') << " |  ";
				i++;
				if(i%8 == 0)
				{
					std::cout << std::endl;
				}
			}
			std::cout << "PC: " << simulator.GetPC() << " | " << "CC: " << cycle_count;
			std::cout << "\n \n";	
	}
	if(argc > 2){
		std::ofstream dump;
		dump.open(argv[2], std::ios::binary);
		std::cout << "Writing to " << argv[2];
		for (Simulator::RegisterIterator itr = simulator.RegisterBegin();itr != simulator.RegisterEnd();++itr) {
			dump.write(reinterpret_cast<char*>(&(*itr)), sizeof(*itr));
		}
		dump.flush();
		dump.close();
		return 0;

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
