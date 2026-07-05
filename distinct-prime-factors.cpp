
 unordered_set<int>s;
void calc(int n)
{
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        s.insert(i);
        while(n%i==0)
        n=n/i;
    }
   if(n!=1)
   s.insert(n);
}
    int distinctPrimeFactors(vector<int>& nums) {
       
        for(int x:nums)
        {
            calc(x);
        }
    return s.size();
    }
};
