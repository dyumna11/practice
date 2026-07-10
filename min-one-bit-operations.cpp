class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long>F(31,0);
        F[0]=1;
        int res=0;
        for(int i=1;i<=30;++i)
        {
            F[i]=2*F[i-1]+1;
        }
        bool sign=true;
        for(int i=30;i>=0;--i)
        {
            int ithbit=(1<<i)&n;
            if(ithbit==0)
            continue;
            if(sign)
            res+=F[i];
            else
            res-=F[i];
            sign=!sign;
        }
        return res;
    }
};
