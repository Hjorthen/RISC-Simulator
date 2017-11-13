#include "../instruction-types/IType.h"



class IHandler{
	public:
		void Handle(IType& instruction, Register rs, Register& rd);
	
	private:
		void ADDI(const uint16_t imm, Register rs, Register& rd);
		void SUBI(const uint16_t imm, Register rs, Register & rd);
		void SLLI(const uint16_t imm, const Register rs, Register & rd);
		void SRLI(const uint16_t imm, const Register rs, Register & rd);
		void SRAI(const uint16_t imm, const Register rs, Register & rd);
		void LB(const uint16_t imm, const Register rs, Register & rd);
		void LH(const uint16_t imm, const Register rs, Register & rd);
		void LW(const uint16_t imm, const Register rs, Register & rd);
		void LBU(const uint16_t imm, const Register rs, Register & rd);
		void LHU(const uint16_t imm, const Register rs, Register & rd);
		void XORI(const uint16_t imm, const Register rs, Register & rd);
		void ORI(const uint16_t imm, const Register rs, Register & rd);
		void ANDI(const uint16_t imm, const Register rs, Register & rd);
};

