class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;

        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;

        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        return build(nums, 0, nums.size() - 1);
    }
};