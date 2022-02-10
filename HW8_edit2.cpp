/* 2022/2/10 c++과제
시간저장, 출력

??this포인터의 생략??
?? const를 쓰는 순서 ??
??음수시간 표현?? 예외처리??
?? this는 비정적 맴버 함수 내에서만 가능하다??

??참조객체를 리턴해야하는데 const Time&라 수정 못함...=> 걍 member함수 내에 또다른 객체 만들까> -> edit1 ==> ㄴㄴreturn type이 다름.....
	==> 그럼 수정함수 사용해볼까?? ==> ㄴㄴ해당 plus함수 내에서 Time type의 객체 선언해볼까? -> edit2

	
 중요,핵심!! => const화된 참조객체를 para로 받고 해당 타입을 return 하는 맴버함수 내에서 참조객체를 통해 수정한 내용을 리턴하고자 할 때 해당 함수 내에서 (리턴 타입과)같은 타입의 객체를 선언하여 
				//해당 객체를 리턴한다!
	
	
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
	Time(const Time&);	// ???copy cons(class자신의 참조객체를 전달인자(para)로 받는 cons)
	Time plus(const Time&);		//class의 맴버함수 => 해당 맴버함수를 호출한 객체의 구소를 받는  Time* const this포인터를 전달인자로 갖고있음   
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
	~Time() { ; }	//작성 안해도 됨??
};

Time::Time() {
	hour = 0;		//this->hour
	min = 0;		//this->min
}

Time::Time(int hour, int min) {		//?? para가 초기회 되지 않았다는 경고 해결??=> 전달인자를 포함한 함수 call로 해결??
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
	this->hour = (int)(hour / 1);			//자동 형변환이랑 차이 있나??
	this->min = (int)(((double)this->hour - hour) * 60);

}

Time::Time(const Time& tr) {
	this->hour = tr.hour;
	this->min = tr.min;
}


int main() {
	//	Time a(&a, 3, 20);		//?? a가 정의되지 않았다고 오류 뜸 
	//	Time b(&b);
	Time a(3, 20);
	Time b;


	cout << a.getHour() << "시간 " << a.getMin() << "분" << endl;

	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "시간 " << b.getMin() << "분" << endl;

	Time res = a.plus(b);
//	cout << "두 시간을 더하면: " << res.getHour() << "시간 " << b.getMin() << "분" << endl;		//휴먼에러 : 객체명 잘못 작성(res를 b라)
	cout << "두 시간을 더하면: " << res.getHour() << "시간 " << res.getMin() << "분" << endl;
	return 0;
}

//Time plus(const Time &tr) {		//주의!: member함수를 객체형틀 밖에서 정의=> ::꼭 붙이기!!
Time Time::plus(const Time& tr) {		// 개념: 참조를 리턴하는 함수 
	Time c;
	int hourPlus;
	int sumHour;
	int sumMin;

	sumHour = this->hour + tr.hour; //? ? this는 비정적 맴버 함수 내에서만 가능하다 ? ? => class의 맴버함수라는 ::연산자 표시가 없어서 오류 
//	tr.hour = sumHour;				//주의: para가 const Time& tr => 변수 tr을 lv로 사용 불가!
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


