#ifndef DLINKLIST_H
#define DLINKLIST_H

typedef int ElementType;
typedef struct Node *DLinkList;
typedef DLinkList Position;

void NullAndExit(DLinkList L);									//操作指针为空时异常退出
void PositionInvalid(Position P);								//输入位置无效时异常退出
int IsLast(Position P, DLinkList L);							//判断当前位置是否为表尾
int IsEmpty(DLinkList L);										//判断表是否为空
DLinkList CreateList();											//创建空表
void MakeEmpty(DLinkList L);									//清空表
void DeleteList(DLinkList L);									//删除表
ElementType Retrieve(Position P, DLinkList L);					//返回表中指定位置元素
Position Find(ElementType X, DLinkList L);						//返回表中指定元素所在位置
Position FindForward(ElementType X, Position P, DLinkList L);	//从某个位置开始前向查找
Position FindBackward(ElementType X, Position P, DLinkList L);	//从某个位置开始后向查找
void Insert(ElementType X, Position P, DLinkList L);			//向表中指定位置后插入元素
void Delete(ElementType X, DLinkList L);						//删除表中指定元素
Position Advance(Position P, DLinkList L);						//返回表中指定位置的后继位置
Position First(DLinkList L);									//返回表头第一个元素

#endif 