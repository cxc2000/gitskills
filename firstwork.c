#include <stdio.h>
#include <string.h>
#define N 10
struct Electric
{
	char name[N];
	char brand[N];
	double price;//
	int num;
	struct Electric *next;
}
typedef Electric *elepointer;
Elepointer Read_list()//���ļ��������� 
{
	FILE *f;
	Element p,s;
	if((f == fopen("list.txt","rb")) == NULL)
	{
		printf("Fail\n");
		exit(0);
	}
	
} 
void Begin_list(elepointer l)//��ʼӪҵ 
{
	int inum,i,j,k;
	elepointer p,s;
	float f;
	printf("How many datas do you want to input?\n");
	scanf("%d",&inum);
	printf("input your datas:\n");
	p = l;
	for(i=0;i<inum;i++)//�����ݴ�������s�� 
	{
		s = (elepointer *)malloc( sizeof(Electric));
		printf("input the No.%d name:\n");
		scanf("%s",&s->name); 
		for(j = strlen(s->name)+2;j<N;j++)
		{
			s->name[j]= " ";
		}
		printf("input the No.%d brand:\n");
		scanf("%s",&s->brand); 
		for(j = strlen(s->brand)+1;j<N;j++)
		{
			s->brand[j]= " ";
		}
		printf("input the No.%d price:\n");
		scanf("%f",&s->price); 
		printf("input the No.%d num:\n");
		scanf("%d",&s->num); 
		p->next = s;//
		p = p->next;
	}
}
void Wtofile(elepointer l)//������l�����ļ��� 
{
	FILE *f;
	elepointer p;
	p = l ->next;
	if((f = fopen("list1.txt","wb")) == NULL)
	{
		printf("Open Fail!\n");
		exit(1);
	}
	while(p!=NULL)
	{
		if(fwrite(p,sizeof(Electric),1,f) != 1) 
		printf("writing error\n");
		p = p->next;
    }
    printf("Saved\n");
    fclose(f);
}
void Push_list(elepointer l)//���� 
{
	int i,j=0,k,pnum;
	printf("Which goods do you want to insert?\n");
	scanf("%d",&pnum);//������������� 
	printf("please input the information of product\n");
	elepointer p,s,q;
	p = l;
	q= l->next; 
	while(q!= NULL)//Ϊʲôq������l 
	{
		q= q->next;
		j++;
	}
	if(pnum<1 || pnum>j)
	{
		printf("error\n");
	}
	else
	{
		for(j=1;j<pnum;j++)//�����ݴ�������s�� 
		{ 
		    p = p->next;
	    }
		s = (elepointer *)malloc( sizeof(Electric));
		printf("input the No.%d name:\n");
		scanf("%s",&s->name); 
		for(j = strlen(s->name)+2;j<N;j++)
		{
			s->name[j]= " ";
		}
		printf("input the No.%d brand:\n");
		scanf("%s",&s->brand); 
		for(j = strlen(s->brand)+1;j<N;j++)
		{
			s->brand[j]= " ";
		}
		printf("input the No.%d price:\n");
		scanf("%f",&s->price); 
		printf("input the No.%d num:\n");
		scanf("%d",&s->num); 
		s ->next = p->next;
		p->next = s;//����S��p��p->next֮�� 
		printf("\n");
	}	
}
void Pop_list(elepointer l)//ȡ�� 
{
	int i,j=0,k,onum;
	printf("Which goods do you want to take?\n");
	scanf("%d",&onum);
	elepointer p,s;
	p = l;
	s= l->next;
	while(p != NULL)
	{
		p = p->next;
		j++;
	}
	if(onum<1 || onum >j)
	{
		printf("error\n");
	}
	else
	{
		for(j=1;j<onum;j++)
		{
			p = p->next; 
		}
		s = p->next;
		p->next = s->next ;
		free(s) ;
	}	 
}
void Search_list()//��ѯ��Ϣ 
{
	int i,j=0,k;
	printf("Which goods do you want to search?\n");
	scanf("%d",&i);
	elepointer p,s;
	p = l;
	s= l->next;
	while( s != NULL)
	{
		s = s->next;
		j++;
	}
	if(i<1 || i>j)
	{
		printf("error\n");
	}
	else
	{
		for(j = 1;j<i;j++)
		{
			p = p->next;
		}
		if(p == NULL)
		{ 
		  printf("error\n");;
		}
		else{
			printf("the name is %s,the brand is %s,the price is %f,the num is %d\n",p->name,p->brand,p->price,p->num);
		}	
	}
}
void Update_list()//������Ϣ 
{
	int j=0,i,k,m=0;
   nodetype *p;
   printf("Which line do you want to updata?\n");
   scanf("%d",&i);
   p=l->next;
   while(p!=NULL)
   {
       p=p->next;
       j++;
    }
   p=l;
   if(i<1||i>j)
      printf("error\n");
   else
      {for (j=1;j<=i;j++)
          p=p->next;
    printf("the No.%d's JDname is:",i);
    scanf("%s",&p->JDname);
    while(p->JDname[m]!='\0')
            m++;
    for(k=m+1;k<=14;k++)
        p->JDname[k]=' ';
    printf("the No.%d's JDbrand is:",i);
    scanf("%s",&p->JDbrand);
        m=0;
    while(p->JDbrand[m]!='\0')
            m++;
    for(k=m+1;k<=14;k++)
        p->JDbrand[k]=' ';
        printf("the No.%d's prize is:",i);
    scanf("%s",&p->prize);
        m=0;
    while(p->prize[m]!='\0')
            m++;
    for(k=m+1;k<=14;k++)
        p->prize[k]=' ';
        printf("the No.%d's amount is:",i);
    scanf("%s",&p->amount);
        m=0;
    while(p->amount[m]!='\0')
            m++;
    for(k=m+1;k<=14;k++)
        p->amount[k]=' ';
       }
}

int Menu(void)
{
	int choice;
	printf("The module of a store\n");
	printf("1.������\n2.Ӫҵ��ʼ\n3.����\n4.���\n");
	printf("5.��ѯ��Ϣ\n6.������Ϣ\n7.Ӫҵ����\n");
	scanf("%d",&choice);
	return choice;
} 
int main()
{
	int choice;
	choice = Menu();
	switch(choice)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
	}
	Elepointer p,L;
	L = new Electric;
	while (p != NULL)
	{
		switch(Compare())//�жϼҵ��Ƿ���� 
		{
			case "": 
		    strcpy(p->name[N],);
			strcpy(p->brand[N],);
			p ->price = price1;
			p ->num = p ->num + num1;
			p = p->next;
		}
			
	}
	int flag_in,flag_out;
	LIST L;//����һ�����Ա� L;
	���ļ�store.txt�ж����������� 
	if(flag_in == 1) 
	{
	  Insert(x,1,L);
	}
	if(flag_in == 1) //���������������Ʒ�����ƺ����� 
	{
	  Delete(x,1,L);
	}
	 
}
