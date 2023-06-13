#include <stdio.h>

// Функция для слияния двух отсортированных подмассивов
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0; // индекс для перебора левого подмассива
    int j = 0; // ...правого подмассива
    int k = 0; // индекс для записи элементов в исходный массив

    while (i < leftSize && j < rightSize) {   // есть элементы в обоих подмассивах
        if (left[i] <= right[j]) { // сравниваем элементы левого и правого подмассивов и записываем меньший элемент в исходный массив
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {  // копируем оставшиеся элементы из левого подмассива, если они есть
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < rightSize) { // аналог для правого
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {   // если массив пустой или состоит из одного элемента
        return;
    }

    int mid = size / 2; // индекс середины массива
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++) { // копируем элементы в левый и правый подмассивы
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);  // рекурсивно вызываем для левого и правого подмассивов
    mergeSort(right, size - mid);

    merge(arr, left, mid, right, size - mid);  //слияние отсортированных подмассивов
}