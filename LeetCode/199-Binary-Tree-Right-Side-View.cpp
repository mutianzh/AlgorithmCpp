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
    void dfs(TreeNode* node, unordered_set<int>& visited, vector<int>& res, int l){ 
        if (node == nullptr) {return;}
        if (!visited.count(l)){
            res.push_back(node -> val);
            visited.insert(l);
        }
        dfs(node -> right, visited, res, l+1);
        dfs(node -> left, visited, res, l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        unordered_set<int> visited;
        vector<int> res;
        dfs(root, visited, res, 0);
        return res;
    }
};
