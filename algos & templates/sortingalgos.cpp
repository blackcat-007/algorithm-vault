#include<bits/stdc++.h>
using namespace std;
void bubblesort(vector<int>arr,int size){
for(int i=0;i<size-1;i++){
for(int j=0;j<size-i-1;j++){
if(arr[j]>arr[j+1]){
swap(arr[j],arr[j+1]);
}
}
}
for(int i=0;i<size;i++){
cout<<arr[i]<<" ";
}
}
void selectionsort(vector<int>arr,int size){
for(int i=0;i<size-1;i++){
int minindex=i;
for(int j=i+1;j<size;j++){
if(arr[j]<arr[minindex]){
minindex=j;
}
}
swap(arr[i],arr[minindex]);
}
for(int i=0;i<size;i++){
cout<<arr[i]<<" ";
}
}
void insertionsort(vector<int> arr,int size){
for(int i=1;i<size;i++){
int key=arr[i];
int j=i-1;
while(j>=0 && arr[j]>key){
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}
for(int i=0;i<size;i++){
cout<<arr[i]<<" ";
}
}
void merge(vector<int>&arr,vector<int>& temp,int start,int mid, int end){
int size=end-start+1,right_first=mid+1;
int k=start, left=start, right=end;
while(start<=mid && right_first<=end){
if(arr[start]<arr[right_first]){
temp[k++]=arr[start++];
}
else{
temp[k++]=arr[right_first++];
}
}
while(start<=mid){
temp[k++]=arr[start++];
}
while(right_first<=end){
temp[k++]=arr[right_first++];
}
for(int i=left;i<=right;i++){
arr[i]=temp[i];

}
}

void mergesort(vector<int>&arr,vector<int>& temp,int start,int end){
if(start<end){
int mid=(start+end)/2;
mergesort(arr,temp,start,mid);
mergesort(arr,temp,mid+1,end);
merge(arr,temp,start,mid,end);
}
}
int partitioning(vector<int>& arr,int start,int end){
int pivot=start;
while(start<end){
while(arr[start]<arr[pivot]){
start++;
}
while(arr[end]>arr[pivot]){
end--;
}
if(start<end){
swap(arr[start],arr[end]);
}
}
swap(arr[end],arr[pivot]);
return end;
}

void quicksort(vector<int>& arr,int start,int end){
if(start<end){
int partition=partitioning(arr,start,end);
quicksort(arr,start,partition-1);
quicksort(arr,partition+1,end);
}
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Unsorted array:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "Which sort do you want to use?\n"
         << "(BUBBLE SORT: b, SELECTION SORT: s, INSERTION SORT: i, MERGE SORT: m, QUICK SORT: q)\n";

    char ch;
    cin >> ch;

    switch (ch) {
        case 'b':
            cout << "Sorted list by bubble sort:\n";
            bubblesort(arr, n);
            cout << "\n";
            break;

        case 's':
            cout << "Sorted list by selection sort:\n";
            selectionsort(arr, n);
            cout << "\n";
            break;

        case 'i':
            cout << "Sorted list by insertion sort:\n";
            insertionsort(arr, n);
            cout << "\n";
            break;

        case 'm': {
            cout << "Sorted list by merge sort:\n";
            vector<int> temp(n);
            vector<int> arrtemp = arr;
            int start = 0, end = n - 1;

            mergesort(arrtemp, temp, start, end);

            for (int x : arrtemp) cout << x << " ";
            cout << "\n";
            break;
        }

        case 'q': {
            cout << "Sorted list by quick sort:\n";
            int start = 0, end = n - 1;
            quicksort(arr, start, end);
            for (int x : arr) cout << x << " ";
            cout << "\n";
            break;
        }

        default:
            cout << "Invalid option selected!\n";
    }

    return 0;
}
