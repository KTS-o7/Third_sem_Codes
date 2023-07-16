// a recursive code to check if the array is sorted
// checks ascending order only

#include <stdio.h>

int check_sort(int array[], int size)
{
    if (size == 1)
        return 1;
    else
        return array[size - 1] < array[size - 2] ? 0 : check_sort(array, size - 1);
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size], i, res;
    while (i != size)
    {
        printf("Enter the %d th element: ", i + 1);
        scanf("%d", &array[i]);
        printf("\n");
        i++;
    }
    res = check_sort(array, size);
    if (res == 0)
        printf("Array not sorted\n");
    else
        printf("Array is sorted");
    return 0;
}
