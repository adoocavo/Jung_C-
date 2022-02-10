/*2022/2/8 C++��� ����
    ��¥�� ���� ���η� ��� ���α׷�

    // 1900~������� : sum1
    // 1900~���� ��¥: sum2

    sum1 < sum2 => ������� ����
    sum1 > sum2  => s1 - s2 = 0~3 : 50�� ����
                => s1 - s2 = 4~10 : 20�� ����
                => s1-s2 >10 :�����Ǹ�


    tot_days >> leap_check  => 2�� call  => selling_price���� 1�� ,


    ??����ü ������ extern���� �����ϸ� data�ս� ����??

    ??"-"�� ���? '-'�� ���??

     if (check < 0) {            //�Ǽ�1 => �̰� �������Ԥ�

     +) ��¥ �Է� ���� Ȯ�� �Լ� �ۼ�
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
inline static int leap_check(int year) {    //���� 1, ��� 0
    if (year % 4 != 0) {  //���
        return 0;
    }
    else {
        if (year % 100 == 0 && year % 400 == 0) { //����
            return 1;
        }
        else if (year % 100 == 0 && year % 400 != 0) { //���
            return 0;
        }
        else if (year % 100 != 0) {				//����
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

    cout << "** ���α׷� ���� ��¥ : " << stdate.da_year << "��" << stdate.da_mon << "��" << stdate.da_day << "��" << endl;

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

    cout << "ǰ�� �Է�: ";
    cin.getline(g.item, sizeof(g.item));

    cout << "���� �Է�: ";
    cin >> g.price;

    cout << "������� �Է�: ";
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

        if (leapCheck1 == 0) {  //���
            sum += 365;
        }
        else {
            if (leapCheck1 == 1) { //����
                sum += 366;
            }
            else if (leapCheck1 == 0) { //���
                sum += 365;
            }
            else if (leapCheck1 == 1) {				//����
                sum += 366;
            }
            else { ; }
        }
        calyear += 1;				//�Ǵ� ��� => 1900�⵵���� �Էµ� �⵵�� �����⵵���� => �ݺ��ɶ����� ���ؾ��� 
    }

    for (i = 1; i < m; i++) {				//�Էµ� �⵵ ������ ���翩�ο� ����, ��������� ���� �������� �ϼ� �ٸ��� �ۼ� 
        if ((i == 4) || (i == 6) || (i == 9) || (i == 11)) {
            sum += 30;
        }
        else if (i == 2) {
            if (leapCheck2 == 0) {  //���
                sum += 28;
            }
            else {
                if (leapCheck2 == 1) { //����
                    sum += 29;
                }
                else if (leapCheck2 == 0) { //���
                    sum += 28;
                }
                else if (leapCheck2 == 1) {				//����
                    sum += 29;
                }
                else { ; }
            }
        }
        else {
            sum += 31;
        }
    }

    sum += d;		//���������� ���� �ϼ� �����ֱ� 

    return sum;
}

void selling_price(Goods& g) {
    int daySum1;
    int daySum2;
    int check;

    getdate(&stdate);

    daySum1 = tot_days(g.year, g.mon, g.day);
    daySum2 = tot_days(stdate.da_year, stdate.da_mon, stdate.da_day);
 
    check = daySum1 - daySum2;          //������ѱ��� �󸶳� ���Ҵ��� chseck 
  
    if (check < 0) {            //�Ǽ�1 => �̰� �������Ԥ�
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
        cout << "��������� �������ϴ�!" << endl;
    }
    else {
        cout << "ǰ��: " << g.item << endl;
        cout << "�ǸŰ�: " << g.price << endl;
        cout << "�������: " << g.year << "-" << g.mon << "-" << g.day << endl;        // ??"-"�� ���? '-'�� ���??
        cout << "������: " << g.discount << "%" << endl;
    }

    return;
}

