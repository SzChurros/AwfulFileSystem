#include <stdio.h>
#include <cstring>

#include "help.h"
#include "metadata.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("please do mkfs.szczafs --help\n");
        return 1;
    }
    if (strcmp(argv[1], "--help") == 0)
    {
        help();
        return 0;
    }

    metadata(argv[1]);

    return 0;
}