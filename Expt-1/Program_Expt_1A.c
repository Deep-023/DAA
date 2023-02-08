#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(){
    printf("\n");
    for(int n=1;n<=100;n++){     
    printf("%d\n",(int)pow(n,3));
    }
    printf("\n");
    for(int n=1;n<=100;n++){     
    printf("%.2f\n",pow(1.5,n));
    }
    printf("\n");
    for(int n=1;n<=100;n++){     
    printf("%.2f\n",log2(n));
    }
    printf("\n");
    for(int n=1;n<=100;n++){     
    printf("%d\n",n);
    }
    printf("\n");
    for(int n=1;n<=100;n++){     
    printf("%.2f\n",pow(2,n));
    }
    printf("\n");
    for(int n=1;n<=100;n++){     
    printf("%.2f\n",(n*log2(n)));
    }
    printf("\n");
    for(int n=1;n<=100;n++){     
    printf("%.2f\n",log2(log2(n)));
    }
    printf("\n");
    for(int n=1;n<=100;n++){     
    printf("%.2f\n",sqrt(log(n)));
    }
    printf("\n");
    for(int n=1;n<=100;n++){     
    printf("%.2f\n",pow(2,log2(n)));
    }
    printf("\n");
    for(int n=1;n<=100;n++){     
    printf("%.2f\n",log(n) );
    }
    printf("\n");
}