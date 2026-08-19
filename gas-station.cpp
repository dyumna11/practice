int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int start=0,gas=0,total=0;
    int n=A.size();
    for(int i=0;i<n;++i)
    {
        int diff=A[i]-B[i];//calculate diff
        gas+=diff;
        total+=diff;//after traversing whole it must not be -ve
        if(gas<0)// if <0 then in circle also we cannot take the same path, so discard it
        {
            gas=0;
            start=i+1;
        }
       
    }
     if(total<0)//if it is then not possible
        return -1;
    return start;
}
