#include<stdio.h>

struct find
{
	int min, max;
};


struct find search_min_max(int a[], int start, int end)
{
	struct find f1, f2, f3;

	if(start == end)
		{
			f1.min = a[start];
			f1.max = a[end];
			return f1;
		}

	if((end+1) == 2 )
	{
		if(a[start] >= a[end])
		{
			f1.max = a[start];
			f1.min = a[end];
		}
		else
		{
			f1.min = a[start];
			f1.max = a[end];
		}
		return f1;
	}
	int mid = (start + end)/2;
	f2 = search_min_max(a, start, mid);
	f3 = search_min_max(a, mid+1, end);

	if(f2.min < f3.min)
	{
		
	}
}


int main()
{
	struct find answer;
	int n;
	printf("How many elements are to be entered:");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("\nEntered  elements are:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);

	answer = search_min_max(a, 0, n-1);

	printf("\nMin element: %d", answer.min);
	printf("\nMax element: %d", answer.max);
return 0;
}