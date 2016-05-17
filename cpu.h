#include <stdint.h>

// registers
uint8_t V[16];
uint16_t I;
uint16_t pc;

// device memory
uint8_t memory[4096];

uint16_t fetch_next_instruction();
void decode_instruction(uint16_t opcode);