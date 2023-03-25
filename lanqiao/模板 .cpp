#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n-1; i++) {
        cin >> a[i];
    }
    return 0;
}