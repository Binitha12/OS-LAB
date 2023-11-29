#include <stdio.h>
#include <math.h>

int main()
{
    int n, start, dir, temp;
    int startpos, dist = 0;

    printf("Enter the no of tasks to be seeked");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the tasks");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the starting posn");
    scanf("%d", &start);
    startpos = start;

    printf("Enter the direction to proceed 1 for R and 2 for L\n");
    scanf("%d", &dir);

    // sort the sequence
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    }
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    if (dir == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= startpos)
            {
                dist = dist + abs(startpos - arr[i]);
                startpos = arr[i];
                printf("%d ", arr[i]);

                printf("    %d    ", dist);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < startpos && arr[i] <= start)
            {
                dist = dist + abs(startpos - arr[i]);
                printf("%d ", arr[i]);
            }
        }
    }

    if (dir == 2)
    {

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] <= startpos)
            {
                dist = dist + abs(startpos - arr[i]);
                printf("%d ", arr[i]);
                startpos = arr[i];
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] >= startpos && arr[i] > start)
            {
                dist = dist + abs(startpos - arr[i]);
                startpos = arr[i];
                printf("%d ", arr[i]);
            }
        }
    }

    printf("%d", dist);
}