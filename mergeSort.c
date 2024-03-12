#include <stdio.h>

void merge(int arr[], int leftIndex, int middleIndex, int rightIndex) {
    int lengthLeft = middleIndex - leftIndex + 1;
    int lengthRight = rightIndex - middleIndex;
    
    int tempLeft[lengthLeft];
    int tempRight[lengthRight];
    
    for (int i = 0; i < lengthLeft; i++) {
        tempLeft[i] = arr[leftIndex + i];
    }
    for (int i = 0; i < lengthRight; i++) {
        tempRight[i] = arr[middleIndex + 1 + i];
    }
    
    int arrIter = leftIndex;
    int leftIter = 0;
    int rightIter = 0;
    
    for (arrIter; arrIter < (rightIndex + 1); arrIter++) {
        if (leftIter == lengthLeft) {
            arr[arrIter] = tempRight[rightIter];
            rightIter++;
            continue;
        }
        if (rightIter == lengthRight) {
            arr[arrIter] = tempLeft[leftIter];
            leftIter++;
            continue;
        }
        if (tempLeft[leftIter] < tempRight[rightIter]) {
            arr[arrIter] = tempLeft[leftIter];
            leftIter++;
        }
        else {
            arr[arrIter] = tempRight[rightIter];
            rightIter++;
        }
    }
}

void mergeSort(int arr[], int leftIndex, int rightIndex) {
    int middleIndex = (leftIndex + rightIndex) / 2;
    
    if (middleIndex != leftIndex) {
        mergeSort(arr, leftIndex, middleIndex);
        mergeSort(arr, middleIndex + 1, rightIndex);
    }
    
    merge(arr, leftIndex, middleIndex, rightIndex);
}

void printIntArr(int arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5,2,1,5,6,7,1,8,5,2,3};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    printIntArr(arr, arrLength);
    
    mergeSort(arr, 0, arrLength - 1);
    
    printIntArr(arr, arrLength);
    
    return 0;
}
