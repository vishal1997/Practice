#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    int vertex;
    list<int> *adj;
public:
    Graph(int vertex);
    void addEdge(int src, int dest);
    void centrality();
};

Graph::Graph(int vertex) {
    this->vertex=vertex;
    adj = new list<int>[vertex];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
    //adj[dest].push_back(src);
}

void Graph::centrality() {
    vector <float> bCentrality(vertex,0);
    for(int src=0;src<vertex;++src) {
        stack <int> S;
        //printf("\n%d",src);
        list<int> P[vertex];
        vector<int> sigma(vertex,0);
        sigma[src]=1;
        vector <int> dist(vertex,-1);
        dist[src]=0;
        list <int> Q;
        Q.push_back(src);
        list <int>::iterator w;
        while(!Q.empty()) {
            int v=Q.front();
            Q.pop_front();
            S.push(v);
            for(w=adj[v].begin();w!=adj[v].end();w++) {
                if(dist[*w]<0) {
                    Q.push_back(*w);
                    dist[*w]=dist[v]+1;
                }
                if(dist[*w]=dist[v]+1) {
                    sigma[*w]=sigma[*w]+sigma[v];
                    P[*w].push_back(v);
                }
            }
        }
        vector <float> delta(vertex,0.0);
        list<int> :: iterator v;
        while(!S.empty()) {
            int w=S.top();
            S.pop();
            for(v=P[w].begin();v!=P[w].end();v++) {
                delta[*v]=delta[*v]+(float)(sigma[*v]/sigma[w])*(1+delta[w]);
            }
            if(w!=src)
                bCentrality[w]=bCentrality[w]+delta[w];
        }
    }
    for(int i=0;i<vertex;i++) {
        cout<<endl<<i<<"\t"<<bCentrality[i];
    }
}

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,6);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.centrality();
    return 0;
}
