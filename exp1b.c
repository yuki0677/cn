#include <stdio.h>
#include <string.h>

#define DLE 16
#define STX 2
#define ETX 3

int main() {
    int ch;  // Change char to int to accommodate getchar's return type
    char arr[100] = {DLE, STX};
    int i = 2, j;

    printf("\nEnter the data stream (CTRL+B -> STX, CTRL+C -> ETX, CTRL+P -> DLE, ENTER to stop):\n");
    do {
        ch = getchar();  // Read character using getchar
        if (ch == '\n') {
            break;  // Stop if newline is encountered
        }

        // Check and process the input character
        if (ch == DLE) {
            arr[i++] = DLE;
            printf("DLE");
        } else if (ch == STX) {
            printf("STX");
        } else if (ch == ETX) {
            printf("ETX");
        } else {
            printf("%c", ch);
        }
        arr[i++] = ch;  // Store the character in the array
    } while (1);  // Loop until newline is encountered

    arr[i++] = DLE;
    arr[i++] = ETX;

    printf("\nThe stuffed stream is:\n");
    for (j = 0; j < i; j++) {
        if (arr[j] == DLE) {
            printf("DLE");
        } else if (arr[j] == STX) {
            printf("STX");
        } else if (arr[j] == ETX) {
            printf("ETX");
        } else {
            printf("%c", arr[j]);
        }
    }

    printf("\nThe de-stuffed data is:\n");
    for (j = 2; j < i - 2; j++) {
        if (arr[j] == DLE) {
            printf("DLE");
            j++;
        } else if (arr[j] == STX) {
            printf("STX");
        } else if (arr[j] == ETX) {
            printf("ETX");
        } else {
            printf("%c", arr[j]);
        }
    }

    return 0;
}
