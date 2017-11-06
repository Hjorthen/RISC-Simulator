#include "../instruction-types/IType.h"



class IHandler{
	public:
		void Handle(IType& instruction, Register rs, Register& rd);
	
	private:
		void ADDI(IType& instruction, Register rs, Register& rd);

};

