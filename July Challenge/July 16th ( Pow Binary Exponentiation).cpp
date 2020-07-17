In all recursive functions 
Space O(logn) 
Time O(logn)

class Solution {

   //Simple recursive func
    double mypow(double x,long n)
    {
        if(n==0) return 1;
        if(n==1) return x;
        if(n<0) return mypow(1/x,-n);
        
        double result = mypow(x,n/2);
        if(n%2==0) return result*result;
        else return  result*result*x;
    }
    
    //Binary exponentiation
    double mypow(double x,long n)
    {
        if(n==1) return x;
        if(n==0) return 1.0;
        if(n<0) return mypow(1/x,-n);
        double result = mypow(x*x,n/2);
        if(n%2)   result *= x;
        return result;
    }
    
    //Bitmasking 0(1) space and 0(logn) time
    double mypow(double x,long n)
    {
        if(n<0)
            return mypow(1/x,-n);
        double res=1.0;
        while(n)
        {
          if(n&1){
            res *= x;
          }
          x*=x;
          n = n>>1;
        }
        return res;
    }
public:
    double myPow(double x, int n) {
       return mypow(x,n);    
  }
};
