#include <stdio.h>
#include "my_mat.h"

int main(){
    char selection = 'A';
    while (selection != 'D'){
        scanf("%c", &selection);
        if(selection == 'A'){
                graphInput();
        }
        else if(selection == 'C' || selection == 'B')
        {   
            
            if(selection == 'B'){
                int i=0;
                int j=0;
                scanf("%d", &i);
                scanf("%d", &j);
                isPath(i,j);
            }
            else if(selection == 'C'){
                int i=0;
                int j=0;
                scanf("%d", &i);
                scanf("%d", &j);
                printf("%d",shortestPath(i,j));
            }
            printf("\n");
        }
        else if(selection =='D'){
            continue;
        }
        else{
            continue;
        }
    }
    return 0;
}