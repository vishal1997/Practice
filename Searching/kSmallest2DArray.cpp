/*
Problem Statement: Given an n x n matrix, where every row and column is sorted in non-decreasing order.
Find the kth smallest element in the given 2D array.

eg.     10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50
The 3rd smallest element is 20 and 7th smallest element is 30

Algorithm:

    The idea is to use min heap. Following are detailed step.
    1) Build a min heap of elements from first row. A heap entry also stores row number and column number.
    2) Do following k times.
        …a) Get minimum element (or root) from min heap.
        …b) Find row number and column number of the minimum element.
        …c) Replace root with the next element from same column and min-heapify the root.
    3) Return the last extracted root.


*/


#include<bits/stdc++.h>
#define ROW 4
#define COL 4
using namespace std;

struct heapNode {
    int row,
    col,
    val;
};
//left index
int left(int i){
    return 2*i + 1;
}
//right index
int right(int i) {
    return 2*i + 2;
}
//swap two heap node
void swapNode(heapNode *node1 , heapNode * node2) {
    heapNode temp=*node1;
    *node1= *node2;
    *node2= temp;
}
//function to satisfy min heap property
void heapify(heapNode head[], int i, int heapSize) {
    int smallest=i;
    int l=left(i);
    int r=right(i);
    if(l<heapSize && (head[l].val < head[smallest].val))
        smallest=l;
    if(r<heapSize && (head[r].val < head[smallest].val))
        smallest=r;
    if(smallest!=i){
        swapNode(&head[i],&head[smallest]);
        heapify(head,smallest,heapSize);
    }
}



//return kth smallest number in 2D sorted array(row and col wise sorted)
int kSmallest(int arr[ROW][COL], int len, int k) {
    //if k is invalid return
    if(k<=0 || k>len*len)
        return -1;

    //create an array for heap
    heapNode head[len];
    //insert first row in heap;
    for(int i=0;i<len;i++){
        head[i].val=arr[0][i];
        head[i].row=0;
        head[i].col=i;
        //cout<<"\n"<<head[i].val<<" "<<head[i].row<<" "<<head[i].col;
    }
    //temp node to store the current min.
    heapNode node;
    for(int i=0;i<k;i++) {
        node=head[0];
        //cout<<"\n"<<node.val<<" "<<node.row<<" "<<node.col;

        int nextValue=((node.row)+1 < len ) ? arr[(node.row)+1][node.col]: INT_MAX;
        //cout<<"\n"<<nextValue;
        head[0].val=nextValue;
        head[0].row=(node.row)+1;
        head[0].col=node.col;
        heapify(head,0,len);
    }
    /*for(int i=0;i<len;i++)
        cout<<"\n"<<head[i].val;*/
    return node.val;
}


int main()
{
  int mat[ROW][COL] ={ {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  cout << "7th smallest element is " << kSmallest(mat, 4, 7);
  return 0;
}
