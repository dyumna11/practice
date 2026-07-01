//2 pointer approach, fix the last element
    int triangleNumber(vector<int>& a) {
        int c=0,n=a.size();
        sort(a.begin(),a.end());
        for(int i=n-1;i>=0;--i)
        {
            int l=0,r=i-1;
            while(l<r)
            {
                if(a[r]+a[l]>a[i])
               {
                c+=(r-l);
                --r;
               }
               else
               ++l;
            }
        }
        return c;
    
