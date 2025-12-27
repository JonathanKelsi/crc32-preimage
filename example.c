#include <stdio.h>
#include <stdint.h>
#include "crc32_preimage.h"

int main(void)
{
    uint32_t target_crc = 0xDEADBEEF;
    uint8_t msg[4];

    crc32_init();
    crc32_preimage(target_crc, msg);

    printf("Recovered bytes: %02x %02x %02x %02x\n",
           msg[0], msg[1], msg[2], msg[3]);

    uint32_t check = crc32(0, msg, 4);
    printf("CRC32 check: 0x%08x\n", check);

    return 0;
}
