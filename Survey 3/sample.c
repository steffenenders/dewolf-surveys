#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert_binary_to_hex()
{
    long long binary;
    char hex[65] = "";
    int rem;
    printf("Enter any binary number: ");
    scanf("%lld", &binary);
    int original_binary = binary;
    while(binary > 0)
    {
        rem = binary % 10000;
        switch(rem)
        {
            case 0:
                strcat(hex, "0");
                break;
            case 1:
                strcat(hex, "1");
                break;
            case 10:
                strcat(hex, "2");
                break;
            case 11:
                strcat(hex, "3");
                break;
            case 100:
                strcat(hex, "4");
                break;
            case 101:
                strcat(hex, "5");
                break;
            case 110:
                strcat(hex, "6");
                break;
            case 111:
                strcat(hex, "7");
                break;
            case 1000:
                strcat(hex, "8");
                break;
            case 1001:
                strcat(hex, "9");
                break;
            case 1010:
                strcat(hex, "A");
                break;
            case 1011:
                strcat(hex, "B");
                break;
            case 1100:
                strcat(hex, "C");
                break;
            case 1101:
                strcat(hex, "D");
                break;
            case 1110:
                strcat(hex, "E");
                break;
            case 1111:
                strcat(hex, "F");
            break;
        }
        binary /= 10000;
    }
    printf("Binary number: %lld\n", original_binary);
    printf("Hexadecimal number: %s", hex);
    return 0;
}

int main()
{
	convert_binary_to_hex();
}
