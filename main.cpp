#include "FileReader.h"
#include "Node.h"
using namespace std;

void HeapSort(vector<Node*>& data);
void Heapify(vector<Node*>& data, int size, int parent);

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
