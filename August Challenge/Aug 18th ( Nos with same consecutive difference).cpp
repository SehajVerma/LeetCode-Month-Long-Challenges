class Solution {
public:
    void dfs(int n,int k,int curr,int i,int no,vector<int>&v)
    {
        if(i==n-1){
            v.push_back(no);
            return;
        }
        
        int next = curr+k;
        if(next<10)
            dfs(n,k,next,i+1,no*10+next,v);
        
        next = curr-k;
        if(k!=0 && next>=0)
            dfs(n,k,next,i+1,no*10+next,v);
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int>v;
        if(N==1)
            return {0,1,2,3,4,5,6,7,8,9};
        for(int i=1;i<10;i++)
        {
            dfs(N,K,i,0,i,v);
        }
        return v;
    }
};
