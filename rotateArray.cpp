/*
* Rotate an array by k right shifts.
*/

#include <iostream>

using namespace std;

void rotateArray(int arr[], int n, int k) {
    bool increment=false;
    if (k%2==0 && n%2==0) {
        increment = true;
    }
    int temp;
    int next=arr[0];
    int currIndex=0;
    int nextIndex=0;
    int i=0;
    while (i<n) {
        nextIndex = (currIndex + k)%n;
        temp = arr[nextIndex];
        arr[nextIndex] = next;
        next = temp;
        //cout << "currIndex: " << currIndex << endl;
        //cout << "nextIndex: " << nextIndex << endl;
        //cout << "temp: " << temp << endl;
        //cout << "next: " << next << endl;
        //cout << "i: " << i << endl;
        currIndex = nextIndex;
        i++;
        // if k even and n also even then only this step is required
        if (increment && i%k==0) {
            currIndex++;
            next = arr[currIndex];
        }
        
    }
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    //n odd, k even
    rotateArray(arr,5,2);
    int arr1[5] = {1,2,3,4,5};
    //n odd, k odd
    rotateArray(arr1,5,3);
    int arr2[4] = {1,2,3,4};
    //n even, k odd
    rotateArray(arr2,4,3);
    int arr3[4] = {1,2,3,4};
    //n even, k even
    rotateArray(arr3,4,2);
    return 0;
}
