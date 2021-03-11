vector <int> bottomView(Node *root)
{
   // Your Code Here
   if(!root)
   return {};
   
   vector<int>ans;
   queue<pair<Node*,int>>q;
   map<int,int>m;
   
   q.push(make_pair(root,0));
   
   while(!q.empty())
   {
       Node *temp=q.front().first;
       int hd=q.front().second;
       
       q.pop();
       
       
       m[hd]=temp->data;
       
       if(temp->left)
       q.push(make_pair(temp->left,hd-1));
       
       if(temp->right)
       q.push(make_pair(temp->right,hd+1));
   }
   
   for(auto i:m)
   ans.push_back(i.second);
   
   return ans;
}
