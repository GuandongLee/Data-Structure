#ifndef RLINKLIST_H
#define RLINKLIST_H

typedef int ElementType;
typedef struct Node *RLinkList;
typedef RLinkList Position;

void NullAndExit(RLinkList L);				//操作指针为空时异常退出
void PositionInvalid(Position P);			//输入位置无效时异常退出
int IsLast(Position P, RLinkList L);			//判断当前位置是否为表尾
int IsEmpty(RLinkList L);				//判断表是否为空
RLinkList CreateList();					//创建空表
void MakeEmpty(RLinkList L);				//清空表
void DeleteList(RLinkList L);				//删除表
ElementType Retrieve(Position P, RLinkList L);		//返回表中指定位置元素
Position Find(ElementType X, RLinkList L);		//返回表中指定元素所在位置
Position FindPrevious(ElementType X, RLinkList L);	//返回表中指定元素前驱位置
void Insert(ElementType X, Position P, RLinkList L);	//向表中指定位置后插入元素
void Delete(ElementType X, RLinkList L);			//删除表中指定元素
Position Advance(Position P, RLinkList L);		//返回表中指定位置的后继位置
Position First(RLinkList L);				//返回表中第一个元素

#endif 