#include "ReverseList.h"

int main(void)
{
	//Node* head = nullptr;
	system("chcp 1251");
	system("cls");
	List list;
	list.Print();
	// ������� ������, �������� �������� � ������
	for (int i = 0; i < 10; i++)
	{
		int z;
		cout << ">> ";
		cin >> z;
		list.AddNode(z);
	}
	cout << "C�����: " << endl;
	list.Print();
	cout << "��������� �������: " << list.GetData(list.GetLastNode()) << endl;
	cout << endl;
	// �������� ������
	Node* head = list.GetFirstNode();
	list.ReverseList();
	cout << "����������� ������: " << endl;
	list.Print();
	// ������� ��������, ������ 0
	Node* p = list.GetFirstNode();
	do {
		if (list.GetData(p) == 0)
			p = list.DelNode(p);
		else
			p = list.NextNode(p);
	} while (p != NULL);
	cout << "C����� ��� ����: " << endl;
	list.Print();
	cout << "� ������ " << list.GetCount() << " ��������� (������ � ��������� ���������� �������):" << endl;
	list.Swap(list.GetFirstNode(), list.GetLastNode());
	list.Print();
	list.DelList();
	list.Print();
	cout << endl;
	cout << "� ������ " << list.GetCount() << " ���������" << endl;
	//cin.get(); 
	return 0;
}