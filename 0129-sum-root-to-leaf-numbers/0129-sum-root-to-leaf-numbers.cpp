class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int curr) {
        if (root == NULL) return;

        curr = curr * 10 + root->val;

        if (root->left == NULL && root->right == NULL) {
            ans += curr;
            return;
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};