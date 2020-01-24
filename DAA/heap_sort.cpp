#include <iostream>
using namespace std;

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[],int n,int i)
{
    int largest = i;
    int  l = 2*i+1;
    int r = 2*i+2;
    
    if(l<n and a[largest] < a[l])
    largest = l;
    
    if(r<n and a[largest]< a[r])
    largest = r;
    
    if(largest!=i)
    {
        my_swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
    
}

void heapsort(int a[],int n)
{
    for(int i=(n/2-1); i>=0; i--)
    {
        heapify(a,n,i);
    }
    
    for(int i  = n-1; i>=0;i--)
    {
        my_swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}


int main() {
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    heapsort(a,n);
    
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
	return 0;
}