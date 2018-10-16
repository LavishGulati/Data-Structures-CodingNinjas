#include<iostream>
#include<vector>
using namespace std;

int count3Cycles(bool **graph, int sourceX, int x, int n, int count, bool *isVisited){
    if(count > 3) return 0;
    isVisited[x] = true;

    int total = 0;
    for(int i = 0; i < n; i++){
        if(count == 3){
            if(graph[x][i] && i == sourceX) total += 1;
        }

        if(graph[x][i] && !isVisited[i]){
            total += count3Cycles(graph, sourceX, i, n, count+1, isVisited);
        }
    }

    isVisited[x] = false;

    return total;
}

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

    bool *isVisited = new bool[n];
    for(int i = 0; i < n; i++) isVisited[i] = false;

    int total = 0;
    for(int i = 0; i < n; i++){
        total += count3Cycles(graph, i, i, n, 1, isVisited);
    }

    total /= 6;
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
