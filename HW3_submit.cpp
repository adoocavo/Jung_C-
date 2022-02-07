/*2022/2/7 C++언어 과제
	default parameter이용

실수1 => 선언된 배열의 전체를 출력하는것이 아니라 입력된 만큼만 출력하고 비교

 +) cin.getline()의 리턴값 => 입력받은 문자열
	( cin.getline()으로 )입력받은 값을(배열을) 배열의 시작 주소로 확인/수정 할 수 있다!(압력함수는 입력만!!!)

실수2(핵주의!) => 입력 버퍼의 끝 == '\n'
	  => 배열의 끝 == '\0'
*/


#include<string.h>
#include<iostream>
using namespace std;
void str_prn(char*, char = '\0');
#define N 80

int main() {
	char str[N];
	char ch;

	cout << "문장 입력: ";
	cin.getline(str, sizeof(str));

	cout << "문자 입력: ";
	cin >> ch;

	str_prn(str);
	str_prn(str, ch);

	return 0;
}

void str_prn(char* s, char c) {
	int i;
	int size = strlen(s) + 1;  //마지막 \0까지 검사 

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