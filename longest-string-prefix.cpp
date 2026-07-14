//tc= O(n*l) n=number of words, l=avg length of word
//sc= O(n*l)
  struct TrieNode{
      TrieNode* children[26];
      bool endofword;
      TrieNode()
      {
          endofword=false;
          for(int i=0;i<26;++i)
          children[i]=nullptr;
      }
  };
  
  void insert(string s, TrieNode* root)
  {
       TrieNode* crawler=root;
       for(char c:s)
       {
           if(crawler->children[c-'a']==nullptr)
           crawler->children[c-'a']=new TrieNode();
           crawler=crawler->children[c-'a'];
       }
       crawler->endofword=true;

  }
  bool checkprefix(string s, TrieNode*root)
  {
      TrieNode* crawler=root;
      for(char c:s)
      {
          crawler = crawler->children[c-'a'];
          if(crawler==nullptr || !crawler->endofword)
          return false;
      }
      return true;
      
  }
    string longestString(vector<string> &words) {
         TrieNode*root=new TrieNode();
     
        for(string s:words)
        {
            insert(s,root);
        }
        string longest="";
        for(string &s:words)
        {
            if(checkprefix(s,root))
            {
                if(s.size()>longest.size())
                {
                    longest=s;
                }
                else if(s.size()==longest.size() && s<longest)
                longest=s;
                
                
            }
        }
        if (longest == "")
            return "";
        return longest;
    }
};
