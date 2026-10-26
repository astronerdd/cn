#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 200

void crc(char data[], char gen[]){
    char temp[MAX + 20];

    int n = strlen(data);
    int g = strlen(gen);
    int i,j;

    strcpy(temp, data); 

    for(i =n; i<g+n-1; i++){
        temp[i] = 0;
    }

    temp[n+g-1] = '\0';

    for(i=0; i<n; i++){
        if(temp[i]=='1'){
            for(j=0; j<g;j++){
                temp[i+j] = (temp[i+j] == gen[j]) ? '0' : '1';
            }
        }
    }
    printf("CRC remainder : ");
    for(i =n ; i<n+g-1; i++){
        printf("%c", temp[i]);
    }

    printf("\nCRC codeword : %s ", data);
    for(i =n ; i<n+g-1; i++){
            printf("%c", temp[i]);
    }

    printf("\n");
}


void menu(){
    printf("Enter choice :\n");
    printf("\n1. CRC 12");
    printf("\n2. CRC 16");
    printf("\n3. CRC ccit");
    printf("\n0.exit");
}

int main(){
    char data[MAX];

    int choice;


    char crc12[] = "1100000001111";
    char crc16[] = "11000000000000101";
    char crcccit[] = "10001000000100001";

    while(1){

        printf("Enter binary data :");
        scanf("%199s", data);
        
        
        menu();
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                crc(data, crc12);
                break;
            case 2:
                crc(data, crc16);
                break;
            case 3:
                crc(data, crcccit);
                break;
            case 4: 
                exit(0);
            default:
                printf("Invalid Choice!\n");
                break;
        }
        
    }
    
}

