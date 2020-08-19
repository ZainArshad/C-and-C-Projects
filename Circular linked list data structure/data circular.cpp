#include<iostream>
using namespace std;

template<class T>
class node{
public:
	T data;
	node*next;
	node*prev;

	node()
	{
		prev = 0;
		next = 0;
	}

};

template<typename T>
class DLLADT{
	node<T>*first;
public:
	DLLADT()
	{
		first = 0;
	}

	node<T>*get()
	{
		return first;
	}

	void insert(T a)
	{
		/*if (a > 9 || a<0)
		{
		return;
		}*/
		node<T>*curr = new node<T>;
		curr->data = a;
		if (first == 0)
		{
			first = curr;
		}
		else
		{
			node<T>*t = new node<T>;
			t = first;
			if (t->next != 0)
			{
				while (t->next != first)
				{
					t = t->next;
				}
			}
			t->next = curr;
			t->next->prev = t;
			t->next->next = first;
			first->prev = t->next;
		}
	}

	int count()
	{
		int o = 0;
		node<T>*t = new node<T>;
		t = first;
		if (first != 0)
		if (t->next != 0)
		{
			while (t->next != first)
			{
				t = t->next;
				o++;
			}
		}
		o++;
		return o;
	}

	bool removeFirst()
	{
		if (first != 0)
		{
			if (first->next == 0)
			{
				delete first;
				first = 0;
				return true;
			}
			else
			{
				node<T>*t = new node<T>;
				t = first;
				first->prev->next = first->next;
				first->next->prev = first->prev;
				first = first->next;
				/*first->prev = t->prev;
				t->prev = first->next;*/
				t->next = 0;
				t->prev = 0;
				delete t;
				return true;
			}
		}
		return false;
	}

	void printForward()
	{
		if (first != 0)
		{

			node<T>*t = new node<T>;
			t = first;
			if (first->next != 0)
			while (t->next != first)
			{
				cout << t->data;
				t = t->next;


			}
			cout << t->data;
		}
	}

	void printBackward()
	{
		if (first != 0)
		{

			node<T>*t = new node<T>;
			t = first;
			if (first->next != 0)
			while (t->next != first)
			{
				t = t->next;


			}
			while (t->prev != first->prev)
			{
				cout << t->data;
				t = t->prev;


			}
			cout << t->data;
		}
	}

	bool removefromPositon(int index)
	{
		if (first != 0)
		{
			if (first->next == 0)
			{
				if (index == 0)
				{
					delete first;
					first = 0;
					return true;
				}
			}
			else
			{
				int count = 0;
				node<T>*t = new node<T>;
				t = first;
				while (t->next != first)
				{
					if (count == index)
					{
						t->prev->next = t->next;
						t->next->prev = t->prev;
						delete t;
						return true;
					}
					t = t->next;
					count++;
				}
				if (first != 0)
				{
					if (count == index)
					{
						t->prev->next = first;
						first->prev = t->prev;
						t->next = 0;
						t->prev = 0;
						delete t;
						return true;
					}
				}
			}
		}
		return false;
	}

	bool remove(T a)
	{
		if (first != 0)
		{
			if (first->next == first || first->next == 0)
			{
				if (first->data == a)
				{
					delete first;
					first = 0;
					return true;
				}
			}
			else
			{
				node<T>*t;
				t = first;
				if (first != 0)
				{
					if (t == first)
					{
						if (t->data == a)
						{
							node<T>*o = t;
							t = t->next;
							t->prev = t->prev->prev;
							t->prev->next = t;
							o->next = 0;
							o->prev = 0;
							delete o;
							first = t;
							return true;
						}
					}
				}
				if (first != 0)
				while (t->next != first)
				{
					if (t->data == a)
					{
						t->prev->next = t->next;
						t->next->prev = t->prev;
						t->next = 0;
						t->prev = 0;
						delete t;
						return true;
					}
					t = t->next;
				}
				if (first != 0)
				{
					if (t->data == a)
					{
						t->prev->next = first;
						first->prev = t->prev;
						t->next = 0;
						t->prev = 0;
						delete t;
						return true;
					}
				}
			}
		}
		return false;
	}

	~DLLADT()
	{
		clear();
	}

	void clear()
	{
		node<T>*t = new node<T>;
		if (first != 0)
		{
			if (first->next == 0)
			{
				delete first;
				first = 0;
			}
			else
			{

				while (first->next != first)
				{
					t = first;
					first->prev->next = first->next;
					first->next->prev = first->prev;
					first = first->next;
					/*first->prev = t->prev;
					t->prev = first->next;*/
					t->next = 0;
					t->prev = 0;
					delete t;
				}
			}
		}
		t = 0;
		first = t;
	}



};

int main()
{
	DLLADT<int>o1;
	o1.insert(3);
	o1.insert(4);
	o1.insert(5);
	o1.insert(5);
	//o.clear();
	//	o.clear();
	o1.printForward();
	o1.printBackward();
	cout << o1.count();
	DLLADT<int>o2;
	o2.insert(7);
	o2.insert(9);
	int *arr = new int(o1.count());
	int *arr2 = new int(o2.count());
	int index = 0;

	int size = o1.count();
	int size2 = o2.count();
	int b = 0;
	int s1;
	DLLADT<int>onn;
	node<int>* bb = o1.get();//using get function add fuction that works
	if (bb != 0)
	{
		s1 = o1.count();
	}
	else
		s1 = 0;
	node<int>* bo = o2.get();
	if (bo != 0)
	{
		b = o2.count();
	}
	else
		b = 0;
	int no = pow(10, s1-1);
	int on = pow(10, b-1);
	int ans1 = 0, ans2 = 0;
	if (bb != 0)
	{
		node <int>*n = bb;
		while (n->next != bb)
		{
			ans1 = ans1 + no*n->data;
			no = no / 10;
			n = n->next;
		}
		ans1 = ans1 + no*n->data;
	}
	if (bo != 0)
	{
		node <int>*n = bo;
		while (n->next != bo)
		{
			ans2 = ans2 + on*n->data;
			on = on / 10;
			n = n->next;
		}
		ans2 = ans2 + on*n->data;
	}
	ans1 = ans1 + ans2;
	on = ans1;
	no = 0;
	while (ans1 != 0)
	{
		ans1 = ans1 / 10;
		no++;
	}
	no = pow(10, no - 1);
	float temp;
	while (no != 0)
	{
		ans1 = on / no;
		onn.insert(ans1);//ans
		temp = on / no;
		temp = no*temp;
		on = on - temp;
		no = no / 10;
	}
	onn.printForward();
	for (int i = 0; i < size; i++)//portion where i added two DLLADT without get function
	{
          b = 0;

		while (o1.remove(b) != true)
		{
			b++;
		}
		arr[index] = b;
		index++;
		 arr[index - 1];
	}
	index = 0;
	for (int i = 0; i < size2; i++)
	{
		int b = 0;

		while (o2.remove(b) != true)
		{
			b++;
		}
		arr2[index] = b;
		index++;
		b++;
	}//end here add without get
	 ans1=0, ans2=0;
	
	no = pow(10, size-1);
	 on = pow(10, size2-1);
	int i = 0;
	while (i<size)
	{
		ans1 = ans1 + no*arr[i];
		no = no / 10;
		i++;
	}
	i = 0;
		while (i<size2)
		{
			ans2 = ans2 + on*arr2[i];
				on = on / 10;
			i++;
		}
	ans1 = ans1 + ans2;
	on = ans1;
	no = 0;
	while (ans1 != 0)
	{
		ans1 = ans1 / 10;
		no++;
	}
	no = pow(10, no - 1);
	 temp;
	DLLADT<int>o;
	while (no != 0)
	{
		ans1 = on / no;
		o.insert(ans1);//result
		temp = on / no;
		temp = no*temp;
		on = on - temp;
		no = no / 10;
	}
	o.printForward();
	system("pause");
}