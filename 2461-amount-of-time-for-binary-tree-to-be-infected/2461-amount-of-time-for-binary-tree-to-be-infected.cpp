class Solution {
public:
    TreeNode* first = NULL;

    void find(TreeNode* root, int start) {
        if (root == NULL) return;
        if (root->val == start) {
            first = root;
            return;
        }
        find(root->left, start);
        find(root->right, start);
    }

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (root == NULL) return;
        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;
        markParents(root->left, parent);
        markParents(root->right, parent);
    }

    int amountOfTime(TreeNode* root, int start) {
        find(root, start);
        if (first == NULL) return 0;

        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        unordered_set<TreeNode*> isInfected;
        isInfected.insert(first);
        queue<pair<TreeNode*, int>> q;
        q.push({first, 0});

        int maxLevel = 0;

        while (!q.empty()) {
            auto [temp, level] = q.front();
            q.pop();
            maxLevel = max(maxLevel, level);

            if (temp->left && isInfected.find(temp->left) == isInfected.end()) {
                q.push({temp->left, level + 1});
                isInfected.insert(temp->left);
            }

            if (temp->right && isInfected.find(temp->right) == isInfected.end()) {
                q.push({temp->right, level + 1});
                isInfected.insert(temp->right);
            }

            if (parent.find(temp) != parent.end()) {
                TreeNode* par = parent[temp];
                if (par && isInfected.find(par) == isInfected.end()) {
                    q.push({par, level + 1});
                    isInfected.insert(par);
                }
            }
        }

        return maxLevel;
    }
};
