//
// Created by Nichlos Ho on 10/30/20.
//

#ifndef PROJECT4_PATIENTPRIORITYQUEUE_H
#define PROJECT4_PATIENTPRIORITYQUEUE_H
#include <vector>
#include <algorithm>
#include "Patient.h"

/**
 * This class holds a vector of patients in a min heap order.
 */

class PatientPriorityQueue {
public:
    /**
     * default zero arg constructor
     */
    PatientPriorityQueue();  // zero-arg constructor

    /**
     * Adds patient to the back of the vector and will call percolateUp(int inedx) to heapify
     * @param newItem patient object
     */
    void enqueue(const Patient& newItem);

    /**
     * Removes the highest priority patient from the queue and returns it. It will then call percolateDown
     * @return the patient removed
     */
    Patient dequeue();

    /**
     * Returns the highest priority patient without removing it.
     * @return root
     */
    const Patient &peek() const;

    /**
     * Returns the number of patients still waiting.
     * @return size
     */
    int size();

    /**
     * retrieve the data of the patient such as name, priority code and order number.
     * mainly used to toString patient details in main
     * @param index of the vector
     * @return patient at the index
     */
    Patient getData(int index);

private:
    /**
     * vector of patients. Will be stored in a min heap order
     */
    std::vector<Patient> data;

    /**
     * re-heapify upwards after a patient was added
     * @param index
     */
    void percolateUp(int index);

    /**
     * calculate the parent index of the child given in the parameter
     * @param child
     * @return parent index
     */
    static int getParent(int child);

    /**
     * re-heapify downwards after a patient was removed
     * @param index
     */
    void percolateDown(int index);

    /**
     * calculate the right index of the parent given in the parameter
     * @param index
     * @return right index
     */
    static int getRight(int index);

    /**
     * calculate the right index of the parent given in the parameter
     * @param index
     * @return left index
     */
    static int getLeft(int index);
};


#endif //PROJECT4_PATIENTPRIORITYQUEUE_H
