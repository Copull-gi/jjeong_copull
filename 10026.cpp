#include<iostream>
#include<queue>

using namespace std;
int n;
char board[101][101];
bool vis[101][101];
int area;
int area2;
int dx[4] = {1, 0, -1, 0}; // 동, 남, 서, 북
int dy[4] = {0, 1, 0, -1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i< n; i++){
        fill(vis[i], vis[i] +n, 0);
    }

    for(int i = 0; i<n; i ++){
        for(int j = 0; j < n; j++){
            char color;
            cin >> color;

            board[i][j] = color;
        }
    }

    queue<pair<int, int>>Q;

    for(int i = 0; i<n; i ++){
        for(int j = 0; j < n; j++){
            if(vis[i][j]) continue;

            Q.push({i, j});
            area++;

            while(!Q.empty()){
                auto cur = Q.front();
                Q.pop();

                for(int k = 0; k<4; k++){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx <0 || ny <0 || nx >=n|| ny >=n) continue;
                    if(vis[nx][ny] || board[nx][ny] != board[cur.first][cur.second]) continue;

                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }

    for(int i = 0; i< n; i++){
        fill(vis[i], vis[i] +n, 0);
    }
    

    for(int i = 0; i<n; i ++){
        for(int j = 0; j < n; j++){
            if(vis[i][j]) continue;

            Q.push({i, j});
            area2++;

            while(!Q.empty()){
                auto cur = Q.front();
                Q.pop();

                for(int k = 0; k<4; k++){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx <0 || ny <0 || nx >=n|| ny >=n) continue;
                    if(vis[nx][ny]) continue;
                    if(board[cur.first][cur.second] != board[nx][ny]){
                        if(board[cur.first][cur.second] == 'B' || board[nx][ny] == 'B'){
                            continue;
                        }
                    }
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }

    cout << area << " " << area2;
}