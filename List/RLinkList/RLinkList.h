#ifndef RLINKLIST_H
#define RLINKLIST_H

typedef int ElementType;
typedef struct Node *RLinkList;
typedef RLinkList Position;

void NullAndExit(RLinkList L);				//����ָ��Ϊ��ʱ�쳣�˳�
void PositionInvalid(Position P);			//����λ����Чʱ�쳣�˳�
int IsLast(Position P, RLinkList L);			//�жϵ�ǰλ���Ƿ�Ϊ��β
int IsEmpty(RLinkList L);				//�жϱ��Ƿ�Ϊ��
RLinkList CreateList();					//�����ձ�
void MakeEmpty(RLinkList L);				//��ձ�
void DeleteList(RLinkList L);				//ɾ����
ElementType Retrieve(Position P, RLinkList L);		//���ر���ָ��λ��Ԫ��
Position Find(ElementType X, RLinkList L);		//���ر���ָ��Ԫ������λ��
Position FindPrevious(ElementType X, RLinkList L);	//���ر���ָ��Ԫ��ǰ��λ��
void Insert(ElementType X, Position P, RLinkList L);	//�����ָ��λ�ú����Ԫ��
void Delete(ElementType X, RLinkList L);			//ɾ������ָ��Ԫ��
Position Advance(Position P, RLinkList L);		//���ر���ָ��λ�õĺ��λ��
Position First(RLinkList L);				//���ر��е�һ��Ԫ��

#endif 