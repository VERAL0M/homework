#include <iostream>
#include "func.h"
#include <list>
#include <vector>
#include <array>


using namespace std;

int sum(int arr [], int n){

    int res=0;
    for (int i=0; i<n; i++){
        res+=arr[i];

    }
    return res;
}

void task1(){
    int n;
    cin>>n;
    int* arr =new int[n];
    
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Summ arr: "<<sum(arr, n);
    delete[] arr;
    
 
}


int count_even(int arr[], int n){
    int count=0;
    for (int i=0; i<n; i++){
        if (arr[i]%2==0){
            count+=1;
        }

    }
    return count;
}

void task2(){
    int n;
    cin>>n;
    int* arr =new int[n];
    
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Кол-во чётных чисел: "<<count_even(arr, n)<<endl;
    delete[] arr;
}

int max_elemenst(int arr[], int n){
    int max_el=-100000000;
    for (int i=0; i<n; i++){
        if (max_el<arr[i]){
            max_el=arr[i];
        }

    }
    return max_el;

}

int min_elemenst(int arr[], int n){
    int min_el=1000000000;
    for (int i=0; i<n; i++){
        if (min_el>arr[i]){
            min_el=arr[i];
        }

    }
    return min_el;

}

void task3(){
    int n;
    cin>>n;
    int* arr =new int[n];
    
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Max element: "<<max_elemenst(arr, n)<<endl;
    cout<<"Min element: "<<min_elemenst(arr, n)<<endl;
    delete[] arr;


}
    double average(const vector<int>& v){
        double sum_el=0;
        int n=v.size();
        for (int i=0; i<n; i++){
            sum_el+=v[i];

        }
        return sum_el/v.size();


    }
    void task4(){
        int n;
        // vector<int> v;
        cout<<"Введите размерность массива: ";
        cin>>n;
        vector<int> v(n);
        for (int i=0; i<n; i++){
            cout<<"Введите элемент массива: ";
            cin>>v[i];
        
        }
        cout<<"Среднее арифметическое элементов массива"<<average(v);
    }





