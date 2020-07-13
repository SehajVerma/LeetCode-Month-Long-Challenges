class Solution {
    bool solve(TreeNode* p, TreeNode* q)
    {
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        if(p->val == q->val){
            bool b1 = solve(p->left,q->left);
            bool b2 = solve(p->right,q->right);
            if(b1==b2 && b1==true)
            return true;
            else
            return false;
        }
        else
            return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
