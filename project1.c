#include<stdio.h>
#include<stdlib.h>
int p=1;
struct user
{
	char name[20];
	char age[10];
	char place[20];
	int friends;
	int usernumber;
	
};

struct node {
	struct user data;
	struct node* link;
};

struct node* root=NULL; 

void append()																	//NEW USER ADD
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter User name:");
	scanf("%s",&temp->data.name);
	printf("enter User age:");
	scanf("%s",&temp->data.age);
	printf("enter User place:");
	scanf("%s",&temp->data.place);
	temp->data.friends=0;
	temp->data.usernumber=p;
	p=p+1;
	temp->link=NULL;
	if(root==NULL){
		root=temp;
	}
	else{
		struct node* p=root;
		while(p->link!=NULL){
			p=p->link;
		}
		p->link=temp;
		
	}
}
void display(int x)																			//DISPLAY
{
	int i;
struct node* temp=root;
if(temp==NULL)
		{
		printf("\n There are no users signed up yet\n");
		}
else
		{
			for(i=0;i<x-1;i++){
									printf("Name : %s\n",temp->data.name);
									printf("Age : %s\n",temp->data.age);
									printf("Place : %s\n",temp->data.place);
									printf("Number of Friends : %d\n",temp->data.friends);
									printf("**USER_NUMBER(ref): %d\n",temp->data.usernumber);
									printf("\n\n\n\n");
									temp=temp->link;	
							}	
		}
}

void presentusers()																//PRESENT USERS
{
	int i;
struct node* temp=root;
if(temp==NULL)
		{
		printf("\n There are no users signed up yet\n");
		}
else
		{	
			printf("\n=========================================================\n");
			for(i=0;i<p-1;i++){
									printf("Name : %s\n",temp->data.name);
									printf("Age : %s\n",temp->data.age);
									printf("Place : %s\n",temp->data.place);
									printf("Number of Friends : %d\n",temp->data.friends);
									printf("USER_NUMBER(ref): %d\n",temp->data.usernumber);
									printf("\n\n\n\n");
									temp=temp->link;	
							}	
							printf("\n=========================================================\n");
		}
}

void userinfo(int x)																//USER INFO		
{
		int i;
	struct node* temp=root;
	if(temp==NULL)
		{
		printf("\n There are no users signed up yet\n");
		}
else
		{
			printf("\n********************************************************\n");
			for(i=0;i<x-1;i++){
								
									temp=temp->link;	
							}	
								printf("Name : %s\n",temp->data.name);
									printf("Age : %s\n",temp->data.age);
									printf("Place : %s\n",temp->data.place);
									printf("Number of Friends : %d\n",temp->data.friends);
									printf("USER_NUMBER(ref): %d\n",temp->data.usernumber);
									printf("\n\n\n\n");
									printf("\n********************************************************\n");
		}
}

int totalusers()
{
	int total;
	struct node* temp=root;
	while(temp!=NULL)
	{	
		total=total+1;
		temp=temp->link;
	}
	return total;
}
void friendsadd(int x)															
{
		int i;
	struct node* temp=root;
	if(temp==NULL)
		{
		printf("\n There are no users signed up yet\n");
		}
else
		{
			
			for(i=0;i<x-1;i++){
								
									temp=temp->link;	
							}	temp->data.friends++;
								printf("Name : %s\n",temp->data.name);
									printf("Age : %s\n",temp->data.age);
									printf("Place : %s\n",temp->data.place);
									printf("Number of Friends : %d\n",temp->data.friends);
									printf("USER_NUMBER(ref): %d\n",temp->data.usernumber);
									printf("\n\n\n\n");
									
		}
}

//===========================================================================

struct AdjListNode 
{ 
    int dest; 
    struct AdjListNode* next; 
}; 

struct AdjList 
{ 
    struct AdjListNode *head;  
};

struct Graph 
{ 
    int V; 
    struct AdjList* array; 
};
struct AdjListNode* newAdjListNode(int dest) 
{ 
    struct AdjListNode* newNode = 
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
}

struct Graph* createGraph(int V) 
{ 
    struct Graph* graph =  
        (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
    graph->array =(struct AdjList*) malloc(V * sizeof(struct AdjList)); 
    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 

void addEdge(struct Graph* graph, int src, int dest) 
{ 
 
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 

    newNode = newAdjListNode(src); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
}

void printGraph(struct Graph* graph) 
{ 
    int v; 

    for (v = 1; v < totalusers()+1; ++v) 
    { 
        struct AdjListNode* pCrawl = graph->array[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
}


void printuserfrnds(struct Graph* graph,int z) 
{ 
    int v; 
    for (v = 1; v <z+1 ; ++v) 
    { 
    	
        struct AdjListNode* pCrawl = graph->array[v].head; 
         if(v==z-1){
         	printf("\n Adjacency list of vertex %d\n head ", v);
		 } 
        while (pCrawl) 
        { 
            if(v==z-1){
			
			printf("-> %d", pCrawl->dest);
			printf("ok"); }
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
}
//=====================================================================//   common friends 
int *commonhelp(struct Graph* graph,int *a,int z)
{	 
	int v; 
	int i=0;
    for (v = 1; v <z+1 ; ++v) 
    { 
    	
        struct AdjListNode* pCrawl = graph->array[v].head; 
        while (pCrawl) 
        { 
            if(v==z-1)
			{
				a[i]=pCrawl->dest;
				i=i+1;
		
			}
            pCrawl = pCrawl->next; 
        } 
       
    }
	return a; 
}


int printCommon(int arr1[], int len1, int arr2[],int len2) 
{
	printf("\n********************************************************\n\n");
	printf("COMMON FRIENDS ARE:  ");
int i,j;
for(i = 0; i < len1 ;i++) 
	{
for(j = 0; j < len2 ;j++) 
			{
				if(arr1[i] == arr2[j])
				{
				printf("%d  ", arr1[i]);
			}
			}
	}
	printf("\n********************************************************\n\n\n"); 
}
int getsize(int x)																//to get no.of friends		
{
		int i;
	struct node* temp=root;
	if(temp==NULL)
		{
		printf("\n There are no users signed up yet\n");
		return 0;
		}
else
		{
		
			for(i=0;i<x-1;i++){
								
									temp=temp->link;	
							}	
						
																	
		return temp->data.friends;							
		}
}
//===========================================================================
void delete()
{
	int loc,len=length();
	struct node* temp;
	printf("\nenter the Reference_Number of the USER:");
	scanf("%d",&loc);
	if(loc>len)
		{
			printf("INVALID");
			exit(0);
		}
	else if(loc==1)
		{
			temp=root;
			root=temp->link;
			temp->link=NULL;
			free(temp);
		}
	else
		{
			struct node* p=root;
			struct node* q;
			int i=1;
			while(i<(loc-1))
				{
					p=p->link;
					i++;
				}
			q=p->link;
			p->link=q->link;
			q->link=NULL;
			free(q);
			
		}
		p=p-1;
}
int length()
	{
		int count=0;
		struct node* temp=root;
		if(temp==NULL)
			{
				return 0;
			}
		else
			{
				while(temp!=0)
					{
						count++;
						temp=temp->link;
					}
			return count;
			}
	}

void main()
{	
	int opt,ref,x;
	x=1;
	printf("WEB APP\n");
	int V =1000;
	struct Graph* graph = createGraph(V);
	while(x==1){
	printf("\n1.Present users\n2.Add user\n3.User info\n4.User friends\n5.Make friends for USER\n6.DELETE A USER\n7.Total_USERS\n8.All USERS and Their friends\n9.Common friends between two\n10.quit\nOpt your choice:-");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:{
					presentusers();
					break;
			};
		case 2:	{
					append();
					break;
				};
		case 3:{
				printf("Kindly Enter the USER_REFERENCE_NUMBER:-");	
				scanf("%d",&ref);
				userinfo(ref);
				break;
			};
		case 4:{
				int ad;
			 
				if(V!=0){
				
    				
					printf("Kindly Enter the USER_REFERENCE_NUMBER:-");	
					scanf("%d",&ref);
					ad=ref+1;
					printuserfrnds(graph,ad);
					}
					else{
						printf("\nThere are no users yet\n");
					}
				
			break;
		};
		
		case 5:{
				int fir,sec;
				int V = totalusers();
				if(V!=0){
				
							
							printf("\nFrom which user to which user you are making a friendship bond(ref_nums):-");
							scanf("%d %d",&fir,&sec);
							addEdge(graph, fir, sec);
							friendsadd(fir);
							friendsadd(sec);
					}
				else{
						printf("\nThere are no users yet\n");
					}
			break;
		};
		
		case 6:{
			delete();
			break;
		};
		
		case 7:{
			int ttl;
			ttl=totalusers();
			printf("\nTotal users are: %d\n",ttl);
			break;
		};
		
		case 8:{
			
				if(V!=0){
					
					printGraph(graph);
					
				}
				else{
						printf("\nThere are no users yet\n");
					}
			break;
		};
		
		case 9:
							{		int cd;
									int gg,ab,nf1,nf2;
									printf("\nEnter the reference numbers of the two users :");
									scanf("%d %d",&gg,&ab);
									nf1=getsize(gg);
									nf2=getsize(ab);
									int *u;
									int *h;
									int one[nf1],two[nf2];
									u=commonhelp(graph,one,gg+1);
									h=commonhelp(graph,two,ab+1);
									for(cd=0;cd<nf1;cd++)
									{
										one[cd]=u[cd];
									}
									for(cd=0;cd<nf2;cd++)
									{
										two[cd]=h[cd];
									}
									printCommon(one,nf1,two,nf2);
									break;
							};
		
		case 10:{
			x=0;
			break;
		}
		
		default:{
			printf("\n_________________________invalid________________________\n");
			
			break;
		}	
				
		
		
		
		
	}
	}
	
	printf("\n\n______________________________BY GALI RAVI PRAVEEN\n");


}
