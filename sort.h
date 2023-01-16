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
