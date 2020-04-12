#include "DRLinkList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
	ElementType Element;
	Position Next;
	Position Prev;
};

void NullAndExit(DRLinkList L) {
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

int IsLast(Position P, DRLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);

	return P->Next == L;
}

int IsEmpty(DRLinkList L) {
	NullAndExit(L);
	return L->Next == L;
}

DRLinkList CreateList() {
	DRLinkList L = (DRLinkList)malloc(sizeof(struct Node));
	if (L == NULL) {
		printf("Out of Space!!!");
		exit(1);
	}

	L->Next = L;
	L->Prev = L;
	return L;
}

void MakeEmpty(DRLinkList L) {
	NullAndExit(L);

	Position TmpCell, P;
	P = L->Next;
	L->Next = L;
	L->Prev = L;

	while (P != L) {
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}

	printf("MakeEmpty Success!\n");
}

void DeleteList(DRLinkList L) {
	NullAndExit(L);
	MakeEmpty(L);
	free(L);
	printf("DeleteList Success!\n");
}

ElementType Retrieve(Position P, DRLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);

	return P->Element;
}

Position FindForward(ElementType X, DRLinkList L) {
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

Position FindBackward(ElementType X, DRLinkList L) {
	NullAndExit(L);
	Position P = L->Prev;
	while (P != L && P->Element != X) {
		P = P->Prev;
	}

	if (P == L) {
		printf("No such Element in the List!\n");
		P = NULL;
	}
	return P;
}

void Insert(ElementType X, Position P, DRLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);

	Position TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL) {
		printf("Out of Space!!!");
		exit(1);
	}

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	TmpCell->Prev = P;
	P->Next->Prev = TmpCell;
	P->Next = TmpCell;
	printf("Insert Success!\n");
}

void Delete(ElementType X, DRLinkList L) {
	NullAndExit(L);
	if (IsEmpty(L)) {
		printf("The List is Empty!Please Insert First!");
		exit(1);
	}

	Position P = FindForward(X, L);
	NullAndExit(P);

	P->Prev->Next = P->Next;
	P->Next->Prev = P->Prev;
	free(P);

	printf("Delete Success!\n");
}

Position Advance(Position P, DRLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);
	return P->Next;
}

Position First(DRLinkList L)
{
	NullAndExit(L);
	return L->Next;
}