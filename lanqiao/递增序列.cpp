#include <iostream>
using namespace std;
int main() {
    string str[30];
    int ans = 0;
    for (int i = 0; i < 30; i++) {
        cin >> str[i];
    }
    // ��
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 49; j++) {
            for (int k = j + 1; k < 50; k++) { // 50ϸ��
                if (str[i][j] < str[i][k])
                    ans++;
            }
        }
        // ��ֹԽ��
        if (i != 29) {

            for (int j = 0; j < 50; j++) {
                // ���·�
                for (int k = i + 1; k < 30; k++) {
                    if (str[i][j] < str[k][j])
                        ans++;
                }
                // ���½�
                for (int k = i + 1; k < 30; k++) {
                    if (j != 49 && (j + (k - i)) < 50 &&
                        str[i][j] <str[k][j +(k - i)]) // �Խ��ߣ��������ºʹ������Ҷ�һ��
                        ans++;
                }
                // ���½�
                for (int k = i + 1; k < 30; k++) {
                    if (j != 0 && (j - (k - i)) >= 0 &&
                        str[i][j] !=str[k][j -(k -i)]) // �Խ��ߣ��ɷ�ת�������ϵ��²��ǵ����������ҾͿ��ܵ�����ֻҪλ�ò�ͬ����
                        ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}