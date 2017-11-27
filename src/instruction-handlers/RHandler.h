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
		void MUL(Register& rd, Register rs1, Register rs2);
		void MULH(Register& rd, Register rs1, Register rs2); 
		void MULHSU(Register& rd, Register rs1, Register rs2); 
		void MULHU(Register& rd, Register rs1, Register rs2); 
		void DIV(Register& rd, Register rs1, Register rs2);
		void DIVU(Register& rd, Register rs1, Register rs2);
		void REM(Register& rd, Register rs1, Register rs2);
		void REMU(Register& rd, Register rs1, Register rs2);

};
