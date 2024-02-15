#include <stdio.h>
#include <string.h>

void xorEncryptDecrypt(char *input, char *key) {
    int input_len = strlen(input);
    int key_len = strlen(key);

    for (int i = 0; i < input_len; i++) {
        input[i] ^= key[i % key_len];
    }
}

void base64Encode(char *input, char *output) {
    FILE *fp = popen("base64", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening pipe for base64 encoding.\n");
        return;
    }

    fprintf(fp, "%s", input);
    fflush(fp);
    pclose(fp);
}

void base64Decode(char *input, char *output) {
    FILE *fp = popen("base64 -d", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening pipe for base64 decoding.\n");
        return;
    }

    fprintf(fp, "%s", input);
    fflush(fp);
    pclose(fp);
}

int main() {
    char choice[2];
    printf("Enter your choice (1 for encrypt, 2 for decrypt): ");
    scanf("%1s", choice);

    if (strcmp(choice, "1") == 0 || strcmp(choice, "2") == 0) {
        char input[100];
        char key[100];

        printf("Enter the string to %s: ", (strcmp(choice, "1") == 0) ? "encrypt" : "decrypt");
        scanf(" %[^\n]", input);

        printf("Enter the XOR key: ");
        scanf(" %[^\n]", key);

        if (strcmp(choice, "1") == 0) {
            base64Encode(input, input);
        }

        xorEncryptDecrypt(input, key);

        if (strcmp(choice, "2") == 0) {
            base64Decode(input, input);
        }

        printf("%s string: %s\n", (strcmp(choice, "1") == 0) ? "Encrypted" : "Decrypted", input);

    } else {
        printf("Invalid choice. Please enter '1' for encrypt or '2' for decrypt.\n");
    }

    return 0;
}
