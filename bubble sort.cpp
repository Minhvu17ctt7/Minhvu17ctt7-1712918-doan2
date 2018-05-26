#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
/*void input(int *&A, int &n)
{
	printf("input n = ");
	scanf_s("%d", &n);
	A = new int[n];
	for (int i = 0; i < n; i++)
	{
		printf("input a[%d] = ", i);
		scanf_s("%d", A + i);
	}
}*/
void input(long *&A, long n)
{
	A = new long[n];
	for (long i = 0; i < n; i++)
	{
		A[i] = rand() % n;
	}
}
void output(long A[], long n)
{
	for (long i = 0; i < n; i++)
	{
		printf("%4d", *(A + i));
	}
}
void hoanvi(long &n,long &m)
{
	long temp = n;
	n = m;
	m = temp;
}
void bubblesort(long *&A, long n)
{
	for (long i = 0; i < n - 1; i++)
	{
		for (long j = n - 1; j>i; j--)
		{
			if (A[j] < A[j - 1])
			{
				hoanvi(A[j], A[j - 1]);
			}
		}
	}
}
void shakersort(long *&A, long n)
{
	long l = 0, r = n - 1, k=n-1, i;
	while (l < r)
	{
		 i = r;
		while (i>l)
		{
			if (A[i]< A[i - 1])
			{
				hoanvi(A[i], A[i - 1]);
				k = i;
			}
				i--;
		}
		l = k;
		i = l;
		while (i < r)
		{
			if (A[i]>A[i + 1])
			{
				hoanvi(A[i], A[i + 1]);
				k = i;
			}
			i++;
		}
		r = k;
	}
}
void selection(long *&A, long n)
{
	long min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (long j = i; j < n; j++)
		{
			if (A[j]<A[min])
			{
				min = j;
			}
		}
		hoanvi(A[i], A[min]);
	}
}
void insertionsort(long *&A, long n)
{
	for (long i = 1; i < n; i++)
	{
		long temp = A[i];
		long j = i;
		while (j >= 0 && temp <= A[j])
		{
			A[j] = A[j - 1];
			j--;
		}
		A[j + 1] = temp;
	}
}
void qicksort(long *&A, long l,long r)
{
	long i = l, j = r, x = A[(l + r) / 2];
	do{
		while (A[i] < x)
		{
			i++;
		}
		while (A[j]>x)
		{
			j--;
		}
		if (i <= j)
		{
			hoanvi(A[i], A[j]);
			i++, j--;
		}
	} while (i < j);
	if (l < j)
	{
		qicksort(A, l, j);
	}
	if (i < r)
	{
		qicksort(A, i, r);
	}
}
void main()
{
	srand(time(NULL));
	long *A=NULL;
	long n = 1000000;
	printf("\n\t\tARRAY\n\n");
	printf("\tInput\n");
	input(A, n);
	printf("\n\tOutput\n");
	output(A, n);
	printf("\nSau khi sap xep : ");
	clock_t start = clock();
	//bubblesort(A, n);
	//shakersort(A, n);
	//selection(A, n);
	insertionsort(A, n);
	//qicksort(A, 0, n - 1);
	output(A, n);
	clock_t finish = clock();
	double time = (double)(finish - start);
	printf("\n\ntime = %f", time);
	delete[]A;
	_getch();
}