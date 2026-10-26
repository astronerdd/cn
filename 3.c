#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){
    int n, window, lost, base, end, i;
    int recovered = 0 ;

    printf("Enter Frame size :");
    scanf("%d", &n);
    printf("Enter window size :");
    scanf("%d", &window);
    printf("Enter lost data :");
    scanf("%d", &lost);


    base =1;

    while(base <n){
        end = base+window -1;

        if(end >n){
            end = n;
        }

        printf("\n. Sending Window ");
        for(i=0; i<end; i++){
            printf("%d ", i);
        }

        printf("\n");

        for(i=0;i<end;i++){
            if(i==lost && !recovered){
                printf("Frame %d lost!\n", i);
                printf("Going back...\nRetransmitting...\n");
                

                for(int j=i; j<=end; j++){
                    printf("%d ", j);
                }
                printf("\n");

                recovered = 1;
            }
            else{
                printf("Frame %d recieved\n", i);
            }
        }

        printf("ACK Recieved for window\n");
        base = end+1;
    }

    printf("\nAll frames transmitted successfully.\n");


}