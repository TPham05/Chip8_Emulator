# 🎮 CHIP-8 Emulator: SDL3 + GLAD  

This project is a modern implementation of the classic **CHIP-8 virtual machine** in C++. It faithfully emulates the 1970s-era system, complete with registers, memory, and timers, while using **SDL3** and **GLAD** to provide a clean, scalable display for modern computers.  

---

## 🧠 Features  

- 📝 **Opcode Support**  
  Executes the full CHIP-8 instruction set, including drawing, arithmetic, and flow control.  

- 🖥️ **Registers & Memory**  
  Implements 16 general-purpose registers (V0–VF), the index register (I), stack, program counter, and delay/sound timers.  

- 🟩 **Pixel-Perfect Display**  
  Uses SDL3 and OpenGL (via GLAD) to render the 64×32 CHIP-8 framebuffer with crisp scaling.  

- 🎹 **Keyboard Input**  
  Maps the original CHIP-8 hex keypad to modern keyboard keys for intuitive gameplay.  

- ⏱️ **Accurate Timing**  
  Maintains 60Hz refresh for timers to stay true to the original hardware.  

⚙️ **Setup Note**  
To run this project, install **SDL3** and generate a GLAD loader (e.g., OpenGL 3.3 core). Update your build system to include them before compiling.  

---

## 🛠️ Technologies & Tools  

- **C++17** – Core implementation  
- **SDL3** – Window, events, and OpenGL context  
- **GLAD** – OpenGL function loader  
- **CMake** – Build system  

---

## 🚀 Future Improvements  

- 📈 Add support for SCHIP (Super CHIP-8) extended resolution (128×64).  
- 🔊 Add audio support for the CHIP-8 sound timer beep.  
- 🎮 Add savestates and debugger tools.  
- 📱 Port to embedded platforms like Raspberry Pi.  

---

## 🎬 Demonstration  

> A demo video of the emulator running classic CHIP-8 games will be available soon!  
