#include "io.h"

unsigned char port_byte_in(unsigned short port) {
    unsigned char result;
    __asm__ __volatile__("in %%dx, %%al" : "=a"(result) : "d"(port));
    return result;
}

void port_byte_out(unsigned short port, unsigned char data) {
    __asm__ __volatile__("out %%al, %%dx" : : "a"(data), "d"(port));
}

unsigned short port_word_in(unsigned short port) {
    unsigned short result;
    __asm__ __volatile__("in %%dx, %%ax" : "=a"(result) : "d"(port));
    return result;
}

void port_word_out(unsigned short port, unsigned short data) {
    __asm__ __volatile__("out %%ax, %%dx" : : "a"(data), "d"(port));
}

char decode_scan_code(unsigned char scan_code) {
    // Example mapping for a UK QWERTY keyboard
    static const char keyboard_map[128] = {
        0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', '\t', // 0-15
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0, 'a', 's', // 16-31
        'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x', 'c', 'v', // 32-47
        'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' ', // 48-57 and 58-61
        0, // 62
        0, // 63
        0, // 64
        '7', '8', '9', '-', '4', '5', '6', '+', '1', '2', '3', '0', '.', // 65-76
        0, 0, 0, // 77-79
        0, // 80
        0, 0, 0, // 81-83
        0, // 84
        0, 0, // 85-86
        0, // 87
        0, // 88
        0, // 89
        0, // 90
        0, // 91
        0, // 92
        0, // 93
        0, // 94
        0, // 95
        0, // 96
        0, // 97
        0, // 98
        0, // 99
        0, // 100
        0, // 101
        0, // 102
        0, // 103
        0, // 104
        0, // 105
        0, // 106
        0, // 107
        0, // 108
        0, // 109
        0, // 110
        0, // 111
        0, // 112
        0, // 113
        0, // 114
        0, // 115
        0, // 116
        0, // 117
        0, // 118
        0, // 119
        0, // 120
        0, // 121
        0, // 122
        0, // 123
        0, // 124
        0, // 125
        0, // 126
        0  // 127
    };

    // Check if the scan code is within the valid range
    if (scan_code < 128) {
        // Lookup the corresponding character in the keyboard map
        return keyboard_map[scan_code];
    }

    // If the scan code is not in the map, return a null character
    return '\0';
}