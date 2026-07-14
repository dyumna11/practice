//tc- O(n^2), sc=O(n^2) though for tries it cannot be determined clearly, worst case it that for each node we search for 26 times
     struct TrieNode
     {
         TrieNode* children[26];

         TrieNode()
         {
             for(int i=0;i<26;++i)
             children[i]=nullptr;

         }
     };
     
    int countSubs(string& s) {
        int n=s.size(),ans=0;
          TrieNode* root=new TrieNode();
     for(int i=0;i<n;++i)
     {
       TrieNode* curr=root;
         for(int j=i;j<n;++j)
         {
             int idx=s[j]-'a';
             if(curr->children[idx]==nullptr)
             {
             curr->children[idx]=new TrieNode();
             ++ans;
         }
             curr=curr->children[idx];
         }
     }
     
     return ans;
    }
//-----------------------------------------------------------------------
//tc- O(n^3) fails on large test cases
    int countSubs(string& s) {
        // code here
        unordered_set<string>st;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                st.insert(s.substr(i,j-i+1));
            }
        }
        return st.size();
    }
//---------------------------------------------------------------------------
 void memo(int i, string &s,string&sub,unordered_set<string>&st)
  {
      int n=s.size();
      if(i>=n)
      {
         
          return;
      }
     
      sub.push_back(s[i]);
       st.insert(sub);
      memo(i+1,s,sub,st);
     
  }
    int countSubs(string& s) {
        // code here
        unordered_set<string>st;
        int n=s.size();
         
         for(int i=0;i<n;++i)
         {
             string sub="";
              memo(i,s,sub,st);
         }
       
        return st.size();
    }
//tc=O(n^3) sc= O(n^3) 
