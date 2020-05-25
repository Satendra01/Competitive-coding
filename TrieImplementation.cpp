#include <bits/stdc++.h>
using namespace std;
struct Node{
    struct Node *alphabet[26];
    bool isEndOfWord;
    int count;
};
Node* getNode()
{
    Node * n=new Node();
    for(int i=0;i<26;i++)
    {
        n->alphabet[i]=NULL;
        n->isEndOfWord=false;
        n->count=0;
    }
    return n;
}

void addNode(string str,Node *root)
{
        Node * temp=root;
        for(int i=0;i<str.length();i++)
        {
            Node * node=getNode();
            int index=abs('a'-str[i]);
            if(temp->alphabet[index]==NULL)
            {
                
                temp->alphabet[index]=node;
            }
            temp=temp->alphabet[index];
            temp->count++;
        }
        temp->isEndOfWord=true;
}
int search(string str,Node*root)
{
        Node *temp=root;
        for(int i=0;i<str.length();i++)
        {
            int index=abs('a'-str[i]);
            if(temp->alphabet[index]!=NULL)
            temp=temp->alphabet[index];
            else
            {
                return 0;
            }
            
        }

      return temp->count;
        
}

int main()
{
    string str[]={"hack","hackerrank"};
    Node *root=getNode();
    for(int i=0;i<sizeof(str)/sizeof(str[0]);i++)
    {
        addNode(str[i],root);
    }
    cout<<search("hacker",root)<<endl;
    cout<<search("haco",root);
    return 0;
}