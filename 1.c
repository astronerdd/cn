#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX 200
#define FLAG "01111110"

void characterCount(void){

    char data[MAX];
    int count = 0;

    printf("Enter data: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';

    count = (int)strlen(data);

    printf("Original Data : %s\n", data);
    printf("Character Stuffed Data : %d%s\n", count, data);

}

void characterStuffing(void){
    
    char data[MAX];
    char frame[2 * MAX +5];
    int i, j =0;

    printf("Enter Data : ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';

    frame[j++] = '~';

    for(i = 0; data[i] != 0; i++){
        if(data[i] == '~' || data[i] == '{'){
            frame[j++] = '{';
        }

        frame[j++] = data[i];
    }

    frame[j++] = '~';

    printf("Original Data : %s\n", data);
    printf("Data after Character stuffing : %s\n", frame);

}

void bitStuffing(void){
    char data[MAX];
    char frame[2* MAX +20];
    int i, j=0, ones =0;

    printf("Enter the data : ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';


    for(i =0; data[i]!='\0'; i++){
        if(data[i] != '0' && data[i]!= '1'){
            printf("Please Enter valid Binary String!\n");
            bitStuffing();
        }
    }

    for(i=0; FLAG[i]!='\0'; i++){
        frame[j++] = FLAG[i];
    }

    for(i=0; data[i]!='\0'; i++){
        frame[j++] = data[i];

        if(data[i] == '1'){
            ones++;
            if(ones == 5){
                frame[j++]= '0';
                ones =0;
            }
        }
        else{
            ones =0;
        }

    }

    for(i=0; FLAG[i]!='0'; i++){
        frame[j++] = FLAG[i];
    }

    frame[j]= '\0';

    printf("original Data : %s\n", data);
    printf("frame Data : %s\n", frame);

}

void menu(){
    printf("------DATA LINK LAYER FRAMING------\n");
    printf("1. Character Count Method\n");
    printf("2. Character Stuffing Mehtod\n");
    printf("3. Bit Stuffing Mehtod\n");
    printf("0. Exit\n");
}

int main(){

    int choice;

    while(1){
        menu();
        scanf("%d", &choice);
        getchar();

        switch (choice){
            case 1:
                characterCount();
                break;
            case 2:
                characterStuffing();
                break;
            case 3:
                bitStuffing();
                break;
            case 0:
                exit(0);
            default: 
                printf("Invalid Choice!\n");
                break;

        }
    }
}