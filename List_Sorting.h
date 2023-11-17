//
// Implementation of List ADT sorting methods
// Author: Max Benson
// Modified by: 
// Date: 10/18/2021
// Modification Date: 
//

#ifndef LIST_SORTING_H
#define LIST_SORTING_H

/**
 * Perform insertion sort for range of list
 * Uses helper function shared with Shell short
 * @param list to sort
 */
template <typename ItemType>
void Sort<ItemType>::InsertionSort(List<ItemType>& list) {
    assert(false);
}

/**
 * Perform selection sort for range of list
 * @param list to sort
 */
template <typename ItemType>
void Sort<ItemType>::SelectionSort(List<ItemType>& list) {
    assert(false);
}

/**
 * Perform Shell sort for range of list
 * Uses helper function shared with insertion sort
 * performs "h-sort" using so-called Hibbard series
 * @param list to sort
 * @param lowIndex first element of range for sorting
 * @param highIndex last element of range for sorting
 */
template <typename ItemType>
void Sort<ItemType>::ShellSort(List<ItemType>& list) {
    assert(false);
}

/**
 * Perform quick sort for range of list
 * Picks pivot based on median of first, middle, and last element
 * @param list to sort
 * @param lowIndex first element of range for sorting
 * @param highIndex last element of range for sorting
 */
template <typename ItemType>
void Sort<ItemType>::QuickSort(List<ItemType>& list, int lowIndex, int highIndex) {
    ItemType midpoint;
   midpoint = PickPivot(list,lowIndex,highIndex);
   int right;
   int left;

   if(lowIndex<highIndex) {

       Partition(list, lowIndex, highIndex, midpoint, left, right);
       QuickSort(list, lowIndex, right);
       QuickSort(list, left, highIndex);
   }
//    assert(false);
}

/**
 * Perform merge sort for range of list
 * @param list to sort
 * @param lowIndex first element of range for sorting
 * @param highIndex last element of range for sorting
 * @param fAscending if true sort in ascending order, else in descending order
 */
template <typename ItemType>
void Sort<ItemType>::MergeSort(List<ItemType>& list) {
    assert(false);
}

/**
 * Called by QuickSort to choose pivot value
 * Takes median of first, middle and last element
 * Assumes there are there element in the list
 * @param list to sort
 * @param lowIndex first element of range for sorting
 * @param highIndex last element of range for sorting
 * @return pivot item
 */
template <typename ItemType>
ItemType Sort<ItemType>::PickPivot(const List<ItemType>& list, int lowIndex, int highIndex ) {
    int median;

    median = lowIndex+(highIndex-lowIndex)/2;
    ItemType newList;

  list.Get(median,newList);
    return newList;
    assert(false);
}

/**
 * Called by QuickSort to find the partition point for recursive
 * calls to sort the left and the right halves of the array
 * @param list to sort
 * @param lowIndex first element of range for sorting
 * @param highIndex last element of range for sorting
 * @param pivot
 * @param left receives the final value of "left" which is the first index of the right subarray
 * @param right receives the final value of "right" which is the last index of the left subarray
 */
template <typename ItemType>
void Sort<ItemType>::Partition(List<ItemType>& list, int lowIndex, int highIndex, ItemType pivot, int& left, int& right) {

//ItemType median= PickPivot(list,lowIndex,highIndex);
left=lowIndex;
right=highIndex;
int lowVal;
int highVal;
int temp;

while(right>left) {
    list.Get(left,lowVal);
    list.Get(right,highVal);
    while (lowVal < pivot) {
        left++;
        list.Get(left,lowVal);
    }
    while (highVal>pivot) {
        right--;
        list.Get(right,highVal);
    }
    if (left <= right)  {
        list.Swap(left,right);
        left++;
        right--;
       /* temp = lowVal;
        lowVal = highVal;
        highVal= temp;
        left++;
        right--;*/
    }
}
list.Get(left,lowVal);
list.Get(right,highVal);
    if(lowVal==pivot){
        left++;
        list.Get(left,lowVal);
        while(lowVal<pivot) {
            left++;
            list.Get(left,lowVal);
        }
    }

    if(highVal==pivot) {
        right--;
        list.Get(right,highVal);
        while(highVal>pivot ) {
            right--;
            list.Get(right,highVal);
        }
    }
    //return highIndex;
//  assert(false);
}

/**
 * Helper function for merge sort
 * Recursively sorts two halves of list, then merges those two lists
 * The auxillary list aux is use for the merging process
 * @param list to sort
 * @param aux auxillary array
 * @param left first element of range for sorting
 * @param right last element of range for sorting
 */
template <typename ItemType>
void Sort<ItemType>::DoMergeSort(List<ItemType>& list, ItemType* aux, int left, int right) {

    assert(false);
}

/**
 * Helper function for merge sort
 * Sorted merge of two sorted lists.
 * First list in positions left to center
 * Second list in positions center+1 to right
 * The auxillary list aux is used for the merging process
 * @param list we are sorting
 * @param aux auxillary array
 * @param left first element of range
 * @param center last element of first list
 * @param right last element of range for sorting
 */
template <typename ItemType>
void Sort<ItemType>::MergeSortedLists(List<ItemType>& list, ItemType* aux, int lowIndex, int left, int center, int right) {
}


#endif //SORTING_H
