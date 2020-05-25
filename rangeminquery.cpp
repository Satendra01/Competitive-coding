#include<bits/stdc++.h>
using namespace std;


int createSegTree(int segtree[],int arr[],int index,int l,int h)
{
	if(l==h)
		{segtree[index]=arr[l];return arr[l];}
	int mid=(l+h)/2;
	int left=createSegTree(segtree,arr,2*index+1,l,mid);
	int right=createSegTree(segtree,arr,2*index+2,mid+1,h);
	int val=min(left,right);
	segtree[index]=val;
	return segtree[index];
}
int minquery(int tree[],int lazytree[],int index,int lindex,int rindex,int l,int r)
{
    if(lazytree[index]!=0)
    {
        tree[index]+=lazytree[index];
        if(lindex!=rindex)
        {
            lazytree[2*index+1]+=lazytree[index];
            lazytree[2*index+2]+=lazytree[index];
        }
        lazytree[index]=0;
    }
	if(rindex<l or r<lindex)
		return INT_MAX;
	int mid=(lindex+rindex)/2;
	if(l<=lindex && r>=rindex)
		return tree[index];
	else
		return min(minquery(tree,lazytree,2*index+1,lindex,mid,l,r),minquery(tree,lazytree,2*index+2,mid+1,rindex,l,r));
	
}

int lazyrangeupdate(int lazytree[],int segtree[],int index,int lindex,int rindex,int l,int r,int val)
{
    

    if(lazytree[index]!=0)
    {
        segtree[index]+=lazytree[index];
        if(lindex!=rindex)
        {
            lazytree[2*index+1]+=lazytree[index];
            lazytree[2*index+2]+=lazytree[index];
        }
        lazytree[index]=0;
    }

    if(l>rindex or r<lindex)
    return segtree[index];

    if(lindex>=l && rindex<=r)
    {
        segtree[index]+=val;
        if(lindex!=rindex)
        {
            lazytree[2*index+1]+=val;
            lazytree[2*index+2]+=val;
        }
        return segtree[index];
    }
        
    
    int mid=(lindex+rindex)/2;
    int left=lazyrangeupdate(lazytree,segtree,2*index+1,lindex,mid,l,r,val);
    int right=lazyrangeupdate(lazytree,segtree,2*index+2,mid+1,rindex,l,r,val);
    segtree[index]=min(left,right);
    return segtree[index];


}
int main()
{
	int n=7;
	int arr[]={5,1,7,3,9,6,2};
	int segtree[4*7+1];
    int lazytree[4*n+1];
	memset(segtree,INT_MAX,sizeof(segtree));
    memset(lazytree,0,sizeof(lazytree));
	int index=0,l=0,h=6;
	createSegTree(segtree,arr,index,l,h);
    lazyrangeupdate(lazytree,segtree,index,0,n-1,1,3,3);
	int minval=minquery(segtree,lazytree,index,0,n-1,2,6);

	cout<<minval;
}