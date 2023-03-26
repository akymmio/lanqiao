#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    vector<char> l(100);
    set<char> s;
    string str;
    cin >> str;
    int n;
    cin >> n;
    int i = 0;
    while (i <= str.size()) {
        s.insert(str[i]);
        i++;
    }
    int c = s.size()-1;
    while (n--) {
        s.erase(s.erase(c--));
    }
    for (auto j : s) {
        cout << j;
    }
}