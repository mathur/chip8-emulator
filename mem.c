#include <stdint.h>

void copy_prog_to_mem(uint8_t fname) {
    // attempt to open the file
    FILE * prog = fopen(fname, "rb");

    // if the open failed, error out
    if(prog == NULL) {
        printf("File open failed! Check to make sure the program name is correct.\n");
        fflush(stdin);
        exit(1);
    }

    // if the file exists, load it into memory
    fread(memory + META_MEM_PADDING, 1, TOTAL_MEMORY_SIZE - META_MEM_PADDING, prog);
}