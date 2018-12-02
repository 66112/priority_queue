//#include <iostream>
//#include <queue>
//#include <functional>
//using namespace std;
//
//class Date
//{
//public:
//	Date(){}
//	Date(const int year,const int month	, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	friend ostream& operator<<(ostream& out, const Date& d);
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	bool operator < (const Date& d) const
//	{
//		if (_year < d._year)
//			return true;
//		else
//			return false;
//	}
//private:
//	int _year = 2000;
//	int _month = 1;
//	int _day = 1;
//};
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;
//}
//
//void Test1()
//{
//	//priority_queue<int,vector<int>,greater<int>> pq;     //优先级队列，默认大堆
//	//pq.push(1);
//	//pq.push(8);
//	//pq.push(3);
//	//pq.push(4);
//	/*while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;*/
//	Date d1;
//	Date d2(1999, 1, 20);
//	Date d3(1998, 2, 28);
//	Date d4(d1);
//
//	priority_queue<Date> pqd;
//	pqd.push(d1);
//	pqd.push(d2);
//	pqd.push(d3);
//	pqd.push(d4);
//	while (!pqd.empty())       //排堆要重载 < 或 >
//	{
//	cout << pqd.top() << " ";
//	pqd.pop();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Test1();
//	return 0;
//}