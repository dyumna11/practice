class Trie {
public:
struct Node
{
    Node* links[26];
    bool flag=false;
     Node()
    {
        for(int i=0;i<26;i++)
            links[i]=nullptr;
    }
    bool containsKey(char c)
    {
        return links[c-'a']!=NULL;
    }

void put(char c, Node* node)
{
    links[c-'a']=node;
}
Node* get(char c)
{
    return links[c-'a'];
}
   void setEnd()
   {
    flag=true;
   }
   bool isEnd()
{
    return flag;
}
};
Node* root;
    Trie() {
         root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();++i)
        {
            if(!node->containsKey(word[i]))
            node->put(word[i],new Node());
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();++i)
        {
            if(!node->containsKey(word[i]))
            return false;
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    
    bool startsWith(string word) {
          Node* node=root;
        for(int i=0;i<word.size();++i)
        {
            if(!node->containsKey(word[i]))
          return false;
            node=node->get(word[i]);
        }
    
    return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
