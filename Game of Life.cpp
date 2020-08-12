#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<time.h>
#include<cstdlib>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void save(int i, char *arr,int index, int index2)
{
	ofstream fout;
	fout.open("save.txt");
    fout<<i;
	fout<<endl;
	int size=strlen(arr);
	fout<<size;
	fout<<endl;fout<<index;
	fout<<endl;
	fout<<index2;
	for(int o=0; o<size; o++)
	{
		fout<<arr[o];
	}
	fout<<endl;
}

void load(int i, char *&arr, int index, int index2)
{
	ifstream fin;
	fin.open("save.txt");
	fin>>i;
	/*if(i==1)
	{
		arr=new char[25];
	}
	else if(i==2)
	{
		arr=new char[49];
	}
	else if(i==3)
	{
		arr=new char[81];
	}
	else if(i==4)
	{
		arr=new char[121];
	}*/
	int size;
	fin>>size;
	fin>>index;
	fin>>index2;
	arr=new char[size];
	fin.getline(arr,size);
	
}

void BoxToIndexConverter(int index,int level,int &x,int &y)
{
	if(level==5)
	{
		if(index==24)
		{
			x=42;
			y=33;
		}
		else if(index==23)
		{
			x=32;
			y=33;
		}
		else if(index==22)
		{
			x=22;
			y=33;
		}
		else if(index==21)
		{
			x=12;
			y=33;
		}
		else if(index==20)
		{
			x=2;
			y=33;
		}
		else if(index==19)
		{
			x=42;
			y=26;
		}
		else if(index==18)
		{
			x=32;
			y=26;
		}
		else if(index==17)
		{
			x=22;
			y=26;
		}
		else if(index==16)
		{
			x=12;
			y=26;
		}
		else if(index==15)
		{
			x=2;
			y=26;
		}
		else if(index==14)
		{
			x=42;
			y=19;
		}
		else if(index==13)
		{
			x=32;
			y=19;
		}
	}
	
}



void printmenu(int &c3)
{
	int c=0;
				gotoxy(0,82);
				cout<<"Press 0 to Load New Game\n\n";
				cout<<"Press 1 to Buy a Hurdle and save in chest\n\n";
				cout<<"Press 2 to Buy a Helping Object and save in chest\n\n";
				cout<<"Press 3 to Trap the Opponent with any hurdle\n\n";
				cout<<"Press 4 to Use a Helping Object against any hurdle\n\n";
				cout<<"Press 5 to Quit and Save the Game\n\n";
				cout<<"Press 6 to Reload Previous Save Game\n\n";
				cout<<"Press 7 to Continue with Moves\n\n";
				cout<<"Please Enter Your Choice\n\n";
				cin>>c;

				c3=c;

}

void removemenu()
{
	gotoxy(0,80);
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
	cout<<"                                                      "<<endl;
}


void indexToGSconverter(int i, int level, int&x, int &y)
{
	if (level == 5)
	{
		if (i == 19)
		{
			x = 48;
			y = 26;
		}
		else if (i == 18)
		{
			x = 38;
			y = 26;
		}
		else if (i == 17)
		{
			x = 28;
			y = 26;
		}
		else if (i == 16)
		{
			x = 18;
			y = 26;
		}
		else if (i == 15)
		{
			x = 8;
			y = 26;
		}
	}
	else if (level == 7)
	{
		if (i == 41)
		{
			x = 68;
			y = 40;
		}
		else if (i == 40)
		{
			x = 58;
			y = 40;
		}
		else if (i == 39)
		{
			x = 48;
			y = 40;
		}
		else if (i == 38)
		{
			x = 38;
			y = 40;
		}
		else if (i == 37)
		{
			x = 28;
			y = 40;
		}
		else if (i == 36)
		{
			x = 18;
			y = 40;
		}
		else if (i == 35)
		{
			x = 8;
			y = 40;
		}
		else if (i == 34)
		{
			x = 68;
			y = 33;
		}
		else if (i == 33)
		{
			x = 58;
			y = 33;
		}
		else if (i == 32)
		{
			x = 48;
			y = 33;
		}
		else if (i == 31)
		{
			x = 38;
			y = 33;
		}
		else if (i == 30)
		{
			x = 28;
			y = 33;
		}
		else if (i == 29)
		{

			x = 18;
			y = 33;
		}
		else if (i == 28)
		{
			x = 8;
			y = 33;
		}

	}
	else if (level == 9)
	{
		if (i == 71)
		{
			x = 88;
			y = 54;
		}
		else if (i == 70)
		{
			x = 78;
			y = 54;
		}
		else if (i == 69)
		{
			x = 68;
			y = 54;
		}
		else if (i == 68)
		{
			x = 58;
			y = 54;
		}
		else if (i == 67)
		{
			x = 48;
			y = 54;
		}
		else if (i == 66)
		{
			x = 38;
			y = 54;
		}
		else if (i == 65)
		{
			x = 28;
			y = 54;
		}
		else if (i == 64)
		{
			x = 18;
			y = 54;
		}
		else if (i == 63)
		{
			x = 8;
			y = 54;
		}
		else if (i == 62)
		{
			x = 88;
			y = 47;
		}
		else if (i == 61)
		{
			x = 78;
			y = 47;
		}
		else if (i == 60)
		{
			x = 68;
			y = 47;
		}
		else if (i == 59)
		{
			x = 58;
			y = 47;
		}
		else if (i == 58)
		{
			x = 48;
			y = 47;
		}
		else if (i == 57)
		{
			x = 38;
			y = 47;
		}
		else if (i == 56)
		{
			x = 28;
			y = 47;
		}
		else if (i == 55)
		{
			x = 18;
			y = 47;
		}
		else if (i == 54)
		{
			x = 8;
			y = 47;
		}
	}
	else if (level == 11)
	{
		if (i == 109)
		{
			x = 108;
			y = 68;
		}
		else if (i == 108)
		{
			x = 98;
			y = 68;
		}
		else if (i == 107)
		{
			x = 88;
			y = 68;
		}
		else if (i == 106)
		{
			x = 78;
			y = 68;
		}
		else if (i == 105)
		{
			x = 68;
			y = 68;
		}
		else if (i == 104)
		{
			x = 58;
			y = 68;
		}
		else if (i == 103)
		{
			x = 48;
			y = 68;
		}
		else if (i == 102)
		{
			x = 38;
			y = 68;
		}
		else if (i == 101)
		{
			x = 28;
			y = 68;
		}
		else if (i == 100)
		{
			x = 18;
			y = 68;
		}
		else if (i == 99)
		{
			x = 8;
			y = 68;
		}
		if (i == 98)
		{
			x = 108;
			y = 61;
		}
		else if (i == 97)
		{
			x = 98;
			y = 61;
		}
		else if (i == 96)
		{
			x = 88;
			y = 61;
		}
		else if (i == 95)
		{
			x = 78;
			y = 61;
		}
		else if (i == 94)
		{
			x = 68;
			y = 61;
		}
		else if (i == 93)
		{
			x = 58;
			y = 61;
		}
		else if (i == 92)
		{
			x = 48;
			y = 61;
		}
		else if (i == 91)
		{
			x = 38;
			y = 61;
		}
		else if (i == 90)
		{
			x = 28;
			y = 61;
		}
		else if (i == 89)
		{
			x = 18;
			y = 61;
		}
		else if (i == 88)
		{
			x = 8;
			y = 61;
		}
	}
}

void SetColor(int value){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}



void setter(int level, int &objects)
{
	if (level == 1)
	{
		objects = 5;
	}
	else if (level == 2)
	{
		objects = 7;
	}
	else if (level == 3)
	{
		objects = 9;
	}
	else if (level == 4)
	{
		objects = 11;
	}
	objects = objects*objects;
	objects = objects - 1;
	objects = objects / 2;
}

char *makearray(int n)
{
	if (n == 0)
	{
		return nullptr;
	}
	return new char(n);
}

char *extendby1(char *arr1, int& n)
{
	char *arr2 = makearray(n + 1);
	for (int i = 0; i < n; i++)
	{
		arr2[i] = arr1[i];
	}
	//delete[] arr1;
	//arr1 = NULL;
	n++;
	return arr2;
}

class item{
protected:
	int move;
	int points;
	int turn;
public:
	virtual void print(int, int) = 0;
	//virtual void getmove(int &) = 0;
	virtual void getpoints(int &) = 0;
	virtual void getturn(int &) = 0;
	item()
	{
		move = 0;
		turn = 0;
		points = 0;
	}
};

class helpingobject : public item{
public:
	void checkgold()
	{

	}
};

class water : public helpingobject
{
public:
	void setmove()
	{
		move = 0;
	}
};

class hurdle : public item
{
	//protected:
	//	int move;
	//	int points;
	//	int turn;
public:

	hurdle()
	{
		move = 0;
		points = 0;
		turn = 0;
	}
};

class snake : hurdle
{

public:
	void getmove(int & b)
	{
		b = 3;
	}

	void getpoints(int & b)
	{
		b = 30;
	}

	void getturn(int & b)
	{
		b = 3;
	}

	void print(int xaxis, int yaxis)
	{
		gotoxy(xaxis, yaxis);
		cout << "S";
	}

	snake()
	{
	}
};

class fire : public hurdle
{
	bool fireon;
	bool fireoff;
public:
	fire()
	{
		fireon = true;
		fireoff = false;
		move = 0;
		points = 0;
		turn = 0;
	}

	fire(int xaxis, int yaxis, int &b, int & t)
	{
		b = 50;
		t = 2;
		gotoxy(xaxis, yaxis);
		cout << "F";
	}

	void setfireoff()
	{
		fireon = false;
		fireoff = true;
	}

	void getpoints(int & b)
	{
		b = 50;
	}

	void getturn(int & b)
	{
		b = 2;
	}

	void print(int xaxis, int yaxis)
	{
		gotoxy(xaxis, yaxis);
		cout << "F";
	}
};

class ghost : public hurdle
{
public:
	ghost()
	{

	}

	ghost(int xaxis, int yaxis, int &b, int & t)
	{
		b = 20;
		t = 1;
		gotoxy(xaxis, yaxis);
		cout << "G";
	}

	void getpoints(int & b)
	{
		b = 20;
	}

	void getturn(int & b)
	{
		b = 1;
	}

	void print(int xaxis, int yaxis)
	{
		gotoxy(xaxis, yaxis);
		cout << "G";
	}
};

class lion :public hurdle
{
public:
	lion(int xaxis, int yaxis, int &b, int & t)
	{
		b = 50;
		t = 4;
		gotoxy(xaxis, yaxis);
		cout << "L";
	}

	void getpoints(int & b)
	{
		b = 50;
	}

	void getturn(int & b)
	{
		b = 4;
	}

	void print(int xaxis, int yaxis)
	{
		gotoxy(xaxis, yaxis);
		cout << "L";
	}
};

class lock : public hurdle
{
	bool l;
public:
	lock(int xaxis, int yaxis, int &b, int & t)
	{
		b = 50;
		l = true;
		gotoxy(xaxis, yaxis);
		cout << "F";
	}

	void getpoints(int & b)
	{
		b = 50;
	}

	void getstatus(bool & b)
	{
		b = l;
	}

	void print(int xaxis, int yaxis)
	{
		gotoxy(xaxis, yaxis);
		cout << "O";
	}
};
class gold
{
	//int gcoins;
	int xaxis;
	int yaxis;
public:
	gold()
	{
		//gcoins = 0;
		xaxis = 0;
		yaxis = 0;
	}

	void setaxis(int x, int y)
	{
		xaxis = x;
		yaxis = y;
	}

	void print()
	{
		gotoxy(xaxis, yaxis);
		SetColor(14);
		cout << "O";
		SetColor(7);
	}

	void remove()
	{
		gotoxy(xaxis, yaxis);
		cout << " ";
	}
};

class s
{
	//int gcoins;
	int xaxis;
	int yaxis;
public:
	s()
	{
		//gcoins = 0;
		xaxis = 0;
		yaxis = 0;
	}

	void setaxis(int x, int y)
	{
		xaxis = x;
		yaxis = y;
	}

	void print()
	{
		gotoxy(xaxis, yaxis);
		SetColor(15);
		cout << "O";
		SetColor(7);
	}

	void remove()
	{
		gotoxy(xaxis, yaxis);
		cout << " ";
	}
};

class person
{
	gold *g;//gold array
	int gsize;//goldsize a
	s* o;//silver class array;
	int ssize;//silver coins size
	int moves;//moves to stop
	int back;//moves to back
	bool hurdle;//hurdle check
	char * chest;//chest array
	int points;//points
	char hurd;//hurdle type
	int csize;//chest size
	bool water;//one life
	bool shield;//one life
	bool sword;
	bool sword1;//sword two life
	int pno;//player number
	int xaxis[2];
	int yaxis[2];
public:
	person()
	{
		g = new gold[10];
		gsize = 10;
		o = new s[20];
		ssize = 20;
		moves = 0;
		back = 0;
		hurdle = false;
		chest = NULL;
		points = 200;
		hurd = '\0';
		csize = 0;
		water = false;
		shield = false;
		sword = false;
		sword1 = false;
		xaxis[0] = 0;
		xaxis[1] = 0;
		yaxis[0] = 0;
		yaxis[1] = 0;
	}

	void pn(int o)
	{
		if (o == 1)
		{
			pno = 1;
		}
		else if (o == 2)
		{
			pno = 2;
		}
	}

	void incgpoints()
	{
		points = points + 10;
	}

	void incs()
	{
		ssize++;
	}

	void incspoints()
	{
		points = points + 5;
	}

	void incg()
	{
		gsize++;
	}
	void print(int x, int y)
	{
		if (moves == 0 && hurdle == false)
		{
			xaxis[0] = xaxis[1];
			yaxis[0] = yaxis[1];
			xaxis[1] = x;
			yaxis[1] = y;
			{
				gotoxy(xaxis[0], yaxis[0]);
				cout << " " << " ";
				gotoxy(xaxis[1], yaxis[1]);
				if (pno == 1)
				{
					cout << "P1" << endl;
				}
				else if (pno == 2)
				{
					cout << "P2" << endl;
				}
			}
		}
		else
		{
			cout << "You are stuck in trap" << endl;
		}
	}

	void decmove()
	{
		if (moves != 0)
		{
			moves--;
		}
	}

	bool check(char b)
	{
		if (chest != NULL)
		{
			for (int o = 0; o < csize; o++)
			{
				if (b = chest[o])
				{
					return true;
				}
			}
		}
		else
			return false;
	}



	bool use()
	{
		gotoxy(0,82);
		cout << "Enter 1 for using water\n" << endl;
		cout << "Enter 2 for using shield\n" << endl;
		cout << "Enter 3 for using sword\n" << endl;
		cout << "Enter 4 for using  key\n" << endl;
		cout<<"Enter 5 to Continue\n"<<endl;
		int option;
		cin >> option;
		bool ch = false;
		if (option == 1)
		{
			if (hurdle == true && hurd == 'F')
			{
				ch = check('w');
				if (ch == true)
				{
					if (water != true)
					{
						water = true;
						moves = 0;
						hurdle = false;
						hurd = '\0';
						for (int o = 0; o < csize; o++)
						{
							if (chest[o] == 'w')
							{
								chest[o] = '9';
								break;
							}
						}

						return false;
					}
				}
				else
				{
					gotoxy(0, 77);
					cout << "There is no such object present in your chest but we buy are you";
					buy('w');
					return false;
				}
			}
			else
			{
				cout << "You are not trap in fire so water cannot be used" << endl;
			}
		}

		else if (option == 2)
		{
			if (hurdle == true && hurd == 'G')
			{
				ch = check('s');
				if (ch == true)
				{
					if (shield != true)
					{
						shield = true;
						moves = 0;
						hurdle = false;
						for (int o = 0; o < csize; o++)
						{
							if (chest[o] == 's')
							{
								chest[o] = '9';
								break;
							}
						}
					}
					return false;
				}
				else
				{   gotoxy(0, 77);
					cout << "There is no such object present in your chest but we buy are you";
					buy('s');
					return false;
				}
			}
			else
			{
				cout << "You are not in ghost trap" << endl;
			}
		}

		else if (option == 3)
		{
			if (hurdle == false && (hurd == 'S' || hurd == 'L'))
			{
				ch = check('d');
				if (ch == true)
				{
					if (sword != true && sword1 != true)
					{
						if (sword != true && sword1 != true)
						{
							sword = true;
						}
						else if (sword == true && sword1 != true)
						{
							sword1 = true;
						}
						moves = 0;
						hurdle = false;
						for (int o = 0; o < csize; o++)
						{
							if (chest[o] == 'd')
							{
								chest[o] = '9';
								break;
							}
						}
					}
					return false;
				}
				else
				{   gotoxy(0, 77);
					cout << "There is no such object present in your chest but we buy are you";
					buy('d');
					return false;
				}
			}
			else
			{
				cout << "You are not lion and snake trap sword cannot be used" << endl;
			}
		}

		else if (option == 4)
		{
			if (hurdle == true)
			{
				ch = check('K');
				if (ch == true)
				{

					{
						moves = 0;
						hurdle = false;
						for (int o = 0; o < csize; o++)
						{
							if (chest[o] == 'K')
							{
								chest[o] = '9';
								//break;
							}
						}
					}
					return false;
				}
				else
				{   gotoxy(0, 77);
					cout << "There is no such object present in your chest but we buy are you";
					buy('K');
					return false;
				}
			}
			else
			{
				cout << "You are not in lock trap you can not use key" << endl;
			}
		}
		else if(option==5)
		{
			return true;
		}

		return false;
	}

	bool buy(char b)
	{
		
		if (b == 'F')
		{
			if (points >= 50)
			{
				points = points - 50;
				if (chest == NULL)
				{
					chest = new char;
					chest[0] = b;
					csize++;
					return true;
				}
				else
				{
					extendby1(chest, csize);
					chest[csize - 1] = b;
					return true;
				}
			}
			else{
				cout << "Not enought points" << endl;
				return false;
			}
		}
		else if (b == 'S')
		{
			if (points >= 30)
			{
				points = points - 30;
				if (chest == NULL)
				{
					chest = new char;
					chest[0] = b;
					csize++;
					return true;
				}
				else
				{
					extendby1(chest, csize);
					chest[csize - 1] = b;
					return true;
				}
			}
			else{
				cout << "Not enought points" << endl;
				return false;
			}
			//points = points - 30;
		}
		else if (b == 'G')
		{
			if (points >= 20)
			{
				points = points - 20;
				if (chest == NULL)
				{
					chest = new char;
					chest[0] = b;
					csize++;
				}
				else
				{
					extendby1(chest, csize);
					chest[csize - 1] = b;
				}
			}
			else{
				cout << "Not enought points" << endl;
				return false;
			}
			//points = points - 20;
		}
		else if (b == 'L')
		{
			if (gsize>5)
			{
				if (points >= 50)
				{
					points = points - 50;
					if (chest == NULL)
					{
						chest = new char;
						chest[0] = b;
						csize++;
					}
					else
					{
						extendby1(chest, csize);
						chest[csize - 1] = b;
					}
				}
				else{
					cout << "Not enought points" << endl;
					return false;
				}
				//points = points - 50;
			}
		}
		else if (b == 'l')//lock
		{
			if (points >= 60)
			{
				points = points - 60;
				if (chest == NULL)
				{
					chest = new char;
					chest[0] = b;
					csize++;
				}
				else
				{
					extendby1(chest, csize);
					chest[csize - 1] = b;
				}
			}
			else{
				cout << "Not enought points" << endl;
				return false;
			}
			//points = points - 60;
		}
		else if (b == 'd')//sword
		{
			if (points >= 40)
			{
				points = points - 40;
				if (chest == NULL)
				{
					chest = new char;
					chest[0] = b;
					csize++;
				}
				else
				{
					extendby1(chest, csize);
					chest[csize - 1] = b;
				}
			}
			else{
				cout << "Not enought points" << endl;
				return false;
			}
			//points = points - 40;
		}
		else if (b == 's')//shield
		{
			if (points >= 30)
			{
				points = points - 30;
				if (chest == NULL)
				{
					chest = new char;
					chest[0] = b;
					csize++;
				}
				else
				{
					extendby1(chest, csize);
					chest[csize - 1] = b;
				}
			}
			else{
				cout << "Not enought points" << endl;
				return false;
			}
			//points = points - 30;
		}
		else if (b == 'w')//water
		{
			if (points >= 50)
			{
				points = points - 50;
				if (chest == NULL)
				{
					chest = new char;
					chest[0] = b;
					csize++;
				}
				else
				{
					extendby1(chest, csize);
					chest[csize - 1] = b;
				}
			}
			else{
				cout << "Not enought points" << endl;
				return false;
			}
			//points = points - 50;
		}
		else if (b == 'K')//key
		{
			if (ssize>14)
			{
				if (points >= 70)
				{
					points = points - 70;
					if (chest == NULL)
					{
						chest = new char;
						chest[0] = b;
						csize++;
					}
					else
					{
						extendby1(chest, csize);
						chest[csize - 1] = b;
					}
				}
				else{
					cout << "Not enought points or not enought silver coins" << endl;
					return false;
				}
				//points = points - 70;

			}
		}
	}

	void getmove(int & b)
	{
		b = moves;
	}

	void setpoint(int b)
	{
		if (points != 0)
		{
			points = points - b;
		}
	}

	void enterpoint(int b)
	{
		points = b;
	}

	void getpoint(int &b)
	{
		b = points;
	}

	void setmove(int b, int bb, char trap)
	{
		moves = b;
		hurdle = true;
		back = bb;
		hurd = trap;
	}

	void setmoveoff(int b)
	{
		moves = b;
		hurdle = false;
		back = 0;
		hurd = '\0';
	}

};

class board
{
	person p1;
	person p2;
	bool win;
	char *box;
	int size;
	int pp1;
	int pp2;
	int move;
	int level;
public:
	board()
	{
		win = false;
		box = NULL;
		size = 0;
		pp1 = 1;
		pp2 = 2;
		move = 0;
		level = 0;
	}


		void getarr(char *&ar)
	{
		int size;
		if(level==1)
		{
			ar=new char[26];
			size=25;
		}
		else if(level==2)
		{
			ar=new char[50];
			size=49;
		}
		else if(level==3)
		{
			ar=new char[82];
			size=81;
		}
		else if(level==4)
		{
			ar=new char[122];
			size=121;
		}
		for(int o=0; o<size; o++)
		{
			ar[o]=box[o];
		}
		ar[size+1]='\0';
	}
	
	void setarr(char *arr)
	{
		if(box!=NULL)
		{
			delete[]box;
		}
		int size=strlen(arr);
		box=new char[size];
		for(int i=0; i<size; i++)
		{
			box[i]=arr[i];
		}
	}

	bool buy1(char b)
	{
		if (p1.buy(b) != 0)
		{
			return true;
		}
		else
			return false;
	}

	bool buy2(char b)
	{
		if (p2.buy(b) != 0)
		{
			return true;
		}
		else
			return false;
	}

	void setp1move(int b)
	{
		p1.setmoveoff(b);
	}

	void setp2move(int b)
	{
		p2.setmoveoff(b);
	}

	void p1getpoints(int &b)
	{
		p1.getpoint(b);
	}

	void p2getpoints(int &b)
	{
		p2.getpoint(b);
	}

	void printbox()
	{
		for (int o = 0; o < size; o++)
		{
			cout << box[o];
		}
	}

	void p1move(int &move)
	{
		p1.getmove(move);
	}

	void p2move(int &move)
	{
		p2.getmove(move);
	}

	void checkhurdle1(int i)
	{
		int object;
		if (level == 1)
		{
			object = 5;
		}
		else if (level == 2)
		{
			object = 7;
		}
		else if (level == 3)
		{
			object = 9;
		}
		else if (level == 4)
		{
			object = 11;
		}
		/*object = object*object;
		object = object - 1;
		object = object / 2;*/
		if (box[i] != '9')
		{
			if (box[i] == 'F')
			{
				p1.setmove(2, 0, box[i]);
			}
			else if (box[i] == 'S')
			{
				p1.setmove(3, 3, box[i]);
			}
			else if (box[i] == 'G')
			{
				p1.setmove(1, 0, box[i]);
			}
			else if (box[i] == 'L')
			{
				p1.setmove(4, 0, box[i]);
			}
			else if (box[i] == 'l')
			{
				p1.setmove(100, 0, box[i]);
			}
			else if (box[i] == 'g')
			{
				gotoxy(0, 99);
				cout << "Gold coin present do you want to pick if yes press 1" << endl;
				int option;
				cin >> option;
				if (option == 1)
				{
					p1.incg();
					p1.incgpoints();
					int r = i;
					int r1 = 0;
					int x = 8;
					int y = 5;
					int y1 = 0;
					while (r>0)
					{
						r1 = r;
						r = r - object;
						if (r >= 1)
						{
							y1++;
						}
					}
					if (y1 > 0)
					{
						y1 = y1 * 7;
						y = y + y1;
					}
					if (i != 0)
					{
						//r1 = r1 ;
						r1 = r1 * 10;
						x = x + r1;
					}
					gotoxy(x, y);
					cout << ' ';
					gotoxy(0, 99);
					cout << "                                                       ";
					gotoxy(0, 100);
					cout << " ";
				}
				gotoxy(0, 99);
					cout << "                                                       ";
					gotoxy(0, 100);
					cout << " ";
			}
			else if (box[i] == 's')
			{
				gotoxy(0, 101);
				cout << "Silver coin present do you want to pick if yes press 1" << endl;
				int option;
				cin >> option;
				if (option == 1)
				{
					p1.incs();
					p1.incspoints();
					int r = i;
					int r1 = 0;
					int x = 8;
					int y = 5;
					int y1 = 0;
					while (r>0)
					{
						r1 = r;
						r = r - object;
						if (r >= 1)
						{
							y1++;
						}
					}
					if (y1 > 0)
					{
						y1 = y1 * 7;
						y = y + y1;
					}
					if (i != 0)
					{
						//r1 = r1 ;
						r1 = r1 * 10;
						x = x + r1;
					}
					gotoxy(x, y);
					cout << ' ';
					gotoxy(0, 101);
					cout << "                                                       ";
					gotoxy(0, 102);
					cout << " ";
				}
				gotoxy(0, 101);
					cout << "                                                       ";
					gotoxy(0, 102);
					cout << " ";
			}
		}
	}

	void player1print(int x, int y)
	{
		p1.print(x, y);
	}

	void player2print(int x, int y)
	{
		p2.print(x, y);
	}

	void checkhurdle2(int i)
	{
		int object;
		int y;
		int x;
		int index;
		if (level == 1)
		{
			object = 5;
			y = 33;
			x = 48;
			index = 25;
		}
		else if (level == 2)
		{
			object = 7;
			y = 44 + 1;
			x = 62 + 2;
			index = 49;
		}
		else if (level == 3)
		{
			object = 9;
			y = 58 + 1;
			x = 82 + 2;
			index = 81;
		}
		else if (level == 4)
		{
			object = 11;
			y = 72 + 1;
			x = 102 + 2;
			index = 121;
		}
		/*object = object*object;
		object = object - 1;
		object = object / 2;*/
		if (box[i] != '9')
		{
			if (box[i] == 'F')//fire
			{
				p2.setmove(2, 0, box[i]);
			}
			else if (box[i] == 'S')//snake
			{
				p2.setmove(3, 3, box[i]);
			}
			else if (box[i] == 'G')//ghost
			{
				p2.setmove(1, 0, box[i]);
			}
			else if (box[i] == 'L')//lion
			{
				p2.setmove(4, 0, box[i]);
			}
			else if (box[i] == 'l')//lock
			{
				p2.setmove(100, 0, box[i]);
			}
			else if (box[i] == 'g')//gold
			{
				gotoxy(0, 99);
				cout << "Gold coin present do you want to pick if yes press 1" << endl;
				int option;
				cin >> option;
				if (option == 1)
				{
					p2.incg();
					p2.incgpoints();
					int r = i;
					int r1 = 0;
					//int x = 8;
					//int y = 5;
					int y1 = 0;
					int in = index;
					while (r>0)
					{
						r1 = r;
						r = r - object;
						if (r >= 1)
						{
							y1++;
						}
						r1 = 0;
						while (in%object != 0)
						{
							in = in + 1;
							r1++;
						}
					}
					if (y1 > 0)
					{
						y1 = y1 * 7;
						y = y + y1;
						y = y - 28;
					}
					if (r1 != 0)
					{
						r1 = r1 * 7;
						x = x - r1;
					}
					indexToGSconverter(i, object, x, y);
					gotoxy(x, y);
					cout << ' ';
					gotoxy(0, 99);
					cout << "                                                           ";
					gotoxy(0, 100);
					cout << " ";
				}
				gotoxy(0, 99);
					cout << "                                                           ";
					gotoxy(0, 100);
					cout << " ";
			}
			else if (box[i] == 's')//silver
			{
				gotoxy(0, 101);
				cout << "Silver coin present do you want to pick if yes press 1" << endl;
				int option;
				cin >> option;
				if (option == 1)
				{
					p2.incs();
					p2.incspoints();
					/*int r = i;
					int r1 = 0;
					int x = 8;
					int y = 5;
					int y1 = 0;
					while (r>0)
					{
					r1 = r;
					r = r - object;
					if (r >= 1)
					{
					y1++;
					}
					}
					if (y1 > 0)
					{
					y1 = y1 * 7;
					y = y + y1;
					}
					if (i != 0)
					{
					r1 = r1 - 1;
					r1 = r1 * 10;
					x = x + r1;
					}*/
					int r = i;
					int r1 = 0;
					//int x = 8;
					//int y = 5;
					int y1 = 0;
					int in = index;
					while (r>0)
					{
						r1 = r;
						r = r - object;
						if (r >= 1)
						{
							y1++;
						}
						r1 = 0;
						while (in%object != 0)
						{
							in = in + 1;
							r1++;
						}
					}
					if (y1 > 0)
					{
						y1 = y1 * 7;
						y = y + y1;
						y = y - 28;
					}
					if (r1 != 0)
					{
						r1 = r1 * 7;
						x = x - r1;
					}
					indexToGSconverter(i, object, x, y);
					gotoxy(x, y);
					cout << ' ';
					gotoxy(x, y);
					cout << ' ';
					gotoxy(0, 101);
					cout << "                                                           ";
					gotoxy(0, 102);
					cout << " ";
				}
				gotoxy(0, 101);
					cout << "                                                           ";
					gotoxy(0, 102);
					cout << " ";
			}
		}
	}

	void setpointsp1(int b)//points minus
	{
		p1.setpoint(b);
	}

	void setplayer1()//set player 1
	{
		p1.pn(1);
	}

	void setplayer2()// set player 2
	{
		p2.pn(2);
	}

	void setpointsp2(int b)// points minus
	{
		p2.setpoint(b);
	}

	void printp1points()//print points
	{
		/*gotoxy(89,49);
		int g;
		p1.getpoint(g);
		cout << g;*/
		int xlength = 0, x2 = 0;

		if (level == 1)
		{
			xlength = 64;
			x2 = 89;
		}
		else if (level == 2)
		{
			xlength = 100;
			x2 = 135;
		}
		else if (level == 3)
		{
			xlength = 100;
			x2 = 135;
		}
		else if (level == 4)
		{
			xlength = 128;
			x2 = 158;
		}
		int g;
		p1.getpoint(g);
		gotoxy(xlength, 52);
		cout << "Player1 Points:" << g << ' ';

	}

	void printp2points()//prinet points
	{
		//gotoxy(10,2);
		int xlength = 0, x2 = 0;

		if (level == 1)
		{
			xlength = 64;
			x2 = 89;
		}
		else if (level == 2)
		{
			xlength = 100;
			x2 = 135;
		}
		else if (level == 3)
		{
			xlength = 100;
			x2 = 135;
		}
		else if (level == 4)
		{
			xlength = 128;
			x2 = 158;
		}
		gotoxy(xlength, 55);
		int g;
		p2.getpoint(g);
		cout << "Player2 Points:" << g << ' ';
	}

	void initialize()//for initializing chest array
	{
		int b;
		if (level == 1)
		{
			b = 5;
		}
		else if (level == 2)
		{
			b = 7;
		}
		else if (level == 3)
		{
			b = 9;
		}
		else if (level == 4)

		{
			b = 11;
		}
		b = b*b;
		box = new char[b];
	}

	void printhurdle1(int i)//printing hurdle on player 1 side
	{
		int bsize;
		if (level == 1)
		{
			bsize = 5;
		}
		else if (level == 2)
		{
			bsize = 7;
		}
		else if (level == 3)
		{
			bsize = 9;
		}
		else if (level == 4)

		{
			bsize = 11;
		}
		int x = 2;
		int y = 5;
		int y1 = 0;
		int r = i;
		int r1 = 0;
		for (int o = 0; o < size; o++)
		{
			if (i == o + 1)
			{
				if (box[o] != '9')
				{
					while (r>0)
					{
						r1 = r;
						r = r - bsize;
						if (r >= 1)
						{
							y1++;
						}
					}
					if (y1 > 0)
					{
						y1 = y1 * 7;
						y = y + y1;
					}
					r1 = r1 - 1;
					r1 = r1 * 10;
					x = x + r1;
					gotoxy(x, y);
					if (box[o] == 'g')
					{
						x = x + 6;
						gotoxy(x, y);
						SetColor(14);
						cout << "o";
						SetColor(11);
						x = x - 6;
					}
					else if (box[o] == 's')
					{
						x = x + 6;
						gotoxy(x, y);
						SetColor(15);
						cout << "o";
						SetColor(11);
						x = x - 6;
					}
					else
						cout << box[o];
				}
			}
			{
				//	if ((o - 1) % bsize == 0 && (o-1) != 0)//if (o == bsize + 1)
				//	{
				//		y = y + 7;
				//		x = 2;
				//		gotoxy(x, y);
				//		if (box[o] == 'g')
				//		{
				//			SetColor(14);
				//			cout << box[o];
				//			SetColor(11);
				//		}
				//		else if (box[o] == 's')
				//		{
				//			SetColor(15);
				//			cout << box[o];
				//			SetColor(11);
				//		}
				//		else
				//		{
				//			cout << box[o];
				//		}
				//	}
				//	else if (o - 1 == 0)
				//	{
				//		gotoxy(x, y);
				//		cout << box[o];
				//		x = x + 10;
				//	}
				//	else
				//	{
				//		x = x + 10;
				//		gotoxy(x, y);
				//		if (box[o] == 'g')
				//		{
				//			SetColor(14);
				//			cout << box[o];
				//			SetColor(11);
				//		}
				//		else if (box[o] == 's')
				//		{
				//			SetColor(15);
				//			cout << box[o];
				//			SetColor(11);
				//		}
				//		else
				//		{
				//			cout << box[o];
				//		}
				//	}
			}
		}
	}

	void sethurdle1(int i, char b)//set hurdle in player 1 side
	{
		//while (i > size)
		{
			if (i <= size)
			{
				for (int o = 0; o < size; o++)
				{
					if (o + 1 == i)
					{
						box[o] = b;
					}
				}
			}
			else
			{
				cout << "Invalid box enter again" << endl;
			}
			//cin >> i;
		}
		printhurdle1(i);
	}

	void sethurdle2(int i, char b)// set hurdle on player 2 side
	{
		int object = 0;
		if (level == 1)
		{
			object = 5;
		}
		else if (level == 2)
		{
			object = 7;
		}
		else if (level == 3)
		{
			object = 9;
		}
		else if (level == 4)
		{
			object = 11;
		}
		object = object*object;
		object = object - i;
		//while (i > size)
		{
			if (i <= size)
			{
				for (int o = 0; o < size; o++)
				{
					if (o + 1 == object)
					{
						box[o] = b;
					}
				}
			}
			else
			{
				cout << "Invalid box enter again" << endl;
			}
			//cin >> i;
		}
		printhurdle1(object);
	}

	void random()// adding random objects on board
	{
		int object = 0;
		if (level == 1)
		{
			object = 8;
		}
		else if (level == 2)
		{
			object = 16;
		}
		else if (level == 3)
		{
			object = 24;
		}
		else if (level == 4)
		{
			object = 32;
		}
		int mid = object / 2;
		int r;
		srand(time(0)); int count = 0;
		for (int o = 0; o < mid; o++)
		{
			r = (rand() % mid) + 1;
			if (count % 2 == 0)
			{
				sethurdle1(r, 'g');
			}
			else if (count % 2 == 1)
			{
				sethurdle1(r, 's');
			}
			count++;

		}
		count = 0;
		for (int o = mid; o < object; o++)
		{
			r = (rand() % mid + mid) + 1;
			if (count % 2 == 0)
			{
				sethurdle2(r, 'g');
			}
			else if (count % 2 == 1)
			{
				sethurdle2(r, 's');
			}
			count++;
		}
	}

	void printhurdle()// print all hurdle
	{
		int bsize;
		if (level == 1)
		{
			bsize = 5;
		}
		else if (level == 2)
		{
			bsize = 7;
		}
		else if (level == 3)
		{
			bsize = 9;
		}
		else if (level == 4)

		{
			bsize = 11;
		}
		int x = 2;
		int y = 5;
		for (int o = 0; o < size; o++)
		{
			if (box[o] != '9')
			{
				if ((o - 1) % bsize == 0)//if (o == bsize + 1)
				{
					y = y + 7;
					x = 2;
					gotoxy(x, y);
					if (box[o] == 'g')
					{
						SetColor(14);
						cout << box[o];
						SetColor(11);
					}
					else if (box[o] == 's')
					{
						SetColor(15);
						cout << box[o];
						SetColor(11);
					}
					else
					{
						cout << box[o];
					}
				}
				else
				{
					x = x + 10;
					gotoxy(x, y);
					if (box[o] == 'g')
					{
						SetColor(14);
						cout << box[o];
						SetColor(11);
					}
					else if (box[o] == 's')
					{
						SetColor(15);
						cout << box[o];
						SetColor(11);
					}
					else
					{
						cout << box[o];
					}
				}
			}
		}
	}

	void getwin(bool & wi)// check win
	{
		wi = win;
	}

	void p1remove(int i)
	{
		int bsize;
		if (level == 1)
		{
			bsize = 5;
		}
		else if (level == 2)
		{
			bsize = 7;
		}
		else if (level == 3)
		{
			bsize = 9;
		}
		else if (level == 4)

		{
			bsize = 11;
		}
		int x = 2;
		int y = 5;
		int y1 = 0;
		int r = i;
		int r1 = 0;
		while (r>0)
		{
			r1 = r;
			r = r - bsize;
			if (r >= 1)
			{
				y1++;
			}
		}
		if (y1 > 0)
		{
			y1 = y1 * 7;
			y = y + y1;
		}
		r1 = r1 - 1;
		r1 = r1 * 10;
		x = x + r1;
		gotoxy(x, y);
		cout << " ";
	}

	void sethurdle(char b)// set hurdle all side
	{
		if (box == NULL)
		{
			box = new char;
			box[0] = b;
			size++;
		}
		else if (box != NULL)
		{
			extendby1(box, size);
			box[size - 1] = b;
		}
	}

	/*void checkhurdle(int moveb)
	{
	if (pp1 == 1)
	{
	if (moveb < mid)
	{
	if (box[moveb] != '9')
	{
	if (box[moveb] == 'G')
	{

	}
	}
	}
	}
	}*/
	bool check1(char b){

		if (p1.check(b) == 0)
		{
			return false;
		}
		else
			return true;
	}

	void removeprint1(int i, int level)
	{
		int objects;
		if (level == 1)
		{
			objects = 5;
		}
		else if (level == 2)
		{
			objects = 7;
		}
		else if (level == 3)
		{
			objects = 9;
		}
		else if (level == 4)
		{
			objects = 11;
		}
		objects = objects*objects;
		objects = objects - 1;
		objects = objects / 2;
		int r = i;
		int move;
		p1.getmove(move);
		if (move == 0)
		{


			int r1 = 0;
			int x = 2;
			int y = 5;
			int y1 = 0;
			while (r>0)
			{
				r1 = r;
				r = r - objects;
				if (r >= 1)
				{
					y1++;
				}
			}
			if (y1 > 0)
			{
				y1 = y1 * 7;
				y = y + y1;
			}
			if (i != 0)
			{
				//r1 = r1 ;
				r1 = r1 * 10;
				x = x + r1;
			}
			gotoxy(x, y);
			cout << ' ';
			gotoxy(0, 99);
			cout << "                                                     ";
			gotoxy(0, 100);
			cout << " ";
		}
	}

	bool check2(char b){
		if (p2.check(b) == 0)
		{
			return false;
		}
		else
			return true;
	}

	bool use1()
	{
		if(p1.use()!=0)
		{
			return true;
		}
		else
			return false;
	}

	bool use2()
	{
		if(p2.use()!=0)
		{
			return true;
		}
		else
			return false;
	}

	void setboard(int level)//board initializing
	{
		if (level == 1)
		{
			size = 5;
		}
		else if (level == 2)
		{
			size = 7;
		}
		else if (level == 3)
		{
			size = 9;
		}
		else if (level == 4)
		{
			size = 11;
		}
		size = size*size;
		char*box = new char[size];
		for (int o = 0; o < size; o++)
		{
			box[o] = '0';
		}
	}

	void setbox(int bo, char b)// set box
	{
		if (box != NULL)
		{
			for (int o = 0; o < size; o++)
			{
				if (o == bo)
				{
					box[o] = b;
				}
			}
		}
	}

	void removebox(int r)
	{
		int o;
		if(level==1)
		{
			o=25;
		}
		else if(level==2)
		{
			o=49;
		}
		else if(level==3)
		{
			o=81;
		}
		else if(level==4)
		{
			o=121;
		}
		for(int i=0; i<o; i++)
		{
			if(i==r-1)
			{
				box[i]='9';
				break;
			}
		}
	}

	void printboard(int level)// print board
	{
		this->level = level;
		int xytimes = 0;
		int length = 0;
		int width = 0;
		int ad = 0;
		int mids;
		int mide;
		if (level == 1)
		{
			xytimes = 6;
			length = 51;
			width = 35;
			mids = 14;
			mide = 21;
		}
		else if (level == 2)
		{
			xytimes = 8;
			length = 71;
			width = 49;
		}
		else if (level == 3)
		{
			xytimes = 10;
			length = 91;
			width = 63;
		}
		else if (level == 4)
		{
			xytimes = 12;
			length = 111;
			width = 77;
		}

		int mid = xytimes*xytimes;
		mid = mid - 1;
		mid = mid / 2;
		mid = mid + 1;
		int count = 0;
		int loop = xytimes;
		loop = loop / 2;
		loop = loop - 1;
		mid = length;
		while (mid % 10 != 0)
		{
			mid = mid - 1;
		}
		mid = mid / 2;
		mid = length;
		mid = mid / 10;
		mid = mid - 1;
		mid = mid / 2;
		mid = mid * 10;

		for (int j = 0; j < xytimes; j++)
		{
			if (j<loop)
			{
				SetColor(2);
			}
			else if (j>loop + 1)
			{
				SetColor(4);
			}
			for (int o = 0; o < length; o++)
			{

				/*if (mid == o - 5)
				{
				SetColor(7);
				}
				else if (mid == o + 1)
				{
				SetColor(9);
				}
				*/
				if (j == loop || j == loop + 1)
				{
					if (o >= mid && o <= mid + 10)
					{
						SetColor(7);
					}
					else if (o>mid + 10 && j == loop + 1)
					{
						SetColor(4);
					}
					else if (o>mid + 10 && j == loop)
					{
						SetColor(2);
					}
				}
				/*else
				{
				SetColor(2);
				}*/
				gotoxy(o, ad);
				cout << char(205);
				count++;
			}

			ad = ad + 7;
		}

		int sub = 0;
		mid = xytimes;
		loop = xytimes;
		loop = loop / 2;
		loop = loop - 1;
		mid = length;
		while (mid % 10 != 0)
		{
			mid = mid - 1;
		}
		/*mid = mid / 2;
		mid = length;
		mid = mid / 10;
		mid = mid - 1;
		mid = mid / 2;
		mid = mid * 10;*/
		mid = width / 7;
		mid = mid - 1;
		mid = mid / 2;
		mid = mid * 7;
		for (int k = 0; k < xytimes; k++)
		{
			if (k<loop)
			{
				SetColor(2);
			}
			else if (k>loop + 1)
			{
				SetColor(4);
			}
			/*if (k < loop)
			{
			SetColor(9);

			}
			else if (k == loop)
			{
			SetColor(7);
			}
			else if (k>loop)
			{
			SetColor(4);
			}*/

			/*if (k<loop)
			{
			SetColor(2);
			}
			else if (k>loop + 1)
			{
			SetColor(4);
			}*/


			for (int i = 0; i < width; i++)
			{
				/*if (k < mid)
				{
				SetColor(9);
				}
				else if (k == mid || k == mid + 1)
				{
				if (width >= mids || width <= mide)
				{
				SetColor(7);
				}
				}
				else if (k > mid + 1)
				{
				SetColor(6);
				}*/
				if (k == loop || k == loop + 1)
				{
					if (i > mid && i <mid + 7)
					{
						SetColor(7);
					}
					else if (i>mid + 7 && k == loop + 1)
					{
						SetColor(4);
					}
					else if (i>mid + 7 && k == loop)
					{
						SetColor(2);
					}
				}
				gotoxy(sub, i);
				cout << char(186);
			}

			sub = sub + 10;

		}


		int s = 2; int g = 0; int h = 0;
		if (level == 1)
		{
			g = 5;

		}
		else if (level == 2)
		{
			g = 7;

		}
		else if (level == 3)
		{
			g = 9;

		}
		else if (level == 4)
		{
			g = 11;
		}
		int countt = 1; int x99 = 0, y99 = 0;
		int r = 2; int c1 = 0, c2 = 0;
		h = g;
		h = h*h;
		h = h - 1;
		h = h / 2;
		int j = 0;
		for (int i = 0; i < h; i++)
		{
			/*if (i < g)
			{
			gotoxy(s, 2);
			cout << i+1;

			}
			if (i >= g && i<g*2)
			{
			if (i == g)
			s = 2;
			gotoxy(s, 10);
			cout << i+1;
			}
			if (i >= g*2)
			{
			if (i == g*2)
			s = 2;
			gotoxy(s, 18);
			cout << i+1;
			}
			s = s + 10;*/
			if (i == 0)
				j = i;
			if ((j + 1) % (g + 1) != 0)
			{
				gotoxy(s, r);
				cout << countt;
				s = s + 10;
				countt++;
				j++;
			}
			else if ((j + 1) % (g + 1) == 0)
			{
				r = r + 7;
				s = 2;
				//gotoxy(s, r);
				//cout<<countt;
				//s=s+10;
				i--;
				j++;


			}
		}
		if (level == 1)
		{
			r = 30;
			s = 42;
		}
		else if (level == 2)
		{
			r = 44;
			s = 62;

		}
		else if (level == 3)
		{
			r = 58;
			s = 82;
		}
		else if (level == 4)
		{
			r = 72;
			s = 102;
		}



		/*SetColor(11);
		gotoxy(5, 3);
		cout << "P1";
		gotoxy(s + 2, r + 1);
		cout << "P2";*/

		SetColor(4);

		int osama = 1;
		int h2 = g;
		h2 = h2*h2;
		h2 = h2 - 1;
		h2 = h2 / 2;
		j = 0;
		int temps = s;
		for (int i = 0; i < h2; i++)
		{
			if (i == 0)
			{
				j = i;
			}
			if ((j + 1) % (g + 1) != 0)
			{
				gotoxy(s, r);
				cout << osama;
				s = s - 10;
				osama++;
				j++;
			}
			else if ((j + 1) % (g + 1) == 0)
			{
				r = r - 7;
				s = temps;
				//gotoxy(s, r);
				//cout<<countt;
				//s=s+10;
				i--;
				j++;


			}

		}


		SetColor(15);

		//h = g;
		//h = h*h;
		//h = h - 1;
		//h = h / 2;
		// j = 0;
		//int tem = xytimes - 1;
		//tem = tem*tem;
		//count = 1;
		//s = xytimes - 2;
		//s = s*10;
		//s = s+2;
		//r = xytimes - 1;
		//r = r * 7;
		//r = r - 2;
		//int osama = 1;
		//for (int i =tem ; i > h; i--)
		//{
		//	/*if (i < g)
		//	{
		//	gotoxy(s, 2);
		//	cout << i+1;

		//	}
		//	if (i >= g && i<g*2)
		//	{
		//	if (i == g)
		//	s = 2;
		//	gotoxy(s, 10);
		//	cout << i+1;
		//	}
		//	if (i >= g*2)
		//	{
		//	if (i == g*2)
		//	s = 2;
		//	gotoxy(s, 18);
		//	cout << i+1;
		//	}
		//	s = s + 10;*/
		//	 
		//	if (i == 0)
		//		j = i;
		//	if ((j + 1) % (g + 1) != 0)
		//	{
		//		gotoxy(s, r);
		//		cout << osama;
		//		s = s - 10;
		//		osama++;
		//		j++;
		//	}
		//	else if ((j + 1) % (g + 1) == 0)
		//	{
		//		r = r - 7;
		//		s = xytimes-2;
		//		s = s * 10;
		//		s = s + 2;
		//		//gotoxy(s, r);
		//		//cout<<countt;
		//		//s=s+10;
		//		i--;
		//		j++;


		//	}


		//}

		gotoxy(s + 1, r + 2);
		cout << "GOAL!!";

		int xlength = 0, x2 = 0;

		if (level == 1)
		{
			xlength = 64;
			x2 = 89;
		}
		else if (level == 2)
		{
			xlength = 100;
			x2 = 135;
		}
		else if (level == 3)
		{
			xlength = 100;
			x2 = 135;
		}
		else if (level == 4)
		{
			xlength = 128;
			x2 = 158;
		}


		SetColor(15);

		gotoxy(x2, 3);
		cout << "Hurdles";

		gotoxy(xlength, 8);
		cout << "Fire (F)         Price: 50 Points(Both)     Block Opponent For 2 Turns";
		gotoxy(xlength, 11);
		cout << "Snake (S)        Price: 30 Points(Both)     Block Opponent For 3 Turns";
		gotoxy(xlength, 13);
		cout << "                                            also Send him Back 3 Cells";
		gotoxy(xlength, 19);
		cout << "Ghost (G)        Price: 20 Points(Both)     Block Opponent For 1 Turn";
		gotoxy(xlength, 22);
		cout << "Lion (L)         Price: 50 Points(Gold)     Block Opponent For 4 Turns";
		gotoxy(xlength, 25);
		cout << "Lock (l)        Price: 60 Points(Silver)   Block Opponent Until he uses Key";

		SetColor(13);

		gotoxy(x2 - 3, 30);
		cout << "Helping Objects";

		gotoxy(xlength, 35);
		cout << "Sword (S)        Prics: 40 Points        Kills Snake and Lion (Limit: 2)";
		gotoxy(xlength, 38);
		cout << "Shield (s)      Price: 30 Points        It Use against Ghost (Limit: 1)";
		gotoxy(xlength, 41);
		cout << "Water (W)        Price: 50 Points        It use against Fire  (Limit: 1)";
		gotoxy(xlength, 44);
		cout << "Key (K)          Price: 70 Points        It use to open Locked Door";


		SetColor(11);

		gotoxy(x2 - 4, 49);
		cout << "Points of Players";
		gotoxy(xlength, 52);
		cout << "Player1 Points: 200";
		gotoxy(xlength, 55);
		cout << "Player2 Points: 200";

		gotoxy(199, 199);
		cout << endl << endl << endl;
		/*SetColor(7);*/
		mid = xytimes - 1;
		mid = mid*mid;
		mid = mid - 1;
		mid = mid / 2;
		int i = 0;
		/*while (i++ < 3)
		{
		int r = (rand() % mid) + 1;
		checkbox(r, level);
		}
		i = 0;
		while (i < 6)
		{
		int r = (rand() % (xytimes - 1)) + mid;
		if (r>mid)
		{
		checkbox(r, level);
		i++;
		}
		}*/
		mid = xytimes - 1;
		mid = mid*mid;
		box = new char[mid];
		size = mid;
		for (int o = 0; o < mid; o++)
		{
			box[o] = '9';
		}
		int objects = 0;
		if (level == 1)
		{
			objects = 4;
		}
		else if (level == 2)
		{
			objects = 8;
		}
		else if (level == 3)
		{
			objects = 12;
		}
		else if (level == 4)
		{
			objects = 16;
		}
		int x = 2;
		int y = 5;
		/*for (int o = 0; o < objects; o++)
		{
		if (o == 0)
		{
		x = x + 20;
		gotoxy(x, y);
		cout << "G";
		box[o] = 'G';
		}
		else if (o % 2 == 0)
		{
		x = x - 10;
		y = y + 7;
		gotoxy(x, y);
		cout << "S";
		box[o] = 'S';
		}
		else
		{
		x = x + 10;
		y = y + 7;
		gotoxy(x, y);
		cout << "o";
		box[o] = 'g';
		}
		}*/
		mid = xytimes - 1;
		mid = mid*mid;
		mide = mid - 1;
		mide = mide / 2;
		mide = mide + 1;
		/*for (int o = 0; o < objects + 1; o++)
		{
		int r = rand() % mid;
		if (r != mide)
		{
		if (o == 0)
		{
		box[r] = 'G';
		}
		else if (o % 2 == 0)
		{
		box[r] = 'g';
		}
		else if (o % 3 == 0)
		{
		box[r] = 'S';
		}
		else
		{
		box[r] = 'F';
		}
		}
		}
		int xi;
		int yi;
		for (int l = 0; l < mid; l++)
		{
		if (box[l] != '9')
		{
		if (l <= (xytimes - 1))
		{
		xi = l;
		xi = xi * 10;
		x = x + xi;
		gotoxy(x, y);
		cout << box[l];
		}
		}
		}*/
		//checkbox(level,arr);
	}

};

class hurdles{
public:
	virtual void print() = 0;
	virtual void get() = 0;
};

//class fire : public hurdles
//{
//	int move;
//public:
//	fire()
//	{
//		move = 2;
//	}
//
//	void get(int &b)
//	{
//		b = move;
//	}
//
//	void print(int xaxis, int yaxis)
//	{
//		gotoxy(xaxis, yaxis);
//		cout << "F" << endl;
//	}
//};

//class ghost : public hurdles
//{
//	int move;
//public:
//	ghost()
//	{
//		move = 2;
//	}
//
//	void get(int &b)
//	{
//		b = move;
//	}
//
//	void print(int xaxis, int yaxis)
//	{
//		gotoxy(xaxis, yaxis);
//		cout << "G" << endl;
//	}
//};

void which(int p, char &c2)
{
	int c = 0;
	if (p == 2)
	{
		gotoxy(0, 82);
		cout << "Enter 1 for placing Fire Trap\n" << endl;        //buy hurdles,use hurdles, place hurdles, file handling
		cout << "Enter 2 for placing Snake Trap\n" << endl;
		cout << "Enter 3 for placing Ghost Trap\n" << endl;
		cout << "Enter 4 for placing Lion Trap\n" << endl;
		cout << "Enter 5 for placing Lock Trap\n" << endl;
	
		cin >> c;
		if (c == 1)
		{
			c2 = 'F';

		}
		else if (c == 2)
		{
			c2 = 'S';
		}
		else if (c == 3)
		{
			c2 = 'G';
		}
		else if (c == 4)
		{
			c2 = 'L';
		}
		else if (c == 5)
		{
			c2 = 'l';
		}
		
	}

	
}

bool PlayGameOfLife(int index3)
{
	int y2 = 0, x2 = 0;

	board b;
	int i = index3;
	int objects;
	setter(i, objects);
	b.printboard(i);
	b.setplayer1();
	b.setplayer2();
	b.random();
	//b.printbox();
	int x1 = 5;
	int y = 3;
	b.player1print(x1, y);
	int mid;
	objects = objects + 1;
	int points1;
	int points2;
	if (i == 1)
	{
		mid = 5;
		y2 = 30 + 1;
		x2 = 42 + 2;
	}
	else if (i == 2)
	{
		mid = 7;
		y2 = 44 + 1;
		x2 = 62 + 2;
	}
	else if (i == 3)
	{
		mid = 9;
		y2 = 58 + 1;
		x2 = 82 + 2;
	}
	else if (i == 4)
	{
		mid = 11;
		y2 = 72 + 1;
		x2 = 102 + 2;
	}


	int move = 0;
	int index = 1;
	int ho;

	b.player2print(x2, y2);
	int index2 = mid;
	index2 = index2*index2;
	index2 = index2 - 1;
	int move2 = 0;
	for (int o = 0; o < 1000; o++)    
	{

		if (move == 0)
		{
			char c2 = '\0';
			b.checkhurdle1(index-1);
			b.p1move(move);
			b.printp1points();
			if (move == 0)
			{ 
				b.p1remove(index);
				if (index == objects)
				{
					b.p1getpoints(points1);
					b.p2getpoints(points2);
					if (points1>points2)
					{
						cout << "p1 won" << endl;
						return true;
					}
					else
					{
						cout << "game is a draw" << endl;
						return true;
					}
					break;
				}
				b.player1print(x1, y);
				if ((index + 1) % mid == 0)
				{
					y = y + 7;
					x1 = 5;
					if (move==0)
					index++;
				}
				else{

					x1 = x1 + 10;
					if (move==0)
					index++;
				}

				
				int k=0;
				gotoxy(0, 80);
				cout << "Player 1 Turn" << endl<<endl;
				printmenu(k);
				if(k==1)
				{
					char ch='\0';
					removemenu();
					gotoxy(0,80);
					cout<<"Player 1 Turn\n\n";
					cout<<"Welcome you can buy any Hurdle Here\n\n";
					cout<<"Press F to Buy Fire\n\n";
					cout<<"Press S to Buy Snake\n\n";
					cout<<"Press G to Buy Ghost\n\n";
					cout<<"Press L to Buy Lion\n\n";
					cout<<"Press l to Buy Lock\n\n";
					cin>>ch;
					b.buy1(ch);
					cout<<"Thanks For Purchasing Hurdle\n\n";
					removemenu();
					b.printp1points();
					

				}
				else if(k==2)
				{
					char ch='\0';
					removemenu();
					gotoxy(0,80);
					cout<<"Player 1 Turn\n\n";
					cout<<"Welcome you can buy any Helping Object\n\n";
					cout<<"Press d to Buy a Sword\n\n";
					cout<<"Press s to Buy a Shield\n\n";
					cout<<"Press w to Buy Water\n\n";
					cout<<"Press k to Buy Key\n\n";
					cin>>ch;
					b.buy1(ch);
					cout<<"Thanks For Purchasing Helping Object\n\n";
					removemenu();
					b.printp1points();
				}
				else if(k==3)
				{
					char c2='\0';
					removemenu();
					gotoxy(0,80);
					cout<<"Player 1 Turn\n\n";
					which(2,c2);
					if (b.check1(c2) == 0)
					{
						if (b.buy1(c2) != 0)
						{
							b.sethurdle1(index2, c2);
						}
					}
					else
					{
						b.sethurdle1(index2, c2);
					}
					removemenu();
					b.printp1points();
				}
				else if(k==4)
				{
					removemenu();
					gotoxy(0,80);
					cout<<"Player 1 Turn\n\n";
					b.use1();
					removemenu();
					b.printp1points();
				}
				else if(k==5)
				{
					char *a;
		   b.getarr(a);
		   save(i,a,index,index2);
				}
				else if(k==6)
				{

					
					char *a;
					load(i,a,index, index2);
	b.printboard(i);
	b.setarr(a);
	int siz=strlen(a);
	int sii=siz-1;
	sii=sii/2;

	for(int i=0; i<siz; i++)
	{
		if(a[i]!='9')
		{
		b.sethurdle1(i+1,a[i]);
		}
	}
	x1=5;
	y=3;
	if ((index + 1) % mid == 0)
				{
					y = y + 7;
					x1 = 5;
					if (move==0)
					index++;
				}
				else{

					x1 = x1 + 10;
					if (move==0)
					index++;
				}
				if (i == 1)
	{
		mid = 5;
		y2 = 30 + 1;
		x2 = 42 + 2;
	}
	else if (i == 2)
	{
		mid = 7;
		y2 = 44 + 1;
		x2 = 62 + 2;
	}
	else if (i == 3)
	{
		mid = 9;
		y2 = 58 + 1;
		x2 = 82 + 2;
	}
	else if (i == 4)
	{
		mid = 11;
		y2 = 72 + 1;
		x2 = 102 + 2;
	}
				if ((index2 - 1) % mid == 0)
				{
					y2 = y2 - 7;
					x2 = mid - 1;
					x2 = x2 * 10;
					x2 = x2 + 4;
					if (move2==0)
					index2--;
				}
				else{

					x2 = x2 - 10;
					if (move2==0)
					index2--;
				}
				b.player1print(x1,y);
				b.player2print(x2,y2);



				}
				else if(k==7)
				{
					removemenu();

				}
		
				
				
				
					
				
			}
			else
			{

				removemenu();
				gotoxy(0,80);
				cout<<"Player 1 is Blocked due to a Hurdle\n\n";
				if(b.use1()==0)
				{
					if(b.use1()==false)
					{
						b.p1remove(index);
						b.setp1move(0);
						b.p1move(move);
						b.removebox(index);
						gotoxy(40,80);
						b.printbox();
					}
					else
					move = move - 1;
				if (move==0)
				b.setp1move(0);
				}
					gotoxy(0,80);
				cout<<"                                           ";
			}
		}

		else
		{
			move = move - 1;

			if (move == 0)
			{
				b.setp1move(0);
			}
			

		}

		if (move2 == 0)
		{

			if (index2 == objects)
			{
				b.p1getpoints(points1);
				b.p2getpoints(points2);
				if (points2>points1)
				{
					cout << "p2 won"<< endl;
					return true;
					
				}
				else
				{
					cout << "game is a draw" << endl;
					return true;
				}
				break;
			}
			b.checkhurdle2(index2);
			b.p2move(move2);
			b.printp2points();
			if (move2 == 0)
			{
				char c3 = '\0';
				b.player2print(x2, y2);
				if ((index2 - 1) % mid == 0)
				{
					y2 = y2 - 7;
					x2 = mid - 1;
					x2 = x2 * 10;
					x2 = x2 + 4;
					if (move2==0)
					index2--;
				}
				else{

					x2 = x2 - 10;
					if (move2==0)
					index2--;
				}

					int k=0;
				gotoxy(0, 80);
				cout << "Player 2 Turn" << endl<<endl;
				printmenu(k);
				if(k==1)
				{
					char ch='\0';
					removemenu();
					gotoxy(0,80);
					cout<<"Player 2 Turn\n\n";
					cout<<"Welcome you can buy any Hurdle Here\n\n";
					cout<<"Press F to Buy Fire\n\n";
					cout<<"Press S to Buy Snake\n\n";
					cout<<"Press G to Buy Ghost\n\n";
					cout<<"Press L to Buy Lion\n\n";
					cout<<"Press l to Buy Lock\n\n";
					cin>>ch;
					b.buy2(ch);
					cout<<"Thanks For Purchasing Hurdle\n\n";
					removemenu();
					b.printp2points();
					

				}
				else if(k==2)
				{
					char ch='\0';
					removemenu();
					gotoxy(0,80);
					cout<<"Player 2 Turn\n\n";
					cout<<"Welcome you can buy any Helping Object\n\n";
					cout<<"Press d to Buy a Sword\n\n";
					cout<<"Press s to Buy a Shield\n\n";
					cout<<"Press w to Buy Water\n\n";
					cout<<"Press k to Buy Key\n\n";
					cin>>ch;
					b.buy2(ch);
					cout<<"Thanks For Purchasing Helping Object\n\n";
					removemenu();
					b.printp2points();
				}
				else if(k==3)
				{
					char c2='\0';
					removemenu();
					gotoxy(0,80);
					cout<<"Player 2 Turn\n\n";
					which(2,c2);
					if (b.check2(c2) == 0)
					{
						if (b.buy2(c2) != 0)
						{
							b.sethurdle2(index2, c2);
						}
					}
					else
					{
						b.sethurdle2(index2, c2);
					}
					removemenu();
					b.printp2points();
				}
				else if(k==4)
				{
					removemenu();
					gotoxy(0,80);
					cout<<"Player 2 Turn\n\n";
					b.use2();
					removemenu();
					b.printp2points();
				}
				else if(k==5)
				{
					char *a;
		   b.getarr(a);
		   save(i,a,index,index2);
				}
				else if(k==6)
				{

					
					char *a;
					load(i,a,index, index2);
	b.printboard(i);
	b.setarr(a);
	int siz=strlen(a);
	int sii=siz-1;
	sii=sii/2;

	for(int i=0; i<siz; i++)
	{
		if(a[i]!='9')
		{
		b.sethurdle1(i+1,a[i]);
		}
	}
	x1=5;
	y=3;
	if ((index + 1) % mid == 0)
				{
					y = y + 7;
					x1 = 5;
					if (move==0)
					index++;
				}
				else{

					x1 = x1 + 10;
					if (move==0)
					index++;
				}
				if (i == 1)
	{
		mid = 5;
		y2 = 30 + 1;
		x2 = 42 + 2;
	}
	else if (i == 2)
	{
		mid = 7;
		y2 = 44 + 1;
		x2 = 62 + 2;
	}
	else if (i == 3)
	{
		mid = 9;
		y2 = 58 + 1;
		x2 = 82 + 2;
	}
	else if (i == 4)
	{
		mid = 11;
		y2 = 72 + 1;
		x2 = 102 + 2;
	}
				if ((index2 - 1) % mid == 0)
				{
					y2 = y2 - 7;
					x2 = mid - 1;
					x2 = x2 * 10;
					x2 = x2 + 4;
					if (move2==0)
					index2--;
				}
				else{

					x2 = x2 - 10;
					if (move2==0)
					index2--;
				}
				b.player1print(x1,y);
				b.player2print(x2,y2);


				}
				else if(k==7)
				{
					removemenu();
					b.printp2points();

				}
		
				
				
				
					
				
			}
			else
			{

				cout<<"Player 2 is Blocked due to a Hurdle\n\n";
				if(b.use2()==0)
				{
					if(b.use2()==false)
					{
						int x=0,y=0;
						BoxToIndexConverter(index2,mid,x,y);
						gotoxy(x,y);
						cout<<" ";
						b.setp2move(0);
						b.p2move(move2);
						b.removebox(index2+1);
						gotoxy(40,80);
						b.printbox();
					}
					else
					move2 = move2 - 1;
				if (move2==0)
				b.setp2move(0);
				}
					gotoxy(0,80);
				cout<<"                                           ";
			}

		}
		else
		{
			move = move - 1;
			if (move == 0)
				b.setp2move(0);
		}
	}
	

}

int main()
{
	int c=0;
	int index3=1;
	
	if(PlayGameOfLife(1)==1)
	{
		index3=index3+1;
		system("CLS");
		cout<<"Enter 1 to Continue to Next Level\n\n";
		cout<<"Enter 2 To Quit\n\n";
		cin>>c;
	    gotoxy(0,0);
		cout<<"                                          "<<endl;
		cout<<"                                           "<<endl;
		cout<<"    ";
		system("CLS");
		if(c==1)
		{
		
		
		if(PlayGameOfLife(index3)==1)
		{
			index3=index3+1;
			system("CLS");
			cout<<"Enter 1 to Continue to Next Level\n\n";
		    cout<<"Enter 2 To Quit\n\n";
		    cin>>c;
			 gotoxy(0,0);
		
			 cout<<"                                          "<<endl;
		
			 cout<<"                                           "<<endl;
		
			 cout<<"    ";
		
			 system("CLS");
			
			 if(c==1)
			{
			
				if(PlayGameOfLife(index3)==1)
			
				{
				
					index3=index3+1;
				
					system("CLS");
				
					cout<<"Enter 1 to Continue to Next Level\n\n";
		       
					cout<<"Enter 2 To Quit\n\n";
		      
					cin>>c;
			    
					gotoxy(0,0);
		
					cout<<"                                          "<<endl;
		
					cout<<"                                           "<<endl;
		
					cout<<"    ";
		
					system("CLS");
			   
					if(c==1)
			  
					{
				
						if(PlayGameOfLife(index3)==1)
				
						{
					
							system("pause");
					
							return 0;
				
						}
			   }
			   else
			   {
				   system("pause");
			       return 0;

			   }
			}
			
			 }
			
			 else
			
			 {
				
				 system("pause");
			
				 return 0;
			}
		
		}
		
		}
		else
			system("pause");
			return 0;
	}

	
	system("pause");
	return 0;
}

