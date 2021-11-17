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
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root, 0);
        return result;
    }

    void bfs(TreeNode* node, int depth){
        if(node == nullptr) return;
        if(depth >= result.size()){
            result.push_back(vector<int> {});//深度>result的大小，就说明第一次来，那么就扩容，增加一个list
        }
        result[depth].push_back(node->val);
        bfs(node->left, depth+1);
        bfs(node->right, depth+1);
    }
};