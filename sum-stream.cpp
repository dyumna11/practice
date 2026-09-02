#include <iostream>
#include <vector>
using namespace std;
const int N=998244353;

int main() {
   
    int q,k;
    cin>>q>>k;
    vector<int>dp(k+1,0);
    dp[0]=1;
    while(q--)
    {
        char op;
        int n;
        cin>>op>>n;
       
        if(op=='+')
        {
            for(int sum=k;sum>=n;--sum)//to avoid reuse of the newly added ballw e start from here
            {
                dp[sum]=(dp[sum]+dp[sum-n])%N;
            }
        }
        else
        {
            for(int s=n;s<=k;++s)//we need to fix the smaller sums first
                dp[s]=(dp[s]-dp[s-n]+N)%N;
        }
        cout<<dp[k]<<endl;
    }
   
    
}

