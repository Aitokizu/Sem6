#include <stdio.h>
#include "binary_code.h"
#include "quick_sort.h"
#include "counting_sort.h"
#include "merge_sort.h"


#define MAX_SIZE 100

// Макрос SWAP для обмена значениями двух переменных любого типа данных
#define SWAP(type, a, b) { \
    type temp = a; \
    a = b; \
    b = temp; \
}

int main() {

    //Swap
   /* int num1, num2;

    printf("Input a: \n");
    scanf("%d", &num1);

    printf("Input b: \n");
    scanf("%d", &num2);

    printf("Before: a = %d, b = %d\n", num1, num2);

    SWAP(int, num1, num2);

    printf("After : a = %d, b = %d\n", num1, num2); */

//-------------------------------------------------------------//

    //Array
    int arr[MAX_SIZE], size, i;

    printf("Input the size of the array: \n");
    scanf("%d", &size);

    if (size > MAX_SIZE || size < 1) {
        printf("The size is beyond maximum.\n");
        return 1;
    }

    printf("Input the elements: \n");

    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    //Binary search (тут предполагается, что массив уже отсортирован, но если что, всегда можно впихнуть одну из сортировок внутрь этой подпрограммы)
     /* int target;
     printf("Element for search: \n");
     scanf("%d", &target);

     // Вызов рекурсивной функции бинарного поиска
     int index = binary_search(arr, 0, size - 1, target);

     // Вывод результата поиска
     if (index != -1) {
         printf("Element's position is %d.\n", index);
     } else {
         printf("No such element.\n");
     } */

//-------------------------------------------------------------//

    //Quick sort
   /* quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); */

//-------------------------------------------------------------//

    //Counting sort

  /*  int max = arr[0];  // определяем макс значение в массиве
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    countingSort(arr, size, max);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); */

//-------------------------------------------------------------//

    //Merge sort
    mergeSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}




