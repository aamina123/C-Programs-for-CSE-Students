#include<stdio.h>
#include<stdlib.h>
int main(){
	int i , n , temp , j , c , t , m , count , nt , max , k , len =0;
	float  avgt = 0.0 , avgw = 0.0; 
	printf("Enter no. of Processes = ");
	scanf("%d",&n);
	int p[n] , at[n] , bt[n] , ct[n] , tat[n] , wt[n] , rt[n] , gt[10] , flag[n] , rq[n] , r[n] , en[n];
	for(i = 0; i < n; i++ )
    {
        p[i] = i+1;
		printf("Enter Arrival time , Burst time  = ");
        scanf("%d %d", &at[i], &bt[i]);
        flag[i] = 0;en[i] = 0;
	} 
	printf("\n    Process |\tArrival |  Burst Time \n");
	for(i = 0 ; i < n ; i++)
		printf("\n\tP[%d]\t  %d\t\t%d\n",p[i],at[i],bt[i]);
	for(i = 0 ; i < n ; i++){
		for(j = i+1 ; j < n; j++){
			if(at[i] > at[j]){
				temp = at[i];
				at[i] = at[j];
				at[j] = temp;
				temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;	
			}
		}
	}
	for(i = 0 ; i < n ; i++){
		 r[i] = bt[i];
	}
	printf("\n    Process |\tArrival |  Burst Time \n");
	for(i = 0 ; i < n ; i++)
		printf("\n\tP[%d]\t  %d\t\t%d\n",p[i],at[i],bt[i]);
	m = r[0]; c = at[0]; count = 0; k = 1 ;j = 0; max = at[n-1];
	if(c !=0){
		gt[j] = -1 ; j++ ;
	}
	while(count < n){
		if(at[k] == at[k-1])
			k++;
		nt = at[k] - at[k-1];
		for(i = 0 ; i < n ; i++){
			if(r[i] == m  && flag[i]==0 && c < max){
				en[i]++;
				if(en[i] == 1)
					rt[i] = c - at[i];
				if(r[i] > nt){
					r[i] = r[i] - nt;
					c = c + nt;
				}
				else if (r[i] <= nt){
					c = c + r[i];ct[i] = c; r[i] = 0;
					flag[i] = 1;
					tat[i] = ct[i] - at[i];	wt[i] = tat[i] - bt[i];
					avgt = avgt + tat[i]; avgw = avgw + wt[i];count++;len--;
				}
				gt[j] = p[i];j++;
				if(k < n)
					k++;
				break;
			}
			else if (r[i] == m && flag[i]==0 && c >= max){
				en[i]++;
				if(en[i] == 1)
					rt[i] = c - at[i];
				c = c + r[i];ct[i] = c;
				flag[i] = 1;
				tat[i] = ct[i] - at[i];	wt[i] = tat[i] - bt[i];
				avgt = avgt + tat[i]; avgw = avgw + wt[i];count++;len--;
				gt[j] = p[i];j++; 	
				break;			
			}
		}
		if(c < at[i+1] && len==0){
			c = at[k-1];
			gt[j] = -1;j++;
		}
		t = 0 ;len = 0;
		for(i=0; i< n ; i++){
			if(at[i] <= c && flag[i]==0){
				rq[t] = r[i]; t++;len++; 
			}
		}
		m = rq[0];
		for(i = 0 ; i < t; i++){
			if (m > rq[i])
				m = rq[i];
		}	
	}
	printf("  Process |  Arrival  |  Burst   |  Completion  |  TurnAround  |  Waiting  |  Response\n");
    for(i=0;i<n;i++){
       printf("\n    p[%d]        %d          %d         %d\t\t  %d\t\t%d\t\t%d\n",p[i] , at[i] , bt[i] , ct[i] , tat[i] , wt[i] , rt[i]	);
 
    }
    printf("\t---------------Grantt Chart -----------------------\n|");
    for(i = 0 ; i < j ; i++){
		if (gt[i] == -1)
			printf("\tidle |");
		else
			printf("\tP[%d]  |",gt[i]);
    }
    printf("\n\tAverage Turnaround time = %f\n\tAverage Waiting time = %f", avgt/n , avgw/n);
}
