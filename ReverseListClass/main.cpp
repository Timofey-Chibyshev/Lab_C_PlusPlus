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
	Node* DelNode(Node*);            // удаление узла
	void DelList();        // Очистка списка
	void ReverseList();  //разворотт списка
	void Print();        // Вывод значений узлов списка
	void Swap(Node*, Node*);  // Взаимообмен двух узлов
};

Node* List::AddNode(int value, Node* a = nullptr)
{
	Node* elem = new Node();
	elem->_data = value;
	_count++;
	if (a == NULL) // Добавление нового корня
	{
		if (_head == NULL) {
			elem->next = NULL;
			_head = elem;
		}
		else {
			elem->next = _head;
			_head = elem;
		}
		return elem;
	}
	elem->next = a->next; // Добавление узла после текущего
	a->next = elem;
	return elem;
}

Node* List::DelNode(Node* a)
{
	if (a == NULL) { return NULL; } // В списке нет узлов
	_count--;
	if (a == _head)  // Удаление корневого узла
	{
		_head = a->next;
		delete a;
		return _head;
	}
	Node* prev = PrevNode(a); // Удаление промежуточного узла
	prev->next = a->next;
	delete a;
	return prev;
}

Node* List::NextNode(Node* a)
{
	if (IsEmpty()) return NULL;
	return a->next;
}

Node* List::PrevNode(Node* a)
{
	if (IsEmpty()) return NULL;
	if (a == _head) return NULL;
	Node* p = _head;
	while (p->next != a)
		p = p->next;
	return p;
}

Node* List::GetLastNode()
{
	Node* p = _head;
	while (NextNode(p) != NULL)
		p = NextNode(p);
	return p;
}

void List::DelList()
{
	class Node* p = _head;
	if (p == NULL) return;
	do {
		Node* d = p;
		p = NextNode(p);
		delete d;
	} while (p != NULL);
	_count = 0;
	_head = NULL;
}

void List::Print()
{
	if (IsEmpty()) { cout << "Список пуст" << endl; return; }
	Node* p = _head;
	do {
		cout << GetData(p) << " ";
		p = NextNode(p);
	} while (p != NULL);
	cout << endl;
	cout << endl;
}

void List::Swap(Node* a, Node* b)
{
	if (a == NULL || b == NULL) return; // не допускаем обмен с несуществующим узлом
	if (a == b) return; // если один узел указан дважды, менять ничего не надо
	if (b->next == a) // если node2 находится перед node1, меняем их местами
	{
		Node* p = a;
		a = b;
		b = p;
	}
	Node* prev1 = PrevNode(a);
	Node* prev2 = PrevNode(b);
	Node* next1 = NextNode(a);
	Node* next2 = NextNode(b);
	if (next1 == b) // обмен соседних узлов
	{
		if (prev1 != NULL)
			prev1->next = b;
		else
			_head = b;
		b->next = a;
		a->next = next2;
		return;
	}
	if (prev1 != NULL)  // обмен отстоящих узлов
		prev1->next = b;
	else
		_head = b;
	if (prev2 != NULL)
		prev2->next = a;
	else
		_head = a;
	b->next = next1;
	a->next = next2;
}

void List::ReverseList()
{
	Node* cur = _head;
	Node* first = GetFirstNode();
	Node* last = GetLastNode();
	Node* a = nullptr;
	Node* b = nullptr;
	Node* tmp;
	//int counter = 0;
	int counter = 0.5 * _count;
	while (counter)
	{
		Swap(first, last);
		//tmp = first;
		//first = last;
		//last = tmp;
		/*if (counter % 2 == 1)
		{
			tmp = first;
			first = NextNode(last);
			last = PrevNode(tmp);
		}
		if ((counter != 0) && (counter % 2 == 0))
		{
			tmp;
			first = NextNode();
			last = PrevNode();
		}*/
		tmp = first;
		first = NextNode(last);
		last = PrevNode(tmp);
		counter--;
	}
}

int main(void)
{
	//Node* head = nullptr;
	system("chcp 1251");
	system("cls");
	List list;
	list.Print();
	// Создаем список, помещаем элементы в начало
	for (int i = 0; i < 10; i++)
	{
		int z;
		cout << ">> ";
		cin >> z;
		list.AddNode(z);
	}
	cout << "Cписок: " << endl;
	list.Print();
	cout << "Последний элемент: " << list.GetData(list.GetLastNode()) << endl;
	cout << endl;
	// Разворот списка
	Node* head = list.GetFirstNode();
	list.ReverseList();
	cout << "Развернутый список: " << endl;
	list.Print();
	// Удаляем элементы, равные 0
	Node* p = list.GetFirstNode();
	do {
		if (list.GetData(p) == 0)
			p = list.DelNode(p);
		else
			p = list.NextNode(p);
	} while (p != NULL);
	cout << "Cписок без нуля: " << endl;
	list.Print();
	cout << "В списке " << list.GetCount() << " элементов (первый и последний поменялись местами):" << endl;
	list.Swap(list.GetFirstNode(), list.GetLastNode());
	list.Print();
	list.DelList();
	list.Print();
	cout << endl;
	cout << "В списке " << list.GetCount() << " элементов" << endl;
	//cin.get(); 
	return 0;
}