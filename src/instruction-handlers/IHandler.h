#include "../instruction-types/IType.h"



class IHandler{
	public:
		void Handle(IType& instruction, Register rs, Register& rd);
	
	private:
		void ADDI(IType& instruction, Register rs, Register& rd);
		void SUBI(IType & instruction, Register rs, Register & rd);
		void SLLI(IType & instruction, const Register rs, Register & rd);
		void SRLI(IType & instruction, const Register rs, Register & rd);
		void SRAI(IType & instruction, const Register rs, Register & rd);
		void LB(IType & instruction, const Register rs, Register & rd);
		void LH(IType & instruction, const Register rs, Register & rd);
		void LW(IType & instruction, const Register rs, Register & rd);
		void LBU(IType & instruction, const Register rs, Register & rd);
		void LHU(IType & instruction, const Register rs, Register & rd);
		void XORI(IType & instruction, const Register rs, Register & rd);
		void ORI(IType & instruction, const Register rs, Register & rd);
		void ANDI(IType & instruction, const Register rs, Register & rd);
};

