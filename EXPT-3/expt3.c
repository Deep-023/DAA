#include<stdio.h>
#include<stdlib.h>

void strassenmul(int a[2][2],int b[2][2]){
    int s[10],p[7],c[2][2];

    s[0]= b[0][1]-b[1][1];
    s[1]= a[0][0]+a[0][1];
    s[2]= a[1][0]+a[1][1];
    s[3]= b[1][0]-b[0][0];
    s[4]= a[0][0]+a[1][1];
    s[5]= b[0][0]+b[1][1];
    s[6]= a[0][1]-a[1][1];
    s[7]= b[1][0]+b[1][1];
    s[8]= a[0][0]-a[1][0];
    s[9]= b[0][0]+b[0][1];

    p[0]= a[0][0]*s[0];
    p[1]= s[1]*b[1][1];
    p[2]= s[2]*b[0][0];
    p[3]= a[1][1]*s[3];
    p[4]= s[4]*s[5];
    p[5]= s[6]*s[7];
    p[6]= s[8]*s[9];

    c[0][0]= p[4]+p[3]-p[1]+p[5];
    c[0][1]= p[0]+p[1];
    c[1][0]= p[2]+p[3];
    c[1][1]= p[4]+p[0]-p[2]-p[6];

    printf("\nThe Resultant Matrix is :\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int arr[2][2], arr2[2][2];
    printf("\nEnter the 1st 2x2 matrix for Multiplication: ");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Enter the 1st 2x2 matrix for Multiplication: ");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("\nThe Entered 1st Matrix is :\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("The Entered 1st Matrix is :\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }
    strassenmul(arr,arr2);
}