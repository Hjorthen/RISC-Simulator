#include "../instruction-types/BType.h"


class BHandler{
	public:
		uint32_t Handle(BType& instruction, Register rs1, Register rs2);

	private:
		uint32_t BEQ(const int16_t branchAddress, Register rs1, Register rs2);
		uint32_t BNE(const int16_t branchAddress, Register rs1, Register rs2);
		uint32_t BLT(const int16_t branchAddress, Register rs1, Register rs2);
		uint32_t BGE(const int16_t branchAddress, Register rs1, Register rs2);
		uint32_t BLTU(const int16_t branchAddress, Register rs1, Register rs2);
		uint32_t BGEU(const int16_t branchAddress, Register rs1, Register rs2);
};
