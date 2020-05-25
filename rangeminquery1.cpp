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
int minquery(int tree[],int index,int lindex,int rindex,int l,int r)
{
	if(rindex<l or r<lindex)
		return INT_MAX;
	int mid=(l+r)/2;
	if(l<=lindex && r>=rindex)
		return tree[index];
	else
		return min(minquery(tree,2*index+1,lindex,mid,l,r),minquery(tree,2*index+2,mid+1,rindex,l,r));
	
}
int main()
{
	int n=7;
	int arr[]={5,1,7,3,9,6,2};
	int segtree[4*7+1];
	memset(segtree,INT_MAX,sizeof(segtree));
	int index=0,l=0,h=6;
	createSegTree(segtree,arr,index,l,h);
	int minval=minquery(segtree,index,0,n-1,2,5);
	cout<<minval;
}