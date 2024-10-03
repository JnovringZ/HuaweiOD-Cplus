#include <bits/stdc++.h>
using namespace std;
int cnt = 0;

void dfs(vector<vector<int>>& grid, vector<int>& visited, int index, int N) {
    visited[index] = 1;
    for (int j = 0; j < N; j++) {
        if (grid[index][j] == 1 && visited[j] == 0 && index != j) {
            dfs(grid, visited, j, N);
        }
    }
}
int main() {
    string input;
    getline(cin, input);

    vector<int> nums;
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        nums.push_back(stoi(input.substr(0, pos)));
        input.erase(0, pos + 1);
    }
    nums.push_back(stoi(input));
    // vector<vector<int>> grid(nums.size(), vector<int>(nums.size(), 0));
    vector<vector<int>> grid;
    grid.push_back(nums);
    for (int i = 1; i < nums.size(); i++) {
        string input;
        getline(cin, input);

        vector<int> nums;
        size_t pos = 0;
        while ((pos = input.find(' ')) != string::npos) {
            nums.push_back(stoi(input.substr(0, pos)));
            input.erase(0, pos + 1);
        }
        nums.push_back(stoi(input));
        grid.push_back(nums);
    }

    vector<int> visited(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        if (visited[i] == 0) {
            dfs(grid, visited, i, nums.size());
            cnt++;
            // cout << cnt;
        }
    }

    cout << cnt;
}