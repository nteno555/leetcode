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
#define ll long long

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root==nullptr || (root->left == nullptr && root->right == nullptr)) return true;

        queue<pair<ll, ll>> intervals;
        queue<TreeNode*> nodes;

        nodes.emplace(root);
        intervals.push({-LLONG_MAX, LLONG_MAX});

        while (!nodes.empty()) {
            TreeNode* cur = nodes.front();
            ll lowEnd = intervals.front().first, highEnd = intervals.front().second;
            if (cur->left != nullptr) {
                ll leftVal = cur->left->val;
                if (leftVal >= cur->val) return false;
                if (leftVal <= lowEnd || leftVal >= highEnd) return false;
                nodes.emplace(cur->left);
                intervals.push({lowEnd, cur->val});
            }
            if (cur->right != nullptr) {
                ll rightVal = cur->right->val;
                if (rightVal <= cur->val) return false;
                if (rightVal <= lowEnd || rightVal >= highEnd) return false;
                nodes.emplace(cur->right);
                intervals.push({cur->val, highEnd});
            }

            nodes.pop();
            intervals.pop();
        }

        return true;

    //     if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
    //         return true;
    //     }

    //     if (root->left == nullptr) {
    //         return ((root->val < root-> right->val) && isValidBST(root->right));
    //     }

    //     if (root->right == nullptr) {
    //         return ((root->val > root->left->val) && isValidBST(root->left));
    //     }

    //     return ((root->val < root-> right->val) && isValidBST(root->right)) &&
    //             ((root->val > root->left->val) && isValidBST(root->left));
    }
};