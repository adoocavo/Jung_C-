/*2022/2/3 C++언어 과제
똬리배열 

복잡한 배열 -> 사레를 들어가면서(문자대신 순자 넣어서) 변하는 값 파악 후 하나의 반복 덩어리 구하기   

반복의 전체적인 틀이 안잡히면 각 반복을 쪼개어서(이중 or 삼중for문으로 하지말고) 하나의 for문(혹은 while문)으로 작성하고 각 실행문마다 종료조건 작성하기 

*/

#include<stdio.h>
#pragma warning(disable:4996)
#define N 10
void inputArynum(int*);
void inputAryData(int(*)[N], int);	//2차원 배열의 시작주소의 type주의 (+ 변수명 이용해서 포인터 선언 불가!)
void outputAry(int(*)[N], int);

int main(void) {
	int ary[N][N];
	int size;

	inputArynum(&size);

	inputAryData(ary, size);

	outputAry(ary, size);

	return 0;
}

void inputArynum(int* s) {

	printf("# 행/열의 수 입력: ");
	scanf("%d", s);
	
	return;
}

void inputAryData(int(*a)[N], int s) {
	int i;
	int j;
	int k;
	int l;
	int sta = 0;
	int num = 1;
	int usize = s - 1;
	int check = s * s;

	while (1) {
		for (i = sta; i <= usize; i++) {
			a[sta][i] = num;
			num++;

			if (a[sta][i] == check) {
				return;
			}
			else;
		}

		for (j = sta + 1; j <= usize; j++) {
			a[j][usize] = num;
			num++;

			if (a[j][usize] == check) {
				return;
			}
			else;
		}

		for (k = usize - 1; k >= sta; k--) {
			a[usize][k] = num;
			num++;

			if (a[usize][k] == check) {
				return;
			}
			else;
		}
		
		for (l = usize - 1; l >= sta+1; l--) {
			a[l][sta] = num;
			num++;

			if (a[l][sta] == check) {
				return;
			}
			else;
		}

		++sta;
		--usize;
	}
}

void outputAry(int(*a)[N], int s) {
	int i;
	int j;

	for (i = 0; i < s; i++) {
		for (j = 0; j < s; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}

	return;
}