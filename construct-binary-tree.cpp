
    TreeNode* build(vector<int>& inorder, vector<int>& preorder,int start,int end,int &idx)
    { 
        if(start > end)//if base condition fails
    return NULL;
        int rootval=preorder[idx];//find val of node
        int i=start;
        for(;i<=end;++i)
        {
            if(rootval==inorder[i])//check where this node is in inorder
            break;
        }
        ++idx;//increment for next idx
        TreeNode* node=new TreeNode(rootval);//create a root node
        node->left=build(inorder,preorder,start,i-1,idx);//left is from start ... i-1
        node->right=build(inorder,preorder,i+1,end,idx);//right is from i+1 ... end
        return node; //return node
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int idx=0;
    return build(inorder,preorder,0,n-1,idx);
    }
