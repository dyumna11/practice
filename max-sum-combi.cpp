//fails on 1e^5, generating all gives tle
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                 pq.push(a[i]+b[j]);
                 if(pq.size()>k)
                 pq.pop();
            }
           
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
      
        return ans;
    }
//-------------------------------------------------------------------------------

    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>vis;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        pq.push({a[n-1]+b[n-1],{n-1,n-1}}); //push largest sum that can be attained
        vis.insert({n-1,n-1});//keep marking visited
        while(k-- && !pq.empty())
        {
            int sum=pq.top().first;
            ans.push_back(sum);//add best sum
            int i=pq.top().second.first;//explore neighnours
            int j=pq.top().second.second;
            pq.pop();
            if(i>0 && !vis.count({i-1,j}))
            {
                pq.push({a[i-1]+b[j],{i-1,j}});//find next best sum
                vis.insert({i-1,j});
            }
             if(j>0 && !vis.count({i,j-1}))
            {
                pq.push({a[i]+b[j-1],{i,j-1}});
                vis.insert({i,j-1});
            }
        }
        return ans;
    }
