// ОС, ПМ группа №5, Лужкова, ЛР №2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

void min_max(vector<int>& arr) {
    int min_value = *min_element(arr.begin(), arr.end());
    this_thread::sleep_for(chrono::milliseconds(7)); // добавляем задержку
    int max_value = *max_element(arr.begin(), arr.end());
    this_thread::sleep_for(chrono::milliseconds(7)); // добавляем зад
    cout << "Minimum value: " << min_value << endl;
    cout << "Maximum value: " << max_value << endl;
}

void average(vector<int>& arr) {
    float average_value = 0;
    for (int num : arr) {
        average_value += num;

        // Приостанавливаем поток на 12 миллисекунд
        this_thread::sleep_for(chrono::milliseconds(12));
    }
    average_value /= arr.size();
    cout << "Average value: " << average_value << endl;

    for (int& num : arr) {
        num = average_value;
    }
}

int main() {
    int n;
    cout << "Enter array dimension: ";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        //cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }

    thread min_max_thread(min_max, ref(arr));   //создаем поток, передаем вектор по ссылке
    thread average_thread(average, ref(arr));

    average_thread.join();   //делает все что делается в WinAPI за нас
    min_max_thread.join();

    cout << "Updated array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Задержка выполнения программы на 1 секунду
    this_thread::sleep_for(chrono::seconds(1));

    return 0;
}