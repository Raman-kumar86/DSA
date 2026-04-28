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
    TreeNode* targetAddr = nullptr;
    int t;
    void inorderTraversal(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent){
        if(!root) return;
        if(root->val == t){
            targetAddr = root;
        }
        if(root->left){
            parent[root->left] = root;
            inorderTraversal(root->left, parent);
        }
        if(root->right){
            parent[root->right] = root;
            inorderTraversal(root->right, parent);
        }
        
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        t = start;
        if(!root) return 0;
        parent[root] = root;
        inorderTraversal(root, parent);
        unordered_set<TreeNode*>visited;
        visited.insert(targetAddr);
        queue<TreeNode*>q;
        q.push(targetAddr);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited.count(temp->left)){
                    q.push(temp->left);
                    visited.insert(temp->left);
                }
                if(temp->right && !visited.count(temp->right)){
                    q.push(temp->right);
                    visited.insert(temp->right);
                }
                if(!visited.count(parent[temp])){
                    q.push(parent[temp]);
                    visited.insert(parent[temp]);
                }
            }
            level++;
        }
        return level-1;
    }
};