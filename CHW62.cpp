/*2022/2/4 C++언어 과제
	야구게임

*/

#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#define N 4
#pragma warning(disable:4996)
void inputUnum(int*, int);
void makeCnum(int*);
void checkCount(int*, int*, int*, int*);
void outputRes(int, int, int*);

int main(void) {
	int unum[N];
	int cnum[N];
	int trial = 1;
	int check = 0;
	int strike = 0;
	int ball = 0;
	srand((unsigned int)time(NULL));
	
	makeCnum(cnum);

	while (1) {
//		makeCnum(cnum);			//1번만 실행 후 사용x -> 해당 숫자 다 맞추면 반복 끝 -> 해당 프로그램에서 한번만 사용 -> while문 밖으로 나가!
		
		inputUnum(unum, trial);
		
		checkCount(unum, cnum, &strike, &ball);
		
		outputRes(strike, ball, &check);

		if (check == 0) {
			++trial;
			strike = 0;
			ball = 0;
			
			printf("\n");
	
			continue;
		}

		else {
			break;
		}
	}
	return 0;
}


void inputUnum(int* u, int trial) {
	int i;
	printf("# %d차: ", trial);
	
	for (i = 0; i < N; i++) {
		scanf("%d", &u[i]);
	}

	return;
}

void makeCnum(int* c) {
	int i = 0;
	int j;
	int k;
//	int check = 0;		//실수1 => check의 초기값을 0으로 두면 c[0]으로 무한루프 
	int check = 1;

	while (i < N) {
		c[i] = rand() % 10;

		for (j = 0; j < i; j++) {
			check = c[i] - c[j];

			if (check == 0) {
				break;
			}
			else { continue; }
		}

		if (check == 0) {
			continue;
		}
		else {
			++i;
		}
	}
	printf("       ");

	for (k = 0; k < N; k++) {
		printf("%d ", c[k]);
	}
	printf("\n\n");

	return;
}

void checkCount(int* u, int* c, int* s, int* b) {
	int i;
	int j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i == j && u[i] == c[j]) {			//u와c순서가 달라지면 결과도 달라지나? 
				++*s;	//연산자 순서 주의 s*++와 결과 다름  
				break;
			}
			else if (u[i] == c[j]) {
				++*b;
				break;
			}
		}
	}
	return;
}

void outputRes(int s, int b, int* check) {

	if (s == N) {
		printf("OK!!!\n");
		++* check;
	}

	else if (s == 0 && b == 0) {
		printf("NO!\n");
	}

	else {
		printf("%dS %dB\n", s, b);
	}
	
	return;
}









