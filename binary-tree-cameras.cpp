//2- if covered
//1- if one of them is covered
//0 if not covered
int dfs(TreeNode* root,int &camera)
{
    if(!root)
    return 2;
    int left=dfs(root->left,camera);
    int right=dfs(root->right,camera);
    if(left==0 || right==0)//if one of them is not covered, add camera
    {
        camera++;
        return 1;
    }
    else if(left==1 || right==1)//if left/right covered then this node also covered
    return 2;
    
    else
    return 0;//if both uncovered
}
    int minCameraCover(TreeNode* root) {
        int camera=0;
        if(dfs(root,camera)==0)//if not, add a camera
        ++camera;
        return camera;

    }
};
//Time: O(N)
//Space: O(H) (recursion stack)
