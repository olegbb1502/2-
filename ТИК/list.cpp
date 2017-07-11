#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

struct TNode 
{
	int value;
	TNode* pnext, *prev;
};


void add2list(TNode **pphead, int val)
{
	TNode **pp = pphead;

	if (*pp == NULL)	// head == NULL
	{
		*pp = new TNode;
		(*pp)->value = val;
		(*pp)->prev = NULL;
		(*pp)->pnext = NULL;
	}
	else
	{
		while((*pp)->pnext) pp = &((*pp)->pnext);	// листаем до последнего

		(*pp)->pnext = new TNode;
		(*pp)->pnext->value = val;
		(*pp)->pnext->pnext = NULL;
		(*pp)->pnext->prev = *pp;
	}
}

void print(TNode *phead)
{
	TNode* p = phead;

	while(p)
	{
		cout << p->value << ' ';
		p = p->pnext;
	}
	cout << endl;
}

void change(TNode **pphead, int value1, int value2)
{
	TNode **pp = pphead, **pElement1, **pElement2, *ptmp1, *ptmp2;

	while(*pp)
	{
		if (value1 == (*pp)->value) pElement1 = &(*pp);
		if (value2 == (*pp)->value) pElement2 = &(*pp);
		pp = &(*pp)->pnext;
	}
	// меняем местами
	ptmp1 = (*pElement1)->pnext;
	ptmp2 = (*pElement2)->pnext;
	(*pElement1)->pnext = ptmp2;
	(*pElement2)->pnext = ptmp1;
	
	(*pElement2)->pnext->prev = *pElement2;
	(*pElement1)->pnext->prev = *pElement1;

	ptmp1 = (*pElement1)->prev;
	ptmp2 = (*pElement2)->prev;
	(*pElement1)->prev = ptmp2;
	(*pElement2)->prev = ptmp1;

	ptmp1 = *pElement1;
	(*pElement2)->prev->pnext = *pElement2;
	ptmp1->prev->pnext = ptmp1;

}

int main()
{
	TNode *phead=NULL;
	int n, k;
	cin>>n;
	int chislo[100];
	for(int j=0; j<n; j++){
		cin>>k;
		chislo[j]=k;
		add2list(&phead,chislo[j]);
	}
	/*for( int i = 0; i < n; ++i){
		add2list(&phead,chislo[i]);
	}*/

	cout << "Elements of the list:" << endl;
	print(phead);

	int value1, value2;
	cout << "Enter value1: ";
	cin >> value1;
	cout << "Enter value2: ";
	cin >> value2;
	
	change(&phead, value1, value2);
	cout << "Elements of the list after change:" << endl;
	print(phead);
	
	delete phead;
	
	system("pause");

	return 0;
}
