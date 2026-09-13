class Solution {
  public:
    // Returns a vector<int> of size 2 where:
    // [0] = minimum value in arr from index L to R (inclusive),
    // [1] = maximum value in arr from index L to R (inclusive).
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.

    vector<int> query(int node,vector<int>&a,int ql,int qr,int l,int r, vector<vector<int>>& tree)
    {
        if(l>qr || r<ql)
         return {INT_MAX, INT_MIN};;
        if(ql<=l && qr>=r)
        return tree[node];
        int m=(l+r)/2;
        vector<int>left=query(2*node+1,a,ql,qr,l,m,tree);
        vector<int>right=query(2*node+2,a,ql,qr,m+1,r,tree);
        return {min(left[0],right[0]),max(left[1],right[1])};
        
    }
    vector<int> getMinMax(vector<int>& a, int L, int R,
                          vector<vector<int>>& segTree) {
        // code here
        int n=a.size();
       return query(0,a,L,R,0,n-1,segTree);
    }
    void update(int node,int l,int r,vector<vector<int>>& seg, int value,int index)
    {
        if(l==r)
        {
            seg[node][0] = value;
                        seg[node][1] = value;
                        return;
        }
         int m=(l+r)/2;
        if(index<=m)
        update(2*node+1,l,m,seg,value,index);
        else
        update(2*node+2,m+1,r,seg,value,index);
       seg[node][0] =
                  min(seg[2 * node + 1][0],
                      seg[2 * node + 2][0]);

              seg[node][1] =
                  max(seg[2 * node + 1][1],
                      seg[2 * node + 2][1]);
    }
    // Updates the value at arr[index] to 'value' and updates the segTree accordingly.
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.
    void updateValue(vector<int>& arr, int index, int value,
                     vector<vector<int>>& seg) {
                    int n=arr.size();    
    update(0,0,n-1,seg,value,index);

    }
};
