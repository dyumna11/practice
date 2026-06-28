//use dnf for 3 sorting, when m exceeds h, then it means it is sorted. 
//when we find 2, swap and just push it back --h, for 0 swap with low and move both, and for 1 move m
    void sortColors(vector<int>& a) {
       int l=0,h=a.size()-1,m=0;
       while(m<=h)
       {
        if(a[m]==0)
        swap(a[l++],a[m++]);
        else if(a[m]==1)
       m++;
        else
        swap(a[m],a[h--]);
       }
    }
