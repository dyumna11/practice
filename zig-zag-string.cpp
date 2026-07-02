
    string convert(string s, int num) {
        if(num==1 || num>=s.size())
        return s;
        vector<string>rows(num);
        int row=0,dir=1;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            rows[row]+=s[i];
            if(row==0)
            dir=1;
            else if(row==num-1)
            dir=-1;
          row+=dir;
        }
        string ans="";
        for(string x:rows)
        ans+=x;
        return ans;
    }
