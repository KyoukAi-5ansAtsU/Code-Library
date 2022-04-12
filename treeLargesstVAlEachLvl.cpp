class Solution
{
    public:
    void helper(vector<int>& res, Node* root, int d)
    {
        if (!root)
            return;

        if (d == res.size())
            res.push_back(root->data);
    
        else
            res[d] = max(res[d], root->data);

        helper(res, root->left, d + 1);
        helper(res, root->right, d + 1);
    }

    public:
    vector<int> largestValues(Node* root)
    {
        vector<int> res;
        helper(res, root, 0);
        return res;
    }
};