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

template<typename T>
void extendSign(T& value, uint8_t signPos){
		//Sign extend
	    T mask = -1 << signPos;
		uint8_t sign = (value & (1 << (signPos-1))) >> (signPos-1);
		value = value | (mask*sign);
}
