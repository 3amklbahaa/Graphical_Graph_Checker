#include <stdio.h>
#define N 50
int inputgraph(int t[N][N], int n){
    int i, j, start=0, end=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            t[i][j]=0;
        }
    }
    while(start!=-1){
        printf("plz enter startpoint and endpoint(-1 for stoping): ");
        scanf("%d%d",&start,&end);
        t[start][end]=1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",t[i][j]);
        }
        printf("\n");
    }
}
void printdegree(int t[N][N], int n, int z[N]){
    int i,j, sum=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(t[i][j]==1){
                sum ++;
            }
        }
        if(sum>0){
            printf("deg(%d)= %d\n",i,sum);
            z[i]=sum;
            sum = 0;
        }
    }
}
int isgraphical(int t[N][N],int n, int z[N]){
    int i, j=1, res=0, sum=0;
    for(i=0;i<n;i++){
        if(z[i]>0){
            sum=z[i];
            z[i]=0;
            z[i+j]--;
            j++;
            sum --;
        }
    }
    for(i=0;i<n;i++){
        res = res + z[i];
    }
    if(res!=0){
        printf("not graphical");
    }
    else{
        printf("graphical");
    }
}
int main(){
    int n=4, t[N][N], z[N];
    inputgraph(t,n);
    printdegree(t,n,z);
    isgraphical(t,n,z);
    return 0;
}
