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
    vector<vector<int>> result;
    vector<int> rere;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // if(root == NULL) return [];
        dfs(root,targetSum);
        return result;
    }
    
    void dfs(TreeNode* node, int targetSum){ 
        if(node == NULL) return;
        rere.push_back(node->val);
        if(node->left == NULL&&node->right == NULL){
            if(targetSum-node->val == 0) result.push_back(rere);//如果满足，就加进去
        }
        dfs(node->left,targetSum-node->val);
        dfs(node->right,targetSum-node->val);
        rere.pop_back(); //这里疑问，为什么要pop一次？
    }
};