int moveX[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int moveY[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int solve(char Graph[][MAXN],int N, int M, int x, int y, string s, bool **isVisited){
    if(s.length() <= 0) return 1;

    for(int i = 0; i < 8; i++){
        int nextX = x+moveX[i];
        int nextY = y+moveY[i];
        if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M){
            if(Graph[nextX][nextY] == s[0] && !isVisited[nextX][nextY]){
                isVisited[nextX][nextY] = true;
                if(solve(Graph, N, M, nextX, nextY, s.substr(1), isVisited) == 1){
                    return 1;
                }
                isVisited[nextX][nextY] = false;
            }
        }
    }

    return 0;
}

int solve(char Graph[][MAXN],int N, int M){
    bool **isVisited = new bool *[N];
    for(int i = 0; i < N; i++){
        isVisited[i] = new bool[M];
        for(int j = 0; j < M; j++) isVisited[i][j] = false;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Graph[i][j] == 'C'){
                isVisited[i][j] = true;
                if(solve(Graph, N, M, i, j, "ODINGNINJA", isVisited) == 1){
                    return 1;
                }
                isVisited[i][j] = false;
            }
        }
    }

    return 0;
}
