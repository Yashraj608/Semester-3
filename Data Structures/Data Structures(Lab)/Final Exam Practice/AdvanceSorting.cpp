#include<iostream>
using namespace std;


//----------------------------------MergeSort---------------------------------------------//

void merge(int arr[], int mid , int left , int right){
    int n1 = mid - left +1;
    int n2 = right - mid;

    int *L = new int[n1];
    int*R = new int[n2];

    for(int i =0;i<n1;i++){
        L[i] = arr[left +i];
    }

    for(int i= 0;i<n2;i++){
        R[i] = arr[mid +1+i];
    }

    int i=0,j=0,k=left;
    while(i<n1 && j <n2){
        if(L[i]<R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }


    while(i < n1){
        arr[k++] = L[i++];
    }

    while(j <n2){
        arr[k++] = R[j++];
    }

    delete[]L;
    delete[]R;
}
void MergeSort(int arr[], int left , int right){
    if(left < right){
        int mid = left +(right- left)/2;

        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);

        merge(arr,mid ,left, right);
    }
}

//---------------------------------------QuicKSort----------------------------------------//
int getPartition(int arr[] ,int low , int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i +1;
}

void QuickSort(int arr[], int low ,int high){
    if(low < high){
        int p = getPartition(arr,low , high);

        QuickSort(arr,low,p-1);
        QuickSort(arr,p+1,high);
    }
}


// ------------------------------------------RadiX Sort---------------------------------//
  int getMax(int arr[], int n ){
    int max = arr[0];
    for(int i =1;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
  }


  void CountSort(int *arr , int n , int exp){
    int output[n];
    int count[10] ={0};

    for(int i =0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }

    for(int i =1 ;i <10;i++){
        count[i] += count[i-1];
    }

    for(int i = n-1;i>=0;i--){
        int digit = (arr[i]/exp)%10;
        output[count[digit]-1] = arr[i];
        count[digit]--;
    }


    for(int i =0;i<n;i++){
        arr[i] = output[i];
    }
  }

  void RadixSort(int arr[], int n ){
    int m = getMax(arr, n );

    for(int exp = 1;m/exp>0;exp*=10){
      CountSort(arr,n,exp);
    }
  }
//-------------------------------------------Display--------------------------------//

void Display(int arr[],int n ){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n ;
    cout<<"Enter the size of the array :"<<endl;
    cin>>n;
    int *arr = new int[n];

    cout<<"Enter the elements of the array :"<<endl;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    int *arr1 = new int[n];
    int *arr2 = new int[n];
    int *arr3 = new int[n];
    for(int i =0;i<n;i++){
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }
cout<<"Original Array is : "<<endl;
Display(arr,n);

cout<<endl;
    cout<<"After the radix sort: "<<endl;
    RadixSort(arr1,n);
    Display(arr1,n);

   cout<<endl;
    cout<<"After the Quick sort: "<<endl;
    QuickSort(arr2,0,n-1);
    Display(arr2,n);

    cout<<endl;
    cout<<"After the Merge Sort: "<<endl;
    MergeSort(arr3,0,n-1);
    Display(arr3,n);
    return 0;
}