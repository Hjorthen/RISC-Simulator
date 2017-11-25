#include "../instruction-types/BType.h"


class BHandler{
	public:
		uint32_t Handle(BType& instruction, Register rs1, Register rs2);

	private:
		uint32_t BEQ(const uint16_t branchAddress, Register rs1, Register rs2);
		uint32_t BNE(const uint16_t branchAddress, Register rs1, Register rs2);
		uint32_t BLT(const uint16_t branchAddress, Register rs1, Register rs2);
		uint32_t BGE(const uint16_t branchAddress, Register rs1, Register rs2);
};
