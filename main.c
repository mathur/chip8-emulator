#include "cpu.h"
#include "mem.h"

int main() {
    // get the program name from the user
    uint8_t * fname;
    printf("Enter the filename of the program you want to run: ");
    scanf("%s", &fname);

    // copy the program to the device's memory
    copy_prog_to_mem(fname);

    while(1) {
        uint16_t opcode = fetch_next_instruction();
        decode_instruction(opcode);
    }

    return 0;
}