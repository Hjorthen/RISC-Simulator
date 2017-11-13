#include "Simulator.h"
#include "Types.h"
#include <fstream>




int main(int argc, char** argv) {
	std::ifstream dataStream;
	dataStream.open(argv[1], std::ios::binary);
	if (dataStream.is_open()) {
		Instruction ins;
		Simulator simulator;
		while (!dataStream.eof) {
			dataStream >> ins;
			simulator.execute(ins);
		}	
		std::ofstream dump;
		dump.open("result.bin", std::ios::binary);
		for (Simulator::RegisterIterator itr = simulator.RegisterBegin();itr != simulator.RegisterEnd();++itr) {
			dump << *itr;
		}
	}
}