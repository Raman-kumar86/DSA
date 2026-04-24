/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool DFS(TreeNode* root, int data, vector<TreeNode*>&arr){
        if(!root) return false;
        arr.push_back(root);
        if(root->val==data) return true;
        if(DFS(root->left, data, arr) || DFS(root->right, data, arr)){
            return true;
        }
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>arr1;
        vector<TreeNode*>arr2;
        DFS(root, p->val, arr1);
        DFS(root, q->val, arr2);
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<arr2.size();j++){
                if(arr1[i]==arr2[j]) return arr1[i];
            }
        }
        return nullptr;
    }
};