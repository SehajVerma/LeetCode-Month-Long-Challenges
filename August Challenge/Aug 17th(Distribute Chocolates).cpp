class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>a(num_people,0);
        int c=1;
        int dp=0;
        int i=0;
        while(dp<candies)
        {
            if(candies-dp<c)
            c=candies-dp;
            a[i]+=c;
            dp+=c;
            c++;
            i++;
            i=i%num_people;
        }
        return a;
    }
};
