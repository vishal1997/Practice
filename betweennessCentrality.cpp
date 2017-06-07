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
    adj[src].push_back(dest);                   //create adjacent list
    adj[dest].push_back(src);
}

void Graph::centrality() {
    vector <float> bCentrality(vertex,0);       //initialize betweenness centrality with 0 for all vertex
    for(int src=0;src<vertex;++src) {
        stack <int> S;
        list<int> P[vertex];                    //list of all the predecessors of each vertex
        vector<int> sigma(vertex,0);            //No. of shortest path
        sigma[src]=1;                           //No.of shortest path where vertex 'src' lies
        vector <int> dist(vertex,-1);           //total distance from src to dest
        dist[src]=0;
        list <int> Q;                           //create a Queue
        Q.push_back(src);                       //enqueue the current node
        list <int>::iterator w;                 //w is a iterator, to get all the adjacent vertex
        while(!Q.empty()) {
            int v=Q.front();
            Q.pop_front();                      //dequeue a vertex
            S.push(v);                          //push the same vertex in stack which will be used for calculating the dependencies

            //get all the adjacent vertex
            for(w=adj[v].begin();w!=adj[v].end();w++) {
                //if the distance is less than zero than enqueue the adjacent vertex
                //distance of the adjacent from the src = distance of its predecessor + 1
                if(dist[*w]<0) {
                    Q.push_back(*w);
                    dist[*w]=dist[v]+1;
                }
                //if the distance of successor is equal to distance of predecessor +1 than
                //No. of shortest path where a vertex lies equals the sum of the no. of shortest path(current) and No. of shortest path of its predecessor
                //append the predecessor to the list of predecessor for the vertex
                if(dist[*w]==dist[v]+1) {
                    sigma[*w]=sigma[*w]+sigma[v];
                    P[*w].push_back(v);
                }
                //cout<<endl<<adj[v].size();
            }
        }
        vector <float> delta(vertex,0.0);
        list<int> :: iterator v;
        while(!S.empty()) {
            int w=S.top();              //get the vertex in non-increasing order
            S.pop();                    //pop the vertex
            //get all the predecessor of the vertex
            for(v=P[w].begin();v!=P[w].end();v++)
                delta[*v]=delta[*v]+(float)(sigma[*v]/sigma[w])*(1+delta[w]);
            if(w!=src)
                bCentrality[w]=bCentrality[w]+delta[w];
        }
    }
    for(int i=0;i<vertex;i++)
        cout<<endl<<i<<"\t"<<bCentrality[i]/2;
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
    Graph g2(9);
    cout<<"\nGraph 2";
    g2.addEdge(0, 1);
    g2.addEdge(0, 7);
    g2.addEdge(1, 2);
    g2.addEdge(1, 7);
    g2.addEdge(2, 3);
    g2.addEdge(2, 8);
    g2.addEdge(2, 5);
    g2.addEdge(3, 4);
    g2.addEdge(3, 5);
    g2.addEdge(4, 5);
    g2.addEdge(5, 6);
    g2.addEdge(6, 7);
    g2.addEdge(6, 8);
    g2.addEdge(7, 8);
    g2.centrality();
    return 0;
}
