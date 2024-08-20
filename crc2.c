#include <stdio.h>
#define DEGREE 16

int mod2add(int x, int y) { return x ^ y; }

int getnext(int array[], int pos) {
    while (pos < DEGREE && array[pos] == 0) ++pos;
    return pos;
}

void calc_crc(int length, int result[]) {
    int ccitt[DEGREE + 1] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, pos = 0;

    while (pos <= length - DEGREE) {
        for (int i = 0; i <= DEGREE; ++i)
            result[pos + i] = mod2add(result[pos + i], ccitt[i]);
        pos = getnext(result, pos);
    }
}

int main() {
    int array[30], result[30], length = 0;
    char ch;

    printf("Enter the data (Message) stream: ");
    while ((ch = getchar()) != '\n') array[length++] = ch - '0';

    for (int i = 0; i < DEGREE; ++i) array[length + i] = result[length + i] = 0;

    for (int i = 0; i < length + DEGREE; ++i) result[i] = array[i];
    calc_crc(length + DEGREE, result);

    printf("\nThe transmitted frame is: ");
    for (int i = 0; i < length + DEGREE; ++i) printf("%d", i < length ? array[i] : result[i]);

    printf("\nEnter the stream for which CRC has to be checked: ");
    length = 0;
    while ((ch = getchar()) != '\n') array[length++] = ch - '0';

    for (int i = 0; i < length; ++i) result[i] = array[i];
    calc_crc(length, result);

    printf("\nCalculated Checksum: ");
    for (int i = length - DEGREE; i < length; ++i) printf("%d", result[i]);

    return 0;
}