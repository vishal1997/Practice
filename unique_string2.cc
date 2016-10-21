#include<iostream>
using namespace std;

bool allUnique(string given){
    bool Map[126]={false};
    for(int i=0;i<given.size();i++){
        if(Map[given[i]])
            return false;
        Map[given[i]]=true;
    }
    return true;
}

int main(){
    string s;
    getline(cin, s);
    if(allUnique(s))
        cout<<"No Repeated character";
    else
        cout<<"Repeated character";
    return 0;
}

