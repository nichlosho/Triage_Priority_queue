//
// Created by Nichlos Ho on 10/30/20.
//

#include "Patient.h"
#include <sstream>
#include <utility>
using namespace std;
int Patient::counter;

Patient::Patient(std::string n, Patient::priority PC) {
    name = std::move(n);
    priorityCode = PC;
    counter++;
    arrivalOrder = counter;
}

Patient Patient::compareTo(Patient &a, Patient &b) {
    if (a.priorityCode - b.priorityCode < 0)
        return a;
    if (a.priorityCode - b.priorityCode == 0){
        if (a.arrivalOrder - b.arrivalOrder < 0){
            return a;
        }
        return b;
    }
    return b;
}

std::string Patient::toString() {
    ostringstream ss;
    ss << name << " { pri=";
    if (priorityCode == IMMEDIATE){
        ss << "IMMEDIATE";
    } else if (priorityCode == EMERGENCY){
        ss << "EMERGENCY";
    }else if (priorityCode == URGENT){
        ss << "URGENT";
    }else
        ss << "MINIMAL";

    ss << ", arrive=" << arrivalOrder << " }" << endl;
    return ss.str();
}

std::string Patient::getName() {
    return name;
}
