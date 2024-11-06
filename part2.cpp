#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void ShakerSort(int data[], int size) {
    int left = 0;
    int right = size - 1;
    int temp = 0;
    int i = 0;
    int j = 0;

outer_start:
    if (left >= right) goto end_sort;

    i = left;
inner_loop_right:
    if (i >= right) goto end_inner_right;
    if (data[i] > data[i + 1]) {
        temp = data[i];
        data[i] = data[i + 1];
        data[i + 1] = temp;
    }
    i++;
    goto inner_loop_right;

end_inner_right:
    right--;

    j = right;
inner_loop_left:
    if (j <= left) goto end_inner_left;
    if (data[j] < data[j - 1]) {
        temp = data[j];
        data[j] = data[j - 1];
        data[j - 1] = temp;
    }
    j--;
    goto inner_loop_left;

end_inner_left:
    left++;
    goto outer_start;

end_sort:
    return;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    int* data;
    int i = 0;

input_size:
    printf("Введите размер массива: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Некорректный размер массива.\n");
        goto end_program;
    }

    data = (int*)malloc(size * sizeof(int));
    if (data == NULL) {
        printf("Ошибка выделения памяти.\n");
        goto end_program;
    }

input_elements:
    if (i >= size) goto start_sorting;
    printf("Элемент %d: ", i + 1);
    scanf("%d", &data[i]);
    i++;
    goto input_elements;

start_sorting:
    ShakerSort(data, size);

output_elements:
    i = 0;
print_element:
    if (i >= size) goto end_program;
    printf("%d ", data[i]);
    i++;
    goto print_element;

end_program:
    printf("\n");
    return 0;
}
