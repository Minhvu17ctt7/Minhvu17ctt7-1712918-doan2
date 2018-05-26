#include <stdio.h>
#include <conio.h>
#include <string.h>
struct node
{
	int value;
	node *next;
};
struct list
{ 
	node *pheap;
	node *ptail;
};
void khoitao(list &L)
{
	L.pheap = L.ptail = NULL;
}
node* taonut(int n)
{ 
	node*p = new node;
	p->value = n;
	p->next = NULL;
	return p;
}
void themdau(list &L, int n)
{
	node *p = taonut(n);
	if (L.pheap== NULL)
	{
		L.pheap = L.ptail = p;
		return;
	}
	p->next = L.pheap;
	L.pheap = p;
}
void themcuoi(list &L, int n)
{
	node *p = taonut(n);
	if (L.pheap == NULL)
	{
		L.pheap = L.ptail = p;
		return;
	}
	L.ptail->next = p;
	L.ptail = p;

}
void xoadau(list &L)
{
	if (L.pheap == NULL)
	{
		return;
	}
	if (L.pheap == L.ptail)
	{
		delete[]L.pheap;
		L.pheap = L.ptail = NULL;
		return;
	}
	node *p = L.pheap;
	L.pheap = L.pheap->next;
	delete[] p;
}
void xoacuoi(list &L)
{
	if (L.pheap == NULL)
	{
		return;
	}
	if (L.pheap == L.ptail)
	{
		delete[]L.ptail;
		L.pheap = L.ptail = NULL;
		return;
	}
	node*p = L.pheap;
	while (p->next != L.ptail)
	{
		p = p->next;
	}
	delete[]L.ptail;
	p->next = NULL;
	L.ptail = p;
}
int laydau(list &L)
{
	int n;
	if (L.pheap == NULL)
	{
		return -1;
	}
	n = L.pheap->value;
	xoadau(L);
	return n;
}
int laycuoi(list&L)
{
	int n;
	if (L.pheap == NULL)
	{
		return -1;
	}
	n = L.ptail->value;
	xoacuoi(L);
	return n;
}
void xuat(list &L)
{
	for (node *p = L.pheap; p != NULL; p=p->next)
	{
		printf("%4d", p->value);
	}
}
void xoanganxep(list &L)
{
	node *p;
	while (L.pheap);
	{
		p = L.pheap;
		L.pheap = L.pheap->next;
		delete[]p;
	}
}
int tachso(list &L1,list &L2)
{
	int n = 0;
	node *p;
	for (p = L1.pheap; p != NULL; p = p->next)
	{
		char c = p->value;
		if (c != '(')
		{
			break;
		}
	}
	for (node *q = p; q != NULL; q = q->next)
	{
		int x = q->value - 48;
		n = n * 10 + x;
	}
	while (L1.ptail != p)
	{
		xoacuoi(L1);
		xoacuoi(L2);
	}
	xoacuoi(L1);
	xoacuoi(L2);
	return  n;
}
void congthuc(list &L1, list&L2,char s[])
{
	list L3;
	list L4;
	khoitao(L3);
	khoitao(L4);
	for (int i = 0; i < strlen(s); i++)
	{
		char c = s[i];
		int n = s[i];
	   if (c == ' ')
		{
			continue;
		}
		if (c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')' && c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9')
		{
			printf("phep toan khong hop le \n");
			return;
		}
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (i == strlen(s) - 1)
			{
				printf("cong thuc khong hop le 2\n");
				return;
			}
			if (L3.pheap == NULL || L4.ptail->value == 0)
			{
				char c1 = L3.ptail->value;
				if (c1 == ')')
				{
					xoacuoi(L3);
					xoacuoi(L4);
					themcuoi(L3, n);
					themcuoi(L4, 0);
				}
				else{
					printf("phep toan khong hop le 3\n");
					return;
				}
			}
			if (L4.ptail->value == 1)
			{
				int x = tachso(L3, L4);
				themcuoi(L1, x);
				themcuoi(L2, 1);
				themcuoi(L3, n);
				themcuoi(L4, 0);
			}
		}
	
		if (48 <= n && n <= 57)
		{
			if (L3.pheap == NULL || L4.ptail->value == 1)
			{
				themcuoi(L3, n);
				themcuoi(L4, 1);
			}
			if (L4.ptail->value == 0)
			{
				char c1 = L3.ptail->value;
				if (c1 == ')')
				{
					printf("khong hop le 5\n");
					return;
				}
				if (c1 == '(')
				{
					themcuoi(L3, n);
					themcuoi(L4, 1);
				}
				else{
					int x = laycuoi(L3);
					xoacuoi(L4);
					themcuoi(L1, x);
					themcuoi(L2, 0);
					themcuoi(L3, n);
					themcuoi(L4, 1);
				}
				if (i == strlen(s) - 1)
				{
					int x = tachso(L3, L4);
					themcuoi(L1, x);
					themcuoi(L2, 1);
				}
			}
		}
		if (c == '(')
		{

			if (L3.pheap == NULL)
			{
				themcuoi(L3, n);
				themcuoi(L4, 0);
				themcuoi(L1, n);
				themcuoi(L2, 0);
			}
			else{
				if ((char)L3.ptail->value == '(')
				{
					themcuoi(L1, n);
					themcuoi(L2, 0);
					themcuoi(L3, n);
					themcuoi(L4, 0);
				}
				else{
					if (L4.ptail->value == 1 || (char)L3.ptail->value == ')'||i==strlen(s)-1)
					{
						printf("Cong thuc khong hop le 6\n");
						return;
					}
					else{
						if (L4.ptail->value == 0)
						{
							int x = laycuoi(L3);
							xoacuoi(L3);
							xoacuoi(L4);
							themcuoi(L1, x);
							themcuoi(L2, 0);
							themcuoi(L3, n);
							themcuoi(L4, 0);
							themcuoi(L1, n);
							themcuoi(L2, 0);
						}
					}
				}
			}
		}
		if (c == ')')
		{
			if (L3.pheap == NULL || (char)L3.pheap->value != '(' || (char)L3.ptail->value == '(')
			{
				printf("cong thuc khong hop le 7\n");
				return;
			}
			if (i == strlen(s) - 1)
			{
				xoadau(L3);
				xoadau(L4);
				int x = tachso(L3, L4);
				themcuoi(L1, x);
				themcuoi(L2, 1);
				themcuoi(L1, n);
				themcuoi(L2, 0);
			}
			else{
				if (L4.ptail->value == 0)
				{
					char c1 = L3.ptail->value;
					if (c1 == ')')
					{
						xoacuoi(L3);
						xoacuoi(L4);
						themcuoi(L3, n);
						themcuoi(L4, 0);
					}
				}
				else{
					if (L4.ptail->value == 1)
					{
						xoadau(L3);
						xoadau(L4);
						int x = tachso(L3, L4);
						themcuoi(L1, x);
						themcuoi(L2, 1);
						themcuoi(L1, n);
						themcuoi(L2, 0);
						themcuoi(L3, n);
						themcuoi(L4, 0);
					}
				}
			}
		}
	}
}
int uutien(int n)
{
	char c = n;
	if (c == '*' || c == '/')
	{
		return 1;
	}
	if (c == '+' || c == '-')
	{
		return 0;
	}
	return -1;
}
int tinhtoan(list L1, list L2)
{
	list L3, L4, L5, L6;
	khoitao(L3);
	khoitao(L4);
	khoitao(L5);
	khoitao(L6);
	node * p = L1.pheap;
	while (p != NULL)
	{
		int n = L1.pheap->value;
		int m = L2.pheap->value;
		xoadau(L1);
		xoadau(L2);
		char c1 = n;
		if (m == 1)
		{
			themcuoi(L3, n);
			themcuoi(L4, m);
		}
		else{
			if (c1 == '+' || c1 == '-' || c1 == '*' || c1 == '/')
			{
				if (L5.pheap != NULL)
				{
					int n5 = L5.pheap->value;
					int n6 = L6.pheap->value;
					char c2 = n5;
					if (n6 == 0)
					{
						if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/')
						{
							int s1 = uutien(n);
							int s2 = uutien(n5);
							if (s2 > s1)
							{
								xoadau(L5);
								xoadau(L6);
								themcuoi(L3, n5);
								themcuoi(L4, n6);
							}
						}
					}
				}
				themcuoi(L5, n);
					themcuoi(L6, m);
				}
				else
				{
					if (c1 == '(')
					{
						themcuoi(L5, n);
						themcuoi(L6, m);
					}
					else
					{
						if (c1 == ')')
						{
							int n5 = laydau(L5);
							int n6 = laydau(L6);
							char c2 = n5;
							while (c2 != '(')
							{
								themcuoi(L3, n5);
								themcuoi(L4, n6);
								n5 = L5.pheap->value;
								n6 = L6.pheap->value;
								c2 = n5;
								xoadau(L5);
								xoadau(L6);
							}
						}
					}
				}
			}
		p = L1.pheap;
	}
	p = L5.pheap;
	while (p != NULL)
	{
		int n5 = laydau(L5);
		int n6 = laydau(L6);
		themcuoi(L3, n5);
		themcuoi(L4, n6);
		p = L5.pheap;
	}
	p = L3.pheap;
	while (p != NULL)
	{
		int n = laydau(L3);
		int m = laydau(L4);
		char c1 = n;
		if (m == 1)
		{
			themcuoi(L1, n);
			themcuoi(L2, m);
		}
		else
		{
			int x1 = laydau(L1);
			int x2 = laydau(L1);
			int x;
			xoadau(L2);
			xoadau(L2);
			if (c1 == '+')
			{
				x = x1 + x2;
			}
			else{
				if (c1 == '-')
				{
					x = x1 - x2;
				}
				else{
					if (c1 == '*')
					{
						x = x1 * x2;
					}
					else
					{
						x = x1 / x2;
					}
				}
			}
			themcuoi(L1, x);
			themcuoi(L2, 1);
		}
		p = L3.pheap;
	}
	return L1.pheap->value;
}
void main()
{
	list L1;
	list L2;
	khoitao(L1);
	khoitao(L2);
	char s[50];
	printf("Nhap cong thuc : ");
	gets_s(s);
	congthuc(L1, L2, s);
	int x=tinhtoan(L1, L2);
	printf(" = %d", x);
	_getch();
}