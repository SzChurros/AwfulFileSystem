#ifndef META
#define META

#include <iomanip>
#include <stdio.h>
#include <iostream>

#include "shared.h"

void metadata(const char* img)
{
    blockdata metadata = readBlock(img, 0);
    
    printf("existing metadata: \n\n");

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

    uint16_t startaddrhi = metadata.dat[48];
    uint16_t startaddrlo = metadata.dat[49];

    uint32_t startaddr = (startaddrlo << 16) | startaddrhi;

    uint16_t sihi = metadata.dat[50];
    uint16_t silo = metadata.dat[51];

    uint32_t si = (silo << 16) | sihi;

    printf("\nData Start Block Addr: %i\n", startaddr);
    printf("Size: %i (sectors)\n", si);

    printf("Continue? [y/n]: ");
    char cont = 0;
    scanf("%c", &cont);

    if (cont != 'y')
        return;
    const char* statictext = "awfulfilesystemmadeforszczosspecificallypleasedontuseitanywhereelse\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

    for (int i = 0; i < 256; i++)
    {
        metadata.dat[i] = 0;
    }

    for (int i = 0; i < 48; i++)
    {
        uint16_t word = (statictext[i * 2 + 1] << 8) | statictext[i * 2]; 

        metadata.dat[i] = word;
    }

    uint32_t fatSize = 8192;
    uint32_t imgsize = imgSize(img) / 512;

    uint16_t w0 = fatSize & 0xFFFF;
    uint16_t w1 = (fatSize >> 16) & 0xFFFF;

    metadata.dat[48] = w0;
    metadata.dat[49] = w1;

    w0 = imgsize & 0xFFFF;
    w1 = (imgsize >> 16) & 0xFFFF;

    metadata.dat[50] = w0;
    metadata.dat[51] = w1;

    writeBlock(img, metadata, 0);

    blockdata dat;

    for (int i = 0; i < 256; i++)
    {
        dat.dat[i] = 0;
    }

    for (int i = 0; i < imgSize; i++)
    {
        writeBlock(img, dat, i);
    }
}

#endif