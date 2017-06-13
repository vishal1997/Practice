
#include<bits/stdc++.h>
using namespace std;
int n;

bool inRange(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;
}

int findDist(int x, int y, int  a, int b) {
    queue< pair<int, int> > q;
    pair< int, int > p;
    vector< vector<bool> >visited(n+1,vector<bool> (n+1,false));
    vector< vector<int> > dist(n+1,vector<int> (n+1,INT_MAX));
    int d1[]={-a,-a,-b,-b, a, a, b, b};
    int d2[]={-b, b,-a, a, b,-b, a,-a};
    q.push(make_pair(x,y));
    dist[x][y]=0;
    while(!q.empty()) {
        p=q.front();
        q.pop();
        int x1=p.first;
        int y1=p.second;
        if(visited[x1][y1])
            continue;
        visited[x1][y1]=true;
        for(int i=0;i<8;i++) {
            int x2=x1+d1[i];
            int y2=y1+d2[i];
            if(inRange(x2,y2) && visited[x2][y2]==false && dist[x1][y1]+1<dist[x2][y2]) {
                dist[x2][y2]=dist[x1][y1]+1;
                q.push(make_pair(x2,y2));
            }
        }
    }
    return dist[n-1][n-1];
}

int main() {
    cin>>n;
    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            int distance=findDist(0,0,i,j);
            if(distance==INT_MAX)
                cout<<"-1 ";
            else
                cout<<distance<<" ";
        }
        cout<<"\n";
    }
}
