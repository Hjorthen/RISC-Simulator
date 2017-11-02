#include "../instruction-types/IType.h"
#include "../Context.h"



class IHandler{
	public:
 	void Handle(IType& instruction, Context& cxt){
		switch(instruction.funct3){	
		

		}
	};
	
	private:
	void ADDI(IType& instruction, Context& cxt);

};

