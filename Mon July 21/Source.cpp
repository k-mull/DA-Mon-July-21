#include <iostream>
#include "Time.h"
using namespace std;
void testTimeAssignment();
void testTimeSlimplify();
void testTimeAddition();
void testTimeSubtraction();
void testTimeExtractionOp();
void testTimeIntegerConversion();
void testTimeRelationalOp();
int main()
{
	//testTimeAssignment();
	//testTimeSlimplify();
	//testTimeAddition();
	//testTimeSubtraction();
	//testTimeExtractionOp();
	//testTimeIntegerConversion();
	testTimeRelationalOp();
}
void testTimeAssignment()
{
	Time now(10, 22);
	Time classStart(9, 40);
	cout << now.getHours() << ":" << now.getMinutes() << endl; 

	now = classStart;
	cout << now.getHours() << ":" << now.getMinutes() << endl; 

}
void testTimeSlimplify()
{
	Time myTime(36, 61, 61);
	Time myOtherTime(-1, -1, -1);
	cout << myTime.getDays() << " " << myTime.getHours() << ":"
		<< myTime.getMinutes() << " " << myTime.getSeconds() << endl; 
	myTime.simplify();
	cout << myTime.getDays() << " " << myTime.getHours() << ":"
		<< myTime.getMinutes() << " " << myTime.getSeconds() << endl;
	
	cout << myOtherTime.getDays() << " " << myOtherTime.getHours() << ":"
		<< myOtherTime.getMinutes() << " " << myOtherTime.getSeconds() << endl;
	myOtherTime.simplify();
	cout << myOtherTime.getDays() << " " << myOtherTime.getHours() << ":"
		<< myOtherTime.getMinutes() << " " << myOtherTime.getSeconds() << endl;

}
void testTimeAddition()
{
	Time now(3, 38);
	Time end(4, 38);

	Time later = now + end;
	cout << later.getDays() << " " << later.getHours() << ":"
		<< later.getMinutes() << " " << later.getSeconds() << endl; 
}
void testTimeSubtraction()
{
	Time now(3, 38);
	Time end(4, 38);

	Time later = end -now;
	cout << later.getDays() << " " << later.getHours() << ":"
		<< later.getMinutes() << " " << later.getSeconds() << endl;

}
void testTimeExtractionOp()
{
	Time now(0, 12, 17, 32);
	cout << now;
}
void testTimeIntegerConversion()
{
	Time classTomorrow(1, 9, 40, 0);
	cout << static_cast<int>(classTomorrow) << endl; 
	cout << 1 + classTomorrow;
}
void testTimeRelationalOp()
{
	Time dinner(8, 15);
	Time newDinner(7, 15);

if( dinner > newDinner)
cout << dinner;
if (dinner < newDinner)
	cout << newDinner;
if (dinner == newDinner)
cout << "They are equal." << endl; 

}