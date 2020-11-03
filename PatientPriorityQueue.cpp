//
// Created by Nichlos Ho on 10/30/20.
//
#include <algorithm>
#include "PatientPriorityQueue.h"

PatientPriorityQueue::PatientPriorityQueue() = default;


void PatientPriorityQueue::enqueue(const Patient& newItem) {
    data.push_back(newItem);
    percolateUp(data.size() - 1);
}

const Patient &PatientPriorityQueue::peek() const {
    return data.front();
}

int PatientPriorityQueue::size() {
    return data.size();
}


void PatientPriorityQueue::percolateUp(int index) {
    if (index > 0) {
        int p = getParent(index); // getParent index
        Patient temp = Patient::compareTo(data[index], data[p]);
        if (temp.toString() == data[index].toString()) {
            std::swap(data[index], data[p]);
            percolateUp(p);
        }
    }
}

int PatientPriorityQueue::getParent(int child) {
    return (child - 1) / 2;
}

Patient PatientPriorityQueue::getData(int index) {
    return data.at(index);
}

Patient PatientPriorityQueue::dequeue() {
    Patient ret = peek();
    data[0] = data.back();
    data.pop_back();
    percolateDown(0);
    return ret;
}

void PatientPriorityQueue::percolateDown(int index) {
    int l = getLeft(index);
    int r = getRight(index);

    if (size() == 2) {
        Patient temp = Patient::compareTo(data[l], data[index]); // returns the high priority of l or r
        if (temp.toString() == data[l].toString()) {
            std::swap(data[index], data[l]);
            return;
        }
        return;
    }

    if (l >= size())
        return;

    Patient temp = data[l];
    if (l < size() && r < size()) {
        temp = Patient::compareTo(data[l], data[r]);
    }// returns the high priority of l or r
    Patient temp2 = Patient::compareTo(temp, data[index]); // return the higher priority between temp and index (parent)
    if (temp2.toString() == data[l].toString()) {
        std::swap(data[index], data[l]);
        percolateDown(l);
    }
    if (temp2.toString() == data[r].toString()) {
        std::swap(data[index], data[r]);
        percolateDown(r);
    }
}

int PatientPriorityQueue::getRight(int index) {
    return 2 * index + 2;
}

int PatientPriorityQueue::getLeft(int index) {
    return 2 * index + 1;
}
