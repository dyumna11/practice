
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({INT_MAX,{0,0}});
        int n=points.size();
        for(int i=0;i<n;++i)
        {
            int x=points[i][0],y=points[i][1];
            int dst=x*x+y*y;
            pq.push({dst,{x,y}});
        }
        vector<vector<int>>ans;
        while(k--)
        { 
            auto [x,y]=pq.top().second;
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }

