#include <stdio.h>

int partition(int arr[], int leftIndex, int rightIndex) {
    int arrIter = leftIndex;
    int temp = arr[leftIndex];
    for (arrIter; arrIter < rightIndex; arrIter++) {
        if (arr[arrIter] < arr[rightIndex]) {
            arr[leftIndex] = arr[arrIter];
            arr[arrIter] = temp;
            leftIndex++;
            temp = arr[leftIndex];
        }
    }
    arr[leftIndex] = arr[arrIter];
    arr[arrIter] = temp;
    return (leftIndex);
}

void quickSort(int arr[], int leftIndex, int rightIndex){
    if (leftIndex < rightIndex) {
        int middleIndex = partition(arr, leftIndex, rightIndex);
        quickSort(arr, leftIndex, middleIndex - 1);
        quickSort(arr, middleIndex + 1, rightIndex);
    }
}

int main() {
    int arr[] = {30, 50, 25, 66, 18, 489, 154 ,67, 89};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, arrLength - 1);
    
    return 0;
}
