#include <iostream>
#include <stdlib.h>
using namespace std;

//定义双向链表DblNode
template <typename T>
class DblNode{
public:
	T nodeValue;
	DblNode<T> *prev;
	DblNode<T> *next;

	DblNode()
	{
		next = this;
		prev = this;
	}
	DblNode(const T& value) :nodeValue(value){}
};

//变化情况输出
template <typename T>
void writeDLinkedList(DblNode<T> *first)
{
	DblNode<T> *p = first->next;
        cout << "剩余的小孩列表：";
	while (p != first)
	{
		cout << p->nodeValue << " ";
		p = p->next;
	}

}

//加入
template <typename T>
DblNode<T> *insert(DblNode<T> *current, const T& item)
{
	DblNode<T> *newNode, *prevNode;

	newNode = new DblNode<T>(item);

	prevNode = current->prev;

	newNode->prev = prevNode;
	newNode->next = current;

	prevNode->next = newNode;
	current->prev = newNode;

	return newNode;
}

//删去
template <typename T>
void erase(DblNode<T> *current)
{
	if (current->next == current)
		return;

	DblNode<T> *prevNode = current->prev, *succNode = current->next;

	prevNode->next = succNode;
	succNode->prev = prevNode;

	delete current;
}


//初始化链表+计算
void josephus(int n, int m, int o, int p)
{
	DblNode<int> *first = new DblNode<int>, *current;
	int i, j;
    if (p==1)
	{
	    for (i = o; i <= n; i++)
		insert(first, i);
        for (i = 1; i < o; i++)
        insert(first, i);
	}
    else
	{
	    for (i = o; i > 0; i--)
		insert(first, i);
        for (i = n; i > o; i--)
        insert(first, i);
	}
	current = first->next;

	for (i = 1; i < n; i++)
	{
		writeDLinkedList(first);
		for (j = 1; j <= m - 1; j++)
		{
			current = current->next;

			if (current == first)
				current = current->next;
		}
		cout << "淘汰" << current->nodeValue << "号小孩" << endl;

		current = current->next;
		erase(current->prev);

		if (current == first)
		{
			current = current->next;
		}
	}

	cout << "胜者是" << current->nodeValue << "号小孩" << endl;

	delete current;
	delete first;

}
int main()
{
	int n, m, o, p;
	while(1)
    {
        cout << "请输入小孩个数" << endl;
	    cin >> n;
	    if (n > 1) break;
	    else cout << "输入错误，请选择大于一的整数" << endl;
	}
	while(1)
    {
        cout << "请输入间隔个数" << endl;
	    cin >> m;
	    if (m > 0 && m < n) break;
	    else cout << "输入错误，请选择1到" << n-1 << "间的数字" <<endl;
    }
	while(1)
     {
        cout << "请输入起始位置" << endl;
        cin >> o;
        if (o > 0 && o < n) break;
	    else cout << "输入错误，请选择1到" << n-1 << "间的数字" <<endl;
     }
    while(1)
     {
        cout << "请输入数数方向（1为正数，0为倒数）" << endl;
        cin >> p;
        if (p == 1 || p == 0) break;
	    else cout << "输入错误" <<endl;
     }
	cout << endl << "小孩个数" << n << " 间隔个数" << m << " 起始位置" << o;
	if(p == 1)cout << " 正数"  << endl;
	else cout << " 倒数"  << endl;
	josephus(n, m ,o, p);
}
