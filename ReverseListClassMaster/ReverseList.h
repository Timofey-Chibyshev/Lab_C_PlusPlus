#pragma once
#include <iostream>
using namespace std;

class Node
{
	int _data;
	class Node* next;
	friend class List;
};

class List
{
	Node* _head;
	int _count = 0; // Количество узлов списка
	Node* PrevNode(Node*); // Переход к предыдущему узлу (не интерфейсный метод)

public:
	List() { _head = nullptr; }
	int GetData(Node* a) { return a->_data; }
	int GetCount() { return _count; } // Получение количества узлов списка
	void SetData(Node* a, int data) { a->_data = data; }
	bool IsEmpty() { return _head == nullptr; }
	Node* GetFirstNode() { return _head; }
	Node* GetLastNode();      // Получение последнего узла списка
	Node* NextNode(Node*);      // Переход к следующему узлу
	Node* AddNode(int, Node*);  // добавление узла
	Node* AddNode(int);  // добавление узла
	Node* DelNode(Node*);            // удаление узла
	void DelList();        // Очистка списка
	void ReverseList();  //разворотт списка
	void Print();        // Вывод значений узлов списка
	void Swap(Node*, Node*);  // Взаимообмен двух узлов
};