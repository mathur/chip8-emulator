#include "cpu.h"

int main() {
    while(1) {
        uint16_t opcode = fetch_next_instruction();
        decode_instruction(opcode);
    }

    return 0;
}