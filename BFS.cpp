#include<iostream>
#include<cstring>
#include<list>
using namespace std;

class Graph {
    int vertex;
    list<int> *adj;
public:
    Graph(int vertex);
    void addEdge(int src, int dest);
    void BFS(int src);
};

Graph::Graph(int vertex) {
    this->vertex=vertex;
    adj = new list<int>[vertex];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
}

void Graph::BFS(int src) {
    bool *visited =new bool[vertex];
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    visited[src]=true;
    list<int>Queue;
    Queue.push_back(src);
    list<int>::iterator i;
    while(!Queue.empty()) {
        src=Queue.front();
        cout<<src<<" ";
        Queue.pop_front();
        for(i=adj[src].begin();i!=adj[src].end();i++) {
            if(!visited[*i]) {
                visited[*i]=true;
                Queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}
