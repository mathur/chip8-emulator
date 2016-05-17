#include "cpu.h"

uint16_t fetch_next_instruction() {
    return ((memory[PC] << 8) + memory[PC + 1]);
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
                                break;
                            case 0x000E:
                                // 00EE - RET
                                break;
                        }
                        break;
                    default:
                        // 0nnn - SYS addr
                        break;
                }
                break;
            case 0x1000:
                // 1nnn - JP addr
                break;
            case 0x2000:
                // 2nnn - CALL addr
                break;
            case 0x3000:
                // 3xkk - SE Vx, byte
                break;
            case 0x4000:
                // 4xkk - SNE Vx, byte
                break;
            case 0x5000:
                // 5xy0 - SE Vx, Vy
                break;
            case 0x6000:
                // 6xkk - LD Vx, byte
                break;
            case 0x7000:
                // 7xkk - ADD Vx, byte
                break;
            case 0x8000:
                switch(opcode & 0x000F) {
                    case 0x0000:
                        // 8xy0 - LD Vx, Vy
                        break;
                    case 0x0001:
                        // 8xy1 - OR Vx, Vy
                        break;
                    case 0x0002:
                        // 8xy2 - AND Vx, Vy
                        break;
                    case 0x0003:
                        // 8xy3 - XOR Vx, Vy
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
        }
}