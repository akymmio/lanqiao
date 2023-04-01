#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int i,temp=1,count=1;//count表示几种卡片；temp表示最多共有几种不同组合
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