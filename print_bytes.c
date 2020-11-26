#include <stdio.h>
#include <limits.h>
#include "print_bytes.h"

static char *hexs[] = {
    "0000", //0
    "0001", //1
    "0010", //2
    "0011", //3
    "0100", //4
    "0101", //5
    "0110", //6
    "0111", //7
    "1000", //8
    "1001", //9
    "1010", //a
    "1011", //b
    "1100", //c
    "1101", //d
    "1110", //e
    "1111", //f
};

static unsigned char mask1 = 0xF0;
static unsigned char mask2 = 0x0F;

static void print_hex(unsigned char v) {
    printf("%.2X", v);
}

static void print_bin(unsigned char v) {
    printf("%s ", hexs[(v & mask1) >> (CHAR_BIT / 2)]);
    printf("%s ", hexs[v & mask2]);
}

void print_bytes(BYTE_PTR start, int len, int reverse_byte) {
    fputs("0x", stdout);
    if(reverse_byte) {
        for(int i = len - 1;i >= 0;i--)
            print_hex(start[i]);
        fputs("\n", stdout);
        
        for(int i = len - 1;i >= 0;i--)
            print_bin(start[i]);
    }
    else {
        for(int i = 0;i < len;i++)
            print_hex(start[i]);
        fputs("\n", stdout);
        
        for(int i = 0;i < len;i++) {
            print_bin(start[i]);
        }
    }
    fputs("\n", stdout);
}

void print_char_bytes(signed char x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(signed char), reverse_byte);
}

void print_uchar_bytes(unsigned char x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(unsigned char), reverse_byte);
}

void print_int_bytes(int x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(int), reverse_byte);
}

void print_uint_bytes(unsigned x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(unsigned), reverse_byte);
}

void print_short_bytes(short x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(short), reverse_byte);
}

void print_ushort_bytes(unsigned short x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(unsigned short), reverse_byte);
}

void print_long_bytes(long x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(long), reverse_byte);
}

void print_ulong_bytes(unsigned long x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(unsigned long), reverse_byte);
}

void print_int32_bytes(int32_t x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(int32_t), reverse_byte);
}

void print_int64_bytes(int64_t x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(int64_t), reverse_byte);
}

void print_uint32_bytes(uint32_t x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(uint32_t), reverse_byte);
}

void print_uint64_bytes(uint64_t x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(uint64_t), reverse_byte);
}

void print_float_bytes(float x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(float), reverse_byte);
}

void print_double_bytes(double x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(double), reverse_byte);
}

void print_ptr_bytes(void *x, int reverse_byte) {
    print_bytes((BYTE_PTR)&x, sizeof(void *), reverse_byte);
}

int main(int argc, char *argv[]) {
    long x = -8;
    print_long_bytes(x, 0);
    print_long_bytes(x, 1);
    print_ulong_bytes((unsigned long)x, 0);
    print_ulong_bytes((unsigned long)x, 1);
    print_ptr_bytes(&x, 0);
    print_ptr_bytes(&x, 1);
}
