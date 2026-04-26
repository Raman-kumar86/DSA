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
    typedef unsigned long long LL;
    int widthOfBinaryTree(TreeNode* root) {
        LL maxi = 0;
        if(!root) return maxi;
        queue<pair<TreeNode*,LL>>q;
        q.push({root, 0});
        while(!q.empty()){
            LL first = q.front().second;
            LL last = q.back().second;
            maxi = max(maxi, last-first+1);
            int n = q.size();
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                LL idx = it.second;
                if(node->left) q.push({node->left,idx*2+1});
                if(node->right) q.push({node->right,idx*2+2});
            }
        }
        return maxi;
    }
};