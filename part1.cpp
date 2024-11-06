#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _CRT_CECURE_NO_WARNINGS

void ShakerSort(int data[], int size) {
    int left = 0;
    int right = size - 1;
    int temp = 0;

    while (left < right) {
        for (int i = left; i < right; i++) {
            if (data[i] > data[i + 1]) {
                temp = data[i + 1];
                data[i + 1] = data[i];
                data[i] = temp;
            }
        }
        right--;

        for (int j = right; j > left; j--) {
            if (data[j] < data[j - 1]) {
                temp = data[j - 1];
                data[j - 1] = data[j];
                data[j] = temp;
            }
        }
        left++;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int size;
    printf("Введите размер массива: ");
    scanf_s("%d", &size);

    if (size <= 0) {
        printf("Некорректный размер массива.\n");
        return 1;
    }

    int* data = (int*)malloc(size * sizeof(int));

    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        printf("Элемент %d: ", i + 1);
        scanf_s("%d", &data[i]);
    }

    ShakerSort(data, size);

    printf("Отсортированный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}