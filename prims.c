#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define INF 99999
int vis[MAX]={0},selected[MAX]={0};
int n,i,j,G[MAX][MAX]={0},v1,v2,wt,s;
void prim();
void main()
{
     
     printf("\nHOW MANY VERTICES IN A GRAPH : ");
     scanf("%d",&n);
     while (1)
     {
         printf("\nENTER AN EDGE FROM VERTEX V1 TO VERTEX V2,ENTER (0,0) FOR EXIT : ");
         scanf("%d%d",&v1,&v2);
         if (v1<0 || v2<0 || v1>n || v2>n)
         {
            printf("\nPLZ ENTER VALID EDGE : ");
            i--;
         }
         if (v1==0 && v2==0)
            break;
         printf("\nENTER WEIGHT BET %d and %d : ",v1,v2);
         scanf("%d",&wt);
         G[v1-1][v2-1]=wt;
         G[v2-1][v1-1]=wt;
     }
     printf("\nADJACENCY MATRIX OF A GRAPH : \n");
     printf("\n ");
     for (i=0;i<n;i++)
         printf("%4d",i+1);
     printf("\n");
     for (i=0;i<n;i++)
     {    
          printf("\n%d",i+1);
          for (j=0;j<n;j++)   
              printf("%4d",G[i][j]);   
          printf("\n");
     }
     printf("\nEnter Start Vertex : ");
     scanf("%d",&s);
     prim();
}

void prim()
{
	 int no_edge=0,min,x,y,sum=0;
	 selected[s-1]=1;
	 printf("\nEdge  :  Weight\n");
	 while (no_edge < n-1)
	 {
	       min=INF;
	       x=y=0;
	       for (i=0;i<n;i++)
	           if (selected[i])
	              for (j=0;j < n;j++)
	                  if (!selected[j] && G[i][j])
	                      if (min > G[i][j])
	                      {
	                         min=G[i][j];
	                         x=i;
	                         y=j;
	                      }
	      printf("%d  -  %d  :  %d\n",x+1,y+1,G[x][y]);
	      sum=sum+min;
	      
	      selected[y]=1;
	      no_edge++;
	 }
	 printf("\nMinimum Cost of Spanning Tree : %d \n",sum);
}
