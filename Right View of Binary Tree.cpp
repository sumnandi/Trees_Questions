class Solution
{
    public:
    
    void printRightView(Node *root,int &maxlevel,int level,vector<int> &ans)
    {
        if(root)
        {
            if(maxlevel<level)
            {
                ans.push_back(root->data);
                maxlevel=level;
            }
            
            printRightView(root->right,maxlevel,level+1,ans);
            printRightView(root->left,maxlevel,level+1,ans);
        }
    }
    
    vector<int> rightView(Node *root)
    {
       // Your Code here
       if(!root)
       return {};
       
       vector<int>ans;
       int maxlevel=INT_MIN;
       int level=0;
       
       printRightView(root,maxlevel,level,ans);
       
       return ans;
    }
};
