#include "crc32_preimage.h"

static uint32_t crc_table[256];
static uint8_t crc_revtable[256];

void crc32_init(void)
{
    const uint32_t poly = 0xEDB88320;

    for (int i = 0; i < 256; i++) {
        uint32_t crc = i;
        for (int j = 0; j < 8; j++) {
            crc = (crc >> 1) ^ (crc & 1 ? poly : 0);
        }
        crc_table[i] = crc;
    }

    for (int i = 0; i < 256; i++) {
        crc_revtable[crc_table[i] >> 24] = (uint8_t)i;
    }
}

uint32_t crc32(uint32_t crc, const void *buf, size_t len)
{
    const uint8_t *p = buf;

    crc = ~crc;
    while (len--) {
        crc = crc_table[(crc ^ *p++) & 0xff] ^ (crc >> 8);
    }
    return ~crc;
}

void crc32_preimage(uint32_t desired_crc, uint8_t out[4])
{
    uint32_t state = ~desired_crc;
    uint8_t idx[4];

    for (int i = 3; i >= 0; i--) {
        idx[i] = crc_revtable[state >> 24];
        state = (state ^ crc_table[idx[i]]) << 8;
    }

    uint32_t crc = ~0;
    for (int i = 0; i < 4; i++) {
        out[i] = (uint8_t)(idx[i] ^ crc);
        crc = (crc >> 8) ^ crc_table[idx[i]];
    }
}
