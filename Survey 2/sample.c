#include <stdio.h>
#include <windows.h>
#include <minwinbase.h>

#define WIN32_LEAN_AND_MEAN
#define DOMAIN_LENGTH 8


char* dga()
{
    unsigned char* domain;
    char seed;

    domain = malloc(sizeof(SYSTEMTIME));
    seed = (char)GetTickCount();
    GetSystemTime((LPSYSTEMTIME)domain);

    for(char i = 0; i < DOMAIN_LENGTH; i++)
    {
        domain[i] = ((unsigned char)(domain[i] ^ seed) % 24) + 97; // no Z's
    }
    int* end = domain + DOMAIN_LENGTH;
    end[0] = '\x2e\x63\x6f\x6d'; // .com
    end[1] = 0;

    switch(seed % 8){
        case 7:
        case 5:
            end[0] ^= '\x00\x11\x1a\x6d'; // .ru
            break;
        case 1:
        case 6:
            end[0] ^= '\x00\x17\x00\x6d'; // .to
            break;
        case 2:
            end[0] ^= '\x00\x0d\x0a\x19'; // .net
            break;
        default:
            break;
    }
    return domain;
}


int main(int argc, char** argv)
{
    char* domain;

    for(int i = 0; i < 30; i++)
    {
        domain = dga();
        printf("%s\n", domain);
        free(domain);
        Sleep(1);
    }

    return 0;
}
