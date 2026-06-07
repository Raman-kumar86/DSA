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
    unordered_map<int, TreeNode*>mp;
    unordered_set<int>childNode;
    void helper(vector<int>&description){
        int parent = description[0];
        int child = description[1];
        bool isLeft = description[2];
        childNode.insert(child);
        TreeNode* p;
        if(mp.count(parent)){
            p = mp[parent];
        }else{
            p = new TreeNode(parent);
            mp[parent] = p;
        }
        TreeNode* c;
        if(mp.count(child)){
            c = mp[child];
        }else{
            c = new TreeNode(child);
            mp[child] = c;
        }
        if(isLeft){
            p->left = c;
        }else{
            p->right = c;
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int parent = descriptions[0][0];
        int child= descriptions[0][1];
        bool isLeft = descriptions[0][2];
        childNode.insert(child);
        TreeNode* head = new TreeNode(parent);
        mp[parent] = head;
        TreeNode* c = new TreeNode(child);
        mp[child] = c;
        if(isLeft){
            head->left = c;
        }else{
            head->right = c;
        }
        for(int i=1;i<descriptions.size();i++){
            helper(descriptions[i]);
        }
        for(auto& it:descriptions){
            if(!childNode.count(it[0])) return mp[it[0]];
        }
        return head;
    }
};