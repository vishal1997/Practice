#include<iostream>
#include<climits>
using namespace std;
void swapInt(int *a, int *b);

class minHeap{
    int *array;
    int capacity;   //capacity of heap
    int heapSize;   //size of array
public:
    //initialize variables
    minHeap(int capacity){
    this->capacity=capacity;
    heapSize=0;
    //allocate space for heap
    array=new int[capacity];
    }
    int getMin(){return array[0];}
    void decreaseKey(int index, int newKey);
    void deleteKey(int index);
    int extractMin();
    void insertKey(int key);
    int left(int index){return (2*index) +1 ;}
    int right(int index) {return (2*index) +2;}
    int parent(int index ){return (index-1)/2;}
    void minHeapify(int index);
};

/*
Function to insert a new value in heap
*/
void minHeap::insertKey(int key) {
    //if no space left in the heap return Overflow
    if(heapSize==capacity){
        cout<<"\nOverFLow\n";
        return;
    }
    //new value to be added so increase the size of heap by 1
    heapSize++;
    int index=heapSize-1;
    //insert the value at last index
    array[index]=key;
    //if last index is 0 then it satisfies the heap property, so no need to do anything

    //if last index is not 0 than satisfy the heap property
    while(index !=0 && array[index]<array[parent(index)]){
        swapInt(&array[index], &array[parent(index)]);
        index=parent(index);
    }
}
/*
Function to remove and return the min value in heap
*/
int minHeap::extractMin() {
    //if heap is empty
    if(heapSize<=0){
        return INT_MAX;
    }
    //if only one element is in heap then it is the min value
    if(heapSize==1){
        heapSize--;
        return array[0];
    }
    //min value is at index 0 according to heap property
    //store the min value in diff variable and replace the value at index 0 by value at last index
    int minValue=array[0];
    array[0]=array[heapSize-1];
    heapSize--;
    //decrease the size of heap as one element is removed from top
    //placing last element on top will not satisfy the heap property
    //to satisfy the heap property call minHeapify with index 0 because element at index 0 is changed
    minHeapify(0);
    return minValue;
}

/*
delete a value at any given index
*/
void minHeap::deleteKey(int index) {
    //to delete a value from heap replace that value with minus infinity value and then call extractMin to remove minus infinity from heap
    decreaseKey(index, INT_MIN);
    extractMin();
}

/*
Decrease the value of a key . New key as argument is assumed to be smaller than the current value.
*/
void minHeap::decreaseKey(int index, int newKey) {
    //replace the value at the given index
    array[index]=newKey;
    //to maintain heap property
    while(index!=0 && array[index]<array[parent(index)]){
        swapInt(&array[index], &array[parent(index)]);
        index=parent(index);
    }
}


/*
Swap two number
*/
void swapInt(int *a, int *b) {
    int temp=*a;
    *a = *b;
    *b=temp;
}

/*
Function to satisfy the heap property
*/

void minHeap::minHeapify(int index) {
    //index of left child
    int leftChild=left(index),
    //index of right child
    rightChild=right(index),
    //assume smallest value is at given index
    smallest=index;
    //if left child exist and value at left is smaller then parent
    if(leftChild<heapSize && array[leftChild]<array[index])
        smallest=leftChild;
    //if right child exist and value at right is smallest than the current smallest value
    if(rightChild<heapSize && array[rightChild]< array[smallest])
        smallest=rightChild;
    //if smallest value is changed
    if(smallest!=index){
        swapInt(&array[smallest], &array[index]);
        minHeapify(smallest);
    }
}

int main()
{
    minHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    //h.deleteKey(2);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
