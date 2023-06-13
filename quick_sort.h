#include <stdio.h>

#define SWAP(a, b) \
    do { \
        int temp = (a); \
        (a) = (b); \
        (b) = temp; \
    } while (0)

// функция для разделения массива
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // опорный элемент для рабиения на подмассивы (в данном случае берем последний элемент)
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {  // перебираем элементы массива
        if (arr[j] <= pivot) { // если текущий элемент меньше или равен опорному, меняем его местами с элементом перед i
            i++;
            SWAP(arr[i], arr[j]);
        }
    }

    SWAP(arr[i + 1], arr[high]); // меняем опорный элемент с элементом за i

    return i + 1;  // индекс опорного элемента
}

void quickSort(int arr[], int low, int high) {
    int stack[high - low + 1];  // стек для границ подмассивов
    int top = -1; //верхний индеск стека

    stack[++top] = low; // присваиваем значение, а потом увеличиваем индекс
    stack[++top] = high;

    while (top >= 0) { // пока стек не пустой, извлекаем границы подмассивов и разделяем их
        high = stack[top--];
        low = stack[top--];

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) { // есть элементы в левой части подмассива, помещаем границы левой части в стек
            stack[++top] = low;
            stack[++top] = pivotIndex - 1;
        }

        if (pivotIndex + 1 < high) { // аналог с правой частью
            stack[++top] = pivotIndex + 1;
            stack[++top] = high;
        }
    }
}