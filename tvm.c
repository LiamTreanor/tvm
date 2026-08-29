#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdarg.h>

enum vmmode {
    FAST,
    PACKED
} vmmode;

typedef enum operation {
    IDN,    // identity / noop

    SET,    // set register to literal
    LOAD,   // set register to memory value
    COPY,   // set register to value in another register
    STORE,  // store register value in memory

    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    NEG,
    INC,
    DEC,

    CMP,    // evaluate / compare
    JU,     // jump unconditional
    JL,     // jump if less
    JE,     // jump if equal
    JG,     // jump if greater
    JNL,    // jump if not less
    JNE,    // jump if not equal
    JNG,    // jump if not greater

    CF,     // call function
    EF,     // end function / return

    EP      // end program / halt
} operation;

char mode = FAST;

typedef uint8_t byte;
typedef uint8_t trit;
typedef trit u9[9];
#define U9_MAX 19683 // 3 ^ 3 ^ 2
u9 memory[U9_MAX] = {0};
u9 r[27] = {0};

int as_number(u9 nonet) {
    int result = 0;
    int power = 1;
    for (int i = 0; i < 9; i++) {
        result += nonet[i] * power;
        power *= 3;
    }
    return result;
}

int op(operation opcode, ...) {

}

void main(int argc, char** argv) {
    
}