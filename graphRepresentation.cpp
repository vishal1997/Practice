#include<iostream>
using namespace std;

struct AdjListNode{
    int dest;
    struct AdjListNode *next;
};

struct AdjList {
    struct AdjListNode *head;
};

class Graph {
private:
    int noVertex;
    struct AdjList *array;
public:
    Graph(int noVertex);
    void addEdge(int src, int dest);
    AdjListNode *newAdjListNode(int dest);
    void printGraph();
};

Graph::Graph(int noVertex) {
    this->noVertex=noVertex;
    array=new AdjList[noVertex];
    for(int i=0;i<noVertex;i++)
        array[i].head=NULL;
}

AdjListNode* Graph::newAdjListNode(int dest) {
    AdjListNode *newNode=new AdjListNode;
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}



void Graph::addEdge(int src, int dest) {
    AdjListNode *newNode=newAdjListNode(dest);
    newNode->next=array[src].head;
    array[src].head=newNode;

    newNode=newAdjListNode(src);
    newNode->next=array[dest].head;
    array[dest].head=newNode;
}

void Graph::printGraph(){
    for(int i=0;i<noVertex;i++) {
        AdjListNode *ptr=array[i].head;
        cout<<"\nAdjacency list of "<<i<<"\nhead";
        while(ptr) {
            cout<<"->"<<ptr->dest;
            ptr=ptr->next;
        }
    }
}

int main()
{
    Graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);

    // print the adjacency list representation of the above graph
    gh.printGraph();

    return 0;
}
