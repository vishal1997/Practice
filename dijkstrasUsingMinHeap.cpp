#include<iostream>
#include<climits>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void printArr(int dist[], int n);
struct AdjListNode{
    int dest,
    weight;
    AdjListNode *next;
};

struct AdjList{
    AdjListNode *head;
};

struct minHeapNode{
    int vertex,
    dist;
};

class Graph;
class minHeap;

class minHeap {
private:
    int capacity,
    heapSize;
    minHeapNode **array;
    int *pos;
    friend void dijkstras(Graph& graph,minHeap& heap,int src, int noVertex);
public:
    minHeap(int capacity);
    int parent(int vertex) {return (vertex-1)/2;}
    int left(int vertex) {return (2*vertex) +1 ;}
    int right(int vertex) {return (2*vertex) +2;}
    minHeapNode *extractMin();
    void deleteKey(int vertex);
    void decreaseKey(int vertex, int newDist);
    minHeapNode* insertKey(int vertex, int dist);
    void minHeapify(int vertex);
    int isInMinHeap(int vertex);
    int isEmpty(){return heapSize==0;}
    void swapNode(struct minHeapNode **a, struct minHeapNode **b);
};

class Graph {
private:
    int noVertex;
    struct AdjList *array;
    friend void dijkstras(Graph& graph,minHeap& heap,int src, int noVertex);
public:
    Graph(int noVertex);
    void addEdge(int src, int dest, int weight);
    void printGraph();
    AdjListNode *newAdjListNode(int dest, int weight);
};

void dijkstras(Graph& graph,minHeap& heap,int src, int noVertex);
minHeap::minHeap(int capacity) {
    this->capacity=capacity;
    array=(struct minHeapNode**) malloc(capacity * sizeof(struct minHeapNode*));
    heapSize=0;
    pos=new int[capacity];
}

void minHeap::minHeapify(int vertex) {
    //index of left child
    int leftChild=left(vertex),
    //index of right child
    rightChild=right(vertex),
    //assume smallest value is at given index
    smallest=vertex;
    //if left child exist and value at left is smaller then parent
    if(leftChild < heapSize && array[leftChild]->dist < array[vertex]->dist)
        smallest=leftChild;
    //if right child exist and value at right is smallest than the current smallest value
    if(rightChild < heapSize && array[rightChild]->dist < array[smallest]->dist)
        smallest=rightChild;
    //if smallest value is changed
    if(smallest!=vertex){
        minHeapNode *smallestNode = array[smallest];
        minHeapNode *idxNode = array[vertex];

        // Swap positions
        pos[smallestNode->vertex] = vertex;
        pos[idxNode->vertex] = smallest;

        // Swap nodes
        swapNode(&array[smallest], &array[vertex]);
        minHeapify(smallest);
    }
}

void minHeap::swapNode(struct minHeapNode **a, struct minHeapNode **b)
{
    struct minHeapNode* t = *a;
    *a = *b;
    *b = t;
}

minHeapNode *minHeap:: extractMin() {
    /*if(!isEmpty())
        return NULL;*/
    minHeapNode *node=array[0];
    array[0]=array[heapSize-1];
    pos[node->vertex]=heapSize-1;
    pos[array[0]->vertex]=0;
    heapSize--;
    minHeapify(0);
    return node;
}

minHeapNode* minHeap::insertKey(int vertex, int dist) {
    minHeapNode *newNode=new minHeapNode;
    newNode->vertex=vertex;
    newNode->dist=dist;
    return newNode;
}

void minHeap::decreaseKey(int vertex, int newDist) {
    int index=pos[vertex];
    array[index]->dist=newDist;
    while(index!=0 && array[index]->dist<array[parent(index)]->dist){
        pos[array[index]->vertex]=parent(index);
        pos[array[parent(index)]->vertex] = index;
        swapNode(&array[index], &array[parent(index)]);
        index=parent(index);
    }
}

void minHeap::deleteKey(int vertex) {
    decreaseKey(vertex,INT_MIN);
    extractMin();
}

int minHeap::isInMinHeap(int vertex)
{
   if (pos[vertex] < heapSize)
     return 1;
   return 0;
}

void dijkstras(Graph& graph,minHeap& heap,int src, int noVertex) {
    int dist[noVertex];
    for(int i=0;i<noVertex;i++) {
        dist[i]=INT_MAX;
        heap.array[i]=heap.insertKey(i, dist[i]);
        heap.pos[i]=i;
    }
    heap.array[src]=heap.insertKey(src,dist[src]);
    heap.pos[src]=src;
    dist[src]=0;
    heap.decreaseKey(src,dist[src]);
    heap.heapSize=noVertex;

    while(!heap.isEmpty()) {
        minHeapNode *minValue=heap.extractMin();
        int u=minValue->vertex;
        AdjListNode *ptr =graph.array[u].head;
        while(ptr!=NULL) {
            int v=ptr->dest;
            if(heap.isInMinHeap(v) && dist[u]!=INT_MAX && ptr->weight + dist[u] <dist[v]) {
                dist[v]=dist[u]+ptr->weight;
                heap.decreaseKey(v,dist[v]);
            }
            ptr=ptr->next;
        }
    }
    printArr(dist,noVertex);
}

Graph::Graph(int noVertex){
    this->noVertex=noVertex;
    array=new AdjList[noVertex];
    for(int i;i<noVertex;i++)
        array[i].head=NULL;
}

AdjListNode* Graph::newAdjListNode(int dest, int weight){
    AdjListNode *newNode=new AdjListNode;
    newNode->dest=dest;
    newNode->weight=weight;
    newNode->next=NULL;
    return newNode;
}

void Graph::addEdge(int dest, int src, int weight) {
    AdjListNode *createNode=newAdjListNode(dest, weight);
    createNode->next=array[src].head;
    array[src].head=createNode;

    createNode=newAdjListNode(src,weight);
    createNode->next=array[dest].head;
    array[dest].head=createNode;
}

void Graph::printGraph(){
    for(int i=0;i<noVertex;i++) {
        AdjListNode *ptr=array[i].head;
        cout<<"\nAdjacency list of "<<i<<"\nhead";
        while(ptr) {
            cout<<"->"<<ptr->dest<<"("<<ptr->weight<<")";
            ptr=ptr->next;
        }
    }
}

void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
int V = 9;
    Graph graph(V);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);
    minHeap heap(V);
    dijkstras(graph, heap,0,9);

    return 0;
}
