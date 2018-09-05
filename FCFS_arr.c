#include<stdio.h>
#include<stdlib.h>
struct node {
    int p , atime , btime, ct , wt , tat ;
    struct node *next;
};//Structure declaration
struct node *start = NULL;
int main(){
    printf("Enter number of Processes = ");
    int i , n ,j , temp , c;
    float avgt = 0.0 , avgw = 0.0;
    scanf("%d",&n);//Take range from user
    struct node *ptr , *newnode , *preptr ;//Declaring pointers
    for(i=1;i<=n;i++){
        newnode = malloc((struct node * )sizeof(struct node));//Dynamic memory allocation to store structure data
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
    }// creation of singly linked list which stores Process details
    ptr = start;
    i = 1;
     while(ptr!=NULL){
        ptr->p = i ;
        printf("\nP[%d]\t\t%d\t\t%d ",ptr->p,ptr->atime,ptr->btime);
        ptr = ptr->next;
        i++;
     }//displaying the contents of structure in order-wise
     ptr = start;
    //Sorting the linked list in ascending order of Arrival times using bubble sort
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
     printf("\n\t\t----------Grantt Chart------------\n\n");
     while(ptr!=NULL){
        printf("\t\tP[%d]",ptr->p);
        ptr = ptr->next;
     }//displaying the grantt chart
     ptr = start;
     c = ptr->atime ;
     while(ptr!=NULL){
        ptr->ct = c + ptr->btime;//completion time of process
        c = ptr->ct;
        ptr->tat = ptr->ct - ptr->atime;// Turnaround time of process
        ptr->wt = ptr->tat - ptr->btime;//Waiting time of process
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
    }//displaying final process table
     ptr = start;
    while(ptr != NULL){
        avgt = avgt + ptr->tat;
        avgw = avgw + ptr->wt;
        ptr = ptr->next;
    }//finding Average Turnaround time and waiting time
    printf("\n\t\tAvg Turnaround\t\tAvg Waiting\n");
    printf("\t\t\t%f\t\t%f",avgt/n,avgw/n);
}
