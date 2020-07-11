class Solution {
    void solve(vector<int>&nums,vector<vector<int>>&result,int i)
    {
        if(i==nums.size()-1)
        {
            result.push_back({});
            result.push_back({nums[i]});
        }
        else
        {
           solve(nums,result,i+1);
            int n = result.size();
            for(int k=0;k<n;k++)
            {
               vector<int>r = result[k];
               r.push_back(nums[i]);
               result.push_back(r);
            } 
        }
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0)
            return {{}};
        vector<vector<int>>result;
        solve(nums,result,0);
        return result;
    }
};
