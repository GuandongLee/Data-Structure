#include "DLinkList.h"
#include <stdio.h>
#include <stdlib.h>

void PrintDLinkList(DLinkList L) {
	NullAndExit(L);

	Position P = First(L);
	printf("LinkList:[");
	while (P != NULL)
	{
		printf("%d ", Retrieve(P, L));
		P = Advance(P, L);
	}
	printf("]\n");
}

int main(void) {
	DLinkList L = CreateList();

	for (int i = 5; i > 0; --i) {
		Insert(i, L, L);
	}

	PrintDLinkList(L);

	Delete(4, L);

	PrintDLinkList(L);

	Position f = FindBackward(9,Find(3,L),L);
	Insert(9, f, L);

	DeleteList(L);
	L = NULL;
	system("pause");
}