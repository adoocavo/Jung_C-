/*2022/2/7 C++��� ����
	strlen�Լ��� ������� �ʰ� �Էµ� ���ڿ��� ���̸�ŭ �ݺ�

	�Ǽ� 1 => ����� ���� ������� ��

	�Ǽ� 2 => ���ڿ��� ���� ���ڸ� �Է½� ���ڿ� ���̸� ����� �ݺ��� ���� => null�ʱ�ȭ!? => ���� '\0'���� �迭 ���� �� �ݺ� ��(���ڿ� �迭 �Է� ������ ����) �ݺ��� ���๮���� ���λ��� �ۼ�
	==> �ݺ�Ƚ�� ���� ���� ���س���!(�Է��� ���ڰ� ���ڿ��� ������, ������ ��� ����Ǵ�) -> edit1

*/
#include<iostream>
using namespace std;
#define N 50
int my_strlen(char*, char = '\0');

int main() {
	int len1;
	int len2;
	char str[N] = "";
	char ch;

	cout << "���ڿ� �Է�: ";
	cin.getline(str, sizeof(str));

	len1 = my_strlen(str);
	cout << "���ڿ��� ����: " << len1 << endl;

	cout << "���� �Է�: ";
	cin >> ch;

	len2 = my_strlen(str, ch);
	cout << ch << ' ';
	cout << "���� ������ ����: " << len2 << endl;

	return 0;
}

int my_strlen(char* s, char c) {
	int i = 0;
	int res = 0;

	while (s[i] != '\0') {
		if (s[i] != c) {
			res++;
			i++;	//�Ǽ� 1 => ����� ���� ������� ��
		}

		else { break; }
	}

	return res;
}