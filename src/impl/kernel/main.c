#include "print.h"
#include "userInput.h"




void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    print_str("Welcome to Generation OS!");
    extern iostart();
    iostart();
}