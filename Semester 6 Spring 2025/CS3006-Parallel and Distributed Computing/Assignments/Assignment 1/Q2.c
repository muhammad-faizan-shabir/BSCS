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
#define MIN 0 // lower bound for random values
#define MAX 1000 // upper cound for random values

typedef struct // struct to pass arguments to threads
{
    int * start;
    int * end;
    int element;
} arrayMetadata;

void * worker(void * arg) // thread function
{
    arrayMetadata * obj= (arrayMetadata*)arg;

    int found =0; // initially found flag is false
    for(int * i=obj->start;i<=obj->end && found==0;i++) // find element in the sub array
    {
        if(*(i)==obj->element)
        {
            found=1;
        }
    }

    pthread_exit((void*)(__intptr_t)found); // return found flag
}

int main()
{
    // get array size from user
    int arraySize;
    printf("Enter size of array(1-50): ");
    scanf("%d", &arraySize);
    while(arraySize<1 || arraySize>50)
    {
        printf("Please enter a valid size for array(1-50): ");
        scanf("%d", &arraySize);
    }
    
    srand((unsigned int)time(NULL));
    printf("The array contains the following random elements: \n");
    // Dynamic allocation of memory for the array
    int * arr = (int *)malloc(arraySize * sizeof(int));
    for(int i=0;i<arraySize;i++)
    {
        arr[i]=rand() % (MAX - MIN + 1) + MIN;
        printf("%d ",arr[i]);
    }
    printf("\n");

    // get element to be found from the user
    int element;
    printf("Enter the element to search for: ");
    scanf("%d", &element);
    
    // get number of threads to be created from the user
    int noOfThreads;
    printf("Enter the number of threads(1-%d): ",arraySize);
    scanf("%d", &noOfThreads);
    while(noOfThreads> arraySize || noOfThreads<1)
    {
        printf("Please enter valid number of threads(1-%d): ",arraySize);
        scanf("%d", &noOfThreads);
    }

    printf("\n");
    printf("Array will be divided into %d equal parts.\n",noOfThreads);
    
    // dynamic allocation of thread IDs and argument objects
    pthread_t * threadIds = (pthread_t *)malloc(noOfThreads * sizeof(pthread_t));
    arrayMetadata * arguments = (arrayMetadata*)malloc(noOfThreads * sizeof(arrayMetadata));

    int completeDivision= arraySize/noOfThreads; //  calculate no of elements in a complete division of the array
    int remainder= arraySize%noOfThreads; // calculate remainder number of elements after complete divisions
    
    for(int i=0;i<noOfThreads-1;i++) // make threads for each complete division of the array except one of the divisions
    {
        arguments[i].start=(arr+i*completeDivision);
        arguments[i].end=(arr+(i+1)*completeDivision-1);
        arguments[i].element=element;
        pthread_create(&threadIds[i],NULL,worker,(void*)&arguments[i]);
    }
    
    // make a thread for one remaining divison plus remainder number of elements
    arguments[noOfThreads-1].start=(arr+(noOfThreads-1)*completeDivision);
    arguments[noOfThreads-1].end=(arr+(noOfThreads)*completeDivision-1+remainder);
    arguments[noOfThreads-1].element=element;
    pthread_create(&threadIds[noOfThreads-1],NULL,worker,(void*)&arguments[noOfThreads-1]);

    for(int i=0;i<noOfThreads;i++) // join all threads
    {
        void* index;
        pthread_join(threadIds[i],&index);
        if((int)(__intptr_t)index==1) // case when element is found in part i of the array
        {
            printf("Part %d: Element %d FOUND!\n",i+1,element);
        }
        else // case when elemnent is not found in part i of the array
        {
            printf("Part %d: Element %d NOT FOUND!\n",i+1,element);
        }
    }

    // free all the allocated memory
    free(arr);
    free(threadIds);
    free(arguments);
    
    return 0;
}