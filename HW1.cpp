/* 2022/2/4 c++과제	*/


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

	cout << "이름: ";
	cin.getline(name, sizeof(name));
	
	cout << "세 과목의 점수: "; //실수1 => 커서를 내보내지 않음 => name배열의 크기가 5로 지정되어서 발생한 문제 ㅠ
	cin >> kor;
	cin >> eng;
	cin >> math;

	sum = kor + eng + math;
	avg = sum / 3.0;

	for (i = 0; i < 20; i++) {
		cout << " ";
	}
	cout << "=====< 성적표 >=====" << endl;

	for (i = 0; i < 60; i++) {
		cout << "=";
	}

	cout << '\n';		//\n => 1b하나의 기능문자상수 

	cout << setw(10) << "이름";
	cout << setw(10) << "국어";
	cout << setw(10) << "영어";
	cout << setw(10) << "수학";
	cout << setw(10) << "총점";
	cout << setw(10) << "평균" << endl;

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