#include "print.h"




void kernel_main() {
    while (1 == 1){
        print_clear();
        print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
        print_str("Welcome to Generation OS!");
    }
}