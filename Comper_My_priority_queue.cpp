#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Less
{
public:
	bool operator()(const T& x,const T& y)
	{
		return x > y;
	}
};
template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};
// 数据类型 ， 适配器 ，仿函数
template<class T,class Container = vector<T>,class Compare = Less<T>>   //默认大堆
class My_Priority_Queue
{
private:
	void AdjustUp(int child)
	{
		Compare _com;
		while (child > 0)
		{
			int parent = (child - 1) / 2;
			//if (_con[parent] < _con[child])
			if(_com(_con[parent], _con[child]))
			{
				swap(_con[child], _con[parent]);
				child = parent;
			}
			else
				break;
		}
	}
	void AdjustDown(int parent)
	{
		Compare _com;
		size_t child = parent * 2 + 1;
		while (child < _con.size())
		{
			//if (((child + 1) < _con.size()) && _con[child] < _con[child + 1])
			if (((child + 1) < _con.size()) && (_com(_con[child],_con[child+1])))
			{
				child++;
			}
			//if (_con[parent] < _con[child])
			if (_com(_con[parent], _con[child]))
			{
				swap(_con[child], _con[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
public:
	void Push_Back(const T& d)
	{
		_con.push_back(d);
		AdjustUp(_con.size()-1);
	}
	void Pop_Back()
	{
		if (_con.size())
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
	}
	const T& Top()
	{
		return _con[0];
	}
	bool Empty()
	{
		return _con.empty();
	}
	size_t Size()
	{
		return _con.size();
	}
private:
	Container _con;
};

void Test1()
{
	My_Priority_Queue<int> p1;
	p1.Push_Back(1);
	p1.Push_Back(9);
	p1.Push_Back(8);
	p1.Push_Back(0);
	p1.Push_Back(5);
	//p1.Pop_Back();
	while (!p1.Empty())
	{
		cout << p1.Top() << " ";
		p1.Pop_Back();
	}
	cout << endl;
}
int main()
{
	Test1();
	return 0;
}