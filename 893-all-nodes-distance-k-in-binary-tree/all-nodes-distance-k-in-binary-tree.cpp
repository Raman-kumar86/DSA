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
    void inorderTraversal(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(!root) return;
        if(root->left){
            parent[root->left] = root;
            inorderTraversal(root->left, parent);
        }
        if(root->right){
            parent[root->right] = root;
            inorderTraversal(root->right, parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root || !target) return {};
        unordered_map<TreeNode*,TreeNode*>parent;
        parent[root] = root;
        inorderTraversal(root, parent);
        unordered_set<TreeNode*>visited;
        visited.insert(target);
        int level = 0;
        queue<TreeNode*>q;
        q.push(target);
        vector<int>ans;
        while(!q.empty()){
            if(level==k){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(!visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            level++;
        }
        return ans;
    }
};