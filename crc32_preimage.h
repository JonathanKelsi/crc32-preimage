#ifndef CRC32_PREIMAGE_H
#define CRC32_PREIMAGE_H

#include <stdint.h>
#include <stddef.h>

/*
 * Initialize CRC32 tables.
 *
 * This must be called before using crc32() or crc32_preimage().
 */
void crc32_init(void);

/*
 * Compute standard CRC-32 (IEEE).
 *
 * Polynomial: 0xEDB88320.
 */
uint32_t crc32(uint32_t crc, const void *buf, size_t len);

/*
 * Recover a 4-byte message whose CRC32 equals desired_crc.
 */
void crc32_preimage(uint32_t desired_crc, uint8_t out[4]);

#endif /* CRC32_PREIMAGE_H */
