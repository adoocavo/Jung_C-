/*2022/2/3 C++��� ����
�̸��迭 

������ �迭 -> �緹�� ���鼭(���ڴ�� ���� �־) ���ϴ� �� �ľ� �� �ϳ��� �ݺ� ��� ���ϱ�   

�ݺ��� ��ü���� Ʋ�� �������� �� �ݺ��� �ɰ��(���� or ����for������ ��������) �ϳ��� for��(Ȥ�� while��)���� �ۼ��ϰ� �� ���๮���� �������� �ۼ��ϱ� 

*/

#include<stdio.h>
#pragma warning(disable:4996)
#define N 10
void inputArynum(int*);
void inputAryData(int(*)[N], int);	//2���� �迭�� �����ּ��� type���� (+ ������ �̿��ؼ� ������ ���� �Ұ�!)
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

	printf("# ��/���� �� �Է�: ");
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