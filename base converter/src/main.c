#include <stdio.h>
#include "convert_file_base.c"

int main()
{
    char num[100];
    int from_base, to_base;

    printf("Enter a number: ");
    scanf("%s", num);

    printf("Enter the base of the number: ");
    scanf("%d", &from_base);

    printf("Select the base to convert to:\n");
    printf("1. Binary\n");
    printf("2. Octal\n");
    printf("3. Decimal\n");
    printf("4. Hexadecimal\n");
    printf("Enter your choice: ");

    scanf("%d", &to_base);

    switch(to_base) {
        case 1:
            to_base = 2;
            break;
        case 2:
            to_base = 8;
            break;
        case 3:
            to_base = 10;
            break;
        case 4:
            to_base = 16;
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    char *converted_num = convert_base(num, from_base, to_base);
    if (converted_num) {
        printf("Converted number: %s\n", converted_num);
    } else {
        printf("Invalid number or base\n");
    }
    return 0;
}
