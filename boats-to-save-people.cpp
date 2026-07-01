
    int numRescueBoats(vector<int>& a, int limit) {
        sort(a.begin(),a.end());
        int n=a.size();
        int l=0,r=n-1;
        int boats=0;
        while(l<=r)
        {
            int wt=a[l]+a[r];
            if(wt<=limit)

            {
                ++l;
                --r;
                 boats++;
            }
            else
            {
                boats++;
                --r;
            }
        }
        return boats;
    }
