/* 2022/2/4 c++����	*/


#include<iomanip>
#include<iostream>
using namespace std;
#define N 20

int main(void) {
	int kor;
	int eng;
	int math;
	int sum;
	double avg;
	char name[N];
	int i;

	cout << "�̸�: ";
	cin.getline(name, sizeof(name));
	
	cout << "�� ������ ����: "; //�Ǽ�1 => Ŀ���� �������� ���� => name�迭�� ũ�Ⱑ 5�� �����Ǿ �߻��� ���� ��
	cin >> kor;
	cin >> eng;
	cin >> math;

	sum = kor + eng + math;
	avg = sum / 3.0;

	for (i = 0; i < 20; i++) {
		cout << " ";
	}
	cout << "=====< ����ǥ >=====" << endl;

	for (i = 0; i < 60; i++) {
		cout << "=";
	}

	cout << '\n';		//\n => 1b�ϳ��� ��ɹ��ڻ�� 

	cout << setw(10) << "�̸�";
	cout << setw(10) << "����";
	cout << setw(10) << "����";
	cout << setw(10) << "����";
	cout << setw(10) << "����";
	cout << setw(10) << "���" << endl;

	for (i = 0; i < 60; i++) {
		cout << "=";
	}

	cout << '\n';

	cout << setw(10) << name;
	cout << setw(10) << kor;
	cout << setw(10) << eng;
	cout << setw(10) << math;
	cout << setw(10) << sum;
	cout << setprecision(2);
	cout << setw(10) << fixed << avg << endl;




	return 0;
}