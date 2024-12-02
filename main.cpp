#include "FileReader.h"
#include "Node.h"
using namespace std;

void HeapSort(vector<Node*>& data);
void Heapify(vector<Node*>& data, int size, int parent);
void MergeSort(vector<Node*>& list, vector<Node*>& tempList, int start, int end);
void Merge(vector<Node*>& list, vector<Node*>& tempList, int start, int middle, int end);

int main() {
    FileReader file;
    vector<Node*> data = file.ReadFile("../GHCNh_USW00012816_por.psv");
    
    HeapSort(data);
    for (auto & node : data) {
        node->PrintNode();
    }

    return 0;
}

// Resource: Discussion 6 - Heaps & Priority Queues
void HeapSort(vector<Node*>& data) {
    int size = data.size();
    int startIndex = (size / 2) - 1;

    // Create a Heap from an Array in Place
    for (int i = startIndex; i >= 0; i--)
        Heapify(data, size, i);

    // Heap sort
    // i keeps track of end index, which we will use for size -> as the size of the vector will stay the same
    for (int i = size - 1; i > 0; i--) {
        // First swap root with new end index
        Node* temp = data[i];
        data[i] = data[0];
        data[0] = temp;

        // Now make sure new end is in correct place
        Heapify(data, i, 0);
    }
}

// Resource: Discussion 7 - Exam 1 Review Spring 2023
void Heapify(vector<Node*>& data, int size, int parent) {
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int maxIndex = parent;

    // If right is larger than maxIndex
    if (right < size && data[right]->getTemp() > data[maxIndex]->getTemp())
        maxIndex = right;

    // If left is larger than maxIndex
    if (left < size && (data[left]->getTemp() > data[maxIndex]->getTemp()))
        maxIndex = left;

    // If maxIndex is not the parent, swap and re-heapify
    if (maxIndex != parent) {
        Node* temp = data[maxIndex];
        data[maxIndex] = data[parent];
        data[parent] = temp;

        Heapify(data, size, maxIndex);
    }
}

// Reference: Lecture Merge Sort Code Trace (Module 8)
void MergeSort(vector<Node*>& list, vector<Node*>& tempList, int start, int end)
{
    if (start < end) // effectively if sublist.size > 1
    {
        int middle = start + (end - start) / 2;
        MergeSort(list, tempList, start, middle); // recursive call on left side
        MergeSort(list, tempList, middle + 1, end); // recursive call on right side

        Merge(list, tempList, start, middle, end); // combine left and right lists
    }
}
// Reference: Lecture Merge Sort Code Trace (Module 8)
void Merge(vector<Node*>& list, vector<Node*>& tempList, int start, int middle, int end)
{
    int indexL = start; // start index of left
    int indexR = middle + 1; // index start of right
    int current = start; // start index in the main vector

    while (indexL <= middle and indexR <= end) // while there are values in both lists
    {
        if (list[indexL]->getTemp() <= list[indexR]->getTemp()) // if left's value is smaller
        {
            tempList[current++] = list[indexL++]; // add appropriate value to the temporary list and increase the indices
        }
        else // if right's value is smaller
        {
            tempList[current++] = list[indexR++]; // change appropriate index's value to right's value and increase the indices
        }
    }

    while (indexL <= middle) // add what's left on the left (if anything)
    {
        tempList[current++] = list[indexL++];
    }
    while (indexR <= end) // add what's left on the right (if anything)
    {
        tempList[current++] = list[indexR++];
    }

    for (int i = start; i <= end; i++) // update list to match tempList
        list[i] = tempList[i];
}