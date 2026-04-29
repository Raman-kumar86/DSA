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
    void inorderTraversal(TreeNode* root, vector<int>&arr){
        if(!root) return ;
        arr.push_back(root->val);
        if(root->left) inorderTraversal(root->left, arr);
        if(root->right) inorderTraversal(root->right, arr);
    }
    void flatten(TreeNode* root) {
        vector<int>arr;
        if(!root) return;
        inorderTraversal(root, arr);
        TreeNode* t = root;
        if(root->left) root->left = nullptr;
        for(int i=1;i<arr.size();i++){
            TreeNode* node = new TreeNode(arr[i]);
            t->right = node;
            t = t->right;
        }
    }
};