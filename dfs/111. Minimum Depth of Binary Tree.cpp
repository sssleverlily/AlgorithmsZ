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
 /**
 注意如果根节点的左或右子树为空的话是构不成子树的。而最小深度是要求从根节点到子树的。当左或右子树为空时，不符合要求。
 **/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return dfs(root);
    }

    int dfs(TreeNode* node){
        if(node == nullptr) return 0;
        // null节点不参与比较
        if (node->left == nullptr && node->right != nullptr) {
            return 1 + dfs(node->right);
        }
        // null节点不参与比较
        if (node->right == nullptr && node->left != nullptr) {
            return 1 + dfs(node->left);
        }
        return 1 + min(dfs(node->left), dfs(node->right));
       
    }
};