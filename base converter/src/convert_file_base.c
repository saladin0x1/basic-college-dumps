#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* convert_base(char* num, int from_base, int to_base) {
    // error checking for invalid base
    if (from_base < 2 || from_base > 16 || to_base < 2 || to_base > 16) {
        return NULL;
    }

    int decimal_num = 0, i, j, len = 0;
    for (i = 0; num[i] != '\0'; i++) {
        len++;
    }
    // convert from from_base to decimal
    for (i = 0, j = len - 1; i < len; i++, j--) {
        if (num[i] >= '0' && num[i] <= '9') {
            decimal_num += (num[i] - '0') * pow(from_base, j);
        } else if (num[i] >= 'A' && num[i] <= 'F') {
            decimal_num += (num[i] - 'A' + 10) * pow(from_base, j);
        } else {
            return NULL;
        }
    }

    // convert decimal to to_base
    int quotient = decimal_num, remainder, temp = 0;
    char* converted_num = (char*)malloc(sizeof(char) * len);
    while (quotient != 0) {
        remainder = quotient % to_base;
        if (remainder < 10) {
            converted_num[temp++] = remainder + '0';
        } else {
            converted_num[temp++] = remainder - 10 + 'A';
        }
        quotient /= to_base;
    }
    converted_num[temp] = '\0';

    // reverse the converted_num string
    for (i = 0, j = temp - 1; i < j; i++, j--) {
        char temp = converted_num[i];
        converted_num[i] = converted_num[j];
        converted_num[j] = temp;
    }
    return converted_num;
}
