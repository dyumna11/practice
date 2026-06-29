
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>m;
         vector<string>ans;
         int n=s.size();
         if(n<10)
         return {};
        for(int i=0;i<n-9;++i)
        {
            m[s.substr(i,10)]++;
        }
        for(auto i:m)
        {
            if(i.second>=2)
            ans.push_back(i.first);
        }
        return ans;
    }
