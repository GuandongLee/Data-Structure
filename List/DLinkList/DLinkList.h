#ifndef DLINKLIST_H
#define DLINKLIST_H

typedef int ElementType;
typedef struct Node *DLinkList;
typedef DLinkList Position;

void NullAndExit(DLinkList L);									//����ָ��Ϊ��ʱ�쳣�˳�
void PositionInvalid(Position P);								//����λ����Чʱ�쳣�˳�
int IsLast(Position P, DLinkList L);							//�жϵ�ǰλ���Ƿ�Ϊ��β
int IsEmpty(DLinkList L);										//�жϱ��Ƿ�Ϊ��
DLinkList CreateList();											//�����ձ�
void MakeEmpty(DLinkList L);									//��ձ�
void DeleteList(DLinkList L);									//ɾ����
ElementType Retrieve(Position P, DLinkList L);					//���ر���ָ��λ��Ԫ��
Position Find(ElementType X, DLinkList L);						//���ر���ָ��Ԫ������λ��
Position FindForward(ElementType X, Position P, DLinkList L);	//��ĳ��λ�ÿ�ʼǰ�����
Position FindBackward(ElementType X, Position P, DLinkList L);	//��ĳ��λ�ÿ�ʼ�������
void Insert(ElementType X, Position P, DLinkList L);			//�����ָ��λ�ú����Ԫ��
void Delete(ElementType X, DLinkList L);						//ɾ������ָ��Ԫ��
Position Advance(Position P, DLinkList L);						//���ر���ָ��λ�õĺ��λ��
Position First(DLinkList L);									//���ر�ͷ��һ��Ԫ��

#endif 