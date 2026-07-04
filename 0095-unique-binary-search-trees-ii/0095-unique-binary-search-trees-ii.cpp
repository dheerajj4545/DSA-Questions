class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {

        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }

        for (int root = start; root <= end; root++) {

            vector<TreeNode*> leftTrees = solve(start, root - 1);
            vector<TreeNode*> rightTrees = solve(root + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* node = new TreeNode(root);

                    node->left = left;
                    node->right = right;

                    ans.push_back(node);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {

        if (n == 0)
            return {};

        return solve(1, n);
    }
};