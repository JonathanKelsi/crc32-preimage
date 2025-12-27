# crc32-preimage

A minimal **CRC32 preimage generator** for 4-byte messages.

Given a desired CRC32 value, this code reconstructs **one valid 4-byte input**
whose CRC32 (IEEE) equals that value. This is done by inverting the CRC32 state
transition using a reverse lookup table — no brute force.

This is mainly useful for CTF challenges.

## CRC Variant

This implementation assumes **standard CRC-32 (IEEE)** (`0xEDB88320` Polynomial).

If you are using a different CRC variant, this code will not work as-is.

## Files

- `crc32_preimage.c` — implementation
- `crc32_preimage.h` — public API
- `example.c` — minimal usage example

## License

MIT
