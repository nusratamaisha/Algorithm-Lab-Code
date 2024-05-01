#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
vector<int>edges[MAX];
bool visited[MAX];
bool visited1[MAX];
void dfs(int node){
    visited[node] = true;
    cout<<node<<' ';
    for(auto it: edges[node]){
        if(!visited[it]){
            dfs(it);
        }
    }

}

void bfs(){
    queue<int> q;
    q.push(1);
    visited1[1] = true;
    while(!q.empty()){
        cout<<q.front()<<' ';
        for(auto it: edges[q.front()]){
            if(!visited1[it]){
                q.push(it);
                visited1[it] = true;
            }
        }
        q.pop();
    }
}
int main(){
    edges[1].emplace_back(3);
    edges[3].emplace_back(1);
    edges[1].emplace_back(2);
    edges[2].emplace_back(1);
    edges[1].emplace_back(4);
    edges[4].emplace_back(1);
    edges[2].emplace_back(4);
    edges[4].emplace_back(2);
    edges[2].emplace_back(5);
    edges[5].emplace_back(2);
    edges[4].emplace_back(5);
    edges[5].emplace_back(4);
    for(int i=1;i<=5;i ++){
        if(!visited[i]){
            dfs(i);
        }
    }
    cout<<endl;
    bfs();
}




