#include<bits/stdc++.h>
using namespace std;
#define INFINITY 999
int vertices, graph[100][100];
bool visited[100] = {0};
int dist[100];
int parent[100];
int source;

void initialization(){
    for(int i=0; i<vertices; i++){
        dist[i] = INFINITY; 
        parent[i] = i; 
    }
    dist[source] = 0; 
}

int getNearest(){
    int minValue = INFINITY;
    int minNode = 0;
    for(int i=0; i<vertices; i++){
        if(!visited[i] && dist[i]<minValue){
            minValue = dist[i];
            minNode = i;
        }
    }
    return minNode;
}

void dijkstra(){
    for(int i=0; i<vertices; i++){
        int nearest = getNearest();
        visited[nearest] = true;
        for(int adj=0; adj<vertices; adj++){
            if(graph[nearest][adj] != INFINITY && dist[adj] > dist[nearest] + graph[nearest][adj]){ 
                dist[adj] = dist[nearest] + graph[nearest][adj];
                parent[adj] = nearest;
            }
        }

    }
}

void display(){
    cout<<"NODE\t\t\tCost\t\t\tPath";
    cout<<endl;
    for(int i=0; i<vertices; i++){
        cout<<i<<"\t\t\t"<<dist[i]<<"\t\t\t"<<i;
        int parent_node = parent[i];
        while(parent_node != source){
            cout<<" <- "<<parent_node<<" ";
            parent_node = parent[parent_node];
        }
        cout<<endl;
    }
}
int main(){
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    cout<<"Enter the values of edges: ";
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            cin>>graph[i][j];
        }
    }
    cout<<"Enter the source Node: ";
    cin>>source;
    initialization();
    dijkstra();
    display();

}


/*
Sample input: 
6
0 4 999 999 999 8
3 0 11 999 999 3
999 999 0 4 999 999
999 999 999 0 2 7 
999 999 999 3 0 999 
999 999 999 5 4 0
0


Sample Output:
NODE                    Cost                    Path
0                       0                       0
1                       4                       1
2                       15                      2 <- 1
3                       12                      3 <- 5  <- 1
4                       11                      4 <- 5  <- 1
5                       7                       5 <- 1
*/