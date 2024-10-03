#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 定义方向数组，表示上下左右四个方向
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// 计算指定位置的网络信号值
int calculateSignal(vector<vector<int>>& array, int m, int n, int target_i, int target_j) {
    vector<vector<int>> signal(m, vector<int>(n, 0));  // 用来保存每个位置的信号强度
    queue<pair<int, int>> q;                           // BFS 队列

    // 找到信号源并初始化
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] > 0) {  // 找到信号源
                signal[i][j] = array[i][j];
                q.push({i, j});  // 将信号源加入队列
            }
        }
    }

    // 广度优先搜索 (BFS)
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // 遍历四个方向
        for (int d = 0; d < 4; d++) {
            int newX = x + directions[d][0];
            int newY = y + directions[d][1];

            // 检查是否在范围内，且不是阻隔物
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && array[newX][newY] != -1) {
                // 计算新的信号强度
                int newSignal = signal[x][y] - 1;

                // 如果新的信号强度大于当前信号强度，更新并加入队列
                if (newSignal > signal[newX][newY]) {
                    signal[newX][newY] = newSignal;
                    q.push({newX, newY});
                }
            }
        }
    }

    // 返回目标位置的信号值
    return signal[target_i][target_j];
}

int main() {
    int m, n;
    cin >> m >> n;  // 输入地图row和col

    vector<vector<int>> array(m, vector<int>(n));

    // 读取二维数组
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> array[i][j];
        }
    }

    // 读取需要计算的位置
    int target_i, target_j;
    cin >> target_i >> target_j;

    // 计算并输出结果
    int result = calculateSignal(array, m, n, target_i, target_j);
    cout << result << endl;

    return 0;
}
