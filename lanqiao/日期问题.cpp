#include <cstdio>
using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year)
{
	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int get(int year, int month)
{
	if(month == 2) return 28 + is_leap(year);
	return days[month]; 
}

int main()
{
	int a, b, c;
	scanf("%d/%d/%d", &a, &b, &c);
	
	for (int i = 19600101; i <= 20591231; i ++)     
	{
		int year = i / 10000, month = i / 100 % 100, day = i % 100;
		if(month < 1 || month > 12) continue;								// �·ݲ��Ϸ�
		if(day < 1 || day > get(year, month)) continue;				 		// �������Ϸ�
		
		bool flag = false;
		if(year % 100 == a && month == b && day == c) flag = true; 			// ��/��/��
		if(month == a && day == b && year % 100 == c) flag = true;			// ��/��/��
		if(day == a && month == b && year % 100 == c) flag = true;			// ��/��/�� 
		
		if(flag) printf("%02d-%02d-%02d\n", year, month, day);				// %02d����������λ������ǰ��0
	}
	
	return 0;
}
