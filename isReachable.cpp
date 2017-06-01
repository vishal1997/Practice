#include<iostream>
#include <list>
#include <vector>
using namespace std;

class SafeMap {
    int V;
    list <int> *adj;
public:
    SafeMap(int V);
    void addSafeRoute(int src, int dest);
    int isReachable(int s, int d);
};

SafeMap::SafeMap(int V)
{
    this->V = V;
    adj = new list<int> [V];
}

void SafeMap::addSafeRoute(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.
}

// Function to check if S is safely reachable from D
int SafeMap::isReachable(int s, int d)
{


     // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;
    vector<int> dist(V,0);
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // it will be used to get all adjacent vertices of a vertex accesible thru
    // a safe route
    list<int>::iterator i;
   //Write your code below this line
    while (!queue.empty()) {
        s=queue.front();
        if(d==s)
            return dist[d];
        queue.pop_front();
        for(i=adj[s].begin();i!=adj[s].end();i++) {
            if(!visited[*i]) {
                visited[*i]=true;
                dist[*i]=dist[s]+1;
                queue.push_back(*i);
            }
            if(d== *i)
                    return dist[*i];
        }
    }
    return -1;

}


int main()
{
    int vertex = 8;
    SafeMap g(vertex);
    g.addSafeRoute(5,1);
    g.addSafeRoute(1,5) ;
    g.addSafeRoute(7,7) ;
    g.addSafeRoute(3,3) ;
    g.addSafeRoute(5,2) ;
    g.addSafeRoute(7,5) ;
    g.addSafeRoute(4,1) ;
    g.addSafeRoute(1,6) ;
    g.addSafeRoute(5,7) ;
    g.addSafeRoute(3,2) ;
    /*
    g.addSafeRoute(0, 1);
    g.addSafeRoute(0, 7);
    g.addSafeRoute(1, 2);
    g.addSafeRoute(1, 7);
    g.addSafeRoute(2, 3);
    g.addSafeRoute(2, 8);
    g.addSafeRoute(2, 5);
    g.addSafeRoute(3, 4);
    g.addSafeRoute(3, 5);
    g.addSafeRoute(4, 5);
    g.addSafeRoute(5, 6);
    g.addSafeRoute(6, 7);
    g.addSafeRoute(6, 8);
    g.addSafeRoute(7, 8);*/
    int d=g.isReachable(1,7);
    if(d==-1)
        cout<<"Not reachable";
    else
        cout<<"Reachable distance="<<d;

    return 0;
}
