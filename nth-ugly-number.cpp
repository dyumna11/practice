//first app: using recursion
bool prime(int n)
{
  //o(log n)
    while(n%2==0)
    n=n/2;
     while(n%3==0)
    n=n/3;
     while(n%5==0)
    n=n/5;
    if(n!=1)
    return false;
    return true;
    
}
int memo(int i,int n,int num)
{
   //o( n)
    if(i==n)
    return num-1;
    if(prime(num))
    return memo(i+1,n,num+1);
    else
    return memo(i,n,num+1);
}
    int nthUglyNumber(int n) 
    {
       return memo(0,n,1);
    }
};
//tc= o(nlogn), sc=o(n)
//---------------------------------------
    int nthUglyNumber(int n) 
    {
        int i2=0,i3=0,i5=0;
        vector<int>ugly(n);
        ugly[0]=1;
        for(int i=1;i<n;++i)
        {
            int next2=ugly[i2]*2;
            int next3=ugly[i3]*3;
            int next5=ugly[i5]*5;
            ugly[i]=min({next2,next3,next5});
            if(ugly[i]==next2)++i2;
            if(ugly[i]==next3)++i3;
            if(ugly[i]==next5)++i5;
        }
        return ugly[n-1];
      //tc=o(n), sc=o(n)
    }
};
