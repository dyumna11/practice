//tle for 1e5, optimize using dsu 
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>>jobs;
        int n=profit.size(),mx=0;
        for(int i=0;i<n;++i)
        {
            jobs.push_back({profit[i],deadline[i]});
            mx=max(mx,deadline[i]);
        }
        sort(jobs.rbegin(),jobs.rend());
         vector<int> slot(mx + 1, -1);
        int t=0,c=0,s=0;
        for(auto a:jobs)
        {
            int job=a.first;
            int time=a.second;
            for(int d=time;d>=1;--d)
            {
                if(slot[d]==-1)
                {
                    slot[d]=job;
                    s+=job;
                    ++c;
                    break;
                    
                }
            }
            
        }
        return {c,s};
    }
class Solution {
  public:
  vector<int>parent;
  int find(int t)
  {
      if(t==parent[t])
      return t;
      return parent[t]=find(parent[t]);
  }
---------------------------------------------------------------------------
//using dsu
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>>jobs;
        int n=profit.size(),mx=0;
        for(int i=0;i<n;++i)
        {
            jobs.push_back({profit[i],deadline[i]});
            mx=max(mx,deadline[i]);
        }
        parent.resize(mx+1,1);
        for(int i=0;i<=mx;++i)
        parent[i]=i;
        sort(jobs.rbegin(),jobs.rend());
         vector<int> slot(mx + 1, -1);
        int t=0,c=0,s=0;
        for(auto a:jobs)
        {
            int job=a.first;
            int time=a.second;
            int slot=find(time);
            if(slot>0)
            {
                ++c;
                s+=job;
                parent[slot]=find(slot-1);// this slot is taken, when asked return prev available slot
            }
            
        }
        return {c,s};
    }
};
