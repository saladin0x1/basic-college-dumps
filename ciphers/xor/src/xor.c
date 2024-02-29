#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000


// Function to perform XOR encryption or decryption on the input string using the provided key
void xorEncryptDecrypt(char *input, char *key, int input_len) {
    int key_len = strlen(key);

    for (int i = 0; i < input_len; i++) {
        input[i] ^= key[i % key_len];
    }
}

// Function to encode the input string in base64 using an external command
void base64Encode(char *input, char *output, int input_len) {
    FILE *fp = popen("base64", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening pipe for base64 encoding.\n");
        return;
    }

    // Writing the input to the external command for base64 encoding
    fwrite(input, sizeof(char), input_len, fp);
    fflush(fp);
    pclose(fp);
}

// Function to decode the input string from base64 using an external command
void base64Decode(char *input, char *output, int output_len) {
    FILE *fp = popen("base64 -d", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening pipe for base64 decoding.\n");
        return;
    }

    // Writing the input to the external command for base64 decoding
    fwrite(input, sizeof(char), strlen(input), fp);
    fflush(fp);
    pclose(fp);
}

int main() {
    char choice;
    printf("Enter your choice (1 for encrypt, 2 for decrypt): \n ==>");
    scanf(" %c%*c", &choice);  // %*c to consume the newline character

    // Validate the user's choice
    if (choice == '1' || choice == '2') {
        char input[MAX_INPUT_SIZE];
        char key[MAX_INPUT_SIZE];

        // Get the input string from the user
        printf("Enter the string to %s: ", (choice == '1') ? "encrypt" : "decrypt");
        scanf(" %[^\n]%*c", input);  // %[^\n] to read until newline, %*c to consume the newline character

        // Get the XOR key from the user
        printf("Enter the XOR key: ");
        scanf(" %[^\n]%*c", key);  // %[^\n] to read until newline, %*c to consume the newline character

        // Calculate the length of the input string
        int input_len = strlen(input);

        // Perform base64 encoding if the choice is encryption
        if (choice == '1') {
            base64Encode(input, input, input_len);
        }

        // Perform XOR encryption or decryption based on user choice
        xorEncryptDecrypt(input, key, input_len);

        // Perform base64 decoding if the choice is decryption
        if (choice == '2') {
            base64Decode(input, input, input_len);
        }

        // Display the result
        printf("%s string: %s\n", (choice == '1') ? "Encrypted" : "Decrypted", input);
    } else {
        // Display an error message for an invalid choice
        printf("Invalid choice. Please enter '1' for encrypt or '2' for decrypt.\n");
    }

    return 0;
}
