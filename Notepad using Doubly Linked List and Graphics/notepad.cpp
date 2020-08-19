#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>
using namespace std;

struct node
{
	char letter;
	node*next;
	node*prev;
	node*up;
	node*down;
};

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void myRect(int x1, int y1, int x2, int y2, int color1, int color2, int color3) //this function also takes in color information
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(color1, color2, color3));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0)); //Fill color is black. change these values to change the fill color.

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	::DeleteObject(pen);
	::DeleteObject(brush);
	::DeleteObject(device_context);
}


class TwoDLLADT
{
	node*first, *cursor;
public:
	TwoDLLADT()
	{
		first = 0;
		cursor = 0;
	}

	~TwoDLLADT()
	{
		node*r, *c;
		r = first;
		node*v;
		while (r != 0)
		{
			c = r;
			r = r->down;
			v = c->prev;
			c->prev = 0;
			v->next = 0;
			delete v;
			while (c->next != 0)
			{
				c = c->next;
				v = c->prev;
				c->prev = 0;
				v->next = 0;
				v->prev = 0;
				v->down = 0;
				v->up = 0;
				delete v;
			}
			delete c;
		}
		first = 0;
	}

	void Load()
	{
		ifstream fin;
		fin.open("notepad.txt");
		char ch;
		while (fin.get(ch))
		{
			if (ch != '\n')
			{
				if (ch == 'Q')
				{
					Insert(12);
				}
				else
					Insert(ch);
			}
			else if (ch == '\n')
			{
				Insert(13);
			}
		}
	}

	void Save()
	{
		ofstream fout;
		fout.open("notepad.txt");
		node*r, *c;
		r = first;
		c = first;
		while (r != 0)
		{
			while (c != 0)
			{
				if (c->letter == 13)
				{
					fout << endl;

				}
				else
				{
					if (c->letter != 0 && c->letter != 12)
					{
						fout << c->letter;

					}
					else if (c->letter == 12)
					{
						fout << "Q";
					}
				}
				c = c->next;
			}
			r = r->down;
			c = r;
		}
		fout.close();
	}

	void putvalue(char b, node*&temp)
	{
		temp = new node;
		temp->letter = b;
		temp->up = 0;
		temp->down = 0;
		temp->next = 0;
		temp->prev = 0;
	}

	void curs(char o)
	{
		if (cursor->next != 0)
		{
			if (cursor->next->up != 0 && cursor->next->down == 0)
			{
				node*b = cursor;
				cursor = cursor->next;
				node*r, *c;
				check(r, c);
				node*temp;
				putvalue(o, temp);
				cursor->prev->next = temp;
				temp->prev = cursor->prev;
				temp->next = cursor;
				cursor->prev = temp;
				c = r->up;
				join(c, r);
				cursor = cursor->prev;
			}
		}
	}

	void nextnot(node*&cursor, node*&temp)
	{
		temp->next = cursor->next;
		temp->prev = cursor;
		cursor->next->prev = temp;
	}

	void check(node *&row, node *&col)
	{
		row = first, col = first;
		node*b;
		if (cursor->letter != 10)
		{
			b = cursor;
		}
		else
			b = cursor->next;
		while (row != 0)
		{
			while (col != 0)
			{
				if (col == b)
				{
					break;
				}
				col = col->next;
			}
			if (col == b)
			{
				break;
			}
			row = row->down;
			col = row;
		}
	}

	void join(node *&t, node*&b)
	{
		node*tprev = 0, *bprev = 0;
		bprev = b;
		while (bprev != 0)
		{
			tprev = bprev;
			bprev = bprev->next;
		}
		node*o, *i;
		/*o = tprev;
		i = bprev;*/
		o = t;
		i = 0;
		while (o != 0)
		{
			i = o;
			o = o->next;
		}
		/*while (o != 0)
		{
		i=o;
		o = o->next;
		}*/
		if (tprev->letter != 13 && i->letter == 13)
		{
			tprev = 0;
			bprev = 0;
			while (t->letter != 13 && b != 0)
			{
				t->down = b;
				b->up = t;
				tprev = t;
				bprev = b;
				t = t->next;
				b = b->next;
			}
			if (t->letter != 13)
			{
				while (t->letter != 13)
				{
					t->down = bprev;
					t = t->next;
				}
			}
			if (b != 0)
			{
				while (b != 0)
				{
					b->up = tprev;
					b = b->next;
				}
			}
		}
		else if (tprev->letter == 13 && i->letter == 13)
		{
			tprev = 0;
			bprev = 0;
			while (t->letter != 13 && b->letter != 13)
			{
				t->down = b;
				b->up = t;
				tprev = t;
				bprev = b;
				t = t->next;
				b = b->next;
			}
			if (t->letter != 13)
			{
				while (t->letter != 13)
				{
					t->down = bprev;
					t = t->next;
				}
			}
			if (b->letter != 13)
			{
				while (b->letter != 13)
				{
					b->up = tprev;
					b = b->next;
				}
			}
		}
		else if (tprev->letter != 13 && i->letter != 13)
		{
			tprev = 0;
			bprev = 0;
			while (t != 0 && b != 0)
			{
				t->down = b;
				b->up = t;
				tprev = t;
				bprev = b;
				t = t->next;
				b = b->next;
			}
			if (t != 0)
			{
				while (t != 0)
				{
					t->down = bprev;
					t = t->next;
				}
			}
			if (b != 0)
			{
				while (b != 0)
				{
					b->up = tprev;
					b = b->next;
				}
			}
		}
		else if (tprev->letter == 13 && i->letter == 13)
		{
			tprev = 0;
			bprev = 0;
			while (t->letter != 13 && b->letter != 13)
			{
				t->down = b;
				b->up = t;
				tprev = t;
				bprev = b;
				t = t->next;
				b = b->next;
			}
			if (t->letter != 13)
			{
				while (t->letter != 13)
				{
					t->down = bprev;
					t = t->next;
				}
			}
			if (b != 0)
			{
				while (b->letter != 13)
				{
					b->up = tprev;
					b = b->next;
				}
			}
		}
		else if (tprev->letter == 13 && i->letter != 13)
		{
			tprev = 0;
			bprev = 0;
			while (t != 0 && b->letter != 13)
			{
				t->down = b;
				b->up = t;
				tprev = t;
				bprev = b;
				t = t->next;
				b = b->next;
			}
			if (t != 0)
			{
				while (t != 0)
				{
					t->down = bprev;
					t = t->next;
				}
			}
			if (b->letter != 13)
			{
				while (b->letter != 13)
				{
					b->up = tprev;
					b = b->next;
				}
			}
		}
	}

	void cursorupdownzero(char b)
	{
		if (cursor->next == 0 && b != 13)
		{
			putvalue(b, cursor->next);
			cursor->next->prev = cursor;
			cursor = cursor->next;
		}
		else if (cursor->next != 0 && b != 13)
		{
			node*temp;
			putvalue(b, temp);
			temp->prev = cursor;
			temp->next = cursor->next;
			cursor->next->prev = temp;
			cursor->next = temp;
			cursor = cursor->next;
		}
		else if (cursor->letter == 12 && cursor->next->letter == 13 && b == 13)
		{
			node*n;
			putvalue(12, n);
			putvalue(13, n->next);
			n->next->prev = n;
			putvalue(10, n->prev);
			n->prev->next = n;
			cursor->down = n;
			n->up = cursor;
			cursor = n;
		}
		else if (cursor->next == 0 && b == 13)
		{
			putvalue(b, cursor->next);
			cursor->next->prev = cursor;
			node*temp;
			putvalue(12, temp);
			putvalue(10, temp->prev);
			temp->prev->next = temp;
			node*t, *b;
			check(t, b);
			b = t;
			b->down = temp;
			temp->up = b;
			b = b->next;
			if (b->letter != 13)
			{
				while (b->letter != 13)
				{
					b->down = temp;
					b = b->next;
				}
			}
			cursor = temp;
		}
		else if (cursor->next != 0 && b == 13 && cursor->letter != 10)
		{
			node*temp = cursor->next;
			putvalue(b, cursor->next);
			cursor->next->prev = cursor;
			putvalue(10, temp->prev);
			temp->prev->next = temp;
			node*b, *t;
			check(b, t);
			t = b;
			cursor = temp;
			join(t, temp);

		}
		else if (cursor->next != 0 && b == 13 && cursor->letter == 10)
		{
			node*n = cursor->next;
			n->prev = 0;
			cursor->next = 0;
			putvalue(12, cursor->next);
			cursor->next->prev = cursor;
			cursor = cursor->next;
			putvalue(13, cursor->next);
			cursor->next->prev = cursor;
			node*r = n;
			node*c = cursor;
			join(c, r);
			first = cursor;
		}
	}

	void down(char b)
	{
		if (cursor->letter == 10 && b != 13)
		{
			node*n;
			putvalue(b, n);
			n->prev = cursor;
			n->next = cursor->next;
			cursor->next->prev = n;
			cursor->next = n;
			cursor = cursor->next->next;
			node*r, *c;
			check(r, c);
			c = r->down;
			r = r->prev;
			join(r, c);
			cursor = cursor->prev;
		}
		else if (cursor->letter == 10 && b == 13)
		{
			node*n;
			putvalue(12, n);
			putvalue(10, n->prev);
			n->prev->next = n;
			putvalue(13, n->next);
			n->next->prev = n;
			cursor = cursor->next;
			node*r, *c;
			check(r, c);
			join(n, r);
			cursor = n;
			first = cursor;
		}
		else if (cursor->next != 0 && b != 13)
		{
			node*z;
			putvalue(b, z);
			cursor->next->prev = z;
			z->next = cursor->next;
			z->prev = cursor;
			cursor->next = z;
			node*o, *i;
			check(i, o);
			o = i;
			node *v = o->down;
			join(o, v);
			/*o = i;
			v = i->down;
			join(i, o);*/
			cursor = cursor->next;
		}
		else if (cursor->next != 0 && b == 13 && cursor->next->letter != 13)
		{
			node*o = cursor->next;
			node*oo = cursor->next;
			node*temp;
			putvalue(b, temp);
			node*r, *c;
			check(r, c);
			temp->prev = cursor;
			cursor->next = temp;
			node*i = o;
			o->prev = 0;
			putvalue(10, o->prev);
			o->prev->next = o;
			while (i->letter != 13)
			{
				i->down = 0;
				i = i->next;
			}
			i = o;
			c = r->down;
			join(o, c);
			i = oo;
			c = r;
			join(c, oo);
		}
		else if (cursor->next->letter == 13 && b == 13)
		{
			node*temp;
			putvalue(12, temp);
			putvalue(10, temp->prev);
			temp->prev->next = temp;
			putvalue(13, temp->next);
			temp->next->prev = temp;
			node*r, *c;
			check(r, c);
			node*o = temp;
			c = r->down;
			join(o, c);
			o = temp;
			c = r;
			join(c, o);
			cursor = temp;
		}
	}

	void Delete()
	{


		if (cursor == 0)
		{
			return;
		}
		if (cursor->letter == 10)
		{
			if (cursor->next != 0)
			{
				if (cursor->next->up == 0 && cursor->next->down != 0)
				{
					cursor->letter = 0;
					cursor = cursor->next;
				}
				else if (cursor->next->up != 0 && cursor->next->down != 0)
				{
					cursor = cursor->next;
					node*r, *c;
					check(r, c);
					node*rc;
					rc = r->up->up;
					if (rc != 0)
					{
						node*o, *i;
						o = r->up;
						c = r;
						node*t = c->prev;
						t->next = 0;
						c->prev = 0;
						delete t;
						while (o->next != 0)
						{
							o = o->next;
						}
						t = o->prev;
						o->prev->next = 0;
						putvalue(13, o);
						delete o;
						t->next = c;
						c->prev = t;
						t = c->down;
						c = r->up;
						join(c, t);
						t = r->up;
						join(rc, t);
					}
					else
					{

						node*o, *i;
						o = r->up;
						c = r;
						node*t = c->prev;
						t->next = 0;
						c->prev = 0;
						delete t;
						while (o->next != 0)
						{
							o = o->next;
						}
						t = o->prev;
						o->prev->next = 0;
						putvalue(13, o);
						delete o;
						t->next = c;
						c->prev = t;
						t = c->down;
						c = r->up;
						node*vv = cursor;
						while (vv != 0)
						{
							vv->up = 0;
							vv = vv->next;
						}
						join(c, t);
					}
					return;
				}
			}
		}

		//if (cursor->letter == 10 && cursor->next==0)//theek kar lena
		//{
		//	return;
		//}
		//else
		//{
		//	cursor = cursor->next;
		//}
		/*if (cursor->letter == 10)
		{
		cursor = cursor->next;
		}*/
		if (cursor->up == 0 && cursor->down == 0 && cursor->letter != 10)
		{
			if (cursor->next == 0 && cursor->prev->letter == 10)
			{
				node*t = cursor;
				cursor = cursor->prev;
				delete t;
				delete cursor;
				cursor = 0;
				first = cursor;
				return;
			}
			else if (cursor->next == 0)
			{
				node*t = cursor;
				cursor = cursor->prev;
				cursor->next = 0;
				delete t;
			}
			else if (cursor->next != 0 && cursor->letter != 10)//
			{
				node*t = cursor;
				cursor->next->prev = cursor->prev;
				cursor->prev->next = cursor->next;
				cursor = cursor->prev;
				t->prev = 0;
				t->next = 0;
				delete t;
				if (cursor->letter == 10)
				{
					first = cursor->next;
				}
			}
		}
		else if (cursor->down == 0 && cursor->up != 0 && cursor->next == 0 && cursor->prev->letter != 10)//nahi to cursor next waali condition khatam kar do
		{
			node*b = cursor;
			cursor = cursor->prev;
			cursor->next = 0;
			b->prev = 0;
			b->up = 0;
			node*o, *i;
			check(o, i);
			i = o->up;
			join(i, o);
			delete b;
		}

		else if (cursor->up != 0 && cursor->down == 0)
		{
			if (cursor->next == 0 && cursor->prev->letter == 10)
			{
				if (cursor->letter != 12)
				{
					cursor->letter = 12;
					return;
				}
				else if (cursor->letter == 12)
				{
					node*temp = cursor;
					cursor = cursor->up;
					while (cursor->next->letter != 13)
					{
						cursor->down = 0;
						cursor = cursor->next;
					}
					cursor->down = 0;
					node*b = temp->prev;
					putvalue(12, temp);
					delete temp;
					putvalue(12, b);
					delete b;
					b = cursor->next;
					cursor->next = 0;
					b->prev = 0;
					delete b;
				}
			}
			else if (cursor->next != 0 && cursor->prev->letter != 10)
			{
				node*n = cursor;
				cursor->prev->next = cursor->next;
				cursor->next->prev = cursor->prev;
				cursor = cursor->prev;
				n->next = 0;
				n->down = 0;
				delete n;
				node *t, *o;
				check(o, t);
				t = o->up;
				join(t, o);
			}
			//else if (cursor->next != 0 && cursor->prev->letter == 10 )//pehli condition cursor->next != 0 && cursor->prev->letter == 10 && cursor->next->next==0
			//{
			//	node*temp = cursor;
			//	node*b = temp->prev;
			//	temp->prev = 0;
			//	b->next = 0;
			//	delete b;
			//	b = cursor->up;
			//	node*bb = b;
			//	while (b->next != 0)
			//	{
			//		b = b->next;
			//	}
			//	while (temp != 0)
			//	{
			//		temp->up = 0;
			//		temp = temp->next;
			//	}
			//	while (bb->next->letter != 13)
			//	{
			//		bb = bb->next;
			//	}
			//	b = bb->next;
			//	b->prev = 0;
			//	delete b;
			//	temp = cursor;
			//	temp->prev = bb;
			//	bb->next = temp;
			//}
			else if (cursor->next != 0 && cursor->prev->letter == 10)
			{
				node*b = cursor;
				node*n, *o;
				check(n, o);
				o = n->up;
				n = n->next;
				cursor->next->prev = cursor->prev;
				cursor->prev->next = cursor->next;
				cursor = cursor->prev;
				b->next = 0;
				b->prev = 0;
				b->up = 0;

				join(o, n);
				delete b;


			}
		}
		/*else if (cursor->next != 0 && cursor->prev->letter == 10 && cursor->next->next != 0)
		{

		}*/
		else if (cursor->letter == 10 && cursor->next != 0 && cursor->up != 0)
		{
			node*b = cursor;
			cursor = cursor->next->up;
			while (cursor->next->letter != 13)
			{
				cursor->down = 0;
				cursor = cursor->next;
			}
			cursor->down = 0;
			node*n = b->next;
			while (n != 0)
			{
				n->up = 0;
				n = n->next;
			}
			n = b->next;
			b->next = 0;
			delete b;
			b = cursor->next;
			cursor->next = n;
			n->prev = b;
			b->prev = 0;
			delete b;
		}
		else if (cursor->up == 0 && cursor->down != 0)
		{
			if (cursor->prev->letter == 0)
			{
				cursor->prev->letter = 10;
				return;
			}
			if (cursor->prev->letter != 10)
			{
				node*o, *i;
				check(o, i);
				node*b = cursor;
				cursor->next->prev = cursor->prev;
				cursor->prev->next = cursor->next;


				cursor = cursor->prev;
				b->prev = 0;
				b->next = 0;
				b->down = 0;
				i = o->down;
				join(o, i);
				delete b;
			}
			else if (cursor->prev->letter == 10 && cursor->next->letter == 13 && cursor->letter != 12)
			{
				cursor->letter = 12;
				return;
			}
			else if (cursor->letter == 12)
			{
				return;
			}
			else if (cursor->prev->letter == 10 && cursor->next != 0)
			{

				node*n = cursor;
				cursor->prev->next = cursor->next;
				cursor->next->prev = cursor->prev;
				cursor = cursor->next;
				node*r, *c;
				check(c, r);
				c = r->down;
				r = r->next;
				join(r, c);
				n->next = 0;
				n->prev = 0;
				n->down = 0;
				first = cursor;
				delete n;
			}
		}


		else if (cursor->up != 0 && cursor->down != 0)
		{
			if (cursor->next != 0 && cursor->letter != 10 && cursor->prev->letter != 10)
			{
				node*n = cursor;
				node*r, *o;
				check(r, o);
				cursor->next->prev = cursor->prev;
				cursor->prev->next = cursor->next;
				cursor = cursor->prev;
				n->prev = 0;
				n->next = 0;
				o = r->down;
				node*b = r;
				join(b, o);
				o = r->up;
				b = r;
				join(o, b);
				delete n;
				//if (cursor->letter == 10)//delete kar do agar masla aye to
				//{
				//	cursor = cursor->next;
				//}
			}
			else if (cursor->next != 0 && cursor->letter != 10 && cursor->prev->letter == 10 && cursor->next->letter != 13)
			{
				node*n = cursor;
				node*o, *i;
				check(o, i);
				cursor = cursor->next;
				cursor->prev->prev->next = cursor;
				cursor->prev = cursor->prev->prev;
				n->prev = 0;
				n->next = 0;

				i = o->down;
				node*b = cursor;
				join(b, i);
				b = cursor;
				i = o->up;
				join(i, b);
				delete n;
			}
			else if (cursor->next != 0 && cursor->letter != 10 && cursor->prev->letter == 10 && cursor->next->letter == 13 && cursor->letter != 12)
			{
				cursor->letter = 12;
			}
			else if (cursor->letter == 12)
			{
				node*c = cursor;
				node*r = cursor->up;
				node*cc = cursor->down;
				node*v = cursor->up;
				while (v->next->letter != 13)
				{
					v = v->next;
				}
				join(r, cc);
				cursor = v;
				r = c->prev;
				r->next = 0;
				c->prev = 0;
				delete r;
				r = c->next;
				c->next = 0;
				r->prev = 0;
				delete r;
				c->down = 0;
				c->up = 0;
				delete c;
				/*node*r, *c;
				check(r, c);
				node*rc = r->up->up;
				if (rc != 0)
				{
				node*v = cursor->prev;
				v->next = 0;
				cursor->prev = 0;
				delete v;
				c = r->up;
				while (c->next != 0)
				{
				c->down=0;
				c = c->next;
				}
				v= c->prev;
				v->next = 0;
				c->prev = 0;
				delete c;
				v->next = cursor;
				cursor->prev = v;
				c = r->up;
				node*cc = r->up;
				node*vv = r->up->up;
				join(vv, cc);
				vv = cursor->down;
				cursor->down = 0;
				c = r;
				join(cc, vv);
				*/
				//}
			}
		}
		else if (cursor->letter == 10 && cursor->next != 0)// nahi to sub conditions up and down waali khatam kar do
		{
			if (cursor->next->up == 0 && cursor->next->down == 0)
			{
				return;
			}
			else
			{
				node*b = cursor;
				cursor = cursor->next;
				node*r, *c;
				check(r, c);
				c = r->up;
				while (c->next != 0)
				{
					c->down = 0;
					c = c->next;
				}
				b->next = 0;
				cursor->prev = 0;
				delete b;
				b = c->prev;
				b->next = 0;
				c->prev = 0;
				c->down = 0;
				delete c;
				b->next = cursor;
				cursor->prev = b;
				cursor->up = 0;
				node*o = cursor;
				while (o != 0)//nahi to ye loop delete kar do
				{
					o->up = 0;
					o = o->next;
				}
				return;
			}
		}
		else if (cursor->up->letter == 13 && cursor->down == 0 && cursor->next == 0 && cursor->prev->letter == 10)
		{
			node*t = cursor;
			cursor = cursor->up;
			t = t->prev;
			delete t->next;
			delete t;
			cursor = cursor->prev;
			delete cursor->next;
			delete cursor;
			cursor = 0;
			first = 0;
		}
	}

	void upnotzero(char b)
	{
		if (cursor->letter == 10 && b == 13)
		{
			node*n;
			putvalue(12, n);
			putvalue(10, n->prev);
			n->prev->next = n;
			putvalue(13, n->next);
			n->next->prev = n;
			cursor = cursor->next;
			node*r, *c;
			node*v = n;
			check(r, c);
			c = r->up;
			join(c, v);
			v = n;
			c = r;
			join(v, c);
			cursor = n;
		}
		else if (cursor->letter == 12 && cursor->prev->letter == 10 && b == 13)
		{
			node*n;
			putvalue(12, n);
			putvalue(13, n->next);
			n->next->prev = n;
			putvalue(10, n->prev);
			n->prev->next = n;
			cursor->down = n;
			n->up = cursor;
			cursor = cursor->down;

		}
		else if (cursor->next == 0 && b != 13)
		{
			putvalue(b, cursor->next);
			cursor->next->prev = cursor;
			node*b, *t;
			check(b, t);
			t = b->up;
			join(t, b);
			cursor = cursor->next;
		}
		else if (cursor->next != 0 && b != 13 && cursor->letter != 10)
		{
			node *bb;
			putvalue(b, bb);
			bb->next = cursor->next;
			bb->prev = cursor;
			cursor->next->prev = bb;
			node*o, *i;
			check(o, i);
			i = o->up;
			cursor->next = bb;
			cursor = cursor->next;
			join(i, o);

		}
		else if (cursor->next != 0 && b != 13 && cursor->letter == 10)
		{
			node *bb;
			putvalue(b, bb);
			bb->next = cursor->next;
			bb->prev = cursor;
			cursor->next->prev = bb;
			node*o, *i;
			check(o, i);
			i = o->up;
			cursor->next = bb;
			cursor = cursor->next;
			join(i, o->prev);

		}
		else if (cursor->next == 0 && b == 13)
		{
			node *temp;
			putvalue(b, temp);
			temp->prev = cursor;
			cursor->next = temp;
			node*v;
			putvalue(12, v);
			putvalue(10, v->prev);
			v->prev->next = v;
			node*r, *c;
			check(r, c);
			c = v;
			join(r, c);
			cursor = v;
		}
		else if (cursor->next != 0 && b == 13)
		{
			node*temp;
			putvalue(b, temp);
			node*o = cursor->next;
			temp->prev = cursor;
			cursor->next = temp;
			node*l = o;
			while (l != 0)
			{
				l->up = 0;
				l = l->next;
			}
			putvalue(10, o->prev);
			o->prev->next = o;
			l = o;
			node*r, *c;
			check(r, c);
			c = r;
			join(c, l);
			cursor = o;
		}

	}
	void updown(char b)
	{
		if (cursor->letter == 10 && b == 13)
		{
			node*n;
			putvalue(12, n);
			putvalue(10, n->prev);
			n->prev->next = n;
			putvalue(13, n->next);
			n->next->prev = n;
			cursor = cursor->next;
			node*r, *c;
			node*v = n;
			check(r, c);
			c = r->up;
			join(c, v);
			v = n;
			c = r;
			join(v, c);
			cursor = n;
		}
		else if (cursor->next != 0 && b != 13)
		{
			node*n;
			putvalue(b, n);

			cursor->next->prev = n;
			n->next = cursor->next;
			n->prev = cursor;
			cursor->next = n;

			node*o, *i;
			/*check(i, o);*/
			if (cursor->letter == 10)
			{
				cursor = cursor->next->next;
				check(i, o);
				cursor = cursor->prev->prev;
			}
			else
				check(i, o);

			node*v;
			if (cursor->letter == 10)
				v = i->prev;
			else
				v = i;
			//cursor = cursor->next;
			if (cursor->letter != 10)
				o = i->down;
			else
				o = i->next->down->prev;
			join(v, o);
			/*o = i;
			v = i->down;
			join(i, o);*/
			if (cursor->letter != 10)
				o = i->up;
			else
				o = i->next->up->prev;
			if (cursor->letter == 10)
				v = i->prev;
			else
				v = i;
			join(o, v);
			cursor = cursor->next;
			//;
		}
		else if (cursor->next->letter == 13 && b == 13)
		{
			node*n;
			putvalue(12, n);
			putvalue(b, n->next);
			n->next->prev = n;
			putvalue(10, n->prev);
			n->prev->next = n;
			node*o = n;
			node*r, *c;
			check(r, c);
			c = r->down;
			join(o, c);
			o = n;
			c = r;
			join(c, o);
			cursor = n;
		}
		else if (cursor->next != 0 && b == 13)
		{
			node*temp;
			putvalue(b, temp);
			node*o = cursor->next;
			temp->prev = cursor;
			cursor->next = temp;
			node*l = o;
			while (l != 0)
			{
				l->up = 0;
				l = l->next;
			}
			putvalue(10, o->prev);
			o->prev->next = o;
			l = o;
			node*r, *c;
			check(r, c);
			c = r->down;
			join(l, c);
			c = r;
			l = o;
			join(c, l);
			cursor = o;
		}
	}

	void Insert(char b)
	{

		if (first == 0)
		{
			if (b != 13)
			{
				putvalue(b, first);
				putvalue(10, first->prev);
				first->prev->next = first;
				cursor = first;
			}
			else if (b == 13)
			{
				/*putvalue(b, first);
				putvalue(12, first->prev);
				first->prev->next = first;
				putvalue(10, first->prev->prev);
				first->prev->prev->next = first->prev;
				node*temp;
				putvalue(12, temp);
				putvalue(10, temp->prev);
				temp->up = first;
				first->down = temp;
				cursor = temp;*/
				/*node*n;
				putvalue(12, n);
				putvalue(10, n->prev);
				n->prev->next = n;
				putvalue(13, n->next);
				n->next->prev = n;
				cursor = cursor->next;
				node*r, *c;
				node*v = n;
				check(r, c);
				c = r->up;
				join(c, v);
				v = n;
				c = r;
				join(v, c);
				cursor = n;
				first = n;*/
				node*n;
				putvalue(12, n);
				putvalue(13, n->next);
				n->next->prev = n;
				putvalue(10, n->prev);
				n->prev->next = n;
				
				cursor = n;
				first = cursor;
			}
		}

		else if (first != 0)
		{
			bool check = false;
			/*if (cursor->letter == 10 && cursor->next != 0)
			{
			cursor = cursor->next;

			}*/
			if (cursor->letter == 12 && b != 13)
			{
				cursor->letter = b;
				return;
			}
			if (cursor->letter == 13 && cursor->prev->letter != 10)
			{
				cursor = cursor->prev;
			}
			if (cursor->letter == 0)
			{
				cursor->letter = 13;
			}
			if (cursor->letter == 10)
			{
				cursor = cursor->next;
				check = true;
			}
			/*if (cursor->letter == 10)
			{
			cursor = cursor->next;
			}*/
			if (cursor->up == 0 && cursor->down == 0 && cursor->letter != 10)//theek karna
			{
				if (check == true)
				{
					cursor = cursor->prev;
					check = false;
				}
				return cursorupdownzero(b);
			}
			else if (cursor->up == 0 && cursor->down != 0)
			{
				if (check == true)
				{
					cursor = cursor->prev;
					check = false;
				}
				return down(b);
			}
			else if (cursor->up != 0 && cursor->down == 0)
			{
				if (check == true)
				{
					cursor = cursor->prev;
					check = false;
				}
				return upnotzero(b);
			}
			else if (cursor->letter == 10 && cursor->next->up != 0 && cursor->next->down == 0)
			{
				if (check == true)
				{
					cursor = cursor->prev;
					check = false;
				}
				return upnotzero(b);
			}
			/*else if (cursor->letter == 10)
			{
			curs(b);
			}*/
			else if (cursor->up != 0 && cursor->down != 0)
			{
				if (check == true)
				{
					cursor = cursor->prev;
					check = false;
				}
				return updown(b);
			}
		}
	}

	void Up()
	{
		if (cursor == 0)
		{
			return;
		}
		int r = 0, c = 0;
		node *row = first;
		node*col = first;
		if (cursor != 0)
		{
			if (cursor->up != 0 && cursor->letter != 13)
			{
				cursor = cursor->up;
			}
			else if (cursor->letter == 13)
			{
				while (row != 0)
				{
					while (col != 0)
					{
						if (col == cursor)
						{
							break;
						}
						col = col->next;
						c++;
					}
					if (col == cursor)
					{
						break;
					}
					row = row->down;
					r++;
					col = row;
				}
				cursor = row;
			}
		}
		if (cursor->letter == 10)
		{
			if (cursor->next->up != 0)
			{
				cursor = cursor->next->up;
			}
		}
		row = first;
		col = first;
		c = 0;
		r = 0;
		if (cursor->letter != 10)
		{
			while (row != 0)
			{
				while (col != 0)
				{
					if (col == cursor)
					{
						break;
					}
					col = col->next;
					c++;
				}
				if (col == cursor)
				{
					break;
				}
				row = row->down;
				r++;
				col = row;
				c = 0;
			}
		}
		else
		{
			while (row != 0)
			{
				while (col != 0)
				{
					if (col == cursor->next)
					{
						break;
					}
					col = col->next;
					c++;
				}
				if (col == cursor->next)
				{
					break;
				}
				row = row->down;
				r++;
				col = row;
				c = 0;
			}
			gotoxy(c, r - 1);
		}
		gotoxy(c, r);
		/*if (cursor->letter == 13)
		{
		node*temp = new node;
		temp->letter = 13;
		cursor->next = temp;
		temp->prev = cursor;
		temp->next = 0;
		cursor->letter = 0;
		if (cursor->up != 0)
		{
		if (cursor->up->next != 0)
		{
		cursor->up->next->down = temp;
		temp->up = cursor->up->next;
		}
		}
		else
		temp->up = 0;
		if (cursor->down != 0)
		{
		if (cursor->down->next != 0)
		{
		cursor->down->next->up = temp;
		temp->down = cursor->down->next;
		}
		}
		else
		temp->down = 0;
		}*/
	}

	/*void Down()
	{
	if (cursor->down != 0)
	{
	cursor = cursor->down;
	}
	int r = 0, c = 0;
	node *row = first;
	node*col = first;
	while (row != 0)
	{
	while (col != 0)
	{
	col = col->next;
	c++;
	}
	row = row->next;
	r++;
	col = row;
	}
	gotoxy(r, c);
	}*/

	/*void Down()
	{
	int r = 0, c = 0;
	node *row = first;
	node*col = first;
	if (cursor != 0)
	{
	if (cursor->down != 0 && cursor->letter != 13)
	{
	cursor = cursor->down;
	}
	else if (cursor->letter == 13)
	{
	while (row != 0)
	{
	while (col != 0)
	{
	if (col == cursor)
	{
	break;
	}
	col = col->next;
	c++;
	}
	if (col == cursor)
	{
	break;
	}
	row = row->down;
	r++;
	col = row;
	c = 0;
	}
	cursor = row;
	}
	}
	else
	return;
	row = first;
	col = first;
	c = 0;
	r = 0;
	while (row != 0)
	{
	while (col != 0)
	{
	if (col == cursor)
	{
	break;
	}
	col = col->next;
	c++;
	}
	if (col == cursor)
	{
	break;
	}
	row = row->down;
	r++;
	col = row;
	c = 0;
	}
	gotoxy(c, r);
	if (cursor->letter == 13)
	{
	node*temp = new node;
	temp->letter = 13;
	temp->prev = cursor;
	temp->next = 0;
	cursor->letter = 0;
	if (cursor->down != 0)
	{
	if (cursor->down->next != 0)
	{
	cursor->down->next->up = temp;
	temp->down = cursor->down->next;
	}
	}
	else
	temp->down = 0;
	if (cursor->up != 0)
	{
	if (cursor->up->next != 0)
	{
	cursor->up->next->down = temp;
	temp->up = cursor->up->next;
	}
	}
	else
	temp->up = 0;
	}

	}*/ //waapis lagana

	void Down()
	{
		if (cursor == 0)
		{
			return;
		}
		if (cursor->down != 0)
		{
			cursor = cursor->down;
		}
		node *row = first;
		node*col = first;
		int c = 0, r = 0;
		while (row != 0)
		{
			while (col != 0)
			{
				if (col == cursor)
				{
					break;
				}
				col = col->next;
				c++;
			}
			if (col == cursor)
			{
				break;
			}
			row = row->down;
			r++;
			col = row;
			c = 0;
		}
		gotoxy(c, r);
	}

	//void Right()
	//{
	//	if (cursor != 0)
	//	{
	//		if (cursor->next != 0 /*&& cursor->next->letter != 13*/)
	//		{
	//			cursor = cursor->next;
	//		}
	//	}
	//	int r = 0, c = 0;
	//	node *row = first;
	//	node*col = first;
	//	while (row != 0)
	//	{
	//		while (col != 0)
	//		{
	//			if (col == cursor)
	//			{
	//				break;
	//			}
	//			col = col->next;
	//			c++;
	//		}
	//		if (col == cursor)
	//		{
	//			break;
	//		}
	//		row = row->down;
	//		r++;
	//		col = row;
	//		c = 0;
	//	}
	//	//gotoxy(c + 1, r);
	//	gotoxy(c + 1, r);
	//}

	void Right()
	{
		if (cursor == 0)
		{
			return;
		}
		if (cursor->next != 0)
		if (cursor->next->letter != 13)
		{
			cursor = cursor->next;
		}
		int r = 0, c = 0;
		node*o;
		if (cursor->letter == 10)
		{
			o = cursor->next;
		}
		else
			o = cursor;
		node *row = first;
		node*col = first;
		while (row != 0)
		{
			while (col != 0)
			{
				if (col == cursor)
				{
					break;
				}
				col = col->next;
				c++;
			}
			if (col == cursor)
			{
				break;
			}
			row = row->down;
			r++;
			col = row;
			c = 0;
		}
		if (cursor->letter != 13)
			gotoxy(c + 1, r);
		else
			gotoxy(c, r);
	}

	void Left()
	{
		if (cursor == 0)
		{
			return;
		}
		if (cursor != 0)
		{
			if (cursor->prev != 0)
			{
				cursor = cursor->prev;
			}
		}
		node*o;
		if (cursor->letter == 10)
		{
			o = cursor->next;
		}
		else
			o = cursor;
		int r = 0, c = 0;
		node *row = first;
		node*col = first;
		while (row != 0)
		{
			while (col != 0)
			{
				if (col == o)
				{
					break;
				}
				c++;
				col = col->next;
			}
			if (col == o)
			{
				break;
			}
			row = row->down;
			r++;
			col = row;
			c = 0;
		}
		/*if (first->prev->letter != 10)
		gotoxy(c, r);
		else if (r == 1 && first->prev->letter == 10)
		gotoxy(c, r - 1);
		else if (r == 0 && first->prev->letter == 10)
		gotoxy(c, r);*/
		if (cursor->letter == 10)
		{
			gotoxy(c, r);
		}
		else
			gotoxy(c + 1, r);
	}

	void Print()
	{
		myRect(0, 0, 30000, 30000, 1, 1, 1);
		system("cls");
		gotoxy(0, 0);
		if (first == 0)
		{
			return;
		}
		if (first->prev != 0)
		{
			if (first->prev->letter != 10)
			{
				first = first->prev;
			}
		}
		node*row = first;
		node*col = first;
		int r = 0, c = 0;
		//gotoxy(0, 0);
		while (row != 0)
		{
			while (col != 0)
			{
				if (col->letter == 13)
				{
					cout << endl;

				}
				else
				{
					if (col->letter != 0 && col->letter != 12)
					{
						char b = col->letter;
						cout << b;
					}
				}
				col = col->next;
				c++;
			}
			row = row->down;
			r++;
			c = r;
			col = row;
		}
		r = 0, c = 0;
		row = first;
		col = first;
		node*bb;
		if (cursor->letter != 10)
		{
			bb = cursor;
		}
		else
			bb = cursor->next;
		while (row != 0)
		{
			while (col != 0)
			{
				if (col == bb)
				{
					break;
				}
				c++;
				col = col->next;
			}
			if (col == bb)
			{
				break;
			}
			row = row->down;
			r++;
			col = row;
			c = 0;
		}
		if (cursor->letter != 12)
			gotoxy(c + 1, r);
		else
			gotoxy(c, r);
	}

};



int main()
{
	myRect(0, 0, 3000, 3000, 1, 1, 1);
	char b;
	b = _getch();
	TwoDLLADT* n = new TwoDLLADT;

	n->Print();
	while (b != 'Q' && b != 'S')
	{

		if (b == -32)
		{
			b = _getch();
			if (b == 'K')
			{
				n->Left();
			}
			else if (b == 'M')
			{
				n->Right();
			}
			else if (b == 'P')
			{
				n->Down();
			}
			else if (b == 'H')
			{
				n->Up();
			}
			else if (b == 'S')
			{
				n->Delete();
				n->Print();
			}
		}
		else if (b == 8)
		{
			n->Delete();
			n->Print();
		}
		else if (b == 'L')
		{
			delete n;
			n = 0;
			n = new TwoDLLADT;
			n->Load();
			n->Print();
		}
		else
		{
			n->Insert(b);
			myRect(0, 0, 3000, 3000, 1, 1, 1);
			n->Print();
		}

		b = _getch();
	}
	if (b == 'S')
	{
		n->Save();
		system("exit");
	}
	system("pause");
};