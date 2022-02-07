/*2022/2/4 C++언어 과제
	jolly jumper

실수1 => 과거의res값과 모두 비교해야함 -> edit1

실수2 => 인접한 두 수의 차이 절대값 처리 안함ㅜ -> edit2

jolly jumper조건 => 수열의 개수(n)일때 인접하는 수열끼리의 차이가 1~n-1이 나와야 한다
==> 1.비교대상: 인접한 두 수열값의 차이 vs 1~n-1
	2.비교 반복 횟수: 1차 -> n-1번, 2차 -> 이전 차이들과의 중복 비교

==> 조건을 쪼개서 생각해보기!! -> 인접한 두 수의 차이가 1~n-1범위에 있으려면
								1. 차이값이 1~n-1이고
								2. 이전 차이값의 결과와 중복되지 않아야 한다

+)반복수행시 초기화 잊지말기!
*/

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define N 100

int main(void) {
	int num;
	int ary[N];
	int temp[N] = { 0, };
	int check = 0;
	int res;
	int i;
	int j;
	int k;
	int l;

	printf("숫자의 개수: ");
	scanf("%d", &num);

	printf("검사할 수열입력: ");
	for (i = 0; i < num; i++) {
		scanf("%d", &ary[i]);
	}

	for (j = 0; j < num - 1; j++) {			//인접한 수끼리 비교하는 횟수=> num-1번
		res = abs(ary[j + 1] - ary[j]);

		if (res >= 1 && res <= num - 1) {	//인접하는 두 수 차의 값의 범위 체크
			;
		}
		else {
			check++;
			break;
		}

		for (k = 0; k <= j; k++) {		//인접하는 두 수 차의 값 중복 방지 
			if (res != temp[k]) {
				continue;	//속도 차이 있나?
			}
			else {
				check++;
				break;
			}
		}
		if (check != 0) {
			break;
		}
		else;

		temp[j] = res;
	}

	if (check == 0) {
		for (l = 0; l < num; l++) {
			printf("%d ", ary[l]);
		}

		printf("(Jolly jumper)\n");

	}

	else {
		for (l = 0; l < num; l++) {
			printf("%d ", ary[l]);
		}

		printf("(Not jolly jumper)\n");
	}

	printf("\n");

	return 0;
}