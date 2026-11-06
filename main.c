#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>




typedef struct CHIP8
{
   //4kb ram 
   uint8_t memory[4096];

   //16 general purpose registers
   uint8_t V[16];

   //index register
   uint16_t I;

   //program counter
   uint16_t PC;
   
   //stack
   uint16_t stack[16];

   //stack pointer (tracks top of stack)
   uint8_t SP;

   //timers
   uint8_t delay_timer;
   uint8_t sound_timer;

   //display buffer
   uint8_t display[64 * 32];

   //keypad
   uint8_t keypad[16];
}CHIP8;

//prototype for init_chip
void init_chip(CHIP8 *chip);

int main(void)
{
    //initialise chip
    CHIP8 chip8;
    init_chip(&chip8);

    //TODO: make both timers(delay and sound timer) decrement by 1 60 times a second
    //as long as their value is greater than 1
    
    //clear memory
    //fetch,decode,execute loop
}

void init_chip(CHIP8 *chip)
{
    //load font
    uint8_t font[] = {0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
                    0x20, 0x60, 0x20, 0x20, 0x70, // 1
                    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
                    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
                    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
                    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
                    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
                    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
                    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
                    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
                    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
                    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
                    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
                    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
                    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
                    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    //copy font into memory
    memcpy(&chip->memory, font, sizeof(font));
}