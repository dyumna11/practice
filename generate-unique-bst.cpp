vector<TreeNode*> generate(int l,int r)
 {
     if(l>r)
     return {nullptr};
     vector<TreeNode*>ans;
     for(int root=l;root<=r;++root)//for every number from l to r
     {
         vector<TreeNode*>left=generate(l,root-1);//create a left
         vector<TreeNode*>right=generate(root+1,r);//create a right
         for(auto leftnode:left)//then try each combination
         {
             for(auto rightnode:right)
             {
                 TreeNode* newnode= new TreeNode(root);
                 newnode->left=leftnode;
                 newnode->right=rightnode;
                 ans.push_back(newnode);//after that insert the node
             }
         }
     }
     return ans;
     
 }
vector<TreeNode*> Solution::generateTrees(int A) {
    return generate(1,A);//from 1 to A
}
