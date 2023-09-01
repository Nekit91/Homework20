#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
void fill_arr(T arr[], int size, T left, T right) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (right - left) + left;
    }
}

template<typename T>
void print_arr(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
int search_index(T arr[], int size, T element, int begin = 0) {
    for (int i = begin; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

template<typename T>
int search_last_index(T arr[], int size, T element, int begin = 0) {
    for (int i = size - 1; i >= begin; i--) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

template<typename T>
T arr_min(T arr[], int size) {
    T min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

template<typename T>
T arr_max(T arr[], int size) {
    T max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

template<typename T>
double mean_value(T arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

template<typename T>
void range(T arr[], int size, T start, T end) {
    for (int i = 0; i < size; i++) {
        if (arr[i] >= start && arr[i] <= end) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

template<typename T>
int count(T arr[], int size, T element) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    return count;
}

template<typename T>
void sort_arr(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    const int size = 20;
    int arr[size];

    fill_arr(arr, size, -50, 51);
    print_arr(arr, size);

    int element = 0;
    int index = search_index(arr, size, element);
    std::cout << "Первое вхождения элемента в массив " << element << " Индекс: " << index << std::endl;

    int last_index = search_last_index(arr, size, element);
    std::cout << "Последнее вхождения элемента в массив " << element << " Индекс: " << last_index << std::endl;

    int min_val = arr_min(arr, size);
    std::cout << "Минимальное значение в массиве: " << min_val << std::endl;

    int max_val = arr_max(arr, size);
    std::cout << "Максимальное значение в массиве: " << max_val << std::endl;

    double mean = mean_value(arr, size);
    std::cout << "Среднее арифметическое всех элементов массива : " << mean << std::endl;

    int start = -10;
    int end = 10;
    std::cout << "Значения в диапазоне[" << start << ", " << end << "] : ";
    range(arr, size, start, end);

    element = 5;
    int count_val = count(arr, size, element);
    std::cout << "Количество вхождений переданного элемента в массив " << element << " В массиве: " << count_val << std::endl;

    sort_arr(arr, size);
    std::cout << "Сортированный массив: ";
    print_arr(arr, size);


    return 0;
}
