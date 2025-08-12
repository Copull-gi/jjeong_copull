#include<iostream>
#include<queue>

using namespace std;

int R, C;
char maze[1001][1001];
int dx[4] = {1, 0, -1, 0}; // 동, 남, 서, 북
int dy[4] = {0, 1, 0, -1};
int distJ[1001][1001];
int distF[1001][1001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>> R >> C;

    queue<pair<int, int>> qJ;
    queue<pair<int, int>> qF;

    for (int r = 0; r < R; r++) {
        fill(distJ[r], distJ[r] + C, -1);
        fill(distF[r], distF[r] + C, -1);
    }
    

    for (int r = 0; r < R; r++) {
        string s; cin >> s;
        for (int c = 0; c < C; c++) {
            maze[r][c] = s[c];
            if (s[c] == 'J') {
                qJ.push({r, c});
                distJ[r][c] = 0;
            } else if (s[c] == 'F') {
                qF.push({r, c});
                distF[r][c] = 0;
            }
        }
    }

    while(!qF.empty()){ //불에 대한 BFS
        auto cur = qF.front();
        qF.pop();

        for(int i = 0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx >= R || ny >= C || nx < 0 || ny < 0) continue;
            if(maze[nx][ny] == '#' || distF[nx][ny] != -1) continue;

            distF[nx][ny] = distF[cur.first][cur.second] + 1;
            qF.push({nx, ny});
        }
    }

    while(!qJ.empty()){ //지훈이에 대한 BFS
        auto cur = qJ.front();
        if(cur.first == 0 || cur. first == R-1 || cur.second == 0||cur.second == C-1){ //가장자리 도착
            cout << distJ[cur.first][cur.second] + 1 << "\n";
            return 0;
        }
        qJ.pop();

        for(int i = 0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx >= R || ny >= C || nx < 0 || ny < 0) continue;
            if(maze[nx][ny] == '#' || distJ[nx][ny] != -1) continue;
            if(distF[nx][ny] != -1 && distJ[cur.first][cur.second] + 1 >= distF[nx][ny]){//지훈이는 이미 불에 붙은 곳에 방문 불가
                continue; 
            }

            distJ[nx][ny] = distJ[cur.first][cur.second] + 1;
            qJ.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;


}