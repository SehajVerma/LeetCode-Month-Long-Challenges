class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i=0;i<nums.size();i++)
        {
            xorr=xorr^nums[i];
        }
        int mask=xorr&(-xorr);    // yaad rakho if rightmost set bit chaiye toh yeh use kro
        int num1=0;
        int num2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mask&nums[i])
                num1=num1^nums[i];
            else
                num2=num2^nums[i];
        }
        vector<int>v;
        v.push_back(num1);
        v.push_back(num2);
        return v;
    }
};
