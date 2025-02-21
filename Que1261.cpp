// Find Elements in a Contaminated Binary Binary Tree

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
class FindElements {
    public:
        unordered_map<int,int> mp;
        void solve(TreeNode* root, int value)
        {
            if(root==NULL)
                return;
            root->val = value;
            mp[value]++;
            if(root->left)
            {
                solve(root->left,(2*value)+1);
            }
            if(root->right)
            {
                solve(root->right,(2*value)+2);
            }
        }
        FindElements(TreeNode* root)
        {
            root-> val = 0;
            mp[0]++;
            solve(root->left,1);
            solve(root->right,2);
        }
        
        bool find(int target) {
            if(mp.find(target)==mp.end())   
                return false;
            return true;
    
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */