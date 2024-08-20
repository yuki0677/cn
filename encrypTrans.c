#include <stdio.h>
#include <string.h>

void main() {
    char data[100], wrd[] = "MEGABUCK", cipher[20][8];
    int seq[8], i, j, k, cnt;

    for (i = 0; i < 8; i++) {
        cnt = 0;
        for (j = 0; j < 8; j++)
            if (wrd[i] > wrd[j]) ++cnt;
        seq[i] = cnt;
    }

    printf("Enter data: ");
    gets(data);
    cnt = strlen(data);

    for (i = 0; i < cnt; i++)
        cipher[i / 8][i % 8] = data[i];

    for (j = i % 8; j < 8 && j != 0; j++)
        cipher[i / 8][j] = '.', cnt++;

    printf("\nEncrypted data:\n");
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            if (seq[j] == i) break;
        for (k = 0; k < cnt / 8; k++)
            printf("%c", cipher[k][j]);
    }
}
