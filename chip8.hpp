#pragma once

#include <cstdint>
#include <random>

const unsigned int VIDEO_HEIGHT = 32;
const unsigned int VIDEO_WIDTH = 64;

class Chip8
{
public:
    Chip8();
    void LoadROM(char const* filename);
    void Cycle();

    uint32_t video[64 * 32]{};   // Video memory (64x32 pixels)
    uint8_t key[16]{};           // Key states

private:
    //Op Codes can be found at http://devernay.free.fr/hacks/chip8/C8TECH10.HTM
    void OP_NULL();               // Do nothing
    void OP_00E0();               // CLS
    void OP_00EE();               // RET
    void OP_0nnn();               // SYS addr
    void OP_1nnn();               // JP addr
    void OP_2nnn();               // CALL addr
    void OP_3xkk();               // SE Vx, byte
    void OP_4xkk();               // SNE Vx, byte
    void OP_5xy0();               // SE Vx, Vyb
    void OP_6xkk();               // LD Vx, byte
    void OP_7xkk();               // ADD Vx, byte
    void OP_8xy0();               // LD Vx, Vy
    void OP_8xy1();               // OR Vx, Vy
    void OP_8xy2();               // AND Vx, Vy
    void OP_8xy3();               // XOR Vx, Vy
    void OP_8xy4();               // ADD Vx, Vy
    void OP_8xy5();               // SUB Vx, Vy
    void OP_8xy6();               // SHR Vx
    void OP_8xy7();               // SUBN Vx, Vy
    void OP_8xyE();               // SHL Vx
    void OP_9xy0();               // SNE Vx, Vy
    void OP_Annn();               // LD I, address
    void OP_Bnnn();               // JP V0, address
    void OP_Cxkk();               // RND Vx, byte
    void OP_Dxyn();               // DRW Vx, Vy, height
    void OP_Ex9E();               // SKP Vx
    void OP_ExA1();               // SKNP Vx
    void OP_Fx07();               // LD Vx, DT
    void OP_Fx0A();               // LD Vx, K
    void OP_Fx15();               // LD DT, Vx
    void OP_Fx18();               // LD ST, Vx
    void OP_Fx1E();               // ADD I, Vx
    void OP_Fx29();               // LD F, Vx
    void OP_Fx33();               // LD B, Vx
    void OP_Fx55();               // LD [I], Vx
    void OP_Fx65();               // LD Vx, [I]

    uint8_t registers[16]{};      // General purpose registers V0-VF
    uint8_t memory[4096]{};       // Memory (4K)
    uint16_t idx{};               // Index register
    uint16_t pc{};                // Program counter
    uint16_t stack[16]{};         // Stack
    uint8_t sp{};                 // Stack pointer
    uint8_t delayTimer{};         // Delay timer
    uint8_t soundTimer{};         // Sound timer
    uint16_t opcode;              // Current opcode

    std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;

    typedef void (Chip8::*Chip8Func)();
    Chip8Func table[0x10];   
    Chip8Func table0[0x10];  
    Chip8Func table8[0x10];  
    Chip8Func tableE[0x10];  
    Chip8Func tableF[0x100]; 
};
