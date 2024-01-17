#include "print.h"
#include "io.h"


void keyboard_input() {

    char prevChar;
    unsigned char key = port_byte_in(0x60);

    if (!(key & 0x80)) {
        char character = decode_scan_code(key & 0x7F);

        if (character == '\b'){
            prev_char();
            replace_char(' ');
        } else{
            if (character != '\0' ) {
                print_char(character);
            }
        }
            


        
        
        if (character != prevChar){
            for (volatile int i = 0; i < 55500000; i++) {
            }
            prevChar = character;
        }else{
            for (volatile int i = 0; i < 60000000; i++) {
            }
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
            