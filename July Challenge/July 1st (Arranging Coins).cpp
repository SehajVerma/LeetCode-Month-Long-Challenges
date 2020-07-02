https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins( int n) {
        
        
           /*1+2+3+.......+k = k*(k+1)/2;
            if N=6 
                we have 
                    1       (1)
                    1 1     (2)
                    1 1 1   (3)
        i.e 1+2+3 = 6 
                therefore 
                    k*(k+1)/2 <= N
                    k^2 + k -2*N <= 0 
                So find roots of K */
                
          return (sqrt(1+8l*n)-1)/2;
        
    }
};
