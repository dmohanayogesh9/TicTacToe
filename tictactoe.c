#include <stdio.h>
#include <stdlib.h>

int checkForCompleteion(int arr[3][3],int x){
    int c = 3*x;
    if(arr[0][0] + arr[0][1] + arr[0][2] == c)
    return 1;
    if(arr[1][0] + arr[1][1] + arr[1][2] == c)
    return 1;
    if(arr[2][0] + arr[2][1] + arr[2][2] == c)
    return 1;
    if(arr[0][0] + arr[1][0] + arr[2][0] == c)
    return 1;
    if(arr[0][1] + arr[1][1] + arr[2][1] == c)
    return 1;
    if(arr[0][2] + arr[1][2] + arr[2][2] == c)
    return 1;
    if(arr[2][0] + arr[1][1] + arr[0][2] == c)
    return 1;
    if(arr[0][0] + arr[1][1] + arr[2][2] == c)
    return 1;
    
    return 0;
}
void printMatrix(int arr[3][3]){
    for(int i =0; i<3;i++){
        printf("\t");
        if(arr[i][0] == 1){
        printf("X | ");
        }else if(arr[i][0] == 0){
        printf("0 | ");
        }else printf("  | ");

        if(arr[i][1] == 1){
        printf("X | ");
        }else if(arr[i][1] == 0){
        printf("0 | ");
        }else printf("  | ");

        if(arr[i][2] == 1){
        printf("X\n");
        }else if(arr[i][2] == 0){
        printf("0\n");
        }else printf("  \n");
        
        if(i!=2)
        printf("\t---------\n");
    }
}
void main(){
    char ch;
    
    printf("---Welcome to TicTacToe---\n");
    printf("Wanna play a game [y/n] :");
    scanf("%s",&ch);
    system("clear");
    if(ch == 'y'){
        while(1){
            int arr[3][3]={{9,9,9},{9,9,9},{9,9,9}};
            int pos, i;
            printf("\n");
            printMatrix(arr);
            for(i=0; i<9; i++){
                int c = i%2;
                if(c == 0){
                    printf("\nEnter position for X(player1) :");
                }else {
                    printf("\nEnter position for O(player2) :");
                }
                scanf("%d",&pos);
                pos--;
                if(c == 0){
                    arr[pos/3][pos%3] = 1;
                }else arr[pos/3][pos%3] = 0;
                system("clear");
                printMatrix(arr);
                if(checkForCompleteion(arr, (i+1)%2)){
                    printf("\nPlayer %d WIN's\n\n",c + 1);
                    break;
                }
            }
            if(i == 9){
                printf("\nDRAW\n");
            }
            char ch;
            printf("Play Again?? [y/n]\n");
            scanf("%s",&ch);
            
            if( ch == 'n')
            {
                break;
            }
            system("clear");
        }
    }
    system("clear");
    printf("Thank you for visiting!!!");
    printf("\nClosing...");
}