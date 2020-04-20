// Solution1
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
    int idx = 0;
    int len;
    
    TreeNode* createSubTree(vector<int> &tempPreorder, int lower, int upper) {
        if(idx == len)
            return NULL;
        
        int value = tempPreorder[idx];
        
        if(value < lower || value > upper)
            return NULL;
        
        idx++;
        TreeNode *node = new TreeNode;
        node->val = value;
        node->left = createSubTree(tempPreorder, lower, value);
        node->right = createSubTree(tempPreorder, value, upper);
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        len = preorder.size();
        return createSubTree(preorder, INT_MIN, INT_MAX);
    }
};

//Solution2
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
    TreeNode* createBinaryTree(TreeNode* node, int &value) {
        if(node == NULL) {
            node = new TreeNode(value);
        }
        else if(value < node->val) {
            node->left = createBinaryTree(node->left, value);
        }
        else if(value > node->val) {
            node->right = createBinaryTree(node->right, value);
        }
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = createBinaryTree(root, preorder[0]);
        
        for(int i = 0; i < preorder.size(); i++) {
            root = createBinaryTree(root, preorder[i]);
        }
        
        return root;
    }
};
