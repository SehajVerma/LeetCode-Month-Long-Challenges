class Solution {
    map<int,set<pair<int,int>>>m;
    void solve(TreeNode* root,int h,int x)
    {
        if(root==NULL) return;
        m[x].insert({h,root->val});
        solve(root->left,h+1,x-1);
        solve(root->right,h+1,x+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>>v;
        for(auto i : m)
        {
            vector<int>temp;
            for(auto j:i.second)
            {
                temp.push_back(j.second);
            }
            v.push_back(temp);
        }
        return v;
    }
};
