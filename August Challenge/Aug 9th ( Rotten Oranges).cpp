class Solution {
public:
    int issafe(int x,int y,vector<vector<int>>& grid)
    {
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int min=0;
        while(!q.empty())
        {
          queue<pair<int,int>>q1;
          min++;
          while(!q.empty())
         {
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            for(int k=0;k<4;k++)
            {
                int x = i+dx[k];
                int y = j+dy[k];
                if(issafe(x,y,grid))
                {
                    grid[x][y]=2;
                    q1.push({x,y});
                }
            }
         } 
         q=q1;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return  min > 0 ? min-1 : min;
    }
};
