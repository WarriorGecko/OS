#include "print.h"
#include "io.h"


void keyboard_input(){
    print_char(port_byte_in(0x60));
    
}


void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    print_str("Welcome to Generation OS!");
    print_newline();
    print_str("This OS is still in development");
    print_newline();
                
}
            