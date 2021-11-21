#include <stdio.h>
#include <limits.h>

/* 
Assuming that the graph will include exactly 10 Node (As instructed). 
this is 2D array that will represent are graph, every cell will represent weight between two nodes.
*/
int myGraph[10][10];
int *pointer;
int max =10000000;

int len(int array[]){
    int ans = (int) (sizeof(array)/sizeof(array[0]));
    return ans;
}

int graphInput(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            myGraph[i][j] = INT_MAX;
        }
    }
    int weight = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            scanf("%d",&weight);
            myGraph[i][j] = weight;
        }
    }
    return 0;
}

int deQueue(int queue[]){
    int i;
    if(queue[9] != -1){
        i = 0;
        while(i < 9){
            queue[i] = queue[i+1];
            i++;
        }
        queue[9]=-1;
    }
    else{
        i = 9;
        while(queue[i] == -1){
            i--;
        }
        int j = 0;
        while(j <= i){
            queue[j] = queue[j+1];
            j++;
        }
        queue[i]=-1;
        return 0;
    }
}
    
int enQueue(int queue[],int num){
    if(queue[0] == -1){
        queue[0] = num;
    }
    else{
        int i=1;
        while(queue[i] != -1){
            i++;
        }
        queue[i] = num;
    }
    return 0;
}

int isPethHelper(int i, int j){
    int queue[10];
    int visit[10];
    for(int i=0; i<10; i++){
        queue[i] = -1;
    }
    for(int i=0; i<10; i++){
        visit[i] = -1;
    }
    if(myGraph[i][j] != 0){
        return 1;
    }
    else{
        queue[0] = i;
        visit[i] = 1;
        int count = 1;
        while(queue[0] != -1){  
            for(int k=0; k<10; k++){
                if(myGraph[queue[0]][k] != 0 && visit[k] == -1 && k != i){
                    enQueue(queue,k);
                }
            }
            visit[queue[0]] = 1;
            deQueue(queue);
        }
        return visit[j];
    }
}

int isPath(int i, int j){
    if(i==j){
        printf("False");
    }
    else{
        int ans = isPethHelper(i,j);
        if(ans == 1){
            printf("True");
        }
        else if(ans == -1){
            printf("False");
        }
    }
    return 0;
}

void fillGraph(){
    for(int i =0; i<10; i++){
        for(int j=0; j<10; j++){
               if(myGraph[i][j] == 0 && i!=j) {
                   myGraph[i][j] = max;
               }
           }
    }
    for(int k=0; k<10; k++){
       for(int i=0; i<10; i++){
           for(int j=0; j<10; j++){
               if(myGraph[i][j] > (myGraph[i][k]+myGraph[k][j]) && myGraph[i][j] != 0 && myGraph[i][k] != 0 && myGraph[k][j] != 0) {
                   myGraph[i][j] = myGraph[i][k]+myGraph[k][j];
               }
           }
       }
   }
   for(int i =0; i<10; i++){
        for(int j=0; j<10; j++){
               if(myGraph[i][j] == max) {
                   myGraph[i][j] = 0;
               }
           }
    }


}

int shortestPath(int i, int j){
    fillGraph();
    if(myGraph[i][j] == max || myGraph[i][j] == 0){
       return -1;
    }
    else{
        return myGraph[i][j];
    }

}

//// This Main For Test And debug.

/*
int main () {

    int testGraph[10][10] = {{0,1,0,1,0,0,0,0,0,0}, {1,0,1,0,0,0,0,0,0,0}, {0,1,0,1,1,0,0,0,0,0}, {1,0,1,0,0,0,0,0,0,0}, {0,0,1,0,0,0,0,0,0,0}, {0,0,0,0,0,0,1,0,0,0},
                {0,0,0,0,0,1,0,0,0,0}, {0,0,0,0,0,0,0,0,2,3}, {0,0,0,0,0,0,0,2,0,10}, {0,0,0,0,0,0,0,3,10,0} };
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10 ; j++){
            myGraph[i][j]=testGraph[i][j];
        }
    }
    
    printf("Input: \n");
    for(int i=0; i<10; i++){
        for(int j=0; j<10 ; j++){
            printf("%d ",testGraph[i][j]);
        }
        printf("\n");
    }
    printf("\nIs Path: \n");
    
    printf("\n[8,9] = ");// T
    isPath(8,9); 
    printf("\n[0,4] = ");// T
    isPath(0,4);
    printf("\n[5,9] = ");// F
    isPath(5,9);
    printf("\n[5,6] = ");// T
    isPath(5,6);

    printf("\n");
    printf("\nShortest Path: \n");

    printf("[8,9] = %d\n", shortestPath(8,9));// 5
    printf("[0,2] = %d\n", shortestPath(0,2));// 2
    printf("[0,4] = %d\n", shortestPath(0,4));// 3
    printf("[5,9] = %d\n", shortestPath(5,9));// 0
    printf("[5,6] = %d\n", shortestPath(5,6));// 1

    printf("\nAfter Algo: \n");

    for(int i=0; i<10; i++){
        for(int j=0; j<10 ; j++){
            printf("%d ",myGraph[i][j]);
        }
        printf("\n");
    }
    
}
*/

