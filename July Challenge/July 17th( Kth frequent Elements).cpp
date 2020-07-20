class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:m)
        {
           pq.push({it.second,it.first}); 
        }
        while(k--)
        {
            auto i = pq.top();
            v.push_back(i.second);
            pq.pop();
        }
        return v;
    }
};
