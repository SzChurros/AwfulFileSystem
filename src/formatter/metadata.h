#ifndef META
#define META

#include <iomanip>
#include <stdio.h>
#include <iostream>

#include "shared.h"

void metadata(const char* img)
{
    blockdata metadata = readBlock(img, 0);

    for (int i = 0; i < 256; i++)
    {
        uint8_t byte0 = metadata.dat[i] & 0xFF;
        uint8_t byte1 = (metadata.dat[i] >> 8) & 0xFF;

        std::cout << std::setw(2) << std::setfill('0') << std::hex 
                  << (int)byte0 << ' ';
        std::cout << std::setw(2) << std::setfill('0') << std::hex 
                  << (int)byte1 << ' ';
        
        if ((i + 1) % 16 == 0)
        {
            std::cout << "  ";
            for (int j = i - 15; j <= i; j++)
            {
                char c0 = metadata.dat[j] & 0xFF;
                char c1 = (metadata.dat[j] >> 8) & 0xFF; 
                std::cout << (std::isprint(c0) ? c0 : '.');
                std::cout << (std::isprint(c1) ? c1 : '.');
            }
            std::cout << std::endl;
        }
    }

    printf("Continue? [y/n]: ");
    char cont = 0;
    scanf("%c", &cont);
    
}

#endif