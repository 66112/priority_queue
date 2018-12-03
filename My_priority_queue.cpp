#include <iostream>
#include <vector>
using namespace std;

template<class T,class Container = vector<T>,class Compare = less<T>>   //Ä¬ÈÏ´ó¶Ñ
class My_Priority_Queue
{
private:
	void AdjustUp(int pos)
	{
		while (pos > 0)
		{
			int parent = (pos - 1) / 2;
			if (_con[pos] > _con[parent])
			{
				swap(_con[pos], _con[parent]);
				pos = parent;
			}
			else
				break;
		}
	}
	void AdjustDown(int pos)
	{
		size_t child = pos * 2 + 1;
		while (child < _con.size())
		{
			if (((child + 1) < _con.size()) && _con[child] < _con[child + 1])
			{
				child++;
			}
			if (_con[child] > _con[pos])
			{
				swap(_con[child], _con[pos]);
				pos = child;
				child = pos * 2 + 1;
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
	p1.Pop_Back();
	while (!p1.Empty())
	{
		cout << p1.Top() << endl;
		p1.Pop_Back();
	}
}
int main()
{
	Test1();
	return 0;
}