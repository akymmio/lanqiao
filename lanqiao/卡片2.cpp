#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int i,temp=1,count=1;//count��ʾ���ֿ�Ƭ��temp��ʾ��๲�м��ֲ�ͬ���
	for(i=0;;i++){
		if(temp>=n)
		{
			printf("%d",count);
			return 0;
		}
		temp+=2+i;
		count++;
	}
        return 0;
}