#include <bits/stdc++.h>
using namespace std;
int main() {
    // x进制字符串转换10进制数字;
    string hexs = "8000ffff";  // 16进制:(不限制大小写)FFFE也可以
    long long num = stoll(hexs, nullptr, 16);
    cout << num << endl;

    // 数字转16进制字符串
    int val = 128;
    stringstream ss;
    ss << "0x" << hex << uppercase << val;  // 把val变成16进制, 大写
    string ts = ss.str();                   // 用字符串接住
    cout << ts << endl;

    // 数字转数字
    int test = 010;
    // cout << hex << uppercase << test << endl;
    cout << test << endl;
}
