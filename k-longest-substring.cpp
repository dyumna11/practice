
    int longestKSubstr(string &s, int k) {
        // code here
        map<char,int>m;
        int mx=-1,l=0,n=s.size();
        for(int i=0;i<n;++i)
        {
            m[s[i]]++;
            while(m.size()>k)
            {
                m[s[l]]--;
                 if(m[s[l]]==0)
                m.erase(s[l]);
                ++l;
            }
            if(m.size()==k)
            mx=max(mx,i-l+1);
        }
        return mx;
    }
