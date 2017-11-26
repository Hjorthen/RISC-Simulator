#pragma once
#include <stdlib.h>
#include <assert.h>
#include "Types.h"


class Memory {
	uint8_t* data;
	size_t s;
public:
	Memory(size_t size) {
		data = static_cast<uint8_t*>(malloc(size));
		s = size;
	}
	~Memory(){
		free(data);
	}

	template<typename T>
	T Load(size_t position) {
		assert(position + sizeof(T) < s);
		return *reinterpret_cast<T*>(data + position);
	}

	template<typename T>
	void Store(size_t position, T value) {
		assert(position + sizeof(T) < s);
		*reinterpret_cast<T*>(data + position) = value;
	}

	static Memory mem;
};
