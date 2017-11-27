#include "../instruction-types/IType.h"



class IHandler{
	public:
		void Handle(IType& instruction, Register rs, Register& rd);
	
	private:
		void ADDI(const int16_t imm, Register rs, Register& rd);
		void SUBI(const int16_t imm, Register rs, Register & rd);
		void SLLI(const int16_t imm, const Register rs, Register & rd);
		void SRLI(const int16_t imm, const Register rs, Register & rd);
		void SRAI(const int16_t imm, const Register rs, Register & rd);
		void LB(const int16_t imm, const Register rs, Register & rd);
		void LH(const int16_t imm, const Register rs, Register & rd);
		void LW(const int16_t imm, const Register rs, Register & rd);
		void LBU(const int16_t imm, const Register rs, Register & rd);
		void LHU(const int16_t imm, const Register rs, Register & rd);
		void XORI(const int16_t imm, const Register rs, Register & rd);
		void ORI(const int16_t imm, const Register rs, Register & rd);
		void ANDI(const int16_t imm, const Register rs, Register & rd);
};

