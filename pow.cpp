int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long ans=1;
    x = ((x % d) + d) % d;
   while(n>0)
   {
       if(n%2!=0)
       ans=(1LL*ans*x)%d;
      x=(1LL*x*x)%d;
       n=n/2;
   }
   return int(ans%d);
}
