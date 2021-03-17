#include <iostream>
#include<bits/stdc++.h>
#define N 5
using namespace std;

struct Node
{
    int data;
    Node* child[N];
};

Node* newNode(int x)
{
    Node* temp=new Node;
    temp->data=x;
    
    for(int i=0;i<N;i++)
    temp->child[i]=NULL;
    
    return temp;
}

void traverse(Node *root) 
{ 
    if (root) 
    { 
        printf("%d ", root->data); 
        for (int i = 0; i < N; i++) 
        traverse(root->child[i]); 
    } 
} 

void serializeHelper(Node* root,vector<int> &ans)
{
    if(!root)
    {
        return;
    }
    
    ans.push_back(root->data);
    
    for(int i=0;i<N && root->child[i];i++)
    serializeHelper(root->child[i],ans);
    
    ans.push_back(-1);
    
}

vector<int> serialize(Node *root)
{
    vector<int>ans;
    serializeHelper(root,ans);
    
    return ans;
}

int inde=0;
int deSerializeHelper(Node *&root, vector<int> &serAns1) 
{ 
    int val=serAns1[inde];
    inde++; 
    
    if(val==-1)
    return 1;
  
    root = newNode(val); 
    for (int i = 0; i < N; i++) 
        if (deSerializeHelper(root->child[i], serAns1)) 
            break; 
  
    return 0; 
} 

Node * deSerialize(vector<int> &serAns1)
{
    if(serAns1[0]==-1)
    return NULL;
    
    Node * root1=NULL;
    deSerializeHelper(root1,serAns1);
    
    return root1;
}

Node *createDummyTree() 
{ 
    Node *root = newNode(1); 
    root->child[0] = newNode(2); 
    root->child[1] = newNode(3); 
    root->child[2] = newNode(4); 
    root->child[0]->child[0] = newNode(5); 
    root->child[0]->child[1] = newNode(6); 
    root->child[2]->child[0] = newNode(7); 
    root->child[2]->child[1] = newNode(8); 
    root->child[2]->child[2] = newNode(9); 
    root->child[2]->child[3] = newNode(10); 
    root->child[0]->child[1]->child[0] = newNode(11); 
    return root; 
} 

int main()
{
    Node *root = createDummyTree();
    
    cout<<"Original N-ARY tree : ";
    traverse(root);
    
    vector<int> serAns=serialize(root);
    vector<int> serAns1=serAns;
  cout<<endl;
  
  cout<<"Serialization of N-ARY tree : ";
  for(auto i:serAns)
  cout<<i<<" ";

    Node * desRoot=deSerialize(serAns1);
    
    cout<<endl;
    cout<<"Deserialization of N-ARY tree : ";
    traverse(desRoot);
    
    return 0;
}
