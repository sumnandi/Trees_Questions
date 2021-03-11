vector<int> topView(struct Node *root)
{
    //Your code here
    
    if(!root)
    return {};
    
    queue<pair<Node*,int>>q;
    map<int,int>m;
    vector<int> ans;
    
    q.push(make_pair(root,0));
    
    while(!q.empty())
    {
        Node *temp=q.front().first;
        int hd=q.front().second;
        
        q.pop();
        
        if(m.find(hd)==m.end())
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
