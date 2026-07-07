
  
    int longestStringChain(vector<string>& words) {
     
        int mx=0;
        sort(words.begin(),words.end(),[](const string &a, const string &b)
        {
            return a.size()<b.size();
        });
        int n=words.size();
        map<string,int>dp;
        for(auto word:words)
        {
            dp[word]=1;
            for(int i=0;i<word.size();++i) //generate all pred for a given word
            {
                 string str=word.substr(0,i)+word.substr(i+1);//by removing a char
                 if(dp.count(str))
                 dp[word]=max(dp[word],dp[str]+1);//find max of length
            }
           
            mx=max(mx,dp[word]);
        }
        
        return mx;
    }
};
//O(n × L²) : each word of length L generates L^2

//-----------------------------------------------------------------------------

class Solution {
  public:
  bool check(string &a, string &b)
  {
      int i=0,n=a.size(),j=0,m=b.size(),skip=0;
      if(n+1!=m)
      return false;
      while(i<n && j<m)
      {
          if(a[i]==b[j])
          {
              ++i;++j;
          }
          else
          {
              ++skip;
              if(skip>1)
              return false;
              ++j;
          }
      }
      return i==n;
      
  }
    int longestStringChain(vector<string>& words) {        
        sort(words.begin(),words.end(),[](const string &a, const string &b)
        {
            return a.size()<b.size();
        });//sort by length
        int n=words.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(check(words[j],words[i]))//check for all pred before a word
                {
                    dp[i]=max(dp[i],1+dp[j]);//take max length
                }
            }
            
        }
        int mx=*max_element(dp.begin(),dp.end());
        return mx;
    }
}; //tc= O(N^2L)
