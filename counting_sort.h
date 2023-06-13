#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[], int size, int range) {
    int count[range + 1]; // массив для подсчета частоты элементов
    int output[size];

    for (int i = 0; i <= range; i++) {  // заполняем массив частоты нулями
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {  // считаем частоту элементов в исходном   массиве
        count[array[i]]++;
    }

    for (int i = 1; i <= range; i++) {  // ыычисляем сумму частот
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {  // располагаем элементы в правильном порядке
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {  // копируем отсортированный массив обратно в исходный массив
        array[i] = output[i];
    }
}