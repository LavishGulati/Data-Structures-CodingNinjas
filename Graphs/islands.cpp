#include<iostream>
#include<vector>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
int solve(int n,int m,vector<int>u,vector<int>v){
    bool **graph = new bool *[n];
    for(int i = 0; i < n; i++){
        graph[i] = new bool[n];
        for(int j = 0; j < n; j++) graph[i][j] = false;
    }

    for(int i = 0; i < m; i++){
        graph[u[i]-1][v[i]-1] = true;
        graph[v[i]-1][u[i]-1] = true;
    }

    int total = 0;
    bool *isVisited = new bool[n];
    for(int i = 0; i < n; i++) isVisited[i] = false;

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(!isVisited[i]){
            q.push(i);
            isVisited[i] = true;
            total++;

            while(!q.empty()){
                int currVertex = q.front();
                q.pop();

                for(int j = 0; j < n; j++){
                    if(graph[currVertex][j]){
                        if(!isVisited[j]){
                            q.push(j);
                            isVisited[j] = true;
                        }
                    }
                }
            }
        }
    }

    return total;
}

int main()
{
    int n,m;
    vector<int>u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        u.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<solve(n,m,u,v)<<endl;
}
