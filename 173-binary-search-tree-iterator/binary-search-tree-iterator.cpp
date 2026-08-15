class BSTIterator {
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        // The next node may be in this node's right subtree.
        pushLeft(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};