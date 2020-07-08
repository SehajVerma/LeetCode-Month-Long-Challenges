Question - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3384/
Explanation - https://www.youtube.com/watch?v=Ca7k53qcTic

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>temp;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int t = -nums[i];
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int sum = nums[j]+nums[k];
                if(sum==t)
                {
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    temp.push_back(v);
                    j++;
                    k--;
                    while(j<n-1 && nums[j]==nums[j-1])
                    j++;
                    while(k>2 && nums[k]==nums[k+1])
                    k--;
                }
                else if(sum<t)
                    j++;
                else
                    k--;
            }
        }
        return temp;
    }
};
