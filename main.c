#include <stdio.h>
#include "my_mat.h"

int main(){
    char selection = 'A';

    while (selection != 'D'){
        scanf("%c", &selection);
        if(selection == 'A'){
            graphInput();
        }
        else if(selection == 'B'){
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
            printf("\n%d",shortestPath(i,j));

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