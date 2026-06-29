
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int cap) {
        // code here
        int n=val.size();
        vector<pair<double, pair<int, int>>>items;
        for(int i=0;i<n;++i)
        {
            double ratio=(1.0*val[i])/wt[i];
            items.push_back({ratio,{wt[i],val[i]}});
        }
        sort(items.rbegin(),items.rend());
        double totwt=0.0,ans=0.0;
        for(auto item:items)
        {
            int w=item.second.first,val=item.second.second;
            if(cap>=w)
           {
               cap-=w;
                ans+=val;
           }
           else
           {
               ans += (1.0 * val * cap) / w;
               break;
               
           }
        }
        return ans;
        
    }
