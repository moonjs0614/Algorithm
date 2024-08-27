#include <bits/stdc++.h>
 
using namespace std;
 
int N, M, K;
 
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int oddDir[4] = {1, 3, 5, 7};
int evenDir[4] = {0, 2, 4, 6};
 
struct fireball {
    int y;
    int x;
    int m; 
    int s;
    int d;
};
 
vector<fireball> balls[51][51];
 
int start() {
    while(K--) {
        vector<fireball> temp[51][51]; 
        
        //파이어볼 이동
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(balls[i][j].empty()) continue;
                for(int k = 0; k < balls[i][j].size(); k++) {
                    fireball fb = balls[i][j][k];
                    
                    int &y = fb.y;
                    int &x = fb.x;
                    int dir = fb.d;
                    int speed = fb.s;
                    int weight = fb.m;
                    
                    y = ((dy[dir] * speed) + y - 1 + 1000) % N + 1;
                    x = ((dx[dir] * speed) + x - 1 + 1000) % N + 1;
                    
                    temp[y][x].push_back(fb);
                }
            }
        }
        
        //파이어볼 합체
        vector<fireball> tmp[51][51];
        
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(temp[i][j].size() == 0) {
                    continue;
                }
                else if(temp[i][j].size() == 1) {
                    tmp[i][j].push_back(temp[i][j][0]);
                    continue;
                }
                
                int messSum = 0;
                int speedSum = 0;
                int ballsCnt = temp[i][j].size();
                
                bool isOdd = true;  //홀수
                bool isEven = true; //짝수
                
                for(int k = 0; k < ballsCnt; k++) {
                    messSum += temp[i][j][k].m;
                    speedSum += temp[i][j][k].s;
                    int ballDir = temp[i][j][k].d;
                    
                    if(ballDir % 2 == 0) {
                        isOdd = false;
                    }
                    else {
                        isEven = false;
                    }
                }
                
                int finalMess = messSum / 5;
                int finalSpeed = speedSum / ballsCnt;
                
                if(finalMess == 0) continue;
                
                if(isOdd == true || isEven == true) {
                    for(int k = 0; k < 4; k++) {
                        tmp[i][j].push_back({i, j, finalMess, finalSpeed, evenDir[k]});
                    }
                }
                else {
                    for(int k = 0; k < 4; k++) {
                        tmp[i][j].push_back({i, j, finalMess, finalSpeed, oddDir[k]});
                    }
                }
            }
        }
        
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                balls[i][j] = tmp[i][j];
            }
        }
    }
    
    int res = 0;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(balls[i][j].empty()) continue;
            for(int k = 0; k < balls[i][j].size(); k++) {
                res += balls[i][j][k].m;    
            }
        }
    }
    
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    
    cin >> N >> M >> K;
    
    for(int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        
        balls[r][c].push_back({r, c, m, s, d});
    }
    
    cout << start();
}