#include <stdint.h>
#include <assert.h>

class BitReader{
	uint32_t src;
	uint8_t bitsRead;
public:

	BitReader(uint32_t value)
	: src(value)
	, bitsRead(0)
	{}

	~BitReader(){
		assert(bitsRead <= sizeof(uint32_t));		
	}

	template<typename T>
	void Read(T & dst, uint32_t length){
		uint32_t mask = (1 << length) - 1;
		dst = src & mask;
		src >> length;
		bitsRead += length;
	}
};


