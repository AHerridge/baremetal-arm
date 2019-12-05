#include "tasks.h"
#include "uart_pl011.h"
#include "systime.h"
#include <stdio.h>

void task0(void) {
    systime_t start = systime_get();
    uart_write("Entering task 0... systime ");
    uart_write_uint(start);
    uint32_t cpsr;
    asm("mrs %0, cpsr"  : "=r"(cpsr));
    uint8_t mode = cpsr & 0x1F;
    if (mode == 0x10) {
        uart_write("... Task in USER mode\n");
    } else if (mode == 0x13) {
        uart_write("... Task in SUPERVISOR mode\n");
    } else if (mode == 0x1F) {
        uart_write("... Task in SYSTEM mode\n");
    }
    while (start + 1000u > systime_get());
    uart_write("Exiting task 0...\n");
}

void task1(void) {
    systime_t start = systime_get();
    uart_write("Entering task 1... systime ");
    uart_write_uint(start);
    volatile uint32_t cpsr;
    asm("mrs %0, cpsr"  : "=r"(cpsr));
    uint8_t mode = cpsr & 0x1F;
    if (mode == 0x10) {
        uart_write("... Task in USER mode\n");
    } else if (mode == 0x13) {
        uart_write("... Task in SUPERVISOR mode\n");
    } else if (mode == 0x1F) {
        uart_write("... Task in SYSTEM mode\n");
    }
    while (start + 1000u > systime_get());
    uart_write("Exiting task 1...\n");
}

void task2(void) {
    systime_t start = systime_get();
    uart_write("Entering task 2... systime ");
    uart_write_uint(start);
    uart_write("\n");
    while(1);
}
