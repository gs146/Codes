#include<stdio.h>
#include<stdlib.h>

int search_min_max(int a[], int start, int end,int * min,int * max)
{
	int  min1, max1,itr=0;
	itr++;
	if(start == end)
	{
		*min = a[start];
		*max = a[end];
			
	}

	else if(start == (end-1) )
	{
		if(a[start] > a[end])
		{
			*max = a[start];
			*min = a[end];
		}
		else
		{
			*min = a[start];
			*max = a[end];
		}
		
	}
	else
	{
	int mid = (start + end)/2;

	// printf("\nasdaa");
	search_min_max(a, start, mid, min, max);
	// printf("\nasdaa");
	search_min_max(a, mid+1, end, &min1, &max1);
	// printf("\nasdaa");
	if(max1 > *max)
	{
		*max = max1;
	}

	if(*min > min1)
	{
		*min = min1;
	}
}
return itr;
// printf("Number of iterations:%d",itr);
}


int main()
{
	int n, min, max, cnt=0, flag=0;
	char input[100];
	printf("How many elements are to be entered:");
	scanf("%s",input);
	int length = strlen(input);

    while(1){
    	flag=0;
    for (int i=0;i<length; i++)
        if (!isdigit(input[i]))
        {
           break;
        }
        else
        {
        	cnt++;
        }
        if(cnt == length)
        	{
        		flag=1;
        		break;
        	}
        printf("OOps! that was an invalid input please enter the number of elements again:");
    	scanf("%s",input);
    	length = strlen(input);
	}

	if(flag == 1)
	{
		int mult=1;
		for(int i = length-1;i >= 0; i--)
    	{
        	n = n + ((int)input[i] -48)*mult;
        	mult = mult*10;
    	}
	}


	int *a = (int *)malloc(sizeof(int)*n);
	
	printf("\nEnter the elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("\nEntered  elements are:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);

	search_min_max(a, 0, n-1, &min, &max);

	printf("\nMin element: %d", min);
	printf("\nMax element: %d", max);
	// printf("Number of iterations:%d",cn);
	free(a);
return 0;
}