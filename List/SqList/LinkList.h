#ifndef LINKLIST_H
#define LINKLIST_H

typedef int ElementType;
typedef struct Node *LinkList;
typedef LinkList Position;

void NullAndExit(LinkList L);							//����ָ��Ϊ��ʱ�쳣�˳�
void PositionInvalid(Position P);						//����λ����Чʱ�쳣�˳�
int IsLast(Position P, LinkList L);						//�жϵ�ǰλ���Ƿ�Ϊ��β
int IsEmpty(LinkList L);								//�жϱ��Ƿ�Ϊ��
LinkList CreateList();									//�����ձ�
void MakeEmpty(LinkList L);								//��ձ�
void DeleteList(LinkList L);							//ɾ����
ElementType Retrieve(Position P, LinkList L);			//���ر���ָ��λ��Ԫ��
Position Find(ElementType X, LinkList L);				//���ر���ָ��Ԫ������λ��
Position FindPrevious(ElementType X, LinkList L);		//���ر���ָ��Ԫ��ǰ��λ��
void Insert(ElementType X, Position P, LinkList L);		//�����ָ��λ�ú����Ԫ��
void Delete(ElementType X, LinkList L);					//ɾ������ָ��Ԫ��
Position Advance(Position P, LinkList L);				//���ر���ָ��λ�õĺ��λ��
Position First(LinkList L);								//���ر��е�һ��Ԫ��

#endif 