#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int n; //number of vertices
    int **array;
public:
    Graph(int n){   
        this->n = n;
        array = new int *[n];
        for (int i=0; i<n; i++){
            array[i] = new int[n];
            for(int j=0; j<n; j++){
                array[i][j]=0;
            }
        }
    }
    void addEdge(int v, int e);
    void printGraph();
};

void Graph::addEdge(int v, int e){
    if(v>n || e>n || v<0 || e<0){
        cout<<"Invalid edge!"<<endl;
    }
    else{
        array[v][e]=1;
        array[e][v]=1;
    }
}

void Graph::printGraph(){
    cout << "Adjacency Matrix of Undirected Graph:" <<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<array[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    int vertices, max_edges, v, e;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    Graph g(vertices);
    max_edges = vertices * (vertices-1);
    for (int i = 0; i < max_edges; i++){
        cout<<"Enter edge (-1 -1 to exit): ";
        cin>>v>>e;
        if(v==-1 && e==-1){
            break;
        }
        g.addEdge(v,e);
    }
    
    g.printGraph();
    return 0;
}