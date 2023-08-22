



#include <stdarg.h>
#include <stdio.h>



void myPrintf(const char* format, ...);


void myPrintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    // Iterate through the format string
    for (int i = 0; format[i] != '\0'; i++) {
        // Check if '%' character is found
        if (format[i] == '%') {
            // Check the next character after '%'
            switch (format[++i]) {
                case 'c':
                    // Read and print character argument
                    putchar(va_arg(args, int));
                    break;
                case 'd':
                    // Read and print decimal integer argument
                    printf("%d", va_arg(args, int));
                    break;
                case 'f':
                    // Read and print floating-point argument
                    printf("%f", va_arg(args, double));
                    break;
                case 's':
                    // Read and print string argument
                    fputs(va_arg(args, char*), stdout);
                    break;
                default:
                    // Print the '%' character if unrecognized specifier is found
                    putchar('%');
                    --i;
                    break;
            }
        } else {
            // Print regular characters
            putchar(format[i]);
        }
    }
    
    va_end(args);
}

int main() {
    myPrintf("Hello, %s! The value of x is %d and PI is %f.\n", "World", 42, 3.14159);
    myPrintf("This is a character: %c\n", 'A');
    return 0;
}



