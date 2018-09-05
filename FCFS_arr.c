#include<stdio.h>
#include<stdlib.h>
struct node {
    int p , atime , btime, ct , wt , tat ;
    struct node *next;
};
struct node *start = NULL;
int main(){
    printf("Enter number of Processes = ");
    int i , n ,j , temp , c;
    float avgt = 0.0 , avgw = 0.0;
    scanf("%d",&n);
    struct node *ptr , *newnode , *preptr ;
    for(i=1;i<=n;i++){
        newnode = malloc((struct node * )sizeof(struct node));
        printf("Process P[%d]",i);
        printf("\nEnter Arrival time = ");
        scanf("%d",&newnode->atime);
        printf("Enter Burst time = ");
        scanf("%d",&newnode->btime);
        newnode->next = NULL;
        if(start == NULL){
            start = newnode;
            ptr = start;
        }
        else {
            ptr->next = newnode;
            ptr = ptr->next;
        }
    }
    ptr = start;
    i = 1;
     while(ptr!=NULL){
        ptr->p = i ;
        printf("\nP[%d]\t\t%d\t\t%d ",ptr->p,ptr->atime,ptr->btime);
        ptr = ptr->next;
        i++;
     }
     ptr = start;
    while(ptr->next!=NULL){
        preptr = ptr->next;
        while(preptr!=NULL){
            if (ptr->atime > preptr->atime){
                temp = ptr->atime;
                ptr->atime = preptr->atime;
                preptr->atime = temp;
                temp = ptr->btime;
                ptr->btime = preptr->btime;
                preptr->btime = temp;
                temp = ptr->p;
                ptr->p = preptr->p;
                preptr->p= temp;
            }
            preptr = preptr ->next;
        }
        ptr = ptr->next;
    }
    ptr = start;
     printf("\n\t\t----------Grant Chart------------\n\n");
     while(ptr!=NULL){
        printf("\t\tP[%d]",ptr->p);
        ptr = ptr->next;
     }
     ptr = start;
     c = ptr->atime ;
     while(ptr!=NULL){
        ptr->ct = c + ptr->btime;
        c = ptr->ct;
        ptr->tat = ptr->ct - ptr->atime;
        ptr->wt = ptr->tat - ptr->btime;
        ptr = ptr->next;
     }
    printf("\n\n\t\tFinal Table of Processes\n");
    for(i=1;i<=n;i++){
        ptr = start;
        while(ptr!=NULL){
            if(ptr->p == i)
                printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d ",ptr->p,ptr->atime,ptr->btime,ptr->ct,ptr->tat,ptr->wt);
            ptr = ptr->next;
        }
    }
     ptr = start;
    while(ptr != NULL){
        avgt = avgt + ptr->tat;
        avgw = avgw + ptr->wt;
        ptr = ptr->next;
    }
    printf("\n\t\tAvg Turnaround\t\tAvg Waiting\n");
    printf("\t\t\t%f\t\t%f",avgt/n,avgw/n);
}
