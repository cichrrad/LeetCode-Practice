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


#include <queue>
//BFS is probably the best approach
//because we are gonna return as
//soon as we find a node with nullptr
//children, while going through the tree
//layers 
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        //no tree to talk about
        if (root == nullptr) {
            return 0;  
        }
        
        //Q to store node,tree level pairs
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        //until we have nodes to process
        //early exit on first leaf
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            // leaf => we cooking
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }
            
            // no leaf => fetch another layer
            if (node->left != nullptr) {
                q.push({node->left, depth + 1});
            }
            if (node->right != nullptr) {
                q.push({node->right, depth + 1});
            }
        }
        
        return -1; //something horrible
    }
};

