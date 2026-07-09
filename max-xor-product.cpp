class Solution {
public:
typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        ll axor=0,bxor=0;
        const int N=1e9+7;
        for(ll i=49;i>=n;--i)//from 49 to n, bits cant change in x bec of constraints of x
          //x cann only lie till 2^50
        {
            bool aithset=((a>>i)&1)>0;//check if ith bit is set or not
            bool bithset=((b>>i)&1)>0;
            if(aithset)
            axor^=(1ll<<i);//if yes, copy bit as it is
            if(bithset)
            bxor^=(1ll<<i);
        }
        for(int i=n-1;i>=0;--i)//from n-1 to 0 x bits can change
        {
            bool aithset=((a>>i)&1)>0;
            bool bithset=((b>>i)&1)>0;
            if(aithset==bithset)// if both same
            {
                 axor^=(1ll<<i);//just make it 1
                 bxor^=(1ll<<i);
            }
            else
            {
                if(axor>bxor)// if diff
                  bxor^=(1ll<<i);//move the smaller one greedily
                  else
                   axor^=(1ll<<i);

            }
        }
        axor=axor%N;
        bxor=bxor%N;
        return (axor*bxor)%N;
    }
};
