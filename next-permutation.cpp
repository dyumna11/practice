//start from the end, check which element is breaking the inc sequence, make it pivot, then again scan from right find greater element from the pivot
//swap it, now rev from begin+piv+1 to end
//next greater permutation hence necessary to find just greater element from the right and then swap, then reversing

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size(),pivot=-1;
        for(int i=n-2;i>=0;--i)
        {
            if(a[i+1]>a[i])
            {
                pivot=i;
                break;
            }
        } 
        if(pivot==-1)
        {
        reverse(a.begin(),a.end());
        return;
    }
        for(int i=n-1;i>=0;--i)
        {
            if(a[i]>a[pivot])
            {
                swap(a[i],a[pivot]);
                break;
            }
        }       
        reverse(a.begin()+pivot+1,a.end());
    }
};
