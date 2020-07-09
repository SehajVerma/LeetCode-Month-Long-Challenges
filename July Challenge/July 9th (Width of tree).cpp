class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int w=0;
        while(!q.empty())
        {
            int n = q.size();
            int a = q.front().second;
            int b = q.back().second;
            int idx;
             w = max(w,b-a+1);
            for(int i=0;i<n;i++)
            {
                auto p = q.front().first;
                idx = q.front().second-a;
                q.pop();
                if(p->left)  q.push({p->left,2*idx+1});
                if(p->right) q.push({p->right,2*idx+2});
            }
           
        }
        return w;
    }
};
