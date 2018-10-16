#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55

int moveX[4] = {-1, 0, 1, 0};
int moveY[4] = {0, -1, 0, 1};

int countSize(char cake[NMAX][NMAX], int x, int y, int n, bool **isVisited){
    isVisited[x][y] = true;
    int total = 1;
    for(int i = 0; i < 4; i++){
        int nextX = x+moveX[i];
        int nextY = y+moveY[i];

        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n){
            if(cake[nextX][nextY] == '1' && !isVisited[nextX][nextY]){
                total += countSize(cake, nextX, nextY, n, isVisited);
            }
        }
    }

    // cout << x << " " << y << " " << total << endl;
    return total;
}

int solve(int n,char cake[NMAX][NMAX]){
    bool **isVisited = new bool *[n];
    for(int i = 0; i < n; i++){
        isVisited[i] = new bool[n];
        for(int j = 0; j < n; j++) isVisited[i][j] = false;
    }

    int maxSize = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cake[i][j] == '1' && !isVisited[i][j]){
                maxSize = max(maxSize, countSize(cake, i, j, n, isVisited));
            }
        }
    }

    return maxSize;
}

char cake[NMAX][NMAX];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
