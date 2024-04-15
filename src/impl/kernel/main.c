#include "print.h"
#include "io.h"
#include "keyboard.h"

void keyboard_input() {
    while(1){

        unsigned char scan_code = port_byte_in(0x60);
        char character = decode_scan_code(scan_code);
        
        if (scan_code & 0x80) {

        } else{
            switch (character){
                case '\b':
                    prev_char();
                    replace_char(' ');
                    break;
                default:
                    print_char(character);
                    break;
            }
            
                
            for (volatile int i = 0; i < 67000000; i++){
            }
        }
        cursor();
    }
}





void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    print_char('//');
    keyboard_input();      
}
            