#include <iostream>

int main();

int *  mergesort(int array[], int size);

int * merge(int * array1, int size1, int * array2, int size2);

void print(int array[], int size);


int main(){

    int array1[5] = {9, 8, 7, 6, 5};
    print(mergesort(array1, 5), 5);

    return 0;
}

void print(int array[], int size){

    // std::cout << "size: " << size << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int *  mergesort(int array[], int size){
    
    if (size == 1){
        return array;
    }

    //divide into two lists
    int size1 = size/2;
    int size2 = size - size1;
    int * array1;
    int * array2;

    array1 = new int[size1];
    array2 = new int[size2];

    for(int i = 0; i < size1; i++){
        array1[i] = array[i];
        array2[i] = array[i+size1];
    }
    //make sure the last element got copied
    array2[size2-1] = array[size-1];
    

    array1 = mergesort(array1, size1);
    array2 = mergesort(array2, size2);

    // std::cout << "merge: ";
    // print(merge(array1, size1, array2, size2), size1+size2);

    return merge(array1, size1, array2, size2);
}

int * merge(int * array1, int size1, int * array2, int size2){

    int * array3 = new int [size1+size2];
    int count1 = 0;
    int count2 = 0;

    int i = 0;
    int j = 0;

    for(int k = 0; i < size1 && j < size2; k++){
        if(array1[i] < array2[j]){
            array3[k] = array1[i];
            i++;
            count1++;
        }else{
            array3[k] = array2[j];
            j++;
            count2++;
        }
    }
    

    //chekc if every element has been added into the new list
    while(count1 < size1){
        array3[count1+size2] = array1[count1];
        count1 ++;
    }

    while(count2 < size2){
        array3[count2+size1] = array1[count2];
        count2 ++;
    }

    return array3;
}