#include"RLinkList.h"
#include <stdio.h>
#include <stdlib.h>

void PrintRLinkList(RLinkList L) {
	NullAndExit(L);

	Position P = First(L);
	printf("LinkList:[");
	while (P != L)
	{
		printf("%d ", Retrieve(P, L));
		P = Advance(P, L);
	}
	printf("]\n");
}

int main(void) {
	RLinkList L = CreateList();

	for (int i = 5; i > 0; --i) {
		Insert(i, L, L);
	}

	PrintRLinkList(L);

	Delete(4, L);

	Position f = Find(3, L);
	Insert(9, f, L);

	PrintRLinkList(L);

	DeleteList(L);
	L = NULL;
	system("pause");
}