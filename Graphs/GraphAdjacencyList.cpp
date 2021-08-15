#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int vertices;
    vector<list<int> > array;
    vector<bool> visited;
    queue<int> queue;
public:
    Graph(int v){
        array.resize(v);
        vertices = v;
        visited.resize(v, false);
    }

    void addEdge(int v, int e){
        array[v].push_front(e);
    }

    void printGraph(){
        cout << "Adjacency List of Directed Graph:" <<endl;
        for(int i=0; i<vertices; i++){
            cout << "|" << i << "| => ";

            for(auto it: array[i]){
                cout <<  "[" <<it << "] -> ";
            }
            cout <<"NULL"<<endl;
        }
    }

    void bfsTraversal(){
        cout << "BFS Traversal" << endl;
        for(int i = 0; i < vertices; i++){
            bfs(i);
        }
        cout << endl;
    }

    void bfs(int source){
        queue.push(source);
        visited[source] = true;

        while(!queue.empty()){
            int current = queue.front();
            cout << current << ' ';
            queue.pop();

            for(auto it: array[current]){
                if(!visited[it]){
                    queue.push(it);
                    visited[it] = true;
                }
            }
        }
    }

    void dfsTraversal(){
        cout << "DFS Traversal" << endl;
        for(int i = 0; i < vertices; i++){
            dfs(i);
        }
        cout << endl;
    }

    void dfs(int source){
        if(visited[source]){
            return;
        }
        cout << source << ' ';
        visited[source] = true;

        for(auto it: array[source]){
            dfs(it);
        }
    }
};

int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 5);
    g.addEdge(2, 4);
    cout << endl;
    g.printGraph();
    g.dfsTraversal();
    g.bfsTraversal();
    return 0;
}