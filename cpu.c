#include "cpu.h"

void initialize_cpu(void) {
    // zero out all registers
    memset(V, 0, NUM_REGS);

    // set the PC to the point past the metadata padding
    PC = META_MEM_PADDING;
    
    return;
}

uint16_t fetch_next_instruction(void) {
    return ((memory[PC] << 8) + memory[PC + 1]);
}

void increment_pc(void) {
    PC += 2;
    return;
}

void decode_instruction(uint16_t opcode) {
        // decode the opcode and perform the necessary function
        switch(opcode & 0xF000) {
            case 0x0000:
                switch(opcode & 0x0F00) {
                    case 0x0000:
                        switch(opcode & 0x000F) {
                            case 0x0000:
                                // 00E0 - CLS
                                // clears screen
                                initialize_display();
                                increment_pc();
                                break;
                            case 0x000E:
                                // 00EE - RET
                                break;
                        }
                        break;
                    default:
                        // 0nnn - SYS addr
                        // jump to a machine code routine at nnn (deprecated)
                        PC = opcode & 0x0FFF;
                        break;
                }
                break;
            case 0x1000:
                // 1nnn - JP addr
                // jump to a machine code routine at nnn
                PC = opcode & 0x0FFF;
                break;
            case 0x2000:
                // 2nnn - CALL addr
                break;
            case 0x3000:
                // 3xkk - SE Vx, byte
                // skips to next instruction if Vx == KK
                if(V[(opcode & 0x0F00) >> 8] == (opcode & 0x0FF)) {
                    increment_pc();
                    increment_pc();
                } else {
                    increment_pc();
                }
                break;
            case 0x4000:
                // 4xkk - SNE Vx, byte
                // skips to next instruction if Vx != KK
                if(V[(opcode & 0x0F00) >> 8] != (opcode & 0x0FF)) {
                    increment_pc();
                    increment_pc();
                } else {
                    increment_pc();
                }
                break;
            case 0x5000:
                // 5xy0 - SE Vx, Vy
                // skips to next instruction if Vx == Vy
                if(V[(opcode & 0x0F00) >> 8] == V[(opcode & 0x0F0) >> 4]) {
                    increment_pc();
                    increment_pc();
                } else {
                    increment_pc();
                }
                break;
            case 0x6000:
                // 6xkk - LD Vx, byte
                // set Vx to KK
                V[(opcode & 0x0F00) >> 8] = opcode & 0x00FF;
                increment_pc();
                break;
            case 0x7000:
                // 7xkk - ADD Vx, byte
                // add KK to Vx
                V[(opcode & 0x0F00) >> 8] += opcode & 0x00FF;
                increment_pc();
                break;
            case 0x8000:
                switch(opcode & 0x000F) {
                    case 0x0000:
                        // 8xy0 - LD Vx, Vy
                        // sets the value of Vx to Vy
                        V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x0F0) >> 4]);
                        break;
                        increment_pc();
                    case 0x0001:
                        // 8xy1 - OR Vx, Vy
                        // sets Vx to Vx OR Vy
                        V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x0F00) >> 8] | V[(opcode & 0x0F0) >> 4]);
                        increment_pc();
                        break;
                    case 0x0002:
                        // 8xy2 - AND Vx, Vy
                        // sets Vx to Vx AND Vy
                        V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x0F00) >> 8] & V[(opcode & 0x0F0) >> 4]);
                        increment_pc();
                        break;
                    case 0x0003:
                        // 8xy3 - XOR Vx, Vy
                        // sets Vx to Vx XOR Vy
                        V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x0F00) >> 8] ^ V[(opcode & 0x0F0) >> 4]);
                        increment_pc();
                        break;
                    case 0x0004:
                        // 8xy4 - ADD Vx, Vy
                        break;
                    case 0x0005:
                        // 8xy5 - SUB Vx, Vy
                        break;
                    case 0x0006:
                        // 8xy6 - SHR Vx {, Vy}
                        break;
                    case 0x0007:
                        // 8xy7 - SUBN Vx, Vy
                        break;
                    case 0x000E:
                        // 8xyE - SHL Vx {, Vy}
                        break;
                }
                break;
            case 0x9000:
                // 9xy0 - SNE Vx, Vy
                break;
            case 0xA000:
                // Annn - LD I, addr
                break;
            case 0xB000:
                // Bnnn - JP V0, addr
                break;
            case 0xC000:
                // Cxkk - RND Vx, byte
                break;
            case 0xD000:
                // Dxyn - DRW Vx, Vy, nibble
                break;
            case 0xE000:
                switch(opcode & 0x00FF) {
                    case 0x009E:
                        // Ex9E - SKP Vx
                        break;
                    case 0x00A1:
                        // ExA1 - SKNP Vx
                        break;
                }
                break;
            case 0xF000:
                switch(opcode & 0x00FF) {
                    case 0x0007:
                        // Fx07 - LD Vx, DT
                        break;
                    case 0x000A:
                        // Fx0A - LD Vx, K
                        break;
                    case 0x0015:
                        // Fx15 - LD DT, Vx
                        break;
                    case 0x0018:
                        // Fx18 - LD ST, Vx
                        break;
                    case 0x001E:
                        // Fx1E - ADD I, Vx
                        break;
                    case 0x0029:
                        // Fx29 - LD F, Vx
                        break;
                    case 0x0033:
                        // Fx33 - LD B, Vx
                        break;
                    case 0x0055:
                        // Fx55 - LD [I], Vx
                        break;
                    case 0x0065:
                        // Fx65 - LD Vx, [I]
                        break;
                }
                break;
            default:
                printf("Opcode undefined!");
                while(1);
                break;
        }
}
