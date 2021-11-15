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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, q);
        return result;
    }

    void dfs(TreeNode* node1,TreeNode* node2){
        /**
         * 这4个if好丑....
         **/
        if(node1 == NULL && node2 == NULL) return;
        if(node1 == NULL && node2 != NULL) result = false;
        if(node1 != NULL && node2 == NULL) result = false;
        if(node1 != NULL && node2 != NULL){
        if(node1->val != node2->val) result = false;
        dfs(node1->left,node2->left);
        dfs(node1->right,node2->right);
        }
    }
};