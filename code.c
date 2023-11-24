//3mklbahaa
#include <stdio.h>
#define N 50
void inputgraph(int t[N][N], int n, int n_edges){
    int i, j, start=0, end=0;
    printf("plz enter the n_edges: ");
    scanf("%d",&n_edges);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            t[i][j]=0;
        }
    }
    for(i=0;i<n_edges;i++){
        printf("plz enter startpoint and endpoint: ");
        scanf("%d%d",&start,&end);
        t[start][end]=1;
        t[end][start]=1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",t[i][j]);
        }
        printf("\n");
    }
}
void printdegree(int t[N][N], int n, int n_edges, int z[N]){
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
void isgraphical(int t[N][N],int n, int n_edges, int z[N]){
    int i, j=1, res=0, sum=0;
    for(i=0;i<n;i++){
        if(z[i]>0){
            sum=z[i];
            z[i]=0;

            while(j<=sum){
                z[i+j]--;
                j++;
            }
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
    int n, t[N][N], z[N], n_edges;
    printf("plz enter n: ");
    scanf("%d",&n);
    inputgraph(t,n, n_edges);
    printdegree(t,n,n_edges,z);
    isgraphical(t,n,n_edges,z);
    return 0;
}
