#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if(!(cin >> m >> n)) return 0;
    if(m <= 0 || n <= 0){
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<int>> a(m, vector<int>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(!(cin >> a[i][j])) a[i][j] = 0;
        }
    }

    vector<vector<char>> vis(m, vector<char>(n, 0));
    long long best = 0;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] > 0 && !vis[i][j]){
                long long sum = 0;
                deque<pair<int,int>> dq;
                dq.emplace_back(i, j);
                vis[i][j] = 1;
                while(!dq.empty()){
                    auto [x, y] = dq.front(); dq.pop_front();
                    sum += a[x][y];
                    for(int k = 0; k < 4; ++k){
                        int nx = x + dx[k], ny = y + dy[k];
                        if(nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] > 0 && !vis[nx][ny]){
                            vis[nx][ny] = 1;
                            dq.emplace_back(nx, ny);
                        }
                    }
                }
                best = max(best, sum);
            }
        }
    }

    cout << best << '\n';
    return 0;
}
