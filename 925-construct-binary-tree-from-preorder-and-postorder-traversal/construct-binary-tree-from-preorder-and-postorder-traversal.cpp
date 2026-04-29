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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int prestart, int preend, int poststart){
        if(prestart>preend) return nullptr;
        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart == preend) return root;
        int leftNode = preorder[prestart+1];
        int i = poststart;
        while(postorder[i]!=leftNode) i++;
        int num = i - poststart + 1;
        root->left = solve(preorder, postorder, prestart+1, prestart+num, poststart);
        root->right = solve(preorder, postorder, prestart+num+1, preend, i+1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return solve(preorder, postorder, 0, n-1, 0);
    }
};