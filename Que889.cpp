// Construct binary tree from preorder and postorder traversal

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
    public:
    
        TreeNode* solve(TreeNode *node, int m, int n, bool l){
    
    
            if(node == NULL){
                return node;
            }
    
            bool run = false;
            if(node->val == m && node->left == NULL && l){
                run = true;
                node->left = new TreeNode(n);
            }
            else if(node->val == m && node->right == NULL){
                run = true;
                node->right = new TreeNode(n);
            } 
    
    
    
            if(!run){
                node->left = solve(node->left, m, n, l);
                node->right = solve(node->right, m, n, l);
            }
    
            return node;
        }
    
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    
            TreeNode* head = new TreeNode(preorder[0]);
            vector<bool> v(preorder.size()+1,false);
            v[preorder[0]] = true;
            int node = preorder[0];
    
            for(int i = 1; i < preorder.size(); i++){
                if(v[preorder[i]]){
                    node = preorder[i];
                    continue;
                }
                head = solve(head,node,preorder[i],true);
                v[preorder[i]] = true;
    
                // return head;
                //finding post
                int id;
                for(int j = postorder.size()-1; j >= 0; j--){
                    if(postorder[j] == node){
                        id = j-1;
                        break;
                    }
                }
    
                if(id >= 0 && !v[postorder[id]]){
                    head = solve(head,node,postorder[id],false);
                    v[postorder[id]] = true;
                }
                
                node = preorder[i];
            }
    
    
            return head;
        }
    };