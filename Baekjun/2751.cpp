//2751 - cpp 더 공부하고 합시다,,,
//13개월 후 다시
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right-left+1);
    int i = left;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=right) {
        if(arr[i]<=arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid) {
        temp[k++] = arr[i++];
    }

    while(j<=right) {
        temp[k++] = arr[j++];
    }

    for(int p = 0 ; p<k ; p++) {
        arr[left+p] = temp[p];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int count;
    std::cin >> count;

    std::vector<int> arr;
    for(int i = 0;i<count;i++) {
        int temp;
        std::cin >> temp;
        arr.push_back(temp);
    }

    mergeSort(arr, 0, arr.size()-1);

    for(int i = 0;i<arr.size();i++) {
        std::cout << arr[i] << "\n";
    }

    return 0;
}