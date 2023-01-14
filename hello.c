#include <stdio.h>

int main() {
    char *fmt = "Hello, %s!";
    char *subject = "World";
    printf(fmt, subject);
}