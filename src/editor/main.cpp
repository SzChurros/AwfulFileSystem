#include <stdio.h>
#include <cstring>

#include "help.h"
#include "metadata.h"

int main(int argc, char *argv[])
{
    if (argc == 1 || argc > 3)
    {
        printf("please do afsedit --help\n");
        return 1;
    }
    
    if (argc > 2)
    {
        if (strcmp(argv[2], "--help") == 0)
        {
            help();
            return 0;
        }
        if (strcmp(argv[2], "--meta") == 0)
        {
            metadata(argv[1]);
        }
        if (strcmp(argv[1], "--help") == 0)
        {
            help();
            return 0;
        }
        if (strcmp(argv[1], "--meta") == 0)
        {
            metadata(argv[2]);
            return 0;
        }
    }
    if (strcmp(argv[1], "--help") == 0)
    {
        help();
        return 0;
    }
    if (strcmp(argv[1], "--meta") == 0)
    {
        printf("no file to edit\n");
        return -1;
    }
    printf("please do afsedit --help\n");

    return 0;
}