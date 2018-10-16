#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

int moveX[4] = {-1, 0, 1, 0};
int moveY[4] = {0, -1, 0, 1};

bool isCyclePresent(char board[][MAXN], int n, int m, int sourceX, int sourceY, int x, int y, int count, bool **isVisited){
    for(int i = 0; i < 4; i++){
        int nextX = x+moveX[i];
        int nextY = y+moveY[i];

        if(nextX == sourceX && nextY == sourceY && count >= 4) return true;
    }

    for(int i = 0; i < 4; i++){
        int nextX = x+moveX[i];
        int nextY = y+moveY[i];

        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m){
            if(board[nextX][nextY] == board[x][y] && !isVisited[nextX][nextY]){
                isVisited[nextX][nextY] = true;
                if(isCyclePresent(board, n, m, sourceX, sourceY, nextX, nextY, count+1, isVisited)){
                    return true;
                }
                isVisited[nextX][nextY] = false;
            }
        }
    }

    return false;
}

int solve(char board[][MAXN],int n, int m){
    bool **isVisited = new bool *[n];
    for(int i = 0; i < n; i++){
        isVisited[i] = new bool[m];
        for(int j = 0; j < m; j++) isVisited[i][j] = false;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!isVisited[i][j]){
                isVisited[i][j] = true;
                if(isCyclePresent(board, n, m, i, j, i, j, 1, isVisited)) return 1;
                isVisited[i][j] = false;
            }
        }
    }

    return 0;
}

int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}
