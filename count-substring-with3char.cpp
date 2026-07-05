class Solution {
  public:
    int countSubstring(string &s) {
        // Code here
        vector<int>hsh(4,0);
        int c=0,n=s.size(),l=0;
        for(int i=0;i<n;++i)
        {
            hsh[s[i]-'a']++;
            while(hsh[0]>=1 && hsh[1]>=1 && hsh[2]>=1)
          {
              c+=n-i;
              hsh[s[l]-'a']--;
              ++l;
          }
            
        }

    
        return c;
    }
};
