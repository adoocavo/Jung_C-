/* 2022/2/8 c++����

cin�Է� ���п��� => cin.fail()���� flag�� 1���� �˻�!!=> flag�� 0�̿������� �Է°���

while (u != 10 && u != 100 && u != 50 && u != 500) {		//||�� &&�� ���� !

�Է� ����ó�� �˰��� =>		�Է¼���	 =>	(�־��� ���ǿ� ���� ����ó�� �ۼ� )  =>  �����϶�

																			=>	����϶�	    => ����1: 50,10,500,100�� �ϳ�?? => �Է�����

																							=> ����2: ����1�� ���� => ���Է� => �����Է�, �����Է�(���� ���ǵ�) ����� �ݺ��� ���� �Է¹ޱ�


							�Է½���	 => �Է� �����Ҷ����� ���Է� => �Է� ���� ���� ����ó�� �ڵ�
							,

�Ǽ�1: 		else if (u != 10 && u != 100 && u != 50 && u != 500) {
			while (u != 10 && u != 100 && u != 50 && u != 500) { => ����� ���͸� ���� ���� => edit1
			�����Է½� �����Ⱚ �������� => ������ �ݾ�: a
									  ������ �ݾ�: ������ �ݾ�:		//�̷��� ��� => while (cin.fail() == 0) {���� �߸� �ۼ���

			==> ��� �߿��� Ư�� ���� �ԷµǾ�� �ϴ� �����̸� ���� �ش��ϴ� ���� �ԷµǾ��� ���� ������ ���ǹ����� �ۼ��� �� else�� ������ �Է� ����ó���� �ۼ�
				++) ||�����ڴ� ���ǹ����� �����ϸ� �ǹ̾���


�Ǽ�2:  �������� �Է¹޴°� �ۼ�����...�� => edit2
			
			

	+) ���Է¹��� ���� �Լ� �ۼ� (cin.clear()�� ������ ���� ����!) 
*/

#include<iomanip>
#include<iostream>
using namespace std;

struct Savings {
	int w500;
	int w100;
	int w50;
	int w10;
};

void init(Savings&);
void input(int&, int&);
void save(Savings&, int, int);
int total(Savings&);

int main() {
	struct Savings sum;
	int unit = 0;
	int cnt = 0;
	int totalSaving = 0;

	init(sum);

	while (1) {
		input(unit, cnt);

		if (unit < 0) {
			break;
		}
		else { ; }

		save(sum, unit, cnt);
	}

	totalSaving = total(sum);

	cout << "�� ���ݾ�: " << totalSaving << endl;

	return 0;
}

void my_flush() {
	cin.clear();		//�Է¹����� �ֵ��� flag0���� �ٲٱ�

	while (cin.get() != '\n') { ; }		//'\n'���� �Է¹޾Ƽ� ���� ���� 

}



void init(Savings& s) {			//?? ����ü �ʱ�ȭ �� ���ǿ� ���ÿ� �ʱ�ȭ �ϴ°� �ƴϸ� �迭ó�� �ϳ��� ���� �ʱ�ȭ?? 

	s.w10 = 0;
	s.w100 = 0;
	s.w50 = 0;
	s.w500 = 0;

	return;
}

void input(int& u, int& c) {

	cout << "������ �ݾ�: ";
	cin >> u;
	
	if (cin.fail() == 0) {		//�Է��� ����(�����Է�)
		if (u < 0) {
			return;				//�����Է� =-> �ش��Լ� ������ ���α׷� ������ �� �ְ� �Ѵ� 
		}
		else if (u == 10 || u == 100 || u == 50 || u == 500) {
			;
		}

		else {
			while (u != 10 && u != 100 && u != 50 && u != 500) {		//||�� &&�� ���� !
				u = 0;
				cout << "������ �ݾ�: ";
				cin >> u;

				if (cin.fail()) {		//���Է� �� �����Է½� ����ó��
					my_flush();
					continue;
				}

				else if (u < 0) {
					return;
				}
			}
		}
	}

	else {
		while (cin.fail() == 1) {		//�Է½��� (�����Է�)
			my_flush();
			cout << "������ �ݾ�: ";
			cin >> u;
		}

		if (u < 0) {
			return;				//�����Է� =-> �ش��Լ� ������ ���α׷� ������ �� �ְ� �Ѵ� 
		}

		else if (u == 10 || u == 100 || u == 50 || u == 500) {
			;
		}

		else {
			while (u != 10 && u != 100 && u != 50 && u != 500) {		//||�� &&�� ���� !
				u = 0;
				cout << "������ �ݾ�: ";
				cin >> u;

				if (cin.fail()) {		//���Է� �� �����Է½� ����ó��
					my_flush();
					continue;
				}

				else if (u < 0) {
					return;
				}
			}
		}
	}

	cout << "������ ����: ";
	cin >> c;

	if (cin.fail()) {
		while (cin.fail()) {
			my_flush();
			cout << "������ ����: ";
			cin >> c;
		}
	}
	else { ; }

	return;
}

void save(Savings& s, int u, int c) {
	int i;
	for (i = 0; i < c; i++) {
		switch (u)
		{
		case 10:
			++s.w10;
			break;

		case 50:
			++s.w50;
			break;

		case 100:
			++s.w100;
			break;

		case 500:
			++s.w500;
			break;

		default:
			;
		}
	}
	return;
}

int total(Savings& s) {
	int sum;

	sum = 10 * s.w10 + 100 * s.w100 + 50 * s.w50 + 500 * s.w500;

	return sum;
}