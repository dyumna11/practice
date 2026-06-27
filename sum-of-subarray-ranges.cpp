
long long greater(vector<int> &arr,int n)
{
    long long ans=0;
    stack<int>st;
    int s=0;
    vector<int>pge(n,-1);
    vector<int>nge(n,n);
    for(int i=0;i<n;++i)
    {
    while(!st.empty() && arr[st.top()]<=arr[i])
     st.pop();
     if(!st.empty())
     pge[i]=i-st.top();
     else
     pge[i]=i+1;
    st.push(i);
}
    while(!st.empty()) st.pop();

for(int i=n-1;i>=0;--i)
{
      while(!st.empty() && arr[st.top()]<arr[i])
     st.pop();
     if(!st.empty())
     nge[i]=st.top()-i;
     else
     nge[i]=n-i;
    st.push(i);
}
   for(int i=0;i<n;++i)
   {
    ans+=1LL*nge[i]*pge[i]*arr[i];
   }
return ans;
}
long long small(vector<int> &a,int n)
{
    stack<int>st;
    vector<int>pse(n,-1);
    for(int i=0;i<n;++i)
    {
        while(!st.empty() && (a[st.top()]>=a[i]))
        st.pop();
        if(!st.empty())
       pse[i]=i-st.top();
       else
       pse[i]=i+1;
       st.push(i);
    }
    while(!st.empty()) st.pop();
vector<int>nse(n,n);
    for(int i=n-1;i>=0;--i)
{
     while(!st.empty() && (a[st.top()]>a[i]))
        st.pop();
        if(!st.empty())
       nse[i]=st.top()-i;
       else
       nse[i]=n-i;
       st.push(i);
    }
    long long ans=0;
   for(int i=0;i<n;++i)
   {
    ans+=1LL*nse[i]*pse[i]*a[i];
   }
return ans;
}
    long long subArrayRanges(vector<int>& arr) 
    {
        int n=arr.size();
       return greater(arr,n)-small(arr,n);
    }
