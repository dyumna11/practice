
    vector<int> topKFrequent(vector<int>& a, int k) {
      unordered_map<int,int>freq;
      for(int x:a)
      freq[x]++;
      vector<int> ans;
      int n=a.size();
      vector<vector<int>>bucket(n+1);
      for(auto i:freq)
      {
        int ele=i.first;
        int f=i.second;
        bucket[f].push_back(ele);
      }
      for(int i=n;i>=1&&ans.size()<k;--i)
      {
        for(auto x:bucket[i])
        {
            ans.push_back(x);
            if(ans.size()==k)
            break;
        }
      }
      return ans;
    }
