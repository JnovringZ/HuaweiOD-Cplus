// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     string s;
//     char ch;
//     getline(cin, s);
//     cin >> ch;

//     // A-Z:65-90 a-z:97-122
//     int count = 0;
//     char changeCh;
//     if ('A' <= ch && ch <= 'Z') {
//         // changeCh = ch + 32;
//         changeCh = tolower(ch);
//     } else {
//         // changeCh = ch - 32;
//         changeCh = toupper(ch);
//     }

//     for (int i : s) {
//         if (s[i] == ch)
//             count++;
//         if (s[i] == changeCh)
//             count++;
//     }

//     printf("%d\n", count);
//     cout << changeCh << endl;
// }

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
    string s;
    char ch;
    getline(cin, s);
    cin >> ch;

    int count = 0;
    if('a'<=ch && ch<='z'){
        ch = toupper(ch);
    }
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (char i : s)
    {
        if (i == ch)
            count++;
    }

    cout << count << endl;
}

