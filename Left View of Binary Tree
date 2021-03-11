void printLeftView(Node *root,int &maxlevel,int level,vector<int> &ans)
{
    if(root)
    {
        if(maxlevel<level)
        {
            ans.push_back(root->data);
            maxlevel=level;
        }
        
        printLeftView(root->left,maxlevel,level+1,ans);
        printLeftView(root->right,maxlevel,level+1,ans);
    }
}

vector<int> leftView(Node *root)
{
   // Your code here
   
   if(!root)
   return {};
   
   vector<int>ans;
   int maxlevel=INT_MIN;
   int level=0;
   
   printLeftView(root,maxlevel,level,ans);
   
   return ans;
}
