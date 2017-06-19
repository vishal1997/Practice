#include <bits/stdc++.h>

using namespace std;

int maxLen(string s, char x, char y){
    // Complete this function
    char ch=0;
    int length=0;
    int count=0;
    int s_size=s.size();
    for(int i=0;i<s_size;i++) {
        if(s[i]!=x && s[i]!=y)
            continue;
        if(s[i]==ch)
            return 0;
        ch=s[i];
        length+=1;
    }
    return length>=2 ? length : 0;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result=0;
    for(char x='a';x<='z';x++) {
        for(char y= x+1; y<='z' ;y++) {
            result = max(result,maxLen(s,x,y));
        }
    }
    cout << result << endl;
    return 0;
}
