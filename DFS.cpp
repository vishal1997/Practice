#include<iostream>
#include<list>

using namespace std;

class Graph {
    int vertex;
    list<int> *adj;
    void dfsUtil(int src, bool visited[]);
public:
    Graph(int vertx);
    void DFS(int src);
    void addEdge(int src, int dest);
};

Graph::Graph(int vertex) {
    this->vertex=vertex;
    adj=new list<int>[vertex];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
}

void Graph::DFS(int src) {
    bool *visited =new bool[vertex];
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    dfsUtil(src,visited);
}

void Graph::dfsUtil(int src, bool visited[]) {
    visited[src]=true;
    cout<<src<<" ";
    list<int>::iterator i;
    for(i=adj[src].begin();i!=adj[src].end();i++) {
        if(!visited[*i])
            dfsUtil(*i,visited);
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}
