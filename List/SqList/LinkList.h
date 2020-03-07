#ifndef LINKLIST_H
#define LINKLIST_H

typedef int ElementType;
typedef struct Node *LinkList;
typedef LinkList Position;

void NullAndExit(LinkList L);							//操作指针为空时异常退出
void PositionInvalid(Position P);						//输入位置无效时异常退出
int IsLast(Position P, LinkList L);						//判断当前位置是否为表尾
int IsEmpty(LinkList L);								//判断表是否为空
LinkList CreateList();									//创建空表
void MakeEmpty(LinkList L);								//清空表
void DeleteList(LinkList L);							//删除表
ElementType Retrieve(Position P, LinkList L);			//返回表中指定位置元素
Position Find(ElementType X, LinkList L);				//返回表中指定元素所在位置
Position FindPrevious(ElementType X, LinkList L);		//返回表中指定元素前驱位置
void Insert(ElementType X, Position P, LinkList L);		//向表中指定位置后插入元素
void Delete(ElementType X, LinkList L);					//删除表中指定元素
Position Advance(Position P, LinkList L);				//返回表中指定位置的后继位置
Position First(LinkList L);								//返回表中第一个元素

#endif 