#include <iostream>
#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Swap adjacent 16-bit blocks
        n = (n >> 16) | (n << 16);
        
        // Swap adjacent 8-bit blocks
        // Mask 0xFF00FF00 selects the even bytes, 0x00FF00FF selects odd
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        
        // Swap adjacent 4-bit blocks (nibbles)
        // Mask 0xF0F0F0F0 and 0x0F0F0F0F
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        
        // Swap adjacent 2-bit blocks
        // Mask 0xCCCCCCCC and 0x33333333
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        
        // Swap adjacent 1-bit blocks
        // Mask 0xAAAAAAAA and 0x55555555
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
        
        return n;
    }
};