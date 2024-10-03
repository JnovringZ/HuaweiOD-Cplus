// class Solution {
//    public:
//     vector<vector<int>> result;
//     vector<int> path;
//     void backtracking(vector<int>& v, int target, int startIndex) {
//         int sum = accumulate(path.begin(), path.end(), 0);
//         if (sum == target) {
//             result.push_back(path);
//             return;
//         }

//         for (int i = startIndex; i < v.size(); i++) {
//             path.push_back(v[i]);
//             backtracking(v, target, i + 1);
//             path.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         backtracking(candidates, target, 0);
//         sort(result.begin(), result.end());
//         result.erase(unique(result.begin(), result.end()), result.end());

//         return result;
//     }
// };