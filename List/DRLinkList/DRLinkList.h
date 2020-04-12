#ifndef DRLINKLIST_H
#define DRLINKLIST_H

typedef int ElementType;
typedef struct Node *DRLinkList;
typedef DRLinkList Position;

void NullAndExit(DRLinkList L);								//����ָ��Ϊ��ʱ�쳣�˳�
void PositionInvalid(Position P);							//����λ����Чʱ�쳣�˳�
int IsLast(Position P, DRLinkList L);						//�жϵ�ǰλ���Ƿ�Ϊ��β
int IsEmpty(DRLinkList L);									//�жϱ��Ƿ�Ϊ��
DRLinkList CreateList();									//�����ձ�
void MakeEmpty(DRLinkList L);								//��ձ�
void DeleteList(DRLinkList L);								//ɾ����
ElementType Retrieve(Position P, DRLinkList L);				//���ر���ָ��λ��Ԫ��
Position FindForward(ElementType X, DRLinkList L);			//ǰ����ұ���ָ��Ԫ��λ��
Position FindBackward(ElementType X, DRLinkList L);			//������ұ���ָ��Ԫ��λ��
void Insert(ElementType X, Position P, DRLinkList L);		//�����ָ��λ�ú����Ԫ��
void Delete(ElementType X, DRLinkList L);					//ɾ������ָ��Ԫ��
Position Advance(Position P, DRLinkList L);					//���ر���ָ��λ�õĺ��λ��
Position First(DRLinkList L);								//���ر��е�һ��Ԫ��

#endif 