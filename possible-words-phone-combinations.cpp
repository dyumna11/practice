//note for 0 and 1, if they are present move to next character
  void memo(int i, map<int,string>&m,vector<int> &a,string &str,  vector<string>&ans)
  {
    int n=a.size();
      if(i==n)
      {
          ans.push_back(str);
          return;
      }
  if (a[i] == 0 || a[i] == 1) {
        memo(i + 1, m, a, str, ans);
        return;
    }
          string s=m[a[i]];
          for(char c:s)
          {
              str.push_back(c);
              memo(i+1,m,a,str,ans);
              str.pop_back();
          }
      
  }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        if(arr.empty()) return {};
        map<int,string>m;
        m[0]="";
        m[1]="";
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        string str="";
          vector<string>ans;
        memo(0,m,arr,str,ans);
        return ans;
    }
