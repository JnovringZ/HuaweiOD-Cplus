// class Solution {
//    public:
//     vector<vector<int>> result;
//     vector<int> path;
//     void backtracking(vector<int>& v, int target, int startIndex) {
//         int sum = accumulate(path.begin(), path.end(), 0);
//         if (sum == target) {
//             result.push_back(path);
//         }
//         if (sum > target) {
//             return;
//         }

//         for (int i = startIndex; i < v.size(); i++) {
//             path.push_back(v[i]);
//             backtracking(v, target, i);
//             path.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         backtracking(candidates, target, 0);
//         return result;
//     }
// };
