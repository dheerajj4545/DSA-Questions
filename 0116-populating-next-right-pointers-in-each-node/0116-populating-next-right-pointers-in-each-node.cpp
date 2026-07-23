class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node* leftMost = root;

        while (leftMost->left) {
            Node* curr = leftMost;

            while (curr) {
                curr->left->next = curr->right;

                if (curr->next)
                    curr->right->next = curr->next->left;

                curr = curr->next;
            }

            leftMost = leftMost->left;
        }

        return root;
    }
};