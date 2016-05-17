#ifndef _CPU_H
#define _CPU_H

#include <stdint.h>
#include "mem.h"

#define NUM_REGS        16

// registers
extern uint8_t V[NUM_REGS];
extern uint16_t I;
extern uint16_t PC;

uint16_t fetch_next_instruction(void);
void decode_instruction(uint16_t opcode);

#endif /* _CPU_H */