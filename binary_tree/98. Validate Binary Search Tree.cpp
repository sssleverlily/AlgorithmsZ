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
    //node->left->val < node->val
    //node->right->val > node->val 
    //依然还是中序递归
    bool result = true;
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return result;
    }

    void dfs(TreeNode* node){
        if (node == NULL) return;
        dfs(node->left);
        if(pre != NULL){
            if(node->val <= pre->val) result = false;
        }
        pre = node;
        dfs(node->right);
    }
};