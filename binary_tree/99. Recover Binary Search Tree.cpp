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
 * 把反了的两个点记下来，再将值交换即可
 * */
class Solution {
public:
    TreeNode* re1;
    TreeNode* re2;
    TreeNode* pre;
    void recoverTree(TreeNode* root) {
        dfs(root);
        int temp = re1->val;
        re1->val = re2->val;
        re2->val = temp;

    }

    void dfs(TreeNode* node){
        if(node == NULL) return;
        dfs(node->left);
        //记录下来两个反的节点
        if(pre != NULL && pre->val > node->val){
            if(re1 == NULL) re1 = pre;
            re2 = node;
        }
        pre = node;
        dfs(node->right);
    }
};