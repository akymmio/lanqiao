#include <iostream>
using namespace std;
int main(){
    long long int t;
    cin >> t;
    t = t % (24*60*60*1000);//��ȥ�����������ʣ����ٺ���
    int h = t / (60 * 60 * 1000) % 24;//��ȥ�����죬ʣ�¼���Сʱ
    int m = t/(60*1000)%60;//��ȥ������Сʱ��ʣ�¶��ٷ���
    int s = t / (1000) % 60;//ʣ�¶�����
    printf("%02d:%02d:%02d",h,m,s);//����λ�ò���0�����ǿո�
    return 0;
}