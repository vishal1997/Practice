#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph {
    int vertex;
    list<int> *adj;
    void topologicalSortUtil(int src, bool visited[], stack<int> &Stack);
public:
    Graph(int vertex);
    void addEdge(int src, int dest);
    void topologicalSort();
};

Graph::Graph(int vertex) {
    this->vertex=vertex;
    adj=new list<int>[vertex];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
}

void Graph::topologicalSort() {
    stack<int> Stack;
    bool *visited=new bool[vertex];
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    for(int i=0;i<vertex;i++)
        if(!visited[i])
            topologicalSortUtil(i,visited, Stack);

    while(!Stack.empty()) {
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
}

void Graph::topologicalSortUtil(int src, bool visited[], stack<int> &Stack) {
    visited[src]=true;
    list<int>::iterator i;
    for(i=adj[src].begin();i!=adj[src].end();i++)
        if(!visited[*i])
            topologicalSortUtil(*i,visited,Stack);
    Stack.push(src);
}

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
}
