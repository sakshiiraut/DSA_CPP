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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> res;

        if (root == nullptr) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
           int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
            }

            res.push_back(level); // Add current level to result
        }
        return res;
    }
};