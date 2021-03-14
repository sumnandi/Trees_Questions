void countDistinctNodes(Node* root,vector<Node*> v,unordered_set<Node*> &ans,int k,int pathlen)
{
    if(!root)
    return;
    
    v.push_back(root);
    pathlen++;
    
    
    if(!root->left && !root->right)
    {
        int n=v.size()-1;
        
        if(n-k>=0 )
        {
            ans.insert(v[n-k]);
        }
    }
    
    countDistinctNodes(root->left,v,ans,k,pathlen);
    countDistinctNodes(root->right,v,ans,k,pathlen);
    
}

int printKDistantfromLeaf(Node* root, int k)
{
	//Add your code here. 
	if(!root)
	return 0;
	
	int pathlen=0;
	vector<Node*> v;
	unordered_set<Node*> ans;

	countDistinctNodes(root,v,ans,k,pathlen);

	return ans.size();
	
	
}
