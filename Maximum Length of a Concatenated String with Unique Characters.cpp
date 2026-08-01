class Solution {
public:
int mx=0;
bool canadd(string curr,string check)//o(26)=o(1)
{
     vector<int>freq(26,0);
    for(char c:curr)
    freq[c-'a']++;
    for(char c:check)
    {
        if(freq[c-'a'])
        return false;
        freq[c-'a']++;
    }
    return true;
}
void func(int i,vector<string>& arr,string curr)
{
    mx=max(mx,(int)curr.size());
    if(i==arr.size())
    return ;
    if(canadd(curr,arr[i]))//if we can add
    func(i+1,arr,curr+arr[i]);//add
    func(i+1,arr,curr);//we dont use else
    //we miss the optimal answer that may be present further in branch
}
    int maxLength(vector<string>& arr) {
        string str="";
        int n=str.size();
        func(0,arr,"");
        //tc= o(2^n)=2^16, coz we are running for each word
        return mx;
    }
};
