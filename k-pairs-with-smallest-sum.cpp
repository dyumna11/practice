
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
       priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;
        int n=a.size(),m=b.size();
        vector<vector<int>> ans;
        for(int i=0;i<min(k,n);++i)
        pq.push({a[i]+b[0],{i,0}});
        while(k-- && !pq.empty())
        {
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            ans.push_back({a[r],b[c]});
            if(c+1<m)
            pq.push({a[r]+b[c+1],{r,c+1}});
        }
        return ans;
        
    }
