#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b);
class Heap{
    int capacity;
    int *arr;
    
    public:
    int size;
    Heap(int capacity);
    void insert(int key);
    int extractMax();
    void maxHeapify(int index);
};
Heap::Heap(int capacity)
{
    this->capacity=capacity;
    size=0;
    arr=new int[capacity];
}
void Heap:: insert(int key)
{
    size+=1;
    if(size>capacity)
    {cout<<"overflow";return;}
    arr[size]=key;
    int index=size;
    while(index>1 && arr[index/2]<arr[index])
    {
        swap(&arr[index/2],&arr[index]);
        index=index/2;
    }
}
int Heap::extractMax()
{
    if(size==0)
    {cout<<"overflow";return -1;}
    int max=arr[1];
    swap(&arr[size],&arr[1]);
    size--;
    maxHeapify(1);
    return max;
}
void Heap::maxHeapify(int index)
{
    int left=2*index;
    int right=2*index+1;
    int maxindex=index;
    if(index<=size && arr[left]>arr[maxindex])
    maxindex=left;
    if(index<=size && arr[right]>arr[maxindex])
    maxindex=right;
    if(maxindex!=index)
    {
        swap(&arr[index],&arr[maxindex]);
        maxHeapify(maxindex);
    }
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int capacity=30;
    Heap heap(capacity);
    
    
    cout<<heap.extractMax()<<endl;
    cout<<heap.extractMax()<<endl;
    return 0;
}