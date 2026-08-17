class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=1e9;
        vector<int>prev=grid[0];
        for(int i=1;i<n;++i)
        {
            int mn1=1e9,mn2=1e9,idx=0;
            for(int j=0;j<m;++j)
            {
                if(prev[j]<mn1)
                {
                    mn2=mn1;
                    mn1=prev[j];
                    idx=j;
                }
                else if(prev[j]<mn2)
                {
                    mn2=prev[j];
                }
            }
            vector<int>curr(m);
            for(int j=0;j<m;++j)
            {
                if(j!=idx)
                curr[j]=grid[i][j]+mn1;
                else
                curr[j]=grid[i][j]+mn2;
            }
            prev=curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
