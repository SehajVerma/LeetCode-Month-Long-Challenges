class Solution {
public:
    unsigned int hammingDistance(int x, int y) {
        int z = x^y;
        unsigned int count = 0; 
        while (z) { 
            count += z & 1; 
            z >>= 1; 
        } 
        return count;
    }
};
