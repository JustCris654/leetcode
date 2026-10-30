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
        vector<vector<int>> v;
        if (root == nullptr) {
            return v;
        }

        std::queue<std::pair<TreeNode*, int>> q;
        q.push(std::make_pair(root, 0));

        while (!q.empty()) {
            auto u = q.front(); q.pop();

            // aggiunta elemento al vettore di output
            if (v.size() == u.second) {
                v.push_back({u.first->val});
            } else {
                v[u.second].push_back(u.first->val);
            }

            int nextLevel = u.second + 1;
            if (u.first->left != nullptr) {
                q.push(std::make_pair(u.first->left, nextLevel));
            }
            if (u.first->right != nullptr) {
                q.push(std::make_pair(u.first->right, nextLevel));
            }
        }

        return v;
    }
};
