#include<stdio.h>
#include<stdlib.h>

struct jobs
{
	int id;
	double rt;
	char name[2];
	int size;
};


//heapsort

void my_swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int a[],int n,struct jobs *jb,int i )
{
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	// printf("%d " , jb[largest]);
	// printf("%d l: ",jb[a[l]].size );
	if(l<n && jb[a[largest]].size < jb[a[l]].size)
		{largest = l; }
	if(r<n && jb[a[largest]].size < jb[a[r]].size)
		{ largest = r; }
	if(largest != i)
	{
		my_swap(&a[i], &a[largest]);
		heapify(a,n,jb,largest);
	}
}

void heapsort(int a[], int n, struct jobs *jb)
{
	for(int i=(n/2-1);i>=0;i--)
	{
		heapify(a,n,jb,i);
	}

	for(int i=n-1;i>=0;i--)
	{
		my_swap(&a[0],&a[i]);
		heapify(a,i,jb,0);
	}

}


double my_optimal_tape(struct jobs *jb , int t, int n)
{
	// char *s;
	int *a;
	a = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		a[i] = i;
	}

	heapsort(a,n,jb);

	printf("\n heapsort:\n\n");
	for(int i =0;i<n;i++)
	{
		printf("id: %c\t",jb[a[i]].name[0]);
		printf("size: %d\n",jb[a[i]].size);
	}
	printf("\n\n\n");

	int row = t,col = 0;
	if(n%t == 0)
		col = n/t;

	else
		col = (n/t)+1;

	int *matrix;

	matrix = (int*)malloc(row*col*sizeof(int));

	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			*(matrix + i*col + j) = '-';

	int k = 0;
	double cnt = 0;
	for(int i=0;;i++)
	{
		for(int j=0; j<row;j++)
		{
			*(matrix+j*col+i) = a[k];
			if(i == 0)
			{
				jb[a[k]].rt = jb[a[k]].size;
				cnt+=jb[a[k]].rt;
			}
			else
			{
				jb[a[k]].rt =  jb[a[k]].size + jb[*(matrix + (j)*col +i-1)].rt;
				cnt += jb[a[k]].size;
			}
			k++;
			// printf("CNT:%d",cnt);
			if(k==n)
				break;
		}
		if(k==n)
			break;
	}

	int f=0;
	printf("\n\nTAPE STORAGE:\n");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%c  ",jb[*(matrix+i*col+j)].name[0]);
			// f++;
			// if(f == n)
			// 	break;
		}
		printf("\n");
		// if(f==n)
			// break;
	}
	// printf("cnt: %d",cnt);
	
	free(matrix);
	result(jb,cnt,n);
	return cnt;

}


void result(struct jobs *jb, double cnt, int n)
{
	printf("\nID\tName\tSize\tRetrievel Time\n");

	for(int i=0;i<n;i++)
	{
		printf("%d\t%s\t%d\t%.2f\n",jb[i].id, jb[i].name, jb[i].size, jb[i].rt);

	}
	// free(jb);
	
}

int input()
{
	int tmp;
	while(1)
	            {
	            
	            if(scanf("%d",&tmp)!=1 ||  tmp <= 0)
	            {
	                char c;
	                while((c = getchar()) != EOF && c != '\n');
	                printf("Enter integers only\n");
	                		
	            }
	            else
	                break;
	            }
	return tmp;
}


int main()
{
	int ch,tmp,n,t;
	while(1)
	{
		double cnt;
		struct jobs *jb;
		printf("\n1. Input jobs to be stored on multi-tape \n2. Calculate retrieval time \n3.Exit \n Enter your choice:");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:

            	if(n)
            		free(jb);

            	printf("Enter number of tapes:\n");
	            t = input();

	            printf("Enter number of jobs/programs:\n");
	            n = input();            


            	
            	jb = (struct jobs*)malloc(n*sizeof(struct jobs));

            	for(int i=0;i<n;i++)
            	{
            		jb[i].id = i;
            		printf("\n\nEnter the job name:");
            		getchar();
            		scanf("%c" ,&jb[i].name);
            		printf("\nEnter the job size:");
            		jb[i].size = input();

            		// scanf("%d" ,&jb[i].size);
            	}
            	//here jobs and tapes are equal
            	if(n <= t)
            	{
            		 
            		for(int i=0; i<n;i++)
            		{
            			jb[i].rt = jb[i].size;
            			cnt += jb[i].size;            			
            		}
            		printf("\nTape Storage\n");
            		for(int i=0; i<n;i++)
            			printf("%c\n", jb[i].name[0]);

            		result(jb, cnt, n);

            	}
            	else
            		cnt = my_optimal_tape(jb , t, n);
            	
            break;
            case 2:
            printf("\n\n Average retrieval time for all jobs: %.2f",cnt/n);
            break;

            case 3:
            if(jb!=NULL)
            	free(jb);
            exit(0);
		}

 }
	return 0;
}