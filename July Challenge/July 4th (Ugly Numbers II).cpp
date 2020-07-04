#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int multipleof_2=2;
    int multipleof_3=3;
    int multipleof_5=5;
    int dp[n+1];
    int i2=1;
    int i3=1;
    int i5=1;
    dp[0]=0;
    dp[1]=1;
    int next_multiple=0;
    for(int i=2;i<=n;i++)
    {
        next_multiple=min(multipleof_2,min(multipleof_3,multipleof_5));
        dp[i]=next_multiple;
        if(next_multiple==multipleof_2)
        {
            i2++;
            multipleof_2=2*dp[i2];
        }
         if(next_multiple==multipleof_3)
        {
            i3++;
            multipleof_3=3*dp[i3];
        }
         if(next_multiple==multipleof_5)
        {
            i5++;
            multipleof_5=5*dp[i5];
        }
    }
    cout<<dp[n];
}
