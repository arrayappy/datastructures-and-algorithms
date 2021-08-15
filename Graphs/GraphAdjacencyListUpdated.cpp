#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int vertices;
    vector<list<int> > array;
public:
    Graph(int v){
        array.resize(v);
        vertices = v;
    }
    void addEdge(int v, int e);
    void printGraph();
    void bfs(int source);
    void dfs(int source);
};

void Graph::addEdge(int v, int e){
    array[v].push_front(e);
}

void Graph::printGraph(){
    for(int i=0; i<vertices; i++){
        cout << "|" << i << "| => ";

        for(auto it: array[i]){
            cout <<  "[" <<it << "] -> ";
        }
        cout <<"NULL"<<endl;
    }
}

void Graph::bfs(int source){
    vector<bool> visited;
    visited.resize(vertices, false);
    queue<int> queue;
    queue.push(source);
    visited[source] = true;

    while(!queue.empty()){
        int current = queue.front();
        cout<<current<<' ';
        queue.pop();

        for(auto it: array[current]){
            if(!visited[it]){
                queue.push(it);
                visited[it]=true;
            }
        }
    }
}

void Graph::dfs(int source){
    vector<bool> visited;
    visited.resize(vertices, false);

    if(visited[source]){
        return;
    }
    cout << source << ' ';
    visited[source] = true;

    for(auto it: array[source]){
        dfs(it);
    }
}

int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 5);
    g.addEdge(2, 4);
    cout << endl;
    cout << "Adjacency List of Directed Graph:" <<endl;
    g.printGraph();
    cout << "BFS Traversal" << endl;
    g.bfs(0);
    cout << "\nDFS Traversal" << endl;
    g.dfs(0);
    return 0;
}