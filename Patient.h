//
// Created by Nichlos Ho on 10/30/20.
//

#ifndef PROJECT4_PATIENT_H
#define PROJECT4_PATIENT_H
#include <string>

/**
 * this class holds all patient information
 */
class Patient {
public:
    /**
     * priority codes to determine importance of each client
     */
    enum priority{IMMEDIATE = 1, EMERGENCY = 2, URGENT = 3, MINIMAL = 4};

    /**
     * constructor for patient
     * @param name of patient
     * @param priorityCode from enum
     */
    Patient(std::string name, priority priorityCode);

    /**
     * Compares patient A and B and return a negative integer if this patient should be seen first,
     * or positive otherwise. Use this method in the PatientPriorityQueue class
     * @param b patient
     * @param a patient
     * @return the highest priority
     */
    static Patient compareTo(Patient &b, Patient &a);

    /**
     * method that returns the string representation of the object
     * @return string representation of the object
     */
    std::string toString();

    /**
     * retrieves the name of the patient
     * @return name
     */
    std::string getName();
private:
    /**
     * A counter that track the total number of patients
     */
    static int counter;

    /**
     * name of the patient in string
     */
    std::string name;

    /**
     * Arrival order of each patient. This is assigned by the counter variable
     */
    int arrivalOrder = 0;

    /**
     * Variable to store the enum priority code of each patient
     */
    priority priorityCode;
};


#endif //PROJECT4_PATIENT_H
