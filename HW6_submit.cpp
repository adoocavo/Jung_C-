#include<string.h>
#include<iostream>
using namespace std;
void swap_ptr(const char*&, const char*&);

int main() {
	const char* ap = "apple";
	const char* bp = "banana";

	cout << "바꾸기 전의 문자열: " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "바꾼 후의 문자열: " << ap << " " << bp << endl;

	return 0;

}

void swap_ptr(const char*& ap, const char*& bp) {
	
	const char* temp = 0;
	
	temp = ap;			//ap, bp의 저장값을 바꿈(ap와bp는 const가 아니므로 수정 가능하다!)
	ap = bp;
	bp = temp;

	return;

}