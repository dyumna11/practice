
bool check(int days,int k,vector<int>& bloom,int num)
{
    int boq=0,c=0,n=bloom.size();
    for(int i=0;i<n;++i)
    {
        if(bloom[i]<=days)
        ++c;
        else
        {
       
        boq+=c/k;
         c=0;
        }
    }
    boq+=c/k;
    return boq>=num;

}
    int minDays(vector<int>& bloom, int num, int k) {
    if(1LL*num*k>bloom.size())
    return -1;
    int ans=0;
    int l=*min_element(bloom.begin(),bloom.end());
    int r=*max_element(bloom.begin(),bloom.end());
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(check(m,k,bloom,num))
        {
            ans=m;
            r=m-1;
        }
        else
        l=m+1;
    }
    return ans;
    }
