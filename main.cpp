#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int main() {
    const int size = 100; // optional
    int arr[size]{};
    int elements;
    cout <<  "Enter the number of elements" << endl;
    cin >> elements;
    while (elements > size){
        cout << "Amount of elements is higher than acceptable(" << size << "). Enter the number of elements" << endl  ;
        cin >> elements;
    }

    cout << "Values from input - press 1, random values - press 2" << endl;
    int condition;
    cin >> condition;
    if (condition == 1) {
        for (int i = 0; i < elements; i++) {
            cin >> arr[i];
        }
    }
    if (condition == 2) {
        cout << "Left edge - ";
        int left;
        cin >> left;
        cout << "Right edge - ";
        int right;
        cin >> right;
        for (int i = 0; i < elements; ++i) {
            arr[i] = rand() % (right - left + 1) + left;
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool flag = false;
    if (elements < 3){
        cout << "No local minimums" << endl;
        flag = true;
    } else{
        int counter = 0;
        for(int i = 1; i < elements - 1; i++) {
            if (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]) {
                flag = true;
                counter += 1;
                cout << "Index of local minimum "<< counter << ": " << i << endl;
            }
        }
        if (!flag){
            cout << "No local minimums";
        }
        cout << endl;
    }
    int minimum = pow(2, 8);
    int min_index = 0;
    for (int i = 0; i < elements; i++){
        if (arr[i] < minimum){
            min_index = i;
            minimum = arr[i];
        }
    }
    int sum = 0;
    for(int i = min_index; i < elements; i++){
        sum += arr[i];
    }
    cout << "Sum of the elements after the lowest: " << sum << endl;
    for (int i = 0; i < elements; i ++) {
        for (int j = i + 1; j < elements; j++) {
            if (abs(arr[j]) < abs(arr[i])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Sorted array: ";
    for(int i = 0; i < elements; i++){
        cout << arr[i] << " ";
    }


    return 0;
}
