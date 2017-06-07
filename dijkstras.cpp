#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair <int, int> intPair;

class Graph {
    int vertex;
    list <pair <int,int> > *adj;
public:
    Graph(int vertex);
    void addEdge(int src, int dest, int weight);
    void shortestPath(int s);
};

Graph::Graph(int vertex) {
    this->vertex=vertex;
    adj=new list<intPair>[vertex];
}

void Graph::addEdge(int src, int dest, int weight){
    adj[src].push_back(make_pair(dest,weight));
    adj[dest].push_back(make_pair(src, weight));
}

void Graph::shortestPath(int src) {
    priority_queue<intPair, vector <intPair>, greater<intPair> > pq;
    vector <int> dist(vertex, INF);
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty()) {
        int u=pq.top().second;
        pq.pop();
        list< pair<int, int> >::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();i++) {
            int v=(*i).first;
            int weight=(*i).second;
            if(dist[v] > dist[u]+weight) {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    cout<<endl<<"vertex distance from the source\n";
    for(int i=0;i<vertex;i++)
        cout<<endl<<i<<"\t"<<dist[i];
}
int main()
{
    int vertex = 9;
    Graph g(vertex);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}
