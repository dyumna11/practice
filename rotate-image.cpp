class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size();
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                swap(a[j][i],a[i][j]);
            }
        }
         for(int i=0;i<n;++i)
        {
        reverse(a[i].begin(),a[i].end());//for cw rotate each row
          //for acw rotate full matrix
        }
        
    }
};
