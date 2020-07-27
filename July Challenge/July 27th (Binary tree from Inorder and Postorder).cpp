/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 O(N) solution ---if map used
 O(N*N) --------if for or while loop used
class Solution {
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int *k,int start,int end,unordered_map<int,int>&m)
    {
        if(start>end)
            return NULL;
        
        int num = postorder[*k];
        TreeNode *root = new TreeNode(num);
        (*k)--;
        if(start==end)
            return root;
        // int j=inorder.size()-1;
        // while(inorder[j]!=root->val)
        //     j--;
        
        int j = m[num]; //Map approach
        
        root->right = solve(inorder,postorder,k,j+1,end,m);
        root->left = solve(inorder,postorder,k,start,j-1,m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size()-1;
        unordered_map<int,int>m;
        for(int i=0;i<=n;i++)
            m[inorder[i]]=i;
        return solve(inorder,postorder,&n,0,n,m);
    }
};
