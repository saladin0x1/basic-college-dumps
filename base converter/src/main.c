#include <stdio.h>
#include <string.h>
#include<math.h>
#include "convert_base_file.c"
int main()
{
    char repeat = 'y';
    while (repeat == 'y') {
        char num[100];
        int from_base,to_base;

        printf("Enter a number: ");
        scanf("%s", num);


        printf("Enter the base of the number: ");
        scanf("%d", &from_base);

        const char* from_base_string = "";
        switch(from_base) {
            case 2:
                from_base_string = "binary";
                break;
            case 8:
                from_base_string = "octal";
                break;
            case 10:
                from_base_string = "decimal";
                break;
            case 16:
                from_base_string = "hexdecimal" ;
                break;
            default:
                printf("Invalid choice\n");
                return 0;
        }

        printf("Select the base to convert to:\n");
        printf("1. Binary\n");
        printf("2. Octal\n");
        printf("3. Decimal\n");
        printf("4. Hexadecimal\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &to_base);

        const char* to_base_string = "";
        switch(to_base) {
            case 1:
                to_base = 2;
                to_base_string = "binary";
                break;
            case 2:
                to_base = 8;
                to_base_string = "octal";
                break;
            case 3:
                to_base = 10;
                to_base_string = "decimal";
                break;
            case 4:
                to_base = 16;
                to_base_string = "hexdecimal" ;
                break;
            case 5:
                printf("Program terminated\n");
                return 0;
            default:
                printf("Invalid choice\n");
                return 0;
        }
        char *converted_num = convert_base(num, from_base, to_base);
        if (converted_num) 
        {
        printf("-----------------------\n");
        printf("\
            |From the {%s} base.|\n\
            |Converted to the {%s} base.|\n\
            |The Converted number is :{%s}|\n"
            ,from_base_string,to_base_string,converted_num);
        printf("-----------------------\n");

        } else {
            printf("Invalid number or base\n");
        }

        printf("Would you like to repeat the program? (y/n) ");
        scanf(" %c", &repeat);
       if (repeat == 'n')
    {
        printf("goodbye");
        return 0;
    }
        
    }
    return 0;
}
    
