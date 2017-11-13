#pragma once

#include <stdlib.h>
#include <assert.h>


class Memory {
	void* data;
	size_t s;
public:
	Memory(size_t size) {
		data = malloc(size);
		s = size;
	}

	template<typename T>
	T Load(size_t position) {
		assert(position + sizeof(T) < s);
		return *static_cast<T*>(data + position);
	}

	template<typename T>
	void Store(size_t position, T value) {
		assert(position + sizeof(T) < s);
		*static_cast<T*>(data + position) = value;
	}

	static Memory mem;
};
