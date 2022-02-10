/* 2022 / 2 /9 c++����
// HW60 �ֹε�� ��ȿ�� �˻� ���α׷�
// �ۼ��� : �ְ���
//HW7����, ��¥üũ �˰��� �ٽ� �����ϰ� ¥����
//���ʿ��� �ݺ� �������� => �ٽ�!!(����� ���๮�� ���� ����!)
//�Ǽ�1 => checkDate(char* resident_number)�Լ�����
//==> ���ǹ��� ���� Ư�� ������ �ʱ�ȭ�ϰ� ���� code���� ����ϰ��� �ϸ�  ��� ���ǿ� �ʱ�ȭ code�� �ۼ��Ǿ�� �Ѵ� -> edit1
//�Ǽ� 2 => if (resident_number[6] == 1 || resident_number[6] == 2) {		//1900���
		check = 19;
	}
	else if (resident_number[6] == 3 || resident_number[6] == 4) {	//2000���
		check = 20;
	}
	==> 1�� �ƴ϶� '1'�̴�......

	�Ǽ� 2~4 => �޸տ���
	�Ǽ�5 => �˰��� ��������
	
??int availabilityCheck(char* resident_number)		//else�ۼ� ���ص� �ǳ�?? (else�� ������� �ʴ� if��???)
	*/

#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH 13

int availabilityCheck(char* resident_number);
int checkLengthCharacter(char* resident_number);
int checkDate(char* resident_number);
int checkIdentification(char* resident_number);
int checkGender(char* resident_number);
int checkYear(int year);

int main()
{
	/* �׽�Ʈ�� �ֹε�Ϲ�ȣ ���� �迭*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
			"0003154194917", "801203#201122", "7804155328845", "7804150328840",
			"9612241068382", "9902292194322", "0230174326176", "8811391042219",
			"8100122042213", "8112002042213", "9210101069415", "0802294012345",
			"8806311069417","8807311069418" };
	int i;
	int count;

	/* �˻��� �ֹε�Ϲ�ȣ�� ���� ���*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);	// ��ü �迭 ũ�� / �� row�� ũ�� =row���� 
	for (i = 0; i < count; i++) {
		if (availabilityCheck(resident_number[i]) == TRUE) {
			printf("(+) �ֹι�ȣ%s��(��) ��ȿ�� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
		else {
			printf("(-) �ֹι�ȣ%s��(��) ��ȿ���� ���� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
	}
	return 0;
}

/*----------------------------------------------------------------
  availabilityCheck()�Լ� : �ֹε�Ϲ�ȣ ��ȿ�� �˻� �Լ�
  �������� : ��ȿ�� �˻��� �ֹε�Ϲ�ȣ (���ڿ�)
  ���ϰ� : ��ȿ�ϸ� TRUE, ��ȿ���� ������ FALSE ����
------------------------------------------------------------------*/
int availabilityCheck(char* resident_number)		//else�ۼ� ���ص� �ǳ�??
{
	if (checkLengthCharacter(resident_number)) /* �ֹε�Ϲ�ȣ ���� �� ���ڹ��� ��ȿ�� �˻� */
	{
		if (checkDate(resident_number))  /* ��¥ �˻� */
		{
			if (checkGender(resident_number)) /* �ֹε�Ϲ�ȣ�� ���� �ĺ���ȣ(7��° ����) ��ȿ�� �˻� */
			{
				if (checkIdentification(resident_number))  /* �ν��� ����üũ*/
				{
					return TRUE;
				}
			}
		}
	
	}
	return FALSE;
}

int checkLengthCharacter(char* resident_number) {
	int len;
	int i;
	len = strlen(resident_number);

	if (len == 13) {
		for (i = 0; i < 13; ++i) {
			if (resident_number[i] >= '0' && resident_number[i] <= '9') {
				return TRUE;
			}
			else {
				return FALSE;
			}
		}

	}
	else { return FALSE; }

}

int checkDate(char* resident_number) {			//����� �ݺ��� ��� ���ʿ��� �ݺ��� �ߺ��Ǵ°� �����ϱ�		//�� check, y�� �ʱ�ȭ �������� ��� ����??
	int check;
	int tens_y;
	int units_y;
	int tens_m;
	int units_m;
	int tens_d;
	int units_d;
	int y;
	int m;
	int d;

	if (resident_number[6] == '1' || resident_number[6] == '2') {		//1900���
		check = 19;
	}
	else if (resident_number[6] == '3' || resident_number[6] == '4') {	//2000���
		check = 20;
	}
	else { return FALSE; }				//����y�� �ʱ�ȭ���� �ʴ� ��츦 �����ֱ� => checkGender�� �ʿ��Ѱ�??

	tens_y = resident_number[0] - '0';			//���� -> ���� ��ȯ: ���� - '0'(ascii code - ascii code)
	tens_y *= 10;
	units_y = resident_number[1] - '0';

	if (check == 19) {
		y = 1900 + tens_y + units_y;
	}
	else  {
		y = 2000 + tens_y + units_y;
	}


	tens_m = resident_number[2] - '0';
	tens_m *= 10;
	units_m = resident_number[3] - '0';
	m = tens_m + units_m;

	tens_d = resident_number[4] - '0';
	tens_d *= 10;
	units_d = resident_number[5] - '0';
	d = tens_d + units_d;

	if (m >= 1 && m <= 12) {
		if ((m == 4) || (m == 6) || (m == 9) || (m == 11)) {
			if (d >= 1 && d <= 30) {
				return TRUE;
			}
			else { return FALSE; }
		}
		else if (m == 2) {
			if (checkYear(y)) {		//�����̸�
				if (d >= 1 && d <= 29) {
					return TRUE;
				}
				else { return FALSE; }
			}
			else {					//������ �ƴϸ� 
				if (d >= 1 && d <= 28) {
					return TRUE;
				}
				else { return FALSE; }
			}
		}
		else {						// �Ǽ�5: ������ 1-12��� �������� �־�� �Ѵ� ! => edit2
			if (d >= 1 && d <= 31) {
				return TRUE;
			}
			else { return FALSE; }
		}
	}
	else {
		return FALSE;
	}

}

int checkYear(int year) {		//��� 0, ���� 1		//���ǽ����� �Ǵ��� �����°ͺ��� if�� �ۼ� !
	if (year % 4 != 0) {
		return FALSE;
	}
	else {
		if (year % 100 != 0) {
			return TRUE;
		}
		else {
			if (year % 400 == 0) {
				return TRUE;
			}
			else {
				return FALSE;
			}
		}
	}
}

int checkGender(char* resident_number) {
	if (resident_number[6] >= '1' && resident_number[6] <= '4') {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int checkIdentification(char* resident_number) {
	int i;
	int sum = 0;
	int dec;
	int id;
	int check;

	for (i = 0; i <= 11; ++i) {
		//	dec = resident_number[0] - '0';		//�Ǽ�3 => []÷�ڿ� ���� �ƴ� ����� ���� 
		dec = resident_number[i] - '0';
		sum += dec;
	}

	id = resident_number[12] - '0';
	//	check = dec % 10;
	check = sum % 10;				//�Ǽ�4 => �߸��� ���� ��� ..�� 

	if (check == id) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/*-------------------------------------------------------------------------
  checkLengthCharacter()�Լ� : �ֹε�Ϲ�ȣ ���� �� ���� ��ȿ�� �˻� �Լ�
  �������� : �˻��� �ֹε�Ϲ�ȣ (���ڿ�)
  ���ϰ� : �ֹε�Ϲ�ȣ�� ���̰� �°� ���ڹ��ڷθ� �����Ǿ������� TRUE,
		   ���̰� ª�ų� ���, ���ڹ��ڰ� �ƴ� ���ڰ� ���������� FALSE ����
--------------------------------------------------------------------------*/

//TODO

/*----------------------------------------------------------------
  checkDate()�Լ� : ù 6�ڸ�(��,��,��)�� ��ȿ�� �˻� �Լ�
  �������� : ��ȿ�� �˻��� �ֹε�Ϲ�ȣ (���ڿ�)
  ���ϰ� : ��ȿ�� ��¥�̸� TRUE, ��ȿ���� ���� ��¥�̸� FALSE ����
------------------------------------------------------------------*/

// 1. ��Ȯ�� ��, ��, �� ���ϱ� 
// 2. ��, �� ��Ȯ���� üũ(�������� üũ�Լ� �̿�) 


//�������� üũ => �� üũ => �� üũ 
//TODO

/*----------------------------------------------------------------------
  checkGender()�Լ� : 7��° �ڸ��� ���� �ĺ���ȣ ��ȿ�� �˻� �Լ�
  �������� : ��ȿ�� �˻��� �ֹε�Ϲ�ȣ (���ڿ�)
  ���ϰ� : ���� �ĺ���ȣ�� '1'~'4'�̸� TRUE, �׿� ���ڹ����̸� FALSE ����
-----------------------------------------------------------------------*/

//TODO

/*------------------------------------------------------------------------
  checkIdentification()�Լ� : �ֹε�Ϲ�ȣ ���ڸ�(�ν���) ��ȿ�� �˻� �Լ�
  �������� : ��ȿ�� �˻��� �ֹε�Ϲ�ȣ (���ڿ�)
  ���ϰ� : ��ȿ�� ��¥�̸� TRUE, ��ȿ���� ���� ��¥�̸� FALSE ����
-------------------------------------------------------------------------*/

//TODO

/*----------------------------------------------------------------
  checkYear()�Լ� : �⵵�� ��,��� ���� �˻�
  �������� : ��,��� �˻��� �⵵
  ���ϰ� : �����̸� 1, ����̸� 0 ����
------------------------------------------------------------------*/

//TODO

