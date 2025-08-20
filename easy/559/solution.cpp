/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {


    //BFS incremental approach
        
    //early bail out
    if (root == nullptr){
        return 0;
    }
        
    queue<Node*> q;
    q.push(root);
    unsigned int currLevel = 0;
    unsigned int currLevelSize = 0;

    while (!q.empty()){
        
        currLevel++;
        currLevelSize = q.size();
        
        //push children of all current level nodes
        for(int i = 0; i < currLevelSize; i++){
            auto currNode = q.front();
            q.pop();
            auto &ch = currNode->children;
        
            for (auto &node : ch){
                if (node != nullptr){
                    q.push(node);
                }
            }
        }
    }
    return currLevel;
    }
};
