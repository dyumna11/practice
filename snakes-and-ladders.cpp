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
//----------------------------------
//gfg question
class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
      
        vector<bool>vis(n*n+1,false);
        vis[1]=true;
         unordered_map<int,int> ladder, snake;
        for(int i=0;i<lad.size();i+=2)
        ladder[lad[i]]=lad[i+1];
        for(int i=0;i<sn.size();i+=2)
        snake[sn[i]]=sn[i+1];
        int steps=0;
        queue<int>q;
          q.push(1);
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
            int node=q.front();
            q.pop();
            if(node==n*n)
            return steps;
            for(int k=1;k<=6;++k)
            {
                int val=k+node;
                if(val>n*n)
                continue;
               
                
                 if(ladder.count(val))
                {
                    val=ladder[val];
                }
                else if(snake.count(val))
                val=snake[val];
                
                if(vis[val])
                continue;
                q.push(val);
                vis[val]=1;
                
            }
        }
        ++steps;
        }
       return -1; 
    }
};
