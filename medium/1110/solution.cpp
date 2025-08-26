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

    TreeNode* dfs(TreeNode* node, bool is_root, set<int> &set_delete, vector<TreeNode*> &ret){
        
        // end of the tree (child of leaf)
        if (node == nullptr){
            return nullptr;
        }

        // find if node->val is to be deleted
        bool will_delete = set_delete.contains(node->val);

        // if node is root and it wont be deleted, we need to add
        // it to the answer (collection of tree roots -- forest)
        if (is_root && !will_delete){
            ret.push_back(node);
        }

        // recursion here
        // (if this node will get deleted, children are potentially roots
        // --> thus using will_dete as is_root)
        node->left = dfs(node->left, will_delete,set_delete,ret);
        node->right = dfs(node->right, will_delete,set_delete,ret);

        // nullptr denotes "cut me from my parent" (hence setting node->left and 
        // node->right to return value in lines above)
        // node denotes "I am part of some tree (If I was root, I'd be added to ret
        // in the if clause above)"
        return (will_delete ? nullptr : node);
        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        vector<TreeNode*> ret;
        
        // early bail -- delete nothing
        if (to_delete.empty()){
            ret.push_back(root);
            return ret;
        }

        // for O(log k) checks (will be done every dfs call)
        // unordered map for O(1)
        set<int> set_delete (to_delete.begin(),to_delete.end());

        dfs(root,true,set_delete,ret);
    
        return ret;
            
    }
};
