#include<stdio.h>
typedef struct link
{
	int address;
	int data;
	int nextaddr;
	struct link *next;//指向下个节点的指针
} Link;
int i=1;
int data[100004];
int next[100004];
int temp;
int num=0;
Link a[100004];

//创建链表
void create(Link *head)
{
	i = 1;
	while (1)
	{
		if (a[i-1].nextaddr == -1)
		{
			a[i-1].next = NULL;
			num = i-1;
			break;
		}

		a[i].address = a[i-1].nextaddr;
		a[i].data = data[a[i].address];
		a[i].nextaddr = next[a[i].address];
		a[i-1].next = a+i;
		i++;
	}
}

//链表反转
Link *listReverse(Link *head, int k)
{
	int count=1;
	Link *s=head->next;
	Link *old=s->next;
	Link *temp=NULL;

	while(count<k)
	{
		temp=old->next;
		old->next=s;
		old->nextaddr=s->address;
		s=old;  //s向后走一个节点
		old=temp;  //temp向后走一个节点
		count++;
	}

	//使反转后的最后一个节点指向下一段子链表的第一个节点
	head->next->next=old;

	if(old!=NULL)
	{
		head->next->nextaddr=old->address;	//修改next值，使它指向下一个节点的位置
	}
	else
	{
		//如果old为NULL,即没有下一个子链表，那么反转后的最后一个节点即是真个链表的最后一个节点
		head->next->nextaddr=-1;
	}
	return s;
}
int main()
{
	int firstaddr;
	int n=0,k=0;
	Link *head;
	scanf("%d%d%d",&firstaddr,&n,&k);
	a[0].nextaddr=firstaddr;
	for(; i<n+1; i++)
	{
		scanf("%d",&temp);
		scanf("%d %d",&data[temp],&next[temp]);
	}
	create(head);

	Link *p=a; //p指向头结点
	Link *q=NULL;//反转链表函数的返回值
	if(k<=num)
	{
		for(i=0; i<(num/k); i++)
		{
			q=listReverse(p,k);
			p->next=q; // 第一次执行，a[0]->next 指向第一段子链表反转的第一个节点
			p->nextaddr=q->address;  // 更改Next值，指向逆转后它的下一个节点的位置

			//使p指向下一段需要反转的子链表的头结点
			int j=0;
			while(j<k)
			{
				p=p->next;
				j++;
			}
		}
	}
	p=a;
	while(p->next!=NULL)
	{
		p=p->next;
		if(p->nextaddr!=-1)
		{
			printf("%05d %d %05d\n",p->address,p->data,p->nextaddr);
		}
		else
		{
			printf("%05d %d -1\n",p->address,p->data);
		}
	}
	return 0;
}


