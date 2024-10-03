#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

// 递归生成满足条件的不同字符串
void generateDistinctStrings(string s, int length, string current, unordered_set<string>& result, vector<bool>& used) {
    // 当生成的字符串长度等于指定长度时，将其加入到结果集中
    if (current.length() == length) {
        result.insert(current);
        return;
    }

    // 遍历字符串中的字符
    for (int i = 0; i < s.length(); i++) {
        // 判断字符是否已经被使用，或者当前字符与前一个字符相同
        if (used[i] || (current.length() > 0 && current.back() == s[i])) {
            continue;  // 如果字符已被使用或与前一个字符相同，则跳过当前字符
        }
        used[i] = true;  // 标记当前字符为已使用
        // 递归调用生成下一个字符
        generateDistinctStrings(s, length, current + s[i], result, used);
        used[i] = false;  // 取消标记当前字符的使用状态，以便下一次遍历
    }
}

// 计算满足条件的不同字符串的数量
int countDistinctStrings(string s, int length) {
    // 创建一个集合来存储不同的字符串
    unordered_set<string> distinctStrings;
    // 创建一个列表来标记字符串中的字符是否已经被使用
    vector<bool> used(s.length(), false);
    // 调用generateDistinctStrings方法生成满足条件的不同字符串
    generateDistinctStrings(s, length, "", distinctStrings, used);
    // 打印生成的所有不同的字符串
    // for (auto& str : distinctStrings) {
    // cout << str << endl;
    // }
    // 返回不同字符串的数量
    return distinctStrings.size();
}

int main() {
    string input;
    getline(cin, input);
    // 将输入的字符串按空格分割为两部分，分别为字符串和长度
    string str;
    int length;
    istringstream iss(input);
    iss >> str >> length;

    // 调用countDistinctStrings方法计算满足条件的不同字符串的数量
    int count = countDistinctStrings(str, length);
    // 输出计算结果
    cout << count << endl;

    return 0;
}
