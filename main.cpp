#include "chip8.hpp"
#include "screen.hpp"
#include <chrono>
#include <thread>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <ROM file>" << std::endl;
        return 1;
    }

    // Initialize CHIP-8 emulator
    Chip8 chip8;
    chip8.LoadROM(argv[1]);

    // Initialize display window (scale pixels 10x for visibility)
    Platform platform("CHIP-8 Emulator", VIDEO_WIDTH * 10, VIDEO_HEIGHT * 10, VIDEO_WIDTH, VIDEO_HEIGHT);

    const int CYCLES_PER_FRAME = 10; // number of Chip8 cycles per frame
    const int FRAME_DELAY_MS = 16;   

    bool quit = false;
    while (!quit) {
        // Run several Chip8 cycles per frame
        for (int i = 0; i < CYCLES_PER_FRAME; ++i) {
            chip8.Cycle();
        }

        // Handle input
        quit = platform.ProcessInput(chip8.key);

        // Update display
        platform.Update(chip8.video, VIDEO_WIDTH * sizeof(uint32_t));

    }

    return 0;
}
