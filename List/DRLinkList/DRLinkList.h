#ifndef DRLINKLIST_H
#define DRLINKLIST_H

typedef int ElementType;
typedef struct Node *DRLinkList;
typedef DRLinkList Position;

void NullAndExit(DRLinkList L);								//操作指针为空时异常退出
void PositionInvalid(Position P);							//输入位置无效时异常退出
int IsLast(Position P, DRLinkList L);						//判断当前位置是否为表尾
int IsEmpty(DRLinkList L);									//判断表是否为空
DRLinkList CreateList();									//创建空表
void MakeEmpty(DRLinkList L);								//清空表
void DeleteList(DRLinkList L);								//删除表
ElementType Retrieve(Position P, DRLinkList L);				//返回表中指定位置元素
Position FindForward(ElementType X, DRLinkList L);			//前向查找表中指定元素位置
Position FindBackward(ElementType X, DRLinkList L);			//后向查找表中指定元素位置
void Insert(ElementType X, Position P, DRLinkList L);		//向表中指定位置后插入元素
void Delete(ElementType X, DRLinkList L);					//删除表中指定元素
Position Advance(Position P, DRLinkList L);					//返回表中指定位置的后继位置
Position First(DRLinkList L);								//返回表中第一个元素

#endif 