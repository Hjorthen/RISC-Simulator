#pragma once
#include <stdint.h>

typedef uint32_t Instruction;

typedef uint32_t Register;
typedef int32_t SRegister;

template<typename T>
void extendSign(Register& value){
//Sign extend
		uint8_t bits = sizeof(T)*8;
	    T mask = -1 << bits;
		uint8_t sign = (value & (1 << (bits-1))) >> (bits-1);
		value = value | (mask*sign);
			
};

