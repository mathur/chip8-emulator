#ifndef _CPU_H
#define _CPU_H

#include <stdint.h>

// registers
extern uint8_t V[16];
extern uint16_t I;
extern uint16_t PC;

uint16_t fetch_next_instruction();
void decode_instruction(uint16_t opcode);

#endif /* _CPU_H */