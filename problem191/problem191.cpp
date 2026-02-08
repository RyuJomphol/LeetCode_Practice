#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // Step 1: Count bits in pairs (01, 10, 11 -> sum)
        // 0x55555555 is 01010101... in binary
        n = n - ((n >> 1) & 0x55555555);

        // Step 2: Count bits in nibbles (4 bits)
        // 0x33333333 is 00110011... in binary
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);

        // Step 3: Count bits in bytes (8 bits)
        // 0x0F0F0F0F is 00001111... in binary
        n = (n + (n >> 4)) & 0x0F0F0F0F;

        // Step 4: Sum the byte counts into the final result
        // Multiplying by 0x01010101 sums the bytes into the most significant byte
        // Then we shift right by 24 to get that sum.
        return (n * 0x01010101) >> 24;
    }
};