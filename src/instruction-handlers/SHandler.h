#include "../instruction-types/SType.h"
#include "../Types.h"

class SHandler {
	public:
		void Handle(SType& instruction, Register src, Register base);
};
