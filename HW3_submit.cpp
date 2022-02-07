/*2022/2/7 C++��� ����
	default parameter�̿�

�Ǽ�1 => ����� �迭�� ��ü�� ����ϴ°��� �ƴ϶� �Էµ� ��ŭ�� ����ϰ� ��

 +) cin.getline()�� ���ϰ� => �Է¹��� ���ڿ�
	( cin.getline()���� )�Է¹��� ����(�迭��) �迭�� ���� �ּҷ� Ȯ��/���� �� �� �ִ�!(�з��Լ��� �Է¸�!!!)

�Ǽ�2(������!) => �Է� ������ �� == '\n'
	  => �迭�� �� == '\0'
*/


#include<string.h>
#include<iostream>
using namespace std;
void str_prn(char*, char = '\0');
#define N 80

int main() {
	char str[N];
	char ch;

	cout << "���� �Է�: ";
	cin.getline(str, sizeof(str));

	cout << "���� �Է�: ";
	cin >> ch;

	str_prn(str);
	str_prn(str, ch);

	return 0;
}

void str_prn(char* s, char c) {
	int i;
	int size = strlen(s) + 1;  //������ \0���� �˻� 

	for (i = 0; i < size; i++) {
		if (s[i] != c) {
			cout << s[i];
		}
		else {
			break;
		}
	}
	printf("\n");

	return;
}