#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int n; //number of vertices
    int **array;
    vector<bool> visited;
public:
    Graph(int n){   
        this->n = n;
        array = new int *[n];
        visited.resize(n, false);
        for (int i=0; i<n; i++){
            array[i] = new int[n];
            for(int j=0; j<n; j++){
                array[i][j]=0;
            }
        }
    }
    void addEdge(int v, int e);
    void printGraph();
    void bfs(int source);
    void dfs(int source);
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
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<array[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void Graph::bfs(int source){
    vector<bool> visited;
    visited.resize(n, false);
    queue<int> queue;
    queue.push(source);
    visited[source] = true;

    while(!queue.empty()){
        int current = queue.front();
        cout<<current<<' ';
        queue.pop();
        for(int i=0; i<n; i++){
            if(array[current][i]==1 && (!visited[i])){
                queue.push(i);
                visited[i]=true;
            }
        }
    }
}

void Graph::dfs(int source){
    cout << source << ' ';
    visited[source] = true;

    for(int i=0; i<n; i++){
        if(array[source][i]==1 && (!visited[i])){
            dfs(i);
        }
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
    cout << "Adjacency Matrix of Undirected Graph:" <<endl;
    g.printGraph();
    cout << "BFS Traversal" << endl;
    g.bfs(0);
    cout << "\nDFS Traversal" << endl;
    g.dfs(0);
    return 0;
}