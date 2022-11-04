#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <Windows.h>
using namespace std;
using namespace chrono;

#define N 100

int* generate_array(int array[], int sortedArray[]) {
    for (int i = 0; i < N; ++i) {
        array[i] = rand() % 199 - 99;
        sortedArray[i] = array[i];
    }
}

int* print_array(int array[]) {
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
}

int* print_sortedArray(int array[], int sortedArray[]) {
    for (int i = 0; i < N; i++) {
        cout << sortedArray[i] << " ";
        sortedArray[i] = array[i];
    }
}

int* print_sortedArray1(int sortedArray[]) {
    for (int i = 0; i < N; i++) {
        cout << sortedArray[i] << " ";
    }
}

void bubble_sort(int *sortedArray) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (sortedArray[j] > sortedArray[j + 1])
                swap(sortedArray[j], sortedArray[j + 1]);
        }
    }
}

void shaker_sort(int *sortedArray){
    for (int i = 0; i < N; i++){
        for (int j = i; j < N - 1 - i; j++){
            if (sortedArray[j] > sortedArray[j+1])
                swap(sortedArray[j], sortedArray[j+1]);
        }
        for (int j = N-1; j > i; j--){
            if (sortedArray[j] < sortedArray[j-1])
                swap(sortedArray[j], sortedArray[j-1]);
        }
    }
}

void comb_sort(int *sortedArray){
    const float k = 1.247;
    float S = N;
    while (k < S){
        for (int i = 0; i + k < S; i++){
            if (sortedArray[i] > sortedArray[int(i + k)])
                swap(sortedArray[i], sortedArray[int(i + k)]);

        }
        S /= k;
    }
    int count = 0;
    while (true){
        for (int i = 0; i < N - 1; i++){
            if (sortedArray[i] > sortedArray[i + 1])
                swap(sortedArray[i], sortedArray[i+1]);
            else count++;
        }
        if (count == N - 1)
            break;
        else
            count = 0;
    }
}

void insert_sort(int *sortedArray){
    int x, j;
    for (int i = 1; i < N; i++){
        x = sortedArray[i];
        j = i;
        while ((j > 0) && (x < sortedArray[j - 1])){
            sortedArray[j] = sortedArray[j - 1];
            j--;
        }
        sortedArray[j] = x;
    }
}

void quicksort(int* sortedArray, int endd, int begin)
{
    int mid;
    int f = begin;
    int l = endd;
    mid = sortedArray[(f + l) / 2];
    while (f < l)
    {
        while (sortedArray[f] < mid) f++;
        while (sortedArray[l] > mid) l--;
        if (f <= l)
        {
            swap(sortedArray[f], sortedArray[l]);
            f++;
            l--;
        }
    }
    if (begin < l)
        quicksort(sortedArray, l, begin);
    if (f < endd)
        quicksort(sortedArray, endd, f);

}

int linear_search(int sortedArray[], int x) {
    for (int i = 0; i < N; ++i) {
        if (sortedArray[i] == x)
            return i;
    }
    return -1;
}

int binary_search(int sortedArray[], int l, int r, int x) {
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (sortedArray[mid] == x)
            return mid;
        if (sortedArray[mid] > x)
            return binary_search(sortedArray, l, mid - 1, x);
        if (sortedArray[mid] < x)
            return binary_search(sortedArray, mid + 1, r, x);

    }
    return -1;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    srand(time(0));
    auto start = steady_clock::now();
    cout << endl;
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    cout << "Время: " << result.count() << " ns";

    int p, YorN = 1;

    int array[N], sortedArray[N];
    generate_array(array, sortedArray);

    while (YorN == 1) {
        cout << "\n\nВведи номер пункта, который нужно запустить: ";
        cin >> p;
        switch (p) {
            case 1:
            case 2: {
                cout << "\n\n(это пункты 1 и 2)";
                cout << "\n\nВходной массив:\n";
                print_array(array);

                cout << "\n\n\tBubble sort" << endl;
                start = steady_clock::now();
                bubble_sort(sortedArray);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Время: " << result.count() << " ns";
                cout << "\nОтсортированный массив:\n";
                print_sortedArray(array, sortedArray);

                cout << "\n\n\tShaker sort" << endl;
                start = steady_clock::now();
                shaker_sort(sortedArray);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Время: " << result.count() << " ns";
                cout << "\nОтсортированный массив:\n";
                print_sortedArray(array, sortedArray);

                cout << "\n\n\tComb sort" << endl;
                start = steady_clock::now();
                comb_sort(sortedArray);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Время: " << result.count() << " ns";
                cout << "\nОтсортированный массив:\n";
                print_sortedArray(array, sortedArray);

                cout << "\n\n\tInsert sort" << endl;
                start = steady_clock::now();
                insert_sort(sortedArray);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Время: " << result.count() << " ns";
                cout << "\nОтсортированный массив:\n";
                print_sortedArray(array, sortedArray);

                cout << "\n\n\tQuick sort" << endl;
                start = steady_clock::now();
                quicksort(sortedArray, N - 1, 0);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "Время: " << result.count() << " ns";
                cout << "\nОтсортированный массив:\n";
                print_sortedArray1(sortedArray);
                }break;

            case 3: {
                int max1 = array[0], min1 = array[0];
                start = steady_clock::now();
                for (int i = 0; i < N; ++i) {
                    max1 = array[i] > max1 ? array[i] : max1;
                    min1 = array[i] < min1 ? array[i] : min1;
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << endl;
                cout << "\nМаксимальный элемент: " << max1 << "\nМинимальный элемент: " << min1;
                cout << "\nВремя поиска элементов в неотсортированном массиве: " << result.count() << " ns";

                insert_sort(sortedArray);
                start = steady_clock::now();
                int max2 = sortedArray[0];
                int min2 = sortedArray[N - 1];
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\nВремя поиска элементов в отсортированном массиве: " << result.count() << " ns";
                }break;

            case 4: {
                insert_sort(sortedArray);
                int max1 = array[0], min1 = array[0];
                int cou = 0, sredn;
                for (int i = 0; i < N; ++i) {
                    max1 = array[i] > max1 ? array[i] : max1;
                    min1 = array[i] < min1 ? array[i] : min1;
                }
                sredn = (max1 - min1) / 2;
                cout << "\n\tНеотсортированный массив\n" << "Среднее значение = " << sredn << "\n" << "Индексы элементов, равных среднему между макс и мин элементами: ";
                start = steady_clock::now();
                for (int i = 0; i < N; ++i) {
                    if (array[i] == sredn) {
                        cou++;
                        cout << i << " ";
                    }
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\nКоличество таких элементов: " << cou;
                cout << "\nВремя: " << result.count() << " ns";

                cou = 0;
                sredn = (sortedArray[N-1] - sortedArray[0]) / 2;
                cout << "\n\n\tOтсортированный массив\n" << "Среднее значение = " << sredn << "\n" << "Индексы элементов, равных среднему между макс и мин элементами: ";
                start = steady_clock::now();
                for (int i = 0; i < N; ++i) {
                    if (sortedArray[i] == sredn) {
                        cou++;
                        cout << i << " ";
                    }
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\nКоличество таких элементов: " << cou;
                cout << "\nВремя: " << result.count() << " ns";
                }break;

                case 5: {
                    insert_sort(sortedArray);
                    int a, cou = 0;
                    cout << "\nВведи число, чтобы узнать, сколько элементов в массиве меньше него: ";
                    cin >> a;
                    start = steady_clock::now();
                    for (int i = 0; i < N; i++) {
                        if (sortedArray[i] < a)
                            cou++;
                        else
                            break;
                    }
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "В массиве " << cou << " элементов, которые меньше, чем " << a;
                    cout << "\nВремя: " << result.count() << " ns";
                } break;

                case 6: {
                    insert_sort(sortedArray);
                    int b, cou = 0;
                    cout << "\nВведи число, чтобы узнать, сколько элементов в массиве больше него: ";
                    cin >> b;
                    start = steady_clock::now();
                    for (int i = N; i > 0; i--) {
                        if (sortedArray[i] > b)
                            cou++;
                        //else
                        //    break;
                    }
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "В массиве " << cou << " элементов, которые больше, чем " << b;
                    cout << "\nВремя: " << result.count() << " ns";
                } break;

                case 7: {
                    insert_sort(sortedArray);
                    int x, ind;
                    cout << "Введи число, которое хочешь найти в массиве: ";
                    cin >> x;
                    start = steady_clock::now();
                    ind = linear_search(sortedArray, x);
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    if (ind == -1)
                        cout << "\nТакого элемента в массиве нет";
                    if (ind != -1)
                        cout << "\nИндекс числа " << x << " в отсортированном массиве: " << ind;
                    cout << "\nВремя выполнения перебора: " << result.count() << " ns";

                    start = steady_clock::now();
                    binary_search(sortedArray, 0, N - 1, x);
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\nВремя выполнения бинарного поиска: " << result.count() << " ns";
                } break;

                case 8: {
                    insert_sort(sortedArray);
                    cout << "\nОтсортированный массив:" << endl;
                    print_sortedArray1(sortedArray);
                    int elem1, elem2;
                    cout << "\n\nВведи номера элементов (индексы) массива, которые нужно поменять местами: ";
                    cin >> elem1 >> elem2;
                    start = steady_clock::now();
                    swap(sortedArray[elem1], sortedArray[elem2]);
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\nИзменённый массив:" << endl;
                    print_sortedArray1(sortedArray);
                    cout << "\nВремя: " << result.count() << " ns";
                } break;
        }
        cout << "\n\nПродолжить выполнение? (1 - да, 0 - нет)" << endl;
        cin >> YorN;
    }

/*    cout << "\n\n\tQuick sort" << endl;
    start = steady_clock::now();
    quicksort(sortedArray, 0, N - 1);
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Время: " << result.count() << " ns";
    cout << "\nОтсортированный массив:\n";
    print_sortedArray(array, sortedArray);


    start = steady_clock::now();
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\nВремя: " << result.count() << " ns";

    */



    return 0;
}
