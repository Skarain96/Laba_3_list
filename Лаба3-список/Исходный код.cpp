/**
@class list
@brief
Класс, реализующий список.
@note
Содержит методы добавления элемента в определённое место списка, удаления определённого элемента, получения значения определённого элемента и вывода списка на экран.
*/

#include <iostream>
using namespace std;

class list
{
private:
	class item
	{
	private:
		int info;
	public:
		item* next;
		item(int info_, item* next_)
		{
			this->info = info_;
			this->next = next_;
		}
		~item()
		{
		}
		int get()
		{
			return this->info;
		}
	};
	unsigned int len;
	item* head;
public:
	list();
	~list();
	void add(size_t k, int a);
	void del(size_t k);
	int get(size_t k);
	void print();
};

/**
@brief
Конструктор.
*/

list::list()
{
	this->head = nullptr;
	this->len = 0;
}

/**
@brief
Деструктор.
@brief  p
Вспомогательный указатель.
*/

list::~list()
{
	item* p = this->head;
	while (p != nullptr)
	{
		this->head = p->next;
		p->~item();
		p = this->head;
	}
}

/**
@brief
Добавление элемента.
@param k
Позиция элемента.
@param a
Значение элемента.
*/

void list::add(size_t k, int a)
{
	if (this->len == 0)
	{
		item * p = new item(a, nullptr);
		this->head = p;
	}
	else
	{
		if (k == 1)
		{
			item * p = new item(a, this->head);
			this->head = p;
		}
		else
		{
			if (k > this->len)
			{
				item* p = this->head;
				for (unsigned int i = 1; i < this->len; i++)
				{
					p = p->next;
				}
				p->next = new item(a, nullptr);
			}
			else
			{
				item* p = this->head;
				for (unsigned int i = 1; i < k; i++)
				{
					p = p->next;
				}
				p->next = new item(a, p->next);
			}
		}
	}
	this->len++;
}

/**
@brief
Удаление элемента.
*/

void list::del(size_t k)
{
	item* p = this->head;

	if (k == 1)
	{
		this->head = p->next;
		p->~item();
	}
	else
	{
		for (unsigned int i = 2; i < k; i++)
		{
			if (p->next->next == nullptr) break;
			p = p->next;
		}
		item* t = p->next;
		p->next = t->next;
		t->~item();
	}
}

/**
@brief
Получение значения элемента.
*/

int list::get(size_t k)
{
	item* p = this->head;
	for (unsigned int i = 1; i < k; i++)
	{
		p = p->next;
	}
	return p->get();
}

/**
@brief
Печать списка.
*/

void list::print()
{
	item* p = this->head;
	while (p != nullptr)
	{
		cout << p->get() << " ";
		p = p->next;
	}
}

void main()
{
	int N, k, ak;
	cin >> N;
	list A = list();
	for (int i = 0; i < N; i++)
	{
		cin >> k >> ak;
		A.add(k, ak);
	}
	cin >> k;
	A.del(k);
	A.print();
}