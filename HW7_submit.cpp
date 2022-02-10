/*2022/2/8 C++언어 과제
    날짜에 따른 할인률 계산 프로그램

    // 1900~유통기한 : sum1
    // 1900~현재 날짜: sum2

    sum1 < sum2 => 유통기한 지남
    sum1 > sum2  => s1 - s2 = 0~3 : 50퍼 세일
                => s1 - s2 = 4~10 : 20퍼 세일
                => s1-s2 >10 :정가판매


    tot_days >> leap_check  => 2번 call  => selling_price에서 1번 ,


    ??구조체 변수를 extern으로 선언하면 data손실 위험??

    ??"-"로 출력? '-'로 출력??

     if (check < 0) {            //실수1 => 이거 생각안함ㅜ

     +) 날짜 입력 오류 확인 함수 작성
     +) 

    */
#pragma warning(disable:4996)
#include<iostream>
#include <time.h> 
#include<windows.h> 
using namespace std;

struct date {
    unsigned int da_year;
    unsigned int da_mon;
    unsigned int da_day;
} stdate;
void getdate(struct date* p);

struct Goods {
    char item[50];
    int price;
    int year;
    int mon;
    int day;
    int discount;
};

void input(Goods&);
void selling_price(Goods&);
void prn(const Goods&);
int tot_days(int, int, int);
int leap_check(int);
inline static int leap_check(int year) {    //윤년 1, 평년 0
    if (year % 4 != 0) {  //평년
        return 0;
    }
    else {
        if (year % 100 == 0 && year % 400 == 0) { //윤년
            return 1;
        }
        else if (year % 100 == 0 && year % 400 != 0) { //평년
            return 0;
        }
        else if (year % 100 != 0) {				//윤년
            return 1;
        }
        else { ; }
    }
}


int main() {
    Goods goods;
 
    input(goods);

    selling_price(goods);

    prn(goods);

    cout << "** 프로그램 실행 날짜 : " << stdate.da_year << "년" << stdate.da_mon << "월" << stdate.da_day << "일" << endl;

    return 0;
}

void my_flush() {
    while (cin.get() != '\n') { ; }
}

void getdate(struct date* p)
{
    char temp[128];
    char* cp, syear[5] = "20";
    _strdate(temp);
    cp = strtok(temp, "/");
    p->da_mon = atoi(cp);
    cp = strtok(NULL, "/");
    p->da_day = atoi(cp);
    cp = strtok(NULL, "/");
    strcat(syear, cp);
    p->da_year = atoi(syear);
}

void input(Goods& g) {
    int check;

    cout << "품목 입력: ";
    cin.getline(g.item, sizeof(g.item));

    cout << "정가 입력: ";
    cin >> g.price;

    cout << "유통기한 입력: ";
    cin >> g.year;
    cin >> g.mon;
    cin >> g.day;

    my_flush();

    return;
}

int tot_days(int y, int m, int d) {
    int sum = 0;
    int check;
    int i;
    int calyear = 1900;
    int leapCheck1;
    int leapCheck2;
    check = y - 1900;

    leapCheck2 = leap_check(y);

    for (i = 1; i <= check; i++) {
        leapCheck1 = leap_check(calyear);

        if (leapCheck1 == 0) {  //평년
            sum += 365;
        }
        else {
            if (leapCheck1 == 1) { //윤년
                sum += 366;
            }
            else if (leapCheck1 == 0) { //평년
                sum += 365;
            }
            else if (leapCheck1 == 1) {				//윤년
                sum += 366;
            }
            else { ; }
        }
        calyear += 1;				//판단 대상 => 1900년도부터 입력된 년도의 직전년도까지 => 반복될때마다 변해야함 
    }

    for (i = 1; i < m; i++) {				//입력된 년도 내에서 윤녕여부에 따라, 몇월인지에 따라 더해지는 일수 다르게 작성 
        if ((i == 4) || (i == 6) || (i == 9) || (i == 11)) {
            sum += 30;
        }
        else if (i == 2) {
            if (leapCheck2 == 0) {  //평년
                sum += 28;
            }
            else {
                if (leapCheck2 == 1) { //윤년
                    sum += 29;
                }
                else if (leapCheck2 == 0) { //평년
                    sum += 28;
                }
                else if (leapCheck2 == 1) {				//윤년
                    sum += 29;
                }
                else { ; }
            }
        }
        else {
            sum += 31;
        }
    }

    sum += d;		//마지막으로 남은 일수 더해주기 

    return sum;
}

void selling_price(Goods& g) {
    int daySum1;
    int daySum2;
    int check;

    getdate(&stdate);

    daySum1 = tot_days(g.year, g.mon, g.day);
    daySum2 = tot_days(stdate.da_year, stdate.da_mon, stdate.da_day);
 
    check = daySum1 - daySum2;          //유통기한까지 얼마나 남았는지 chseck 
  
    if (check < 0) {            //실수1 => 이거 생각안함ㅜ
        g.discount = -1;
    }
    else if (check >= 0 && check <= 3) {
        g.discount = 50;
        g.price = g.price * 0.50;
    }

    else if (check >= 4 && check <= 10) {
        g.discount = 20;
        g.price = g.price * 0.80;
    }

    else if (check > 10) {
        g.discount = 0;
    }
    return;
}

void prn(const Goods& g) {
    if (g.discount == -1) {
        cout << "유통기한이 지났습니다!" << endl;
    }
    else {
        cout << "품명: " << g.item << endl;
        cout << "판매가: " << g.price << endl;
        cout << "유통기한: " << g.year << "-" << g.mon << "-" << g.day << endl;        // ??"-"로 출력? '-'로 출력??
        cout << "할인율: " << g.discount << "%" << endl;
    }

    return;
}

