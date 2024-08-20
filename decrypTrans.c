#include <stdio.h>
#include <string.h>

int main() {
    char data[100], wrd[] = "MEGABUCK", cipher[20][8];
    int seq[8], i, j, cnt, c;

    for (i = 0; i < 8; i++) {
        cnt = 0;
        for (j = 0; j < 8; j++)
            if (wrd[i] > wrd[j]) ++cnt;
        seq[i] = cnt;
    }

    printf("Enter data: ");
    gets(data);
    cnt = strlen(data);

    if (cnt % 8 != 0) {
        printf("Error: Invalid Input");
    } else {
        for (i = 0; i < 8; i++) {
            for (c = 0; c < 8; c++)
                if (seq[c] == i) break;
            for (j = 0; j < cnt / 8; j++)
                cipher[j][c] = data[i * (cnt / 8) + j];
        }

        printf("Decrypted data: ");
        for (i = 0; i < cnt; i++)
            printf("%c", cipher[i / 8][i % 8]);
    }
    return 0;
}
