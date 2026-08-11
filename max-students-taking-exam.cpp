class Solution {
public:
    bool isvalid(int mask,string& row)
    {
        if(mask & (mask << 1))
            return false;
        int m=row.size();
        for(int j=0;j<m;++j)
        {
            if((1<<j)&mask && row[j]=='#')
            return
             false;
        }
        return true;
    }
    int maxStudents(vector<vector<char>>& seats) {
        int n=seats.size(),m=seats[0].size();
       int c=0;
       vector<vector<int>> valid(n);
       for(int i=0;i<n;++i)
       {
        string row(seats[i].begin(),seats[i].end());
        for(int mask=0;mask<(1<<m);++mask)
        {
            if(isvalid(mask,row))
            valid[i].push_back(mask);
        }
       }
       vector<int>dp(1<<m,-1);
       for(int mask : valid[0])
{
    dp[mask] = __builtin_popcount(mask);
}
       for(int i=1;i<n;++i)
       {
        vector<int>newdp(1<<m,-1);
       
        for(int mask:valid[i])
        {
             int count=__builtin_popcount(mask);
             for(int prev:valid[i-1])
             {
                if(dp[prev]==-1)
                continue;
                
                if(mask&(prev<<1))
                continue;
                if(mask&(prev>>1))
                continue;
                 newdp[mask] =
                        max(
                            newdp[mask],
                            dp[prev] +  count
                        );
             }
        }
        dp=newdp;
       }
            
        return *max_element(dp.begin(),dp.end());

    }
};
----------------------------------------------------
  //backtracking gives tle
  class Solution {
public:
int ans=0;
bool safe(int i,int j,vector<vector<char>>& seats)
{
     int n=seats.size(),m=seats[0].size();
    if(j>0 && seats[i][j-1]=='S')
    return false;
     if(i>0 &&j>0 && seats[i-1][j-1]=='S')
    return false;
    if(i>0 && j+1<m && seats[i-1][j+1]=='S')
    return false;
    return true;

}
void backtrack(int i,int j,int c,vector<vector<char>>& seats)
{
     int n=seats.size(),m=seats[0].size();
     if(i==n)
    {
        ans=max(ans,c);
        return;
    }
       
    int nr=i,nc=j+1;
    if(nc==m)
    {
        nr++;
        nc=0;
    }
   
    backtrack(nr,nc,c,seats);
    if(seats[i][j]=='.' && safe(i,j,seats))
    {
        seats[i][j]='S';
        backtrack(nr,nc,c+1,seats);
        seats[i][j]='.';
    }
    

}
    int maxStudents(vector<vector<char>>& seats) {
        int n=seats.size(),m=seats[0].size();
       int c=0;
                backtrack(0,0,c,seats);
            
        return ans;

    }
};
