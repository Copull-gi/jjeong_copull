#include<iostream>
#include<queue>

using namespace std;
int n;
int m;
int board[1001][1001];
int dis[1001][1001];
bool alreadyRipe = true;
int dx[4] = {1, 0, -1, 0}; // 동, 남, 서, 북
int dy[4] = {0, 1, 0, -1};
int maximum;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>m >> n;
    queue<pair<int, int>> Q;

    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            int num;
            cin >> num;
            board[i][j] = num;

            if(num == 1){ //모든 시작점 큐에 넣기 (익은 토마토)
                Q.push({i, j});
            } else if(num == 0){
                alreadyRipe = false;
            }
        }
    }
    
    if(alreadyRipe){
        cout << 0;
        return 0;
    }

    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();

        for(int i = 0; i<4; i++){
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];

            if(nextX < 0 || nextY <0 || nextX >= n || nextY >= m){
                continue;
            }
            if(board[nextX][nextY] == -1 || board[nextX][nextY] == 1){
                continue;
            }

            board[nextX][nextY] = 1;
            dis[nextX][nextY] = dis[cur.first][cur.second] + 1;
            Q.push({nextX, nextY});
        }
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            maximum = max(maximum, dis[i][j]);
            if(board[i][j] == 0){
                cout << -1;
                return 0;
            }
        }
    }

    cout<<maximum;
    return 0;
}