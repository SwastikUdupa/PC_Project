#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<stdbool.h>
// Number of vertices in the graph
int V;

void printSolution(int color[]);

/* Function to check if the color can be safely assigned */

bool isSafe (int v, int graph[][100], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i]==1 && c == color[i])
            return false;
    return true;
}


bool graphColoringUtil(int graph[][100], int m, int color[], int v)
{
    /* return true if all vertices have been assigned some color */
    if (v == V)
        return true;

    /* for all colors from color 1 to m */
    for (int c = 1; c <= m; c++)
    {
        /* Check if assignment of color c to v is fine*/
        if (isSafe(v, graph, color, c))
        {
           color[v] = c;

           /* recur to assign colors to rest of the vertices */
           if (graphColoringUtil (graph, m, color, v+1) == true)
             return true;

            /* if the color c cannot be assigned */
           color[v] = 0;
        }
    }

    /* return false if no assignment is possible */
    return false;
}



bool graphColoring(int graph[][100], int m)
{
    // Initialize all color values as 0.
    int *color = new int[V];
    for (int i = 0; i < V; i++)
       color[i] = 0;

    bool ret=false;
    if (graphColoringUtil(graph, m, color, 0 ) == false)
    {
      printf("Solution does not exist");
      return false;
    }

    printSolution(color);
    return true;
}

void printSolution(int color[])
{
    printf("Solution Exists:"
            " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
      printf(" %d ", color[i]);
    printf("\n");
}

int main()
{

    printf("Enter Number of vertices\n");
    scanf("%d",&V);
    int graph[100][100];
/* Example Graph
    (3)---(2)
     |   / |
     |  /  |
     | /   |
    (0)---(1)
    {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
*/
    printf("Enter Adjacency Matrix\n");

    for(int i=0;i<V;i++)
    {
      for (int j=0;j<V;j++)
      {
        scanf("%d", &graph[i][j]);
      }
    }
    printf("Enter Number of colours\n");
    int m;
     // Number of colors
     scanf("%d", &m);
    graphColoring (graph, m);
    return 0;
}
