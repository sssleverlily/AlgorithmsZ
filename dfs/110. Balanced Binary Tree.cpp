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
    bool result = true;
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return result;
        result = abs(dfs(root->left)-dfs(root->right))<=1&&isBalanced(root->left)&&isBalanced(root->right);
        //左边是平衡，右边是平衡，左右只差小于1
        return result;
    }

    int dfs(TreeNode* node){
        if(node == nullptr) return 0;
        return max(dfs(node->left),dfs(node->right))+1;
    }
};