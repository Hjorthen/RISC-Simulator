#include "../instruction-types/RType.h"

class RHandler {
	public:
		void Handle(RType& instruction, Register& rd, Register rs1, Register rs2);

	private:
		void SLL(Register& rd, Register rs1, Register rs2);
		void SRL(Register& rd, Register rs1, Register rs2);
		void SRA(Register& rd, Register rs1, Register rs2);
		void ADD(Register& rd, Register rs1, Register rs2);
		void SUB(Register& rd, Register rs1, Register rs2);
		void XOR(Register& rd, Register rs1, Register rs2);
		void OR(Register& rd, Register rs1, Register rs2);
		void AND(Register& rd, Register rs1, Register rs2);
		void SLT(Register& rd, Register rs1, Register rs2);
		void SLTU(Register& rd, Register rs1, Register rs2);
};
