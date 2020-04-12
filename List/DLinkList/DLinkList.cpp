#include "DLinkList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
	ElementType Element;
	Position Next;
	Position Prev;
};

void NullAndExit(DLinkList L) {
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

int IsLast(Position P, DLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);

	return P->Next == NULL;
}

int IsEmpty(DLinkList L) {
	NullAndExit(L);
	return L->Next == NULL;
}

DLinkList CreateList() {
	DLinkList L = (DLinkList)malloc(sizeof(struct Node));
	if (L == NULL) {
		printf("Out of Space!!!");
		exit(1);
	}

	L->Next = NULL;
	L->Prev = NULL;
	return L;
}

void MakeEmpty(DLinkList L) {
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

void DeleteList(DLinkList L) {
	NullAndExit(L);
	MakeEmpty(L);
	free(L);
	printf("DeleteList Success!\n");
}

ElementType Retrieve(Position P, DLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);

	return P->Element;
}

Position Find(ElementType X, DLinkList L) {
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

Position FindForward(ElementType X, Position P, DLinkList L)
{
	NullAndExit(L);
	PositionInvalid(P);
	while (P != L && P->Element != X) {
		P = P->Prev;
	}

	if (P == L) {
		printf("Cannot Find the Element!\n");
		P = NULL;
	}
	return P;
}

Position FindBackward(ElementType X, Position P, DLinkList L)
{
	NullAndExit(L);
	PositionInvalid(P);
	while (P != NULL && P->Element != X) {
		P = P->Next;
	}

	if (P == NULL) {
		printf("Cannot Find the Element!\n");
	}
	return P;
}

void Insert(ElementType X, Position P, DLinkList L) {
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
	P->Next = TmpCell;
	if (!IsLast(TmpCell, L)) {
		TmpCell->Next->Prev = TmpCell;			//注意如果在表尾不加判定会报错
	}

	printf("Insert Success!\n");
}

void Delete(ElementType X, DLinkList L) {
	NullAndExit(L);
	if (IsEmpty(L)) {
		printf("The List is Empty!Please Insert First!");
		exit(1);
	}

	Position P = Find(X, L);
	NullAndExit(P);

	P->Prev->Next = P->Next;
	if (!IsLast(P, L)) {
		P->Next->Prev = P->Prev;		//注意如果在表尾不加判定会报错
	}
	free(P);

	printf("Delete Success!\n");
}

Position Advance(Position P, DLinkList L) {
	NullAndExit(L);
	PositionInvalid(P);
	return P->Next;
}

Position First(DLinkList L) {
	NullAndExit(L);

	return L->Next;
}