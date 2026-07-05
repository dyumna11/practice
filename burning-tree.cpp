//we return c-1 coz already target node is burning, eg if there is only one node it should return 0 not 1
  map<Node*,Node*>parent;
   Node* targetnode;
void findparent(Node* node,Node* parentnode,int target)
{
    if(!node)
    return;
    if(node->data==target)
     targetnode=node;
    parent[node]=parentnode;
    findparent(node->left,node,target);
    findparent(node->right,node,target);
}
    int minTime(Node* root, int target) {
       findparent(root,nullptr,target);
       queue<Node*>q;
       q.push(targetnode);
       map<Node*,int>vis;
       vis[targetnode]=1;
       int c=0;
       while(!q.empty())
       {
           int s=q.size();
           for(int i=0;i<s;++i)
           {
               auto node=q.front();
               q.pop();
               if(node->left && !vis[node->left])
               {
                   q.push(node->left);
                   vis[node->left]=1;
               }
                if(node->right && !vis[node->right])
               {
                   q.push(node->right);
                   vis[node->right]=1;
               }
                if(parent[node] && !vis[parent[node]])
               {
                   q.push(parent[node]);
                   vis[parent[node]]=1;
               }
               
           }
           ++c;
       }
       return c-1;
    }
