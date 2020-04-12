/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // pair<diameter, height>
    pair<int,int> dfs(TreeNode* node){
        if(node == NULL)
            return {0, 0};
        
        pair<int,int> left = dfs(node->left);
        pair<int,int> right = dfs(node->right);
        
        int diam = max(max(left.first, right.first) , left.second + right.second);
        return {diam, max(left.second, right.second) + 1};
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }
};
