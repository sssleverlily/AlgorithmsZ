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
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }
    //这个是递归的 还有非递归的
    void dfs(TreeNode* node){
        if(node == NULL) return;
        dfs(node->left);
        result.push_back(node->val);
        dfs(node->right);
    }
};

/**
 * 前序： 中左右
 * 中序： 左中右
 * 后续： 左右中
 ** /