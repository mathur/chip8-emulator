#ifndef _MEM_H
#define _MEM_H

#include <stdint.h>

#define META_MEM_PADDING        0x200
#define TOTAL_MEMORY_SIZE        4096

// device memory
extern uint8_t memory[4096];

void copy_prog_to_mem(uint8_t fname);

#endif /* _MEM_H */