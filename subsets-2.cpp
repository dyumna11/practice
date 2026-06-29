
void memo(int i,vector<int>&temp,vector<int>&a,vector<vector<int>>&ans)
{
    int n=a.size();
    if(i>=n)
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(a[i]);
    memo(i+1,temp,a,ans);
    while(i+1<n && a[i]==a[i+1])
    ++i;
    temp.pop_back();
    memo(i+1,temp,a,ans);
}
    vector<vector<int>> subsetsWithDup(vector<int>& a) 
    {
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        vector<int>temp;
        memo(0,temp,a,ans);   
        return ans;
    }
