#include <stdio.h>

int main()
{
    int n, w, i, j, lost;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    printf("Enter the window size: ");
    scanf("%d", &w);

    for(i = 0; i < n; i += w)
    {
        printf("\nSending frames: ");

        for(j = i; j < i + w && j < n; j++)
            printf("%d ", j);

        printf("\nEnter lost frame (-1 if no loss): ");
        scanf("%d", &lost);

        if(lost == -1)
        {
            printf("ACK received for all frames.\n");
        }
        else
        {
            printf("Frame %d is lost.\n", lost);

            printf("Retransmitting frames: ");

            for(j = lost; j < i + w && j < n; j++)
                printf("%d ", j);

            printf("\nACK received.\n");
        }
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}