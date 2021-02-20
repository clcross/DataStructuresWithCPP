#include "arrays.hpp"

int countNegatives(const int array[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++){
        if (array[i] < 0){
            count++;
        }
    }
    return count;
}

int findMinOdd(const int array[], int size) {
    int remainder = 0;
    if(size > 0){
        int temp = array[0];
        for (int i = 0; i < size; i++){
            remainder = (array[i] % 2);
            if (remainder != 0 && temp > array[i]){
                temp = array[i];
            }
        }
        if (temp % 2 != 0){
            return temp;
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
}

int search(const int array[], int size, int value) {
    int location = 0;
    bool hasNum = false;
    for (int i = 0; i < size; i++){
        if (array[i] == value){
            location = i;
            hasNum = true;
        }
    }
    if (hasNum == true){
        return location;
    }
    else{
        return -1;
    }
}

bool remove(int array[], int size, int index) {
    if (0 <= index && index < size){
        for (int i = index; i < size - 1; i++){
            array[i] = array[i + 1];
        }
        return true;        
    }
    else{
        return false;
    }
}
