#include<stdio.h>
//burst time waiting time turn around time 
void waiting_time(int process[],int bt[],int wt[],int n){
    wt[0]=0 ;
    for(int i=1;i<n;i++){
        wt[i]= wt[i-1] + bt[i-1] ;
    }
}

void turnaround_time(int process[],int bt[],int wt[],int tat[],int n){
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i] ;
    }
}
int avg_time(int arr[],int n){
    int sum=0 ;
    for(int i=0;i<n;i++){
        sum+=arr[i] ;
    }
    int avg = sum / n ;
    return avg ;
}
void main(){
    int process[]={1,2,3} ;
    int n=sizeof(process)/sizeof(process[0]) ;
    int burst_time[]={10,5,1} ;
    int waitingtime[n] ;
    int turnaroundtime[n] ;
    //sorting to ensure smallest burst time first
    for(int i=0;i<n;i++)
    {
        int pos=i;
        for (int j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
  
        int temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
  
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
    waiting_time(process,burst_time,waitingtime,n) ;
    turnaround_time(process,burst_time,waitingtime,turnaroundtime,n) ;
    float avg_wt,avg_tat ;
    avg_wt = avg_time(waitingtime,n) ;
    avg_tat=avg_time(turnaroundtime,n) ;
    printf("Burst Time   Waiting Time   Turn Around  \n") ;
    for(int i=0;i<n;i++){
        printf("%d %d %d \n",burst_time[i],waitingtime[i],turnaroundtime[i]);
    }
    printf("The average waiting time is = %f \n",avg_wt) ;
    printf("The average turn around time is = %f",avg_tat) ;
}