class Solution {
  public:
  Node* recur(int l,int h,vector<int>& arr)
  {
      if(l>h)
      return nullptr;
      int m=l+(h-l)/2;
      Node* root=new Node(arr[m]);
      root->left=recur(l,m-1,arr);
      root->right=recur(m+1,h,arr);
      return root;
  }
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
       return recur(0,arr.size()-1,arr);
    }
};
