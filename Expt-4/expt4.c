#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int** carr, **karr;
void matrixchain( int arr[],int n){
    int tempk;
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j = i+l-1;
            carr[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
               int cal = carr[i][k] + carr[k+1][j] + arr[i-1]*arr[j]*arr[k];
               if(carr[i][j]>cal){
                  carr[i][j]= cal;
                  karr[i][j]= k;
               }
            }
            
        }
    }
    printf("\nThe resultant matrix is: \n");
    for(int i=1;i<n-1;i++){
        for(int j=2;j<n;j++){
            printf("%d\t",carr[i][j]);
        }
        printf("\n");
    } 
    printf("\nResultant k matrix is: \n");
    for(int i=1;i<n-1;i++){
        for(int j=2;j<n;j++){
            printf("%d  ",karr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter the number of matrix: ");
    scanf("%d",&n);
    n=n+1;
    int arr[n];
    printf("Enter the corresponding dimensions of the Matrices: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    carr=(int**)calloc(n,sizeof(int*));
    for(int i=0; i<n; i++){
        carr[i]=(int*)calloc(n,sizeof(int));
    }

    karr=(int**)calloc(n,sizeof(int*));
    for(int i=0; i<n; i++){
        karr[i]=(int*)calloc(n,sizeof(int));
    }

    matrixchain(arr,n);
    printf("\nMinimum number of multiplications is %d",carr[1][n-1]);
}