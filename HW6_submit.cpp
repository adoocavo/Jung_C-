#include<string.h>
#include<iostream>
using namespace std;
void swap_ptr(const char*&, const char*&);

int main() {
	const char* ap = "apple";
	const char* bp = "banana";

	cout << "�ٲٱ� ���� ���ڿ�: " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "�ٲ� ���� ���ڿ�: " << ap << " " << bp << endl;

	return 0;

}

void swap_ptr(const char*& ap, const char*& bp) {
	
	const char* temp = 0;
	
	temp = ap;			//ap, bp�� ���尪�� �ٲ�(ap��bp�� const�� �ƴϹǷ� ���� �����ϴ�!)
	ap = bp;
	bp = temp;

	return;

}