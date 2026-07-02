
string solve(string s)
{
    if (s.size() < 2)
            return "";
            int n=s.size();
    unordered_set<char>st(s.begin(),s.end());
    for(int i=0;i<n;++i)
    {
        char c=s[i];
        if((islower(c) && st.count(toupper(c))==0) || (isupper(c) && st.count(tolower(c))==0))
        {
        string left=solve(s.substr(0,i));
        string right=solve(s.substr(i+1));
         if(left.size()>=right.size())
        return left;
        return right;
    }
       
    }
    return s;
}
    string longestNiceSubstring(string s) {
        
      
       return solve(s);
    }
