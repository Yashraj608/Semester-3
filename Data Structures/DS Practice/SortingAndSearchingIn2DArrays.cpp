#include<iostream>
using namespace std;

bool LinearSearch(int **arr, int rows, int cols, int target){
        for(int i =0;i<rows;i++){
          for(int j =0;j<cols;j++){
            if(arr[i][j] == target){
              return true;
            }
          }
        }
        return false;
}
bool BinarySearch(int **arr, int rows,int cols,int target){
           int start = 0;
           int end = rows*cols -1;
           while(start <= end){
            int mid = start +(end - start)/2;
              int i = mid/cols;
              int j = mid % cols;
              if(arr[i][j] == target){
                return true;
              }else if(arr[i][j] < target ){
                start = mid +1;
              }else{
                end = mid -1;
              }
        }
        return false;
}


void BubbleSort(int **arr, int rows, int cols){
        int size = rows*cols;
        for(int pass =0;pass<size-1;pass++){
         for(int i =0;i<size-pass-1;i++){
          int r1 = i/cols;
          int c1 = i%cols;
          int r2 = (i+1)/cols;
          int c2 = (i+1)%cols;
          if(arr[r1][c1]>arr[r2][c2]){
            swap(arr[r1][c1],arr[r2][c2]);
          }
         }
        }
}
void combSort(int **arr,int rows,int cols){
        int size = rows*cols;
        int gap = size;
        int *flat =  new int[size];
        int index = 0;

        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                flat[index++] = arr[i][j];
            }
        }
         const double shrink = 1.3;
        bool swapped = true;
        while(gap > 1 || swapped){
            gap = int(gap/shrink);
            if(gap <1 ){
                gap = 1;
            }

            swapped = false;
            for(int i=0;i+gap<size;i++){
                if(flat[i] > flat[i+gap]){
                    swap(flat[i],flat[i+gap]);
                    swapped = true;
                }
            }
        }
         index = 0;
        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                arr[i][j] = flat[index++];
            }
        }
}
int main(){
    int rows,cols;
    cout<<"Enter the number of rows:"<<endl;
    cin>>rows;
    cout<<"Enter the number of cols: "<<endl;
    cin>>cols;
      int**arr = new int*[rows];
      for(int i =0;i<rows;i++){
        arr[i] = new int[cols];
      }


      cout<<"Enter the elements of 2D-Array: "<<endl;
      for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            cin>>arr[i][j];
        }
      }

      // combSort(arr,rows,cols);

  BubbleSort(arr,rows,cols);

      cout<<"After sorting: "<<endl;
      for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
      }
      

      cout<<"Enter the target : "<<endl;
      int target;
      cin>>target;


    bool found =   BinarySearch(arr,rows,cols,target);
      if(!found){
        cout<<"Target Not Found"<<endl;
      }else{
           cout<<"Target Found !"<<endl;
      }


      bool foundLinearly = LinearSearch(arr,rows,cols,target);
      if(foundLinearly){
        cout<<"Found Succesfully By Linear Search. "<<endl;
      }
    return 0;
}