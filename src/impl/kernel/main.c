#include "print.h"
#include "io.h"


void keyboard_input() {
    unsigned char key = port_byte_in(0x60);

    if (!(key & 0x80)) {
        char character = decode_scan_code(key & 0x7F);

        if (character != '\0') {
            print_char(character);
        }

        for (volatile int i = 0; i < 100000; i++) {
        }
    }
}



void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    print_str("Welcome to Generation OS!");
    print_newline();
    print_str("This OS is still in development");
    print_newline();
    while (1){
        keyboard_input();
    }
    
                
}
            