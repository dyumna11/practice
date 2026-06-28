
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
        int N=a.size();
        long long n=1LL*N*N;
        long long expsum=1LL*(n*(n+1))/2;
        long long expsqsum=1LL*(n*(n+1)*(2*n+1))/6;
        long long sum=0,sqsum=0;
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
            sum+=a[i][j];
            sqsum=sqsum+1LL*a[i][j]*a[i][j];
        }
        }
        long long diff=sum-expsum;
        long long sqdiff=sqsum-expsqsum;
         long long add=sqdiff/diff;
         int rep=(diff+add)/2;
         int miss=rep-diff;
        return {rep,miss};
    }
