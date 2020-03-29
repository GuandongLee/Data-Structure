#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

void PrintLinkList(LinkList L) {
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
	LinkList L = CreateList();

	for (int i = 5; i > 0; --i) {
		Insert(i, L, L);
	}

	PrintLinkList(L);

	Delete(6, L);

	PrintLinkList(L);

	Position f = Find(9, L);
	Insert(9, f, L);
	PrintLinkList(L);

	DeleteList(L);
	L = NULL;
	system("pause");
}