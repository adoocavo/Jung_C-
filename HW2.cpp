/*2022/2/7 C++��� ����
�����ε� �Լ� �̿�


�Ǽ� 1 => �Ǽ����ε� int������ �߸� ���� ��



*/
#include<string.h>
#include<iomanip>
#include<iostream>
using namespace std;
double max(double, double);
char* max(char*, char*);
void myflush(void);
#define N 20

int main(void) {
	double num1;
	double num2;
	char str1[N];
	char str2[N];
	double maxNum;
	char* maxStr;

	cout << "�� �Ǽ� �Է�: ";
	cin >> num1;
	cin >> num2;

	myflush();

	maxNum = max(num1, num2);

	cout << setprecision(1);
	cout << "ū ��: ";
	cout << fixed << maxNum << endl;

	cout << "�� ���ڿ� �Է�: ";
	cin.getline(str1, sizeof(str1), ' ');
	cin.getline(str2, sizeof(str2));

	maxStr = max(str1, str2);
	
	cout << "�� ���ڿ�: ";
	cout << maxStr << endl;

	return 0;
}

void myflush() {

	cin.clear();

	while (cin.get() != '\n');
}

double max(double n1, double n2) {
	if (n1 >= n2) {
		return n1;
	}

	else {
		return n2;
	}
}

char* max(char* s1, char* s2) {
	int lenS1;
	int lenS2;

	lenS1 = strlen(s1);
	lenS2 = strlen(s2);
	
	if (lenS1 >= lenS2) {
		return s1;
	}

	else {
		return s2;
	}
}