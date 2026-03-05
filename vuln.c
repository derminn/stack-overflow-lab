#include <stdio.h>
#include <string.h>

void secret() {
    printf("You reached the secret function!\n");
}

void vuln() {
    char buffer[32];

    printf("input : ");
    gets(buffer);   // vulnerable function

    printf("you entered : %s\n", buffer);
}

int main() {
    vuln();
    return 0;
}
