/*2022/2/4 C++��� ����
	jolly jumper

�Ǽ�1 => ������res���� ��� ���ؾ��� -> edit1

�Ǽ�2 => ������ �� ���� ���� ���밪 ó�� ���Ԥ� -> edit2

jolly jumper���� => ������ ����(n)�϶� �����ϴ� ���������� ���̰� 1~n-1�� ���;� �Ѵ�
==> 1.�񱳴��: ������ �� �������� ���� vs 1~n-1
	2.�� �ݺ� Ƚ��: 1�� -> n-1��, 2�� -> ���� ���̵���� �ߺ� ��

==> ������ �ɰ��� �����غ���!! -> ������ �� ���� ���̰� 1~n-1������ ��������
								1. ���̰��� 1~n-1�̰�
								2. ���� ���̰��� ����� �ߺ����� �ʾƾ� �Ѵ�

+)�ݺ������ �ʱ�ȭ ��������!
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

	printf("������ ����: ");
	scanf("%d", &num);

	printf("�˻��� �����Է�: ");
	for (i = 0; i < num; i++) {
		scanf("%d", &ary[i]);
	}

	for (j = 0; j < num - 1; j++) {			//������ ������ ���ϴ� Ƚ��=> num-1��
		res = abs(ary[j + 1] - ary[j]);

		if (res >= 1 && res <= num - 1) {	//�����ϴ� �� �� ���� ���� ���� üũ
			;
		}
		else {
			check++;
			break;
		}

		for (k = 0; k <= j; k++) {		//�����ϴ� �� �� ���� �� �ߺ� ���� 
			if (res != temp[k]) {
				continue;	//�ӵ� ���� �ֳ�?
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