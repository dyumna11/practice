class Solution {
public:
    vector<int> countBits(int n) {
           vector<int> ans;
        for(int i=0;i<=n;++i) //n*log n
        {
            int x=__builtin_popcount(i);//every bit has log n operations
            ans.push_back(x);
        }
        return ans;
    }
};
//tc=o(n log n)
//-------------------------------------


//tc= o(n)
class Solution {
public:
    vector<int> countBits(int n) {
           vector<int> res(n+1,0);
           res[0]=0;
        for(int i=1;i<=n;++i)
        {
           if(i%2==0)
           res[i]=res[i/2];
           else
           res[i]=res[i/2]+1;

        }
        return res;
    }
}; 
