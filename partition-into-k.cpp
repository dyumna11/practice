
  bool check(int ind,int target, vector<int> &bucket,vector<int> &a)
  {
      int n=a.size();
      if(ind==n)
      return true;
      for(int i=0;i<bucket.size();++i)
      {
          if(bucket[i]+a[ind]>target)
          continue;
          bucket[i]+=a[ind];
          if(check(ind+1,target,bucket,a))
          return true;
          bucket[i]-=a[ind];
          if(bucket[i]==0)
          break;
      }
      return false;
  }
    bool isKPartitionPossible(vector<int> &a, int k) {
        // Your code here
        int s=accumulate(a.begin(),a.end(),0);
        if(s%k!=0)
        return false;
        int target=s/k;
        vector<int>bucket(k);
        sort(a.rbegin(),a.rend());
        if(a[0]>target)
        return false;
        return check(0,target,bucket,a);
    }
