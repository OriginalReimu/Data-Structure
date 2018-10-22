#include <iostream>
#include <stdlib.h>
using namespace std;

//����˫������DblNode
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

//�仯������
template <typename T>
void writeDLinkedList(DblNode<T> *first)
{
	DblNode<T> *p = first->next;
        cout << "ʣ���С���б�";
	while (p != first)
	{
		cout << p->nodeValue << " ";
		p = p->next;
	}

}

//����
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

//ɾȥ
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


//��ʼ������+����
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
		cout << "��̭" << current->nodeValue << "��С��" << endl;

		current = current->next;
		erase(current->prev);

		if (current == first)
		{
			current = current->next;
		}
	}

	cout << "ʤ����" << current->nodeValue << "��С��" << endl;

	delete current;
	delete first;

}
int main()
{
	int n, m, o, p;
	while(1)
    {
        cout << "������С������" << endl;
	    cin >> n;
	    if (n > 1) break;
	    else cout << "���������ѡ�����һ������" << endl;
	}
	while(1)
    {
        cout << "������������" << endl;
	    cin >> m;
	    if (m > 0 && m < n) break;
	    else cout << "���������ѡ��1��" << n-1 << "�������" <<endl;
    }
	while(1)
     {
        cout << "��������ʼλ��" << endl;
        cin >> o;
        if (o > 0 && o < n) break;
	    else cout << "���������ѡ��1��" << n-1 << "�������" <<endl;
     }
    while(1)
     {
        cout << "��������������1Ϊ������0Ϊ������" << endl;
        cin >> p;
        if (p == 1 || p == 0) break;
	    else cout << "�������" <<endl;
     }
	cout << endl << "С������" << n << " �������" << m << " ��ʼλ��" << o;
	if(p == 1)cout << " ����"  << endl;
	else cout << " ����"  << endl;
	josephus(n, m ,o, p);
}
