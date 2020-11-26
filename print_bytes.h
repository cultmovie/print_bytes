#ifndef _PRINT_BYTES_H
#define _PRINT_BYTES_H

#include <stdint.h>

typedef unsigned char * BYTE_PTR;

void print_bytes(BYTE_PTR start, int len, int reverse_byte);
void print_char_bytes(signed char x, int reverse_byte);
void print_uchar_bytes(unsigned char x, int reverse_byte);
void print_int_bytes(int x, int reverse_byte);
void print_uint_bytes(unsigned x, int reverse_byte);
void print_short_bytes(short x, int reverse_byte);
void print_ushort_bytes(unsigned short x, int reverse_byte);
void print_long_bytes(long x, int reverse_byte);
void print_ulong_bytes(unsigned long x, int reverse_byte);
void print_int32_bytes(int32_t x, int reverse_byte);
void print_int64_bytes(int64_t x, int reverse_byte);
void print_uint32_bytes(uint32_t x, int reverse_byte);
void print_uint64_bytes(uint64_t x, int reverse_byte);
void print_float_bytes(float x, int reverse_byte);
void print_double_bytes(double x, int reverse_byte);
void print_ptr_bytes(void *x, int reverse_byte);

#endif
