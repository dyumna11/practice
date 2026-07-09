class Solution {
public:
//can use __builtin_popcount() as well;
int findones(int x)//another method to find no. of set bits
{
    int count=0;
    while(x!=0)
    {
        count+=x&1;//check if rightmost is 1 or not
        x=x>>1;//move it right
    }
    return count;
}
    vector<int> sortByBits(vector<int>& arr) {
  
         vector<int> res;
         auto lambda=[&](int &a,int &b)//[&] req to access all elements outside lambda function
         {
            int ca=findones(a);
            int cb=findones(b);
            if(ca==cb)
            return a<b;
            return ca<cb;
       };
         sort(arr.begin(),arr.end(),lambda);
         
       
        return arr;
    }
};
//tc= o(nlogn) sort operations, sc=o(log n) sort
