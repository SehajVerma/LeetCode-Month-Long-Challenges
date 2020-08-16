bool comp(const vector<int> &p1,const vector<int> &p2)
    {
        if(p1[0]==p2[0])
            return p1[1]<p2[1];
        else
            return p1[0]<p2[0];
    }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int c=0;
        if(intervals.size()==1 || intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(), comp);
        for(int i=0;i<intervals.size();i++)
        {
            for(int j=0;j<2;j++)
                cout<<intervals[i][j]<<" ";
            cout<<endl;
        }
        for(int i=0;i<intervals.size()-1;i++)
        {
               if(intervals[i][0]<intervals[i+1][1] && intervals[i][1]>intervals[i+1][0]){
                if(intervals[i][1]<intervals[i+1][1])
                intervals[i+1]=intervals[i];   
                c++;
               }
        }
         return c;
    }
};
