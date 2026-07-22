
  void multiply(vector<int> &ans,int k,int &size)
  {
      int carry=0;
      for(int i=0;i<size;++i)
      {
          int res=k*ans[i];
          res+=carry;
          ans[i]=res%10;
          carry=res/10;
      }
 
       while(carry>0)
        {
            int rem=carry%10;
            ans[size]=rem;
            ++size;
            carry=carry/10;
        }
  }
    vector<int> factorial(int n) {
        // code here
        const int N=1e4;
        vector<int> ans(N,0);
        vector<int> result;
        ans[0]=1;
        int size=1;
        for(int i=2;i<=n;++i)
        multiply(ans,i,size);
        for(int i=size-1;i>=0;--i)
        result.push_back(ans[i]);
        return result;
    }
