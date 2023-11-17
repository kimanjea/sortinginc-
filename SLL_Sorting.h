//
// Implementation of methods for sorting singly linked lists
// Author: Max Benson
// Modified by: 
// Date: 09/10/2021
// Modification Date: 
//

#ifndef SLL_SORTING_H
#define SLL_SORTING_H

/**
 * Perform insertion sort on a linked list
 */
template <typename ItemType>
void SinglyLinkedList<ItemType>::InsertionSort() {
    assert(false);
}

/**
 * Perform selection sort on a linked list
 */
template <typename ItemType>
void SinglyLinkedList<ItemType>::SelectionSort() {
    assert(false);
}

/**
 * Perform merge sort on a linked list
 */
template <typename ItemType>
void SinglyLinkedList<ItemType>::MergeSort() {

   _head= DoMergeSort(_head,this->_size);
}

/**
 * Recursive merge sort routine
 * @param chain - linked chain of nodes to sort
 * @param length - number of nodes in chain
 */
template <typename ItemType>
typename SinglyLinkedList<ItemType>::Node* SinglyLinkedList<ItemType>::DoMergeSort(Node* chain, size_t length) {
    Node* first;
    Node* second;
    int position;
    int position2;
    position=length/2;
    position2=length-position;

    if( length>1){

    SplitIntoTwo(chain,position,&first, &second);
    first=DoMergeSort(first,position);
    second=DoMergeSort(second,position2);

    return MergeSortedLists(first,second);
    } else {
            return chain;
    }

    //assert(false);
}

/**
 * Break a chain of nodes into two chains
 * @param ptr - start of linked chain of nodes 
 * @param position - position to break the chain
 * @param first - receives a pointer to a chain of nodes at positions 0 to position-1
 * @param second - receives a pointer to a chain of nodes at positions position through the end
 */
template <typename ItemType>
void SinglyLinkedList<ItemType>::SplitIntoTwo(Node* ptr, size_t position, Node** first, Node** second) {


    if(position==0) {
        *first=nullptr;
        *second=ptr;
    } else {
        *first=ptr;
        for (size_t i = 0; i < position - 1; i++) {
            ptr=ptr->next;
        }

        *second=ptr->next;
        ptr->next= nullptr;
    }
}

/**
 * Returns sorted merge of two sorted chains of nodes
 * @param first - receives a pointer to a sorted chain of  of nodes
 * @param second - receives a pointer to a sorted chain of nodes
 * @return sorted merge of two linked lists
 */
template <typename ItemType>
typename SinglyLinkedList<ItemType>::Node* SinglyLinkedList<ItemType>::MergeSortedLists(Node* first, Node* second) {
    Node* final=nullptr;

    if(first== nullptr) {
        return (second);

    }else if (second== nullptr){

        return (first);
    }

    if(first->item <= second->item){

        final=first;
        final->next= MergeSortedLists(first->next,second);

    } else{

    final= second;
    final->next= MergeSortedLists(first,second->next);

    }

    return (final);
}

#endif //SLL_SORTING_H
