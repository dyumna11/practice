int Solution::singleNumber(const vector<int> &A) {
    int ans=0;
    for(int k=0;k<=31;++k)
    {
        int countzero=0,coutone=0;
        int temp=(1U<<k);
        for(int x:A)
        {
            if((x&temp)==0)
            ++countzero;
            else
            ++coutone;
        }
        if(coutone%3!=0)
        ans=ans|temp;
    }
    return ans;
}
