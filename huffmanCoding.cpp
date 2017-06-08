#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;

struct minHeapNode {
    char data;
    unsigned freq;
    minHeapNode *left, *right;
    minHeapNode(char data, unsigned freq) {
        this->data=data;
        this->freq=freq;
        left=right=NULL;
    }
};

struct compare {
    bool operator()(minHeapNode *l, minHeapNode *r){
        return l->freq > r->freq;
    }
};

void printCodes(minHeapNode *root, string str) {
    if(!root)
        return ;
    if(root->data!='$')
        cout<<root->data<<":"<<str<<"\n";
    printCodes(root->left, str+'0');
    printCodes(root->right, str +'1');
}

void huffman(char data[], unsigned freq[], size_t length) {
    minHeapNode *left, *right, *top;
    priority_queue< minHeapNode*, vector< minHeapNode*>, compare> minHeap;
    for(int i=0;i<length;i++) {
        minHeap.push(new minHeapNode(data[i],freq[i]));
    }
    while (minHeap.size()!=1) {
        left=minHeap.top();
        minHeap.pop();
        right=minHeap.top();
        minHeap.pop();
        top=(new minHeapNode('$',left->freq + right->freq));
        top->left=left;
        top->right=right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(),"");
}


int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    unsigned freq[] = { 5, 9, 12, 13, 16, 45 };
    size_t size = sizeof(arr) / sizeof(arr[0]);

    huffman(arr, freq, size);

    return 0;
}
