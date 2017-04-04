#include<stdio.h>
#include<stdlib.h>
struct adjListNode *createNode(int dest);
struct Graph *createGraph(int v) ;
void addEdge(struct Graph *graph, int src, int dest) ;
void printGraph(struct Graph *graph);
struct adjListNode {
    struct adjListNode *next;
    int dest;
};

struct adjList {
    struct adjListNode *head;
};

struct Graph {
    int v;
    struct adjList *array;
};

int main() {
    int v;
    printf("\nEnter the no. of nodes:");
    scanf("%d",&v);
    struct Graph *graph=createGraph(v);
    if(!graph)
        return -1;
    addEdge(graph,0,1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);
    return 0;
}

struct adjListNode *createNode(int dest) {
    struct adjListNode *newNode=(struct adjListNode*)malloc(sizeof(struct adjListNode*));
    if(!newNode) {
        printf("\nNo more Space");
        return NULL;
    }
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}

struct Graph *createGraph(int v) {
    struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
    if(!graph) {
        printf("\nNo more space");
        return NULL;
    }
    graph->v=v;
    graph->array=(struct adjList *)malloc(v*sizeof(struct adjList));
    if(!graph->array) {
        printf("\nNo more space");
        return NULL;
    }
    int i;
    for(i=0;i<v;i++)
        graph->array[i].head=NULL;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    struct adjListNode *newNode=(struct adjListNode *)malloc(sizeof(struct adjListNode));
    newNode=createNode(dest);
    if(!newNode)
        return;
    newNode->next=graph->array[src].head;
    graph->array[src].head=newNode;

    newNode=createNode(src);
    if(!newNode)
        return;
    newNode->next=graph->array[dest].head;
    graph->array[dest].head=newNode;
}


void printGraph(struct Graph *graph) {
    int i;
    for(i=0;i<graph->v;i++) {
        struct adjListNode *copy=graph->array[i].head;
        printf("\nAdjacency List of vertex %d\nhead",i);
        while(copy) {
            printf("->%d",copy->dest);
            copy=copy->next;
        }
        printf("\n");
    }
}


