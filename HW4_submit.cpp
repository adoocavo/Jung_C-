/*2022/2/7 C++언어 과제
	strlen함수를 사용하지 않고 입력된 문자열의 길이만큼 반복

	실수 1 => 제어변수 증감 고려안함 ㅠ

	실수 2 => 문자열에 없는 문자를 입력시 문자열 길이를 벗어나서 반복문 실행 => null초기화!? => ㄴㄴ '\0'까지 배열 원소 비교 반복 후(문자열 배열 입력 종료의 기준) 반복의 실행문에서 세부사항 작성
	==> 반복횟수 종료 기준 정해놓기!(입력한 문자가 문자열에 있을때, 없을때 모두 적용되는) -> edit1

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

	cout << "문자열 입력: ";
	cin.getline(str, sizeof(str));

	len1 = my_strlen(str);
	cout << "문자열의 길이: " << len1 << endl;

	cout << "문자 입력: ";
	cin >> ch;

	len2 = my_strlen(str, ch);
	cout << ch << ' ';
	cout << "이전 까지의 길이: " << len2 << endl;

	return 0;
}

int my_strlen(char* s, char c) {
	int i = 0;
	int res = 0;

	while (s[i] != '\0') {
		if (s[i] != c) {
			res++;
			i++;	//실수 1 => 제어변수 증감 고려안함 ㅠ
		}

		else { break; }
	}

	return res;
}