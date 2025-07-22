#include "Time.h"
#include <cstdlib>
Time::Time()
{
	days = 0;
	hours = 0;
	seconds = 0;
	minutes = 0;

}
Time::Time(int d, int h, int m, int s)
{
	days = d;
	hours = h;
	minutes = m;
	seconds = s;
}
Time::Time(int h, int m, int s)
{
	seconds = 0;
	hours = h;
	minutes = m;
	seconds = s;
	days = 0;
}
Time::Time(int h, int m)
{
	days = 0;
	hours = h;
	minutes = m;
	seconds = 0;
}
void Time:: simplify()
{
	if (seconds >= 60) 
	{
		minutes += seconds / 60;
		seconds = seconds % 60;
	}
	if (seconds < 0)
	{
		minutes -= (abs(seconds) / 60 + 1);
		seconds = 60 - (abs(seconds) % 60);
	}
	if (minutes >= 60)
	{
		hours += minutes / 60;
		minutes = minutes % 60;
	}
	if (minutes < 0)
	{
		hours -= (abs(minutes) / 60 + 1);
		minutes = 60 -  (abs(minutes) % 60);
	}
	if (hours >= 24)
	{
		days += hours / 24;
		hours = hours % 24;
	}
	if (hours < 0)
	{
		days -= (abs(hours) / 24 + 1);
		hours = 24 - (abs(hours) % 24);
	}
}
int Time::getDays() const
{
	return days;
}
int Time::getHours() const
{
	return hours;
}
int Time::getMinutes() const
{
	return minutes;
}
int Time::getSeconds() const
{
	return seconds;
}
Time Time::operator +(Time& right)
{
	Time tempTime;
	tempTime.hours = this->hours + right.hours;
	tempTime.days = this->days + right.days;
	tempTime.minutes = this->minutes + right.minutes;
	tempTime.seconds = this->seconds + right.seconds;
	tempTime.simplify();
	return tempTime;
}
Time Time::operator -(Time& right)
{
	Time tempTime;
	tempTime.hours = this->hours - right.hours;
	tempTime.days = this->days - right.days;
	tempTime.minutes = this->minutes - right.minutes;
	tempTime.seconds = this->seconds - right.seconds;
	tempTime.simplify();
	return tempTime;
}
std::ostream& operator<<(std::ostream& strm, Time& obj)
{
	strm << obj.getDays() << " " << obj.getHours() << ":"
		<< obj.getMinutes() << " " << obj.getSeconds() << std::endl; 
	return strm;
}

Time::operator int()
{
	int totalSeconds = 0;
	totalSeconds = seconds + (60 * minutes) + (60 * hours * 60) + (24 * 60 * 60 *days);
	return totalSeconds;
}
bool Time::operator<(Time& right)
{
	if (this->days < right.days)
		return true;
	else if (this->days == right.days)
		if (this->hours < right.hours)
			return true;
		else if (this->hours == right.hours)
			if (this->minutes < right.minutes)
				return true;
			else if (this->minutes == right.minutes)
				if (this->seconds < right.seconds)
					return true;
	return false;

}
bool Time::operator>(Time& right)
{
	if (this->days  > right.days)
		return true;
	else if (this->days == right.days)
		if (this->hours > right.hours)
			return true;
		else if (this->hours == right.hours)
			if (this->minutes > right.minutes)
				return true;
			else if (this->minutes == right.minutes)
				if (this->seconds > right.seconds)
					return true;
	return false;
}
bool Time::operator==(Time& right)
{
	return days == right.days &&
		hours == right.hours &&
		minutes == right.minutes &&
		seconds == right.seconds;
}