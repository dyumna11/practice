class Solution {
public:
pair<int,int>pos(int x,int n)
{
    x--;
    int r=x/n;
    int c=x%n;
    if(r%2!=0)
    c=n-1-c;
    return {n-1-r,c};
}
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int,int>> q;
        vector<int> vis(n*n+1,0);
vis[1]=1;
      q.push({1,0});
      while(!q.empty())
      {
        int node=q.front().first;
        int moves=q.front().second;
        q.pop();
        if(node==n*n)
        return moves;
        for(int next=node+1; next<=min(node+6,n*n);++next)
        {
            auto [r,c]=pos(next,n);
            int dst=next;
            if(board[r][c]!=-1)
            dst=board[r][c];
            if(!vis[dst])
            {
                vis[dst]=1;
                q.push({dst,moves+1});
            }
        }
      }
      return -1;  
    }
};
