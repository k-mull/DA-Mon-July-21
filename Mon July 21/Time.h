#ifndef TIME
#define TIME
#include <iostream>
class Time
{
private:
	int days, hours, minutes, seconds;
public:
	Time();
	Time(int d, int h, int m, int s);
	Time(int h, int m, int s);
	Time(int h, int m);
	void simplify();
	int getDays() const;
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	Time operator +(Time& right);
	Time operator -(Time& right);
	friend std::ostream& operator<<(std::ostream& strm, Time& obj);
	bool operator<(Time& right);
	bool operator>(Time& right);
	bool operator==(Time& right);
	bool operator<=(Time& right);
	bool operator>=(Time& right);

	operator int();

};
#endif

