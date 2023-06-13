#include <stdio.h>

int binary_search(int arr[], int low, int high, int target) {
    if (low > high) { // границы подмассива
        return -1; // элемент не найден
    }
    int mid = (low + high) / 2; // находим центр

    if (arr[mid] == target) {
        return mid; // элемент найден в центре
    } else if (arr[mid] > target) { //идем влево
        return binary_search(arr, low, mid - 1, target); // в левой половине
    } else { //идем вправо
        return binary_search(arr, mid + 1, high, target); // в правой половине
    }
}

