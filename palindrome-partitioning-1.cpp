
void memo(int i,string &s,vector<vector<bool>>&pal, vector<string>&temp,  vector<vector<string>>&ans)
{
    int n=s.size();
    if(i>=n)

    {
        ans.push_back(temp);
        return;
    }
    for(int ind=i;ind<n;++ind)
    {
        if(pal[i][ind])
        {
            temp.push_back(s.substr(i,ind-i+1));
            memo(ind+1,s,pal,temp,ans);
            temp.pop_back();
        }
    }

}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        int n=s.size();
        vector<string>temp;
         vector<vector<bool>>pal(n,vector<bool>(n,false));

        for(int i=n-1;i>=0;--i)
        {
            for(int j=i;j<n;++j)
            {
                if(s[i]==s[j])
                {
                    if(j-i<=2)
                    pal[i][j]=true;
                    else
                    pal[i][j]=pal[i+1][j-1];
                }
            }
        }
       memo(0,s,pal,temp,ans);
        return ans;
    }
