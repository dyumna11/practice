class Solution {
public:

    bool isLeaf(Node* node) {
        return node && !node->left && !node->right;
    }

    void addLeft(Node* root, vector<int>& ans) {
        Node* cur = root->left;

        while(cur) {
            if(!isLeaf(cur))
                ans.push_back(cur->data);

            if(cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    void addLeaves(Node* root, vector<int>& ans) {
        if(!root) return;

        if(isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    void addRight(Node* root, vector<int>& ans) {
        Node* cur = root->right;
        vector<int> temp;

        while(cur) {
            if(!isLeaf(cur))
                temp.push_back(cur->data);

            if(cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }

        for(int i = temp.size()-1; i >= 0; i--)
            ans.push_back(temp[i]);
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;

        if(!root)
            return ans;

        if(!isLeaf(root))
            ans.push_back(root->data);

        addLeft(root, ans);
        addLeaves(root, ans);
        addRight(root, ans);

        return ans;
    }
};
