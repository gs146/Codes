#include<iostream>

using namespace std;


int if_sorted(int a[], int l)
{
    if(l==1)
        return 1;

    else
    {
        return(a[l-1]<a[l-2]?0:if_sorted(a,l-1));
    }                          
}                               

int main()                      
{                               
    int a[] = {1,2,10,8};      
    int l=sizeof(a)/sizeof(int);  
    printf("lenght: %d\n", l);    
    int m = if_sorted(a,l);
    
    printf("\n%d",m);             
    return 0;                   
}                               