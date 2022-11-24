#ifndef CONVERTER_H
#define CONVERTER_H

#include "iomanip"

unsigned char * Image2CPP(char * path)
{
	// Convert image to C++ code
    // Open file


    FILE *file = fopen(path, "rb");

    // Get file size
    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read file

    unsigned char *buffer = new unsigned char[size];

    fread(buffer, 1, size, file);
    fclose(file);

    // limit image size to 128x64

    if (size > 8192)
    {
        return NULL;
    }

    // Print file

    // make list variable

    unsigned char loop_list[8192] = {};


    for (int i = 0; i < size; i++)
    {
        // add byte to list
        loop_list[i] = buffer[i];
    }

    return loop_list;
}

#endif