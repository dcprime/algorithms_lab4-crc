/******************* lab4_main.c ************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "crc.h"

/******************** constants *********************/
#define CRC_LENTH 5
#define HEX_PREFIX 2

void main(int argc, char *argv[])
{
    char buffer[] = { "123456789" };        // message to run crc on
    int bufferLen;                          // stores length of buffer in bytes
    int i;                                  // counter for loop
    crc crc_value;                          // value of calculated CRC
    char crc_hex[HEX_PREFIX + CRC_LENTH];   // crc value to be converted to hex as a string
    char *bufferWithCRC;                    // char array to store buffer with CRC 

    // calculate length of buffer in bytes
    bufferLen = strlen(buffer) + HEX_PREFIX + CRC_LENTH;

    // create char array to store contents of buffer and calculated CRC
    bufferWithCRC = (unsigned char *)malloc(bufferLen * sizeof(unsigned char));
    
    for (i = 0; i < sizeof(buffer); i++) 
    {
        // 1. generate crc for the buffer
        crc_value = crcSlow(buffer, bufferLen);

        // 2. convert crc to string showing hex value
        sprintf_s(crc_hex, (HEX_PREFIX + CRC_LENTH), "0x%X", crc_value);

        // 3. append crc_hex to buffer
        strcpy(bufferWithCRC, buffer);
        strcat(bufferWithCRC, crc_hex);

        // 4. print buffer with hex crc at end
        printf("%s\n\n", bufferWithCRC);

        // 5. modify buffer by changing index i character to 0
        buffer[i] = '0';
    }
        
    printf("Done");
}