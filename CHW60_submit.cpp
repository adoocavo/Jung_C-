/* 2022 / 2 /9 c++과제
// HW60 주민등록 유효성 검사 프로그램
// 작성자 : 최강주
//HW7윤년, 날짜체크 알고리즘 다시 간단하게 짜보기
//불필요한 반복 제거하자 => 핵심!!(공통된 실행문을 먼저 실행!)
//실수1 => checkDate(char* resident_number)함수에서
//==> 조건문에 따라 특정 변수를 초기화하고 이후 code에서 사용하고자 하면  모든 조건에 초기화 code가 작성되어야 한다 -> edit1
//실수 2 => if (resident_number[6] == 1 || resident_number[6] == 2) {		//1900년대
		check = 19;
	}
	else if (resident_number[6] == 3 || resident_number[6] == 4) {	//2000년대
		check = 20;
	}
	==> 1이 아니라 '1'이다......

	실수 2~4 => 휴먼에러
	실수5 => 알고리즘 구성에러
	
??int availabilityCheck(char* resident_number)		//else작성 안해도 되나?? (else를 사용하지 않는 if문???)
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
	/* 테스트할 주민등록번호 저장 배열*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
			"0003154194917", "801203#201122", "7804155328845", "7804150328840",
			"9612241068382", "9902292194322", "0230174326176", "8811391042219",
			"8100122042213", "8112002042213", "9210101069415", "0802294012345",
			"8806311069417","8807311069418" };
	int i;
	int count;

	/* 검사할 주민등록번호의 개수 계산*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);	// 전체 배열 크기 / 한 row의 크기 =row개수 
	for (i = 0; i < count; i++) {
		if (availabilityCheck(resident_number[i]) == TRUE) {
			printf("(+) 주민번호%s는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else {
			printf("(-) 주민번호%s는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}

/*----------------------------------------------------------------
  availabilityCheck()함수 : 주민등록번호 유효성 검사 함수
  전달인자 : 유효성 검사할 주민등록번호 (문자열)
  리턴값 : 유효하면 TRUE, 유효하지 않으면 FALSE 리턴
------------------------------------------------------------------*/
int availabilityCheck(char* resident_number)		//else작성 안해도 되나??
{
	if (checkLengthCharacter(resident_number)) /* 주민등록번호 길이 및 숫자문자 유효성 검사 */
	{
		if (checkDate(resident_number))  /* 날짜 검사 */
		{
			if (checkGender(resident_number)) /* 주민등록번호중 성별 식별번호(7번째 숫자) 유효성 검사 */
			{
				if (checkIdentification(resident_number))  /* 인식자 오류체크*/
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

int checkDate(char* resident_number) {			//공통된 반복은 묶어서 불필요한 반복이 중복되는것 지양하기		//왜 check, y만 초기화 안했을때 경고가 뜨지??
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

	if (resident_number[6] == '1' || resident_number[6] == '2') {		//1900년대
		check = 19;
	}
	else if (resident_number[6] == '3' || resident_number[6] == '4') {	//2000년대
		check = 20;
	}
	else { return FALSE; }				//변수y가 초기화되지 않는 경우를 없애주기 => checkGender가 필요한가??

	tens_y = resident_number[0] - '0';			//문자 -> 정수 변환: 문자 - '0'(ascii code - ascii code)
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
			if (checkYear(y)) {		//윤년이면
				if (d >= 1 && d <= 29) {
					return TRUE;
				}
				else { return FALSE; }
			}
			else {					//윤년이 아니면 
				if (d >= 1 && d <= 28) {
					return TRUE;
				}
				else { return FALSE; }
			}
		}
		else {						// 실수5: 월에도 1-12라는 제한조건 있어야 한다 ! => edit2
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

int checkYear(int year) {		//평년 0, 윤년 1		//조건식으로 판단이 끝나는것부터 if문 작성 !
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
		//	dec = resident_number[0] - '0';		//실수3 => []첨자에 변수 아닌 상수를 넣음 
		dec = resident_number[i] - '0';
		sum += dec;
	}

	id = resident_number[12] - '0';
	//	check = dec % 10;
	check = sum % 10;				//실수4 => 잘못된 변수 사용 ..ㅜ 

	if (check == id) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/*-------------------------------------------------------------------------
  checkLengthCharacter()함수 : 주민등록번호 길이 및 문자 유효성 검사 함수
  전달인자 : 검사할 주민등록번호 (문자열)
  리턴값 : 주민등록번호의 길이가 맞고 숫자문자로만 구성되어있으면 TRUE,
		   길이가 짧거나 길고, 숫자문자가 아닌 문자가 섞여있으면 FALSE 리턴
--------------------------------------------------------------------------*/

//TODO

/*----------------------------------------------------------------
  checkDate()함수 : 첫 6자리(연,월,일)의 유효성 검사 함수
  전달인자 : 유효성 검사할 주민등록번호 (문자열)
  리턴값 : 유효한 날짜이면 TRUE, 유효하지 않은 날짜이면 FALSE 리턴
------------------------------------------------------------------*/

// 1. 정확한 년, 월, 일 구하기 
// 2. 월, 일 정확한지 체크(윤년인지 체크함수 이용) 


//윤년인지 체크 => 달 체크 => 일 체크 
//TODO

/*----------------------------------------------------------------------
  checkGender()함수 : 7번째 자리의 성별 식별번호 유효성 검사 함수
  전달인자 : 유효성 검사할 주민등록번호 (문자열)
  리턴값 : 성별 식별번호가 '1'~'4'이면 TRUE, 그외 숫자문자이면 FALSE 리턴
-----------------------------------------------------------------------*/

//TODO

/*------------------------------------------------------------------------
  checkIdentification()함수 : 주민등록번호 끝자리(인식자) 유효성 검사 함수
  전달인자 : 유효성 검사할 주민등록번호 (문자열)
  리턴값 : 유효한 날짜이면 TRUE, 유효하지 않은 날짜이면 FALSE 리턴
-------------------------------------------------------------------------*/

//TODO

/*----------------------------------------------------------------
  checkYear()함수 : 년도의 윤,평년 여부 검사
  전달인자 : 윤,평년 검사할 년도
  리턴값 : 윤년이면 1, 평년이면 0 리턴
------------------------------------------------------------------*/

//TODO

