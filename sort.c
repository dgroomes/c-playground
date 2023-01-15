#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * This is a simple C program that takes three integer arguments and prints them out in ascending order. Each integer
 * must be between 0 and 999 inclusive.
 */
int main(int argc, char *argv[]);

/*
Parse one program argument into an integer in the range 0 to 999 inclusive. If the given argument is not an integer in
this range, then return -1.
 */
int parse_int_argument(char *arg);

int main(int argc, char **argv) {
    // These represent the three integer arguments. Our goal is to sort the integer values into ascending order where
    // a < b < c.
    int a, b, c;

    if (argc != 4) {
        printf("Usage: %s <int> <int> <int>", argv[0]);
        return EXIT_FAILURE;
    }

    if ((a = parse_int_argument(argv[1])) == -1) {
        printf("The first argument is invalid. Expected an integer in the range 0-999 but found %s", argv[1]);
        return EXIT_FAILURE;
    }

    if ((b = parse_int_argument(argv[2])) == -1) {
        printf("The second argument is invalid. Expected an integer in the range 0-999 but found %s", argv[2]);
        return EXIT_FAILURE;
    }

    if ((c = parse_int_argument(argv[3])) == -1) {
        printf("The third argument is invalid. Expected an integer in the range 0-999 but found %s", argv[3]);
        return EXIT_FAILURE;
    }

    // Normally, we would use a standard sorting function to sort the elements of an array, but we're going to hand-write
    // some "hardcoded three-element" sorting code for the purpose of understanding pointers betters and learning C.
    // Let's write a naive bubble sort!

    // Pass 1. This pushes the greatest valued integer to the end (variable 'c').
    {
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        if (b > c) {
            int temp = b;
            b = c;
            c = temp;
        }
    }

    // Pass 2. This pushes the next greatest valued integer to the second to the end (variable 'b').
    {
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
    }

    // There is no need for a third pass because 'a' is the only remaining integer.

    printf("%d %d %d", a, b, c);
    return EXIT_SUCCESS;
}

int parse_int_argument(char *arg) {
    int result = 0;

    while (*arg != '\0') {
        char dc; // The character value of the program argument which was validated as a digit.
        int d; // The integer value of the digit.

        dc = *arg;
        if (!isdigit(dc)) {
            return -1;
        }

        // '0' is the ASCII value of the character '0'. Subtracting '0' from the digit character gives us the integer
        // value of the digit. Pretty neat.
        d = dc - '0';

        result *= 10;
        result += d;

        if (result > 999) {
            return -1;
        }

        // Move to the next character in the program argument.
        // (Is this considered pointer arithmetic?)
        arg++;
    }

    return result;
}
