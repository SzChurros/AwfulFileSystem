#ifndef SHARED
#define SHARED

#include <cstdint>

#include <iostream>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
const int SECTOR_SIZE = 512;

struct blockdata
{
    uint16_t dat[256];
};

uint32_t imgSize(const char* imagePath)
{
    struct stat file_stat;
    if (stat(imagePath, &file_stat) == 0) {
        return (uint32_t)file_stat.st_size;
    } else {
        perror("Failed to get file size");
    }
}

blockdata readBlock(const char* imagePath, uint64_t sectorNumber)
{
    int fd = open(imagePath, O_RDONLY | O_LARGEFILE);
    if (fd == -1) {
        throw std::runtime_error("Cannot open image file");
    }

    off_t offset = lseek64(fd, sectorNumber * SECTOR_SIZE, SEEK_SET);
    if (offset == -1) {
        close(fd);
        throw std::runtime_error("Seek failed");
    }

    blockdata sector;
    ssize_t bytesRead = read(fd, sector.dat, SECTOR_SIZE);
    close(fd);

    if (bytesRead != SECTOR_SIZE) {
        throw std::runtime_error("Failed to read full sector");
    }

    return sector;
}

void writeBlock(const char* imagePath, blockdata data, uint64_t sectorNumber)
{
    int fd = open(imagePath, O_WRONLY | O_LARGEFILE);
    if (fd == -1) {
        throw std::runtime_error("Cannot open image file for writing");
    }

    off_t offset = lseek64(fd, sectorNumber * SECTOR_SIZE, SEEK_SET);
    if (offset == -1) {
        close(fd);
        throw std::runtime_error("Seek failed");
    }
    ssize_t bytesWritten = write(fd, data.dat, SECTOR_SIZE);
    close(fd);

    if (bytesWritten != SECTOR_SIZE) {
        throw std::runtime_error("Failed to write full sector");
    }
}

#endif