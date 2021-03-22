/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<climits>
#include<iostream>
using namespace std;
int min_distance_vertex(int* dist,bool* visited,int n)
{
    int mindis=INT_MAX;
    int min_i=-1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            if(dist[i]<mindis)
            {
                mindis=dist[i];
                min_i=i;
            }
        }
    }
    return min_i;
}
void Dijkstra(int** graph,int n,int* dist)
{
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    dist[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int min_index=min_distance_vertex(dist,visited,n);
        visited[min_index]=true;
        for(int j=0;j<n;j++)
        {
            if(graph[min_index][j]!=0&&visited[j]==false)
            {
                int current_distance=dist[min_index]+graph[min_index][j];
                if(current_distance<dist[j])
                    dist[j]=current_distance;
            }
        }
    }
    delete[] visited;
    return;
}
int main()
{
    int V, E;
    cin >> V >> E;
    int** graph=new int*[V];
    for(int i=0;i<V;i++)
    {
        graph[i]=new int[V];
        for(int j=0;j<V;j++)
            graph[i][j]=0;
    }
    for(int i=0;i<E;i++)
    {
        int fv,sv,wt;
        cin>>fv>>sv>>wt;
        graph[fv][sv]=wt;
        graph[sv][fv]=wt;
    }
    int* distance=new int[V];
    for(int i=0;i<V;i++)
        distance[i]=INT_MAX;
    Dijkstra(graph,V,distance);
    for(int i=0;i<V;i++)
        cout<<i<<" "<<distance[i]<<endl;
    delete[] distance;
    for(int i=0;i<V;i++)
     delete[] graph[i];
    delete[] graph;
    return 0;
}

