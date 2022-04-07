#include "ReverseList.h"

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