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
// class Solution {
// public:
//     vector<vector<int>> result;
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         bfs(root, 0, 1);
//         return result;
//     }

//     void bfs(TreeNode* node, int depth,int isleft){
//         if(node == nullptr) return;
//         if(depth >= result.size()){
//             result.push_back(vector<int> {});//深度>result的大小，就说明第一次来，那么就扩容，增加一个list
//         }
//         if(isleft == 1){
//             bfs(node->right, depth+1, (-1)*isleft);
//             result[depth].push_back(node->val);
//             bfs(node->left, depth+1, (-1)*isleft);
//         }else if (isleft == -1){
//             bfs(node->left, depth+1, (-1)*isleft);
//             result[depth].push_back(node->val);
//             bfs(node->right, depth+1, (-1)*isleft);
//         }         
//     }
// };
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
 还是广度遍历，结果反转就行了
 **/
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bfs(root, 0);
         for(int i=1;i<result.size();i+=2){
            reverse(result[i].begin(),result[i].end()); //结果反转就行了
        }
        return result;
    }

    void bfs(TreeNode* node, int depth){
        if(node == nullptr) return;
        if(depth >= result.size()){
            result.push_back(vector<int> {});//深度>result的大小，就说明第一次来，那么就扩容，增加一个list
        }
        bfs(node->left, depth+1);
        result[depth].push_back(node->val);
        bfs(node->right, depth+1);        
    }
};