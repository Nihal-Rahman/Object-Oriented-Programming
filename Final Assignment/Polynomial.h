//Author: Nihal Rahman
//File Name: Polynomial.h
//Code Functionality: Header file containing the Polynomial class with its methods and fields and its related functions
#ifndef HW08_POLYNOMIAL_H
#define HW08_POLYNOMIAL_H

#include <iostream>
#include <vector>

class Polynomial{
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial); //output operator for the polynomial class marked as a friend

    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);// equal equal operator for the polynomial class marked as a friend
private:
    struct Node{ //node struct which will be used for the linked list
        Node(int data = 0, Node* next = nullptr); //constructor for Node struct

        int data;
        Node* next;
    };

    void clear(); //clears all the coefficients in the linked list

    void cleanUp(); //removes all the preceeding zeros in the beginning of the list

    Node* coeff;
    size_t degree;
public:
    Polynomial(const std::vector<int>& coefficients); //constructor for the Polynomial class when a vector is passed in

    Polynomial(); //default constructor

    Polynomial& operator=(const Polynomial& rhs); //assignment operator for the Polynomial class

    ~Polynomial(); //destructor for the Polynomial class

    Polynomial(const Polynomial& rhs); //copy constructor for the Polynomial class

    int evaluate(int value); //evaluates the polynomial equation with the inputted value and returns the result

    Polynomial& operator+=(const Polynomial& poly2); // += operator for the Polynomial class


};

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs); //+ operator for the Polynomial class
bool operator!=(const Polynomial& lhs, const Polynomial& rhs); // != operator for the Polynomial class
void doNothing(Polynomial temp); //doNothing function which calls the Copy constructor

#endif //HW08_POLYNOMIAL_H
