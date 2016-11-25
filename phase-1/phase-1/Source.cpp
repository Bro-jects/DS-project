#include <iostream>
using namespace std;

#include<iostream>
#include<fstream>
using namespace std;
struct TOWER
{
	int TH;
	int TP;
	int N;
	char state;
};
struct castle {
	TOWER tower[4];
	int health;
	char state;
};
struct ENEMY
{
	int S;
	int TY;
	int T;
	int H;
	int Pow;
	int Prd;
	char R;
	int speed;
	char state;
};
struct node
{
	ENEMY enemy;
	node* link;
};
struct node1
{
	TOWER tower;
	node1* link;
};
struct queue {
	node* front; node* rear;
};
void creat_node(node*& head)
{
	if (head == NULL)
	{
		head = new node;
		return;
	}
	node* Ptr = new node;
	node* p = head;
	while (p->link != NULL)
		p = p->link;
	p->link = Ptr;
	Ptr->link = NULL;
}
void creat_node1(node1*& head)
{
	if (head == NULL)
	{
		head = new node1;
		return;
	}
	node1* Ptr = new node1;
	node1* p = head;
	while (p->link != NULL)
		p = p->link;
	p->link = Ptr;
	Ptr->link = NULL;
}
void Delete_node(node*& head, node* del)
{
	if (head == del)
	{
		head = head->link;
		delete del;
		return;
	}
	node* pre = head;
	while (pre->link != del)
		pre = pre->link;
	pre->link = del->link;
	delete del;
}
void Delete_node(node1*& head, node1* del)
{
	if (head == del)
	{
		head = head->link;
		delete del;
		return;
	}
	node1* pre = head;
	while (pre->link != del)
		pre = pre->link;
	pre->link = del->link;
	delete del;
}
void Read_Input_File(node*& head, node1*& Head, node*& head_active, int& C1, int& C2, int& C3)
{
	head = new node;
	Head = new node1;
	head_active = new node;
	node* Ptr = head; node1* n_ptr = Head; node* ptr = head_active;
	ifstream file;
	file.open("input.txt", ios::in);
	while (!file.is_open())
	{
		cout << "file does not exist" << endl;
		cout << "please add your input file to this project folder then press enter" << endl;
		char x[1];
		cin.getline(x, '\n');
		file.open("input.txt", ios::in);
	}
	file >> Head->tower.TH >> Head->tower.N >> Head->tower.TP;
	while (n_ptr != NULL)
	{
		creat_node1(Head);
		n_ptr = n_ptr->link;
		n_ptr->tower = Head->tower;
	}
	file >> C1 >> C2 >> C3;
	int x;
	file >> x;
	while (x != -1)
	{
		if (Ptr->enemy.T > 1)
		{
			Ptr->enemy.S = x;
			file >> Ptr->enemy.TY >> Ptr->enemy.T >> Ptr->enemy.H >> Ptr->enemy.Pow >> Ptr->enemy.Prd >> Ptr->enemy.R;
			creat_node(head);
			Ptr = Ptr->link;
		}
		else
		{
			ptr->enemy.S = x;
			file >> ptr->enemy.TY >> ptr->enemy.T >> ptr->enemy.H >> ptr->enemy.Pow >> ptr->enemy.Prd >> ptr->enemy.R;
			creat_node(head_active);
			ptr = ptr->link;
		}
		file >> x;
		if (x == -1)
		{
			Delete_node(head, Ptr);
			Delete_node(head_active, ptr);
		}
	}
	Ptr = NULL;
	n_ptr = NULL;
	file.close();
}
void Simulator(node*& head, node1*& Head, node*& head_active, int C1, int C2, int C3, int i)
{

	Read_Input_File(head, Head, head_active, C1, C2, C3);
	node* p = head; node* n = head_active;
	while (n != NULL && n->link != NULL)
		n = n->link;
	while (p != NULL)
	{
		if (p->enemy.T == i)
		{
			creat_node(head_active);
			n->enemy = p->enemy;
			Delete_node(head, p);
			n = n->link;
		}
		p = p->link;
	}
}