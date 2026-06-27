//sort the array
//move past duplicates
//do 2 pointer approach, add loops acc to numbers
//after encountering a soln do ++l, --r

//TWO SUM- can be solved by hashmap+prefix sum as well

    vector<int> twoSum(vector<int>& a, int k) {
        int l=0,n=a.size(),s=0,r=n-1;
        unordered_map<int,int>m;
        for(int i=0;i<n;++i)
        {
            if(m.find(k-a[i])!=m.end())
            return {i,m[k-a[i]]};
            m[a[i]]=i;
        }
        return{};
  
//3 SUM

    vector<vector<int>> threeSum(vector<int>& a) {
        int l=0,r=a.size()-1;
        int n=a.size();
        map<int,int>m;
        sort(a.begin(),a.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;++i)
        {
            if(i>0 && a[i]==a[i-1]) continue;//duplicates
            l=i+1,r=n-1;
            int s=0;
        while(l<r)
        {
            s=a[l]+a[r]+a[i];
            if(s==0)
            {
                ans.push_back({a[i],a[l],a[r]});
                ++l;//move pointers
                --r;
            while(l<r && a[l]==a[l-1]) l++;//for duplicates
            while(l<r && a[r]==a[r+1]) r--;
            }
            else if (s<0)
            ++l;
            else
            --r;

        }
        }
        return ans;
    }

//4sum
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int n=a.size();
        for(int i=0;i<n;++i)//2 loops req
        {
            if(i>0 && a[i]==a[i-1])
            continue;
            for(int j=i+1;j<n;++j)//i!=j!=r!=l
            {
                 if (j > i + 1 && a[j] == a[j - 1]) continue;
                    int l=j+1, r=n-1;
                    vector<int>temp;
                    while(l<r)
                    {
                        long long sum=(long long)a[i]+a[j]+a[r]+a[l];
                        if(sum==target)
                        {
                            ans.push_back({a[i],a[j],a[l],a[r]});
                        while(l<r && a[l+1]==a[l])
                        ++l;
                        while(l<r && a[r-1]==a[r])
                        --r;
                        ++l;
                        --r;
                        }
                     
                        else if (sum<target)
                        ++l;
                        else
                        --r;
                    }
                    
                
            }
        }
        return ans;
    }
    
