#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

struct edge1
{
    int src, dest, weight;
};

struct graph1
{
    int v,e;
    struct edge1* edge;
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------

struct graph1* create_graph(int v, int e)
{
    struct graph1* graph = (struct graph1*)malloc(sizeof(struct graph1));
    
    graph->v = v;
    graph->e = e;

    graph->edge = (struct edge1*)malloc(e*sizeof(struct edge1));

    return graph;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Bellman_Ford(struct graph1* graph, int src)
{
    int v,e;
    v = graph->v;
    e = graph->e;

    int distance[v];

    for(int i=0;i<v;i++)
    distance[i] = INT_MAX;

    distance[src] = 0;

    for(int i=1; i<=v-1; i++)
    {
        for(int j=0; j<e; j++)
        {
            int s,d,w;
            s = graph->edge[j].src;
            d = graph->edge[j].dest;
            w = graph->edge[j].weight;
            
            if(distance[s]!=INT_MAX && distance[s] + w < distance[d])
                distance[d] = distance[s] + w;
        }
    }

    int f = 0;
    for(int i=0;i<e;i++)
    {
        int s,d,w;
            s = graph->edge[i].src;
            d = graph->edge[i].dest;
            w = graph->edge[i].weight;

            if(distance[s] != INT_MAX && distance[s] + w < distance[d])
            {
                printf("\n----Graph is having negative cycle----\n");
                f = 1;
            }
    }
    
    if(f == 0){
    printf("\n\nVertex\tDistance from source\n");

    for(int i=0;i<v;i++)
    {
        if(distance[i] == INT_MAX)
			printf("%d\tUnreachable -_-\n",i);
        else
            printf("%d\t%d\n",i,distance[i]);
    }
    }

}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
int input()
{
	int tmp;
	while(1)
        {	            
        if(scanf("%d",&tmp)!=1 ||  tmp <= 0)
        {
            char c;
            while((c = getchar()) != EOF && c != '\n');
            printf("\nYou gave wrong input--enter integers only :");	                		
        }
        else
            break;
        }
	return tmp;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    int edges,vertices;
    printf("\nEnter the number of Edges: ");
    edges = input();

    printf("\nEnter the number of Vertices: ");
    vertices = input();

    struct graph1* graph = create_graph(vertices, edges);

    for(int i=0;i<edges;i++)
    {
        printf("\nEnter source | destination | weight for vertex %d: ",i+1);
        scanf("%d",&graph->edge[i].src);
        scanf("%d",&graph->edge[i].dest);
        scanf("%d",&graph->edge[i].weight);
    }

    int s;
    printf("\nEnter one source node:");
    scanf("%d",&s);
    Bellman_Ford(graph, s);

    free(graph);
    return 0;   
    
}
