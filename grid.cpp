#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;
int array[10][10];
int visited[10][10];

int grid(int i,int j, int n, int m) {
    queue<pair<int,int> >q;
    int count=0;
    q.push(make_pair(i,j));
    while(!q.empty()) {
        pair<int,int> cell;
        cell=q.front();
        q.pop();
        if(visited[cell.first][cell.second])
            continue;
        count++;
        visited[cell.first][cell.second]=1;
        for(int ii=-1;ii<=1;ii++){
            for(int jj=-1;jj<=1;jj++) {
                int indexI=cell.first+ii;
                int indexJ=cell.second+jj;
                if(indexI>=0 && indexI<n && indexJ>=0 && indexJ<m && array[indexI][indexJ] && !visited[indexI][indexJ])
                    q.push(make_pair(indexI,indexJ));
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin>>n;
    cin>>m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>array[i][j];
            visited[i][j]=0;
    }
    int largest=0;
    int temp=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
        if(array[i][j]!=0) {
            temp=grid(i,j,n,m);
            if(temp>largest)
                largest=temp;
        }
    }
    cout<<largest;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
