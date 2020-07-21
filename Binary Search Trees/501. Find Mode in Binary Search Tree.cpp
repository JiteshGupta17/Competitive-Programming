class Solution {
public:

    // Using Inorder Traversal

    vector<int> ans;
    int prev = -1;
    int freq = 0;
    int maxi = 0;

    void dfs(TreeNode* root)
    {
        if (!root) return;

        dfs(root->left);

        if (root->val == prev) freq++;
        else freq = 1;

        if (freq >= maxi)
        {
            if (freq > maxi) ans.clear();
            maxi = freq;
            ans.push_back(root->val);
        }

        prev = root->val;
        dfs(root->right);

    }

    vector<int> findMode(TreeNode* root) {

        dfs(root);
        return ans;

    }
};