/* 2022/2/10 c++����
�ð�����, ���

??this�������� ����??
?? const�� ���� ���� ??
??�����ð� ǥ��?? ����ó��??
?? this�� ������ �ɹ� �Լ� �������� �����ϴ�??

??������ü�� �����ؾ��ϴµ� const Time&�� ���� ����...=> �� member�Լ� ���� �Ǵٸ� ��ü �����> -> edit1 ==> ����return type�� �ٸ�.....
	==> �׷� �����Լ� ����غ���?? ==> �����ش� plus�Լ� ������ Time type�� ��ü �����غ���? -> edit2

	
 �߿�,�ٽ�!! => constȭ�� ������ü�� para�� �ް� �ش� Ÿ���� return �ϴ� �ɹ��Լ� ������ ������ü�� ���� ������ ������ �����ϰ��� �� �� �ش� �Լ� ������ (���� Ÿ�԰�)���� Ÿ���� ��ü�� �����Ͽ� 
				//�ش� ��ü�� �����Ѵ�!
	
	
*/
#include<iomanip>
#include<iostream>
using namespace std;
class Time {
private:
	int hour;
	int min;

public:
	Time();		//default cons
	Time(int, int);
	Time(double);
	Time(const Time&);	// ???copy cons(class�ڽ��� ������ü�� ��������(para)�� �޴� cons)
	Time plus(const Time&);		//class�� �ɹ��Լ� => �ش� �ɹ��Լ��� ȣ���� ��ü�� ���Ҹ� �޴�  Time* const this�����͸� �������ڷ� ��������   
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
	~Time() { ; }	//�ۼ� ���ص� ��??
};

Time::Time() {
	hour = 0;		//this->hour
	min = 0;		//this->min
}

Time::Time(int hour, int min) {		//?? para�� �ʱ�ȸ ���� �ʾҴٴ� ��� �ذ�??=> �������ڸ� ������ �Լ� call�� �ذ�??
	int hourPlus;

	this->hour = hour;
	if (min >= 0 && min <= 59) {
		this->min = min;
	}
	else if (min >= 60) {
		hourPlus = min / 60;
		this->min = min % 60;
		hour += hourPlus;
	}
	else { ; }
}

Time::Time(double hour) {
	this->hour = (int)(hour / 1);			//�ڵ� ����ȯ�̶� ���� �ֳ�??
	this->min = (int)(((double)this->hour - hour) * 60);

}

Time::Time(const Time& tr) {
	this->hour = tr.hour;
	this->min = tr.min;
}


int main() {
	//	Time a(&a, 3, 20);		//?? a�� ���ǵ��� �ʾҴٰ� ���� �� 
	//	Time b(&b);
	Time a(3, 20);
	Time b;


	cout << a.getHour() << "�ð� " << a.getMin() << "��" << endl;

	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "�ð� " << b.getMin() << "��" << endl;

	Time res = a.plus(b);
//	cout << "�� �ð��� ���ϸ�: " << res.getHour() << "�ð� " << b.getMin() << "��" << endl;		//�޸տ��� : ��ü�� �߸� �ۼ�(res�� b��)
	cout << "�� �ð��� ���ϸ�: " << res.getHour() << "�ð� " << res.getMin() << "��" << endl;
	return 0;
}

//Time plus(const Time &tr) {		//����!: member�Լ��� ��ü��Ʋ �ۿ��� ����=> ::�� ���̱�!!
Time Time::plus(const Time& tr) {		// ����: ������ �����ϴ� �Լ� 
	Time c;
	int hourPlus;
	int sumHour;
	int sumMin;

	sumHour = this->hour + tr.hour; //? ? this�� ������ �ɹ� �Լ� �������� �����ϴ� ? ? => class�� �ɹ��Լ���� ::������ ǥ�ð� ��� ���� 
//	tr.hour = sumHour;				//����: para�� const Time& tr => ���� tr�� lv�� ��� �Ұ�!
//	this->hour = sumHour;

	sumMin = this->min + tr.min;
	if (sumMin >= 0 && sumMin <= 59) {
		//		this->min = sumMin;
		;
	}
	else if (sumMin >= 60) {
		hourPlus = sumMin / 60;
		sumHour += hourPlus;
		sumMin %= 60;
		//	this->hour += hourPlus;
		//	this->min = sumMin % 60;
	}
	else { ; }

	c.hour = sumHour;
	c.min = sumMin;

	return c;
}

void Time::setHour(int h) {
	this->hour = h;

	return;
}

void Time::setMin(int m) {
	this->min = m;

	return;
}

int Time::getHour() {

	return this->hour;
}

int Time::getMin() {

	return this->min;
}


