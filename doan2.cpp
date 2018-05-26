#include <stdio.h>
#include <conio.h>
#include <string.h>
#define zero '0'
int convert(char a)
{
	return a - zero;
}
void them(char s[],int n)
{
	int l = strlen(s);
	for (int i = l - 1; i >= 0; i--)
	{
		s[i + n] = s[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		s[i] = '0';
	}
	s[l + n] = '\0';
}
void themcuoi(char s[], int n)
{
	int l = strlen(s);
	for (int i = 0; i < n; i++)
	{
		s[l] = '0';
		l++;
	}
	s[l] = '\0';
}
void themcuoi2(char s[], char c)
{
	int l = strlen(s);
	s[l] = c;
	s[l+1] = '\0';
}
void daonguoc(char s[])
{
	char s2[50];
	int l = strlen(s), j = 0;
	for (int i = l-1; i >= 0; i--)
	{
		s2[j] = s[i];
		j++;
	}
	s2[j] = '\0';
	for (int i = 0; i < l; i++)
	{
		s[i] = s2[i];
	}
	s[l] = '\0';
}
void add(char s1[], char s2[],char s[])
{
	if (strlen(s1) != strlen(s2))
	{
		if (strlen(s1) > strlen(s2))
		{
			them(s2, strlen(s1) - strlen(s2));
		}
		else if(strlen(s1) < strlen(s2))
		{
			them(s1, strlen(s2) - strlen(s1));
		}
	}
	int l = strlen(s1), tam = 0, j = 0;
	for (int i = l-1; i>=0; i--)
	{
		int S = convert(s1[i]) + convert(s2[i]) + tam;
		if (S >= 10)
		{ 
			s[j] = (S % 10) + zero;
			tam = 1;
			j++;
		}
		else 
		{
			s[j] = S+zero;
			tam = 0;
			j++;
		}
	}
	if (tam == 1)
	{
		s[j] = 49;
		j++;
	}
	s[j] = '\0';
	daonguoc(s);
} 
int solon(char s1[], char s2[])
{
	if (strlen(s1) > strlen(s2))
	{
		return 1;
	}
	else if (strlen(s2) > strlen(s1))
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < strlen(s1); i++)
		{
			if (convert(s1[i])>convert(s2[i]))
			{
				return 1;
			}
			else if (convert(s1[i]) < convert(s2[i]))
			{
				return -1;
			}
		}
		return 0;
	}
}
void expect(char s1[], char s2[], char s[])
{
			them(s2, strlen(s1) - strlen(s2));
	int l=strlen(s1), tam = 0, j = 0;
	for (int i = l-1; i >= 0; i--)
	{
		if (convert(s1[i]) < (convert(s2[i])+tam))
		{
			s[j] = convert(s1[i]) + 10 - (convert(s2[i]) + tam)+zero;
			j++;
			tam = 1;
		}
		else
		{
			s[j] = convert(s1[i]) - (convert(s2[i]) + tam)+zero;
			tam = 0;
			j++;
		}
	}
	s[j] = '\0';
	int i = strlen(s)-1;
	while (s[i] == '0')
	{
		i--;
	}
	s[i+1] = '\0';
	daonguoc(s);
}
void expect2(char s1[], char s2[], char s[])
{
	if (solon(s1, s2) == 0)
	{
		s[0] = 48;
		s[1] = '\0';
	}
	else if (solon(s1, s2) == 1)
	{
		expect(s1, s2, s);
	}
	else
	{
		expect(s2, s1, s);
		int l = strlen(s);
		for (int i = l - 1; i >= 0; i--)
		{
			s[i + 1] = s[i];
		}
		s[0] = '-';
		s[l + 1] = '\0';
	}
}
void mutipulication1(char s[], char c,char s2[])
{
	char s1[50];
	int l = strlen(s), j = 0, tam = 0;
	for (int i = l - 1; i >= 0; i--)
	{
		if ((convert(s[i])*convert(c)+tam) >= 10)
		{
			s1[j] = (convert(s[i])*convert(c)+tam) % 10 + zero;
			tam = (convert(s[i])*convert(c) + tam) / 10 ;
			j++;
		}
		else
		{
			s1[j] = (convert(s[i])*convert(c) + tam) + zero;
			tam = 0;
			j++;
		}
	}
	if (tam != 0)
	{
		s1[j] = tam + zero;
		j++;
	}
	s1[j] = '\0';
	daonguoc(s1);
	strcpy(s2, s1);
}
void mutipulication2(char s1[], char s2[], char s[])
{
	int tam = 0, l = 0;
	char s3[50], s4[50];
	mutipulication1(s1, s2[strlen(s2) - 1], s3);
	int j = 1;
	for (int i = strlen(s2)-2; i >= 0; i--)
	{
		mutipulication1(s1, s2[i], s4);
		themcuoi(s4, j);
		add(s3, s4, s);
		strcpy(s3, s);
		j++;
	}
	strcpy(s, s3);
}
char division1(char s1[], char s2[])
{
	char s3[50], s4[50];
	for (int i = 49; i < 58; i++)
	{
		mutipulication1(s2, i, s3);
		expect2(s1, s3, s4);
		if (s4[0] == '-')
		{
			return i-1;
		}
	}
	return 57;
}
void division2(char s1[], char s2[],char S1[],char S2[])
{
	if (solon(s1, s2) == 0)
	{
		S1[0] = '1';
		S1[1] = '\0';
		S2[0] = '0';
		S2[1] = '\0';
	}
	else if (solon(s1, s2) == -1)
	{
		S1[0] = '0';
		S1[1] = '\0';
		strcpy(S2, s1);
	}
	else
	{
		char s3[50], s4[50],s5[50];
		int j = 1, i = 0, l = strlen(s1);
		s3[0] = s1[0];
		s3[1] = '\0';
		while (j < l)
		{
			while (solon(s3, s2) == -1)
			{
				themcuoi2(s3, s1[j]);
				j++;
			}
			char x = division1(s3, s2);
			S1[i] = x;
			i++;
			mutipulication1(s2, x, s4);
			expect2(s3, s4, s5); 
			strcpy(s3, s5);
		}
			strcpy(S2, s3);
			S1[i] = '\0';
	}
}
void main()
{
	char s1[100], s2[100], S1[100],S2[100];
	printf("Nhap so thu nhat s1 = ");
	gets_s(s1);
	printf("Nhap so thu 2 s2 = ");
	gets_s(s2);
	printf("\ns1 = %s s2 = %s", s1, s2);
	//add; (s1, s2, s);
	//expect2(s1, s2, S1);
	//mutipulication2(s1, s2, s);
	division2(s1, s2,S1,S2);
	printf("\n expect =  %s %s",S1,S2); 
	_getch();
}