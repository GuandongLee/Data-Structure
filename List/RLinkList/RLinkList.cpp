#include "RLinkList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
	ElementType Element;
	Position Next;
};

void NullAndExit(RLinkList L) {
	if (L == NULL) {
		printf("The List isn't exist!");
		exit(1);
	}
}

void PositionInvalid(Position P) {
	if (P == NULL) {
		printf("The Position is invalid!Please Try Again!");
		exit(1);
	}
}

int IsLast(Position P, RLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);

	return P->Next == L;
}

int IsEmpty(RLinkList L) {
	NullAndExit(L);
	return L->Next == L;
}

RLinkList CreateList() {
	RLinkList L = (RLinkList)malloc(sizeof(struct Node));
	if (L == NULL) {
		printf("Out of Space!!!");
		exit(1);
	}

	L->Next = L;
	return L;
}

void MakeEmpty(RLinkList L) {
	NullAndExit(L);

	Position TmpCell, P;
	P = L->Next;
	L->Next = L;

	while (P != L) {
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}

	printf("MakeEmpty Success!\n");
}

void DeleteList(RLinkList L) {
	NullAndExit(L);
	MakeEmpty(L);
	free(L);
	printf("DeleteList Success!");
}

ElementType Retrieve(Position P, RLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);

	return P->Element;
}

Position Find(ElementType X, RLinkList L) {
	NullAndExit(L);
	Position P = L->Next;
	while (P != L && P->Element != X) {
		P = P->Next;
	}

	if (P == L) {
		printf("No such Element in the List!\n");
		P = NULL;
	}
	return P;
}

Position FindPrevious(ElementType X, RLinkList L) {
	NullAndExit(L);
	Position P = L->Next;
	while (P->Next != L && P->Next->Element != X) {
		P = P->Next;
	}

	if (IsLast(P, L)) {
		printf("No such Element in the List!\n");
		P = NULL;
	}
	return P;
}

void Insert(ElementType X, Position P, RLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);

	Position TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL) {
		printf("Out of Space!!!");
		exit(1);
	}

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
	printf("Insert Success!\n");
}

void Delete(ElementType X, RLinkList L) {
	NullAndExit(L);
	if (IsEmpty(L)) {
		printf("The List is Empty!Please Insert First!");
		exit(1);
	}

	Position P = FindPrevious(X, L);
	NullAndExit(P);

	Position TmpCell = P->Next;
	P->Next = TmpCell->Next;
	free(TmpCell);

	printf("Delete Success!\n");
}

Position Advance(Position P, RLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);
	return P->Next;
}

Position First(RLinkList L)
{
	NullAndExit(L);
	return L->Next;
}