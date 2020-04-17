#include<stdio.h>
#include<pthread.h>
int global[2];

void *mul_thread(void *arg)
{
    int *args_array;
    args_array = arg;

    int n1,n2,mul;
    n1=args_array[0];
    n2=args_array[1];
    mul = n1*n2;

    printf("Multiplication = %d\n",mul);

    return NULL;
}

int main() 
{
    printf("First number: ");
    scanf("%d",&global[0]);

    printf("Second number: ");
    scanf("%d",&global[1]);

    pthread_t tid_mul;
    pthread_create(&tid_mul,NULL,mul_thread,global);
    pthread_join(tid_mul,NULL);

    return 0;
}
