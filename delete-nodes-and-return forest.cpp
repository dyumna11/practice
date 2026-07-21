
TreeNode* func(TreeNode* root,vector<TreeNode*>&ans, unordered_set<int>&s)
{
    if(!root)
    return nullptr;
    root->left=func(root->left,ans,s);//go left and right
    root->right=func(root->right,ans,s);
    if(s.count(root->val)//check if this val has to be deleted
    {
        if(root->left)
        ans.push_back(root->left);//if left/right child present, add to ans
         if(root->right)
        ans.push_back(root->right);
        return nullptr;//return null, then in that tree this side becomes null
    }
    else
    return root;//return root itself
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>s;
        for(int x:to_delete)
        s.insert(x);//in a set for easy access
        func(root,ans,s);
        if(s.count(root->val)==0)//if root has to be deleted ,delete root
        ans.push_back(root);
        return ans;
    }
//tc= o(n), sc=o(h+k)
