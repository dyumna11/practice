int Solution::fibsum(int a) {
    vector<int>fib={1,2};
    while(fib.back()<a)
    {
         int n = fib.size();
        int next=fib[n-1]+fib[n-2];
        if(next>a)
        break;
        fib.push_back(next);
    }
    int ans=0;
    while(a>0)

{
    auto it=upper_bound(fib.begin(),fib.end(),a);
    --it;
    a-=*it;
    ans++;
}
return ans;
}
