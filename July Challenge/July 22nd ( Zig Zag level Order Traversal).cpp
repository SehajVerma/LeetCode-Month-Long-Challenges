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
class Solution {
    vector<vector<int>> solve(TreeNode *root,vector<vector<int>>v)
    {
        stack<TreeNode*>s1;
        s1.push(root);
        while(!s1.empty())
        {
           int n = s1.size();
           stack<TreeNode*>s2;
           vector<int>temp;
           for(int i=0;i<n;i++)
           {
               TreeNode* p = s1.top();
               temp.push_back(p->val);
               s1.pop();
               if(p->left)  s2.push(p->left);
               if(p->right) s2.push(p->right);
           }
            v.push_back(temp);
           int n2 = s2.size();
            vector<int>temp2;
           for(int i=0;i<n2;i++)
           {
               TreeNode* p = s2.top();
               temp2.push_back(p->val);
               s2.pop();
               if(p->right) s1.push(p->right);
               if(p->left)  s1.push(p->left);
               
           }
            if(temp2.size()!=0)
            v.push_back(temp2);
        }
        return v;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>v;
        if(root==NULL)
            return v;
        return solve(root,v);  
    }
};

//Easy Code

class Solution {
public:
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
        return vector<vector<int> > ();
    }
    vector<vector<int> > result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
};

//More Sample Codes

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        while(!q.empty()){
            height++;
            int cnt = q.size();
            vector<int> cur;
            while(cnt--){
                auto r = q.front();
                q.pop();
                if(r->left) q.push(r->left);
                if(r->right) q.push(r->right);
                cur.push_back(r->val);
            }
            if(height % 2 == 0) reverse(cur.begin(), cur.end());
            ans.push_back(cur);
        }
        return ans;
    }
};

