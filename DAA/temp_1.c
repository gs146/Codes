#include<stdio.h>
#include<stdlib.h>

int search_min_max(int a[], int start, int end,int * min,int * max, int *c)
{
	int  min1, max1;
	
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
	*c += 1;
		
	}
	else
	{
	int mid = (start + end)/2;

	search_min_max(a, start, mid, min, max, c);
	search_min_max(a, mid+1, end, &min1, &max1, c);

	if(max1 > *max)
	{
		*max = max1;
	}
	*c += 2;
	if(*min > min1)
	{
		*min = min1;
	}
}
}


int main()
{
	int n=0, c, min, max, tmp,x,ch;
	int *a=NULL;	

	while(1)
	{
		printf("\n1. Input list \n2. Find min-max \n3.Exit \nEnter your choice:");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
			if(n)
				free(a);


            while(1)
            {
            printf("Enter size of array\n");
            if(scanf("%d",&tmp)!=1 ||  tmp <= 0)
            {
                char c;
                while((c = getchar()) != EOF && c != '\n');
                printf("Enter integers only\n");
                		
            }
            else
                break;
            }
 
            n=tmp;
            a=(int*)malloc(n*sizeof(int));
 			
 
            printf("Enter the values\n");
            for(int i=0;i<n;i++)
            {
                if(scanf("%d", &tmp) != 1) {
					char c;
					while((c = getchar()) != EOF && c != '\n');
					printf("\nEnter integers only!\n");
					break;
                }
                else
                {
                    a[i]=tmp;
                }
            }
                break;

            case 2:
            if(n>0)
					{
					    c=0;
						search_min_max(a,0,n-1,&min,&max,&c);
						printf("MAX-%d,MIN-%d,COUNT-%d\n",max,min,c);
					}
					else{
						printf("Please enter input first!!!!!\n");
					free(a);
					}
					break;
			case 3:
					if(a!=NULL)
						free(a);
					return 0;
		}
	}
	return 0;
}