// Recover a tree form preoder traveral

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            unordered_map<int, TreeNode*> levelToCurrNodeMap;
            int ptr = 0;
            while (ptr < traversal.size()) {
                int curr_level = 0;
                while (ptr < traversal.size() && traversal[ptr] == '-') {
                    curr_level++;
                    ptr++;
                }
    
                int curr_value = 0;
                while (ptr < traversal.size() && traversal[ptr] >= '0' &&
                       traversal[ptr] <= '9')
                {
                    curr_value = curr_value * 10 + traversal[ptr] - '0';
                    ptr++;
                }
    
                TreeNode* currnode = new TreeNode(curr_value);
                levelToCurrNodeMap[curr_level] = currnode;
                if (curr_level > 0) {
                    TreeNode* parent = levelToCurrNodeMap[curr_level - 1];
                    if (!parent->left)
                        parent->left = currnode;
                    else if (!parent->right)
                        parent->right = currnode;
                    else
                        throw("Something when Wrong");
                }
            }
            return levelToCurrNodeMap[0];
        }
    };