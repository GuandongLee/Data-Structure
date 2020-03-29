#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
	ElementType Element;
	Position Next;
};

void NullAndExit(LinkList L) {
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

int IsLast(Position P, LinkList L) {
	NullAndExit(L);
	PositionInvalid(P);

	return P->Next == NULL;
}

int IsEmpty(LinkList L) {
	NullAndExit(L);
	return L->Next == NULL;
}

LinkList CreateList() {
	LinkList L = (LinkList)malloc(sizeof(struct Node));
	if (L == NULL) {
		printf("Out of Space!!!");
		exit(1);
	}

	L->Next = NULL;
	return L;
}

void MakeEmpty(LinkList L) {
	NullAndExit(L);

	Position TmpCell, P;
	P = L->Next;
	L->Next = NULL;

	while (P != NULL) {
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}

	printf("MakeEmpty Success!\n");
}

void DeleteList(LinkList L) {
	NullAndExit(L);
	MakeEmpty(L);
	free(L);
	printf("DeleteList Success!\n");
}

ElementType Retrieve(Position P, LinkList L) {
	NullAndExit(L);
	PositionInvalid(P);

	return P->Element;
}

Position Find(ElementType X, LinkList L) {
	NullAndExit(L);
	Position P = L->Next;
	while (P != NULL && P->Element != X) {
		P = P->Next;
	}

	if (P == NULL) {
		printf("No such Element in the List!\n");
	}
	return P;
}

Position FindPrevious(ElementType X, LinkList L) {
	NullAndExit(L);
	Position P = L;
	while (P->Next != NULL && P->Next->Element != X) {
		P = P->Next;
	}

	if (IsLast(P, L)) {
		printf("No such Element in the List!\n");
		return NULL;
	}
	else {
		return P;
	}
}

void Insert(ElementType X, Position P, LinkList L) {
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

void Delete(ElementType X, LinkList L) {
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

Position Advance(Position P, LinkList L) {
	NullAndExit(L);
	PositionInvalid(P);
	return P->Next;
}

Position First(LinkList L)
{
	NullAndExit(L);
	return L->Next;
}
