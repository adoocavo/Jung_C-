/* 2022/2/8 c++과제

cin입력 실패여부 => cin.fail()으로 flag가 1인지 검사!!=> flag가 0이여야지만 입력가능

while (u != 10 && u != 100 && u != 50 && u != 500) {		//||와 &&의 구분 !

입력 예외처리 알고리즘 =>		입력성공	 =>	(주어진 조건에 따라서 예외처리 작성 )  =>  음수일때

																			=>	양수일때	    => 조건1: 50,10,500,100중 하나?? => 입력종료

																							=> 조건2: 조건1에 위배 => 재입력 => 문자입력, 음수입력(이전 조건들) 고려한 반복문 만들어서 입력받기


							입력실패	 => 입력 성공할때까지 재입력 => 입력 성공 후의 예외처리 코드
							,

실수1: 		else if (u != 10 && u != 100 && u != 50 && u != 500) {
			while (u != 10 && u != 100 && u != 50 && u != 500) { => 제대로 필터링 되지 않음 => edit1
			문자입력시 쓰레기값 남아있음 => 동전의 금액: a
									  동전의 금액: 동전의 금액:		//이렇게 출력 => while (cin.fail() == 0) {으로 잘못 작성ㅠ

			==> 양수 중에서 특정 수만 입력되어야 하는 조건이면 먼저 해당하는 수가 입력되었을 때의 실행을 조건문으로 작성한 후 else로 나머지 입력 예외처리를 작성
				++) ||연산자는 조건문에서 웬만하면 의미없다


실수2:  동전개수 입력받는거 작성안함...ㅋ => edit2
			
			

	+) ㅇ입력버퍼 비우는 함수 작성 (cin.clear()가 무조건 먼저 실행!) 
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

	cout << "총 저금액: " << totalSaving << endl;

	return 0;
}

void my_flush() {
	cin.clear();		//입력받을수 있도록 flag0으로 바꾸기

	while (cin.get() != '\n') { ; }		//'\n'까지 입력받아서 버퍼 비우기 

}



void init(Savings& s) {			//?? 구조체 초기화 시 정의와 동시에 초기화 하는게 아니면 배열처럼 하나씩 따로 초기화?? 

	s.w10 = 0;
	s.w100 = 0;
	s.w50 = 0;
	s.w500 = 0;

	return;
}

void input(int& u, int& c) {

	cout << "동전의 금액: ";
	cin >> u;
	
	if (cin.fail() == 0) {		//입력은 성공(숫자입력)
		if (u < 0) {
			return;				//음수입력 =-> 해당함수 끝내서 프로그램 종료할 수 있게 한다 
		}
		else if (u == 10 || u == 100 || u == 50 || u == 500) {
			;
		}

		else {
			while (u != 10 && u != 100 && u != 50 && u != 500) {		//||와 &&의 구분 !
				u = 0;
				cout << "동전의 금액: ";
				cin >> u;

				if (cin.fail()) {		//재입력 후 문자입력시 예외처리
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
		while (cin.fail() == 1) {		//입력실패 (문자입력)
			my_flush();
			cout << "동전의 금액: ";
			cin >> u;
		}

		if (u < 0) {
			return;				//음수입력 =-> 해당함수 끝내서 프로그램 종료할 수 있게 한다 
		}

		else if (u == 10 || u == 100 || u == 50 || u == 500) {
			;
		}

		else {
			while (u != 10 && u != 100 && u != 50 && u != 500) {		//||와 &&의 구분 !
				u = 0;
				cout << "동전의 금액: ";
				cin >> u;

				if (cin.fail()) {		//재입력 후 문자입력시 예외처리
					my_flush();
					continue;
				}

				else if (u < 0) {
					return;
				}
			}
		}
	}

	cout << "동전의 개수: ";
	cin >> c;

	if (cin.fail()) {
		while (cin.fail()) {
			my_flush();
			cout << "동전의 개수: ";
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