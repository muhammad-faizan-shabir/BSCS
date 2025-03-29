#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include<sys/stat.h>
#include <ctype.h>
#include <pthread.h>
#include<semaphore.h>
#include <time.h>
#define MIN 100 // lower bound for random values
#define MAX 999 // upper cound for random values

int totalPrimes=0; // global variable to store no of primes
int maxValue; // global variable to store max value
int maxValueinitialised=0; // value to know whether maxValue is initialised or not
pthread_mutex_t mutexPrime; // mutex for mutual exclusion of totalPrimes
pthread_mutex_t mutexMaxVal; // mutex for mutual exclusion of maxValue

typedef struct // struct to pass arguments to threads
{
    int * arr;
    int size;
} arrayMetadata;

int isPrime(int num) // function to check if a number is prime or not
{
    if(num<=0)
    {
        return 0;
    }

    for(int i=2;i<num;i++)
    {
        if(num%i==0)
        {
            return 0;
        }
    }

    return 1;
}

void * worker(void * arg) // thread function
{
    arrayMetadata * obj= (arrayMetadata*)arg;
    int localTotalPrimes=0;
    int localMaxValue=obj->arr[0];
    
    for(int i=0;i<obj->size;i++) // iterates over the whole row
    {
        if(obj->arr[i]>localMaxValue) // update local max value
        {
            localMaxValue=obj->arr[i];
        }
            
        if(isPrime(obj->arr[i])==1) // update local no of primes
        {
            localTotalPrimes=localTotalPrimes+1;
        }
    }
        
    pthread_mutex_lock(&mutexPrime);
    totalPrimes=totalPrimes+localTotalPrimes; // update global variable of total primes
    pthread_mutex_unlock(&mutexPrime);
        
    pthread_mutex_lock(&mutexMaxVal);
    if(maxValueinitialised==0) // if global maxVlaue is uninitialised then initilise it
    {
        maxValueinitialised=1;
        maxValue=localMaxValue;
    } 
    else // if global maxVlaue is initialised then update it
    {
        if(localMaxValue>maxValue)
        {
            maxValue=localMaxValue;
        }
    }
    pthread_mutex_unlock(&mutexMaxVal);
}

int main()
{
    // initialise mutexes
    pthread_mutex_init(&mutexPrime, NULL);
    pthread_mutex_init(&mutexMaxVal, NULL);

    // get values of m and n from user
    int m;
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    while(m<=0)
    {
        printf("Please enter valid number of rows: ");
        scanf("%d", &m);
    }
    printf("Enter number of colums: ");
    scanf("%d", &n);
    while(n<=0)
    {
        printf("Please enter valid number of columns: ");
        scanf("%d", &n);
    }

    srand((unsigned int)time(NULL));
    printf("The 2D array with random values:\n");
    // Dynamic allocation of memory for the 2D array
    int **array = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) 
    {
        array[i] = (int *)malloc(n * sizeof(int));
        for (int j=0;j<n;j++)
        {
            array[i][j]=rand() % (MAX - MIN + 1) + MIN;
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    
    // dynamic allocation of thread IDs and argument objects
    pthread_t * threadIds = (pthread_t *)malloc(m * sizeof(pthread_t));
    arrayMetadata * arguments = (arrayMetadata*)malloc(m * sizeof(arrayMetadata));
    for(int i=0;i<m;i++) // create thread for each row
    {
        arguments[i].arr=array[i];
        arguments[i].size=n;
        pthread_create(&threadIds[i],NULL,worker,(void*)&arguments[i]);
    }
    for(int i=0;i<m;i++) // join all threads
    {
        pthread_join(threadIds[i],NULL);
    }
 
    // print the final results
    printf("\n");
    printf("Total Number of Primes: %d\n",totalPrimes);
    printf("The Maximum Value in the matrix: %d\n",maxValue);

    // free all the allocated memory
    free(threadIds);
    free(arguments);
    for (int i = 0; i < m; i++) {
        free(array[i]);
    }
    free(array);
    // destroy the mutexes
    pthread_mutex_destroy(&mutexPrime);
    pthread_mutex_destroy(&mutexMaxVal);

    return 0;
}