//Author: Nihal Rahman
//File Name: Polynomial.cpp
//Code Functionality: All the definitions for the functions and methods in the
//                    header file of "Polynomial.h" are defined here

#include <iostream>
#include <vector>
#include "Polynomial.h"

using namespace std;

//definition of friend functions
ostream& operator<<(ostream& os, const Polynomial& polynomial){
    Polynomial::Node* node = polynomial.coeff;
    size_t count = polynomial.degree;
    while(count > 0){
        if(node->data == -1){ //checks if the coefficient is -1
            os << "-x";
        }
        else if(node->data == 1){ //checks if the coefficient is 1
            os << "x";
        }
        else if(node->data > 1){ //checks if the coefficient is greater than 1
            os << node->data << "x";
        }
        else if(node->data < -1){ //checks if the coefficient is less than -1
            os << node->data * -1 << "x";
        }
        if(count > 1 && node->data != 0){ //checks if the degree of the polynomial is greater than 1 and the coefficient is not 0
            os << "^" << count;
        }
        if(node->next->data > 0){ //checks if the next coefficient is greater than zero
            os << " + ";
        }
        else if(node->next->data < 0){ //else the next coefficient is less than zero
            os << " - ";
        }
        count--; //decrease the degree
        node = node->next; //go to the next coefficient
    }
    if(node->data > 0){ //checks if the coefficient of the 0 degree is greater than 0
        cout << node->data << endl;
    }
    else{
        cout << node->data * -1 << endl;
    }
    return os;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs){
    if(lhs.degree == rhs.degree){ //checks if the degrees for both polynomials are the same
        Polynomial::Node* poly1 = lhs.coeff;
        Polynomial::Node* poly2 = rhs.coeff;
        while(poly1!= nullptr && poly2 != nullptr){ //do everything in the while loop as long as neither nodes are nullptrs
            if(poly1->data != poly2->data){ //checks if the coefficients are not equal
                return false;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        return true; //return true is all the coefficients are equal along with the degrees
    }
    return false; //if the degrees aren't equal then return false
}

//constructors + big 3
Polynomial::Polynomial(const vector<int> &coefficients):coeff(nullptr),degree(coefficients.size()-1) {
    coeff= new Node(coefficients[0]);
    Node* temp = coeff;
    for(size_t i = 1; i < coefficients.size(); ++i){ //for loop going through the vector of coefficients
        Node* next = new Node(coefficients[i]);
        temp->next = next;
        temp = temp->next;
    }
    cleanUp(); //clean up any leadings 0s
}

Polynomial::Polynomial():coeff(new Node),degree(0){} //creates a polynomial 0

Polynomial & Polynomial::operator=(const Polynomial &rhs) {
    if (this != &rhs) { //checks if the memory addresses of the polynomials are not equal
        clear();
        coeff = new Node(rhs.coeff->data); //set the first coeff to the first coeff of the rhs polynomial and create it on the heap
        Node* rhs_node = rhs.coeff->next;
        Node* lhs = coeff;
        while (rhs_node != nullptr) { //go through the coefficients of the rhs as long as the pointer isn't nullptr
            Node *next = new Node(rhs_node->data);
            lhs->next = next;
            lhs = next;
            rhs_node = rhs_node->next;
        }
        degree = rhs.degree;
    }
    return *this;
}

Polynomial::~Polynomial(){
    clear(); //clear all the polynomials in the linked list
}

Polynomial::Polynomial(const Polynomial &rhs):coeff(nullptr), degree(rhs.degree){
    coeff = new Node(rhs.coeff->data);
    Node* rhs_node= rhs.coeff->next;
    Node* lhs = coeff;
    while(rhs_node != nullptr){ //while the rhs node is not a nullptr continue through the loop
        Node* next = new Node(rhs_node->data);
        lhs->next = next;
        lhs = next;
        rhs_node = rhs_node->next;
    }
}

//defition of public methods
int Polynomial::evaluate(int value) {
    int result = 0;
    int val = value;
    Node* node = coeff;
    size_t exponent = degree;
    while(node != nullptr){  //while the node is not a nullptr go through the loop
        if(exponent == 0){ //check if the exponent is 0
            return node->data + result;
        }
        if(exponent == 1){ //check is the exponent is 1
            result = result + (val * node->data);
            exponent --;
            node = node->next;
        }
        else{
            while (exponent > 1){ //while the exponent is greater than 1  do the following lines of code
                val = val * value;
                exponent = exponent - 1;
            }
            result = result + (val * node->data); //update the result
            val = value;
            node = node->next; //continue through the linked list
        }
    }


    return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& poly2) {
    Node* lhs = coeff;
    Node* rhs = poly2.coeff;
    if(degree > poly2.degree){ //check if the degree is bigger than the degree of the second polynomial
        size_t diff = degree - poly2.degree;
        for(size_t i = 0; i < diff; ++i){ //continue through the list until the degrees are the same
            lhs = lhs->next;
        }
    }
    else if(poly2.degree > degree){ //check if the second polynomial has a greater degree
        size_t diff = poly2.degree - degree;
        for(size_t i = 0; i < diff; ++i){ //for each polynomial in polynomial 2 not in this polynomial add them to the polynomial
            Node* newcoeff = new Node;
            newcoeff->next = coeff;
            coeff = newcoeff;
            degree++;
        }
        lhs = coeff;
    }
    while(lhs != nullptr){ //while the lhs node is not a nullptr
        lhs->data = lhs->data + rhs->data; //add the data together because the degrees are similar
        lhs = lhs->next;
        rhs = rhs->next;
    }
    cleanUp(); //clean up any leading zeros
    return *this;
}


void Polynomial::clear(){
    Node* p = coeff;
    coeff = nullptr;
    while(p != nullptr){ //while the pointer is not a nullptr delete it and set it to the next pointer
        Node* next = p->next;
        delete p;
        p = next;
    }
    degree = 0;
}


void Polynomial::cleanUp() {
    while(coeff != nullptr && coeff->data == 0){ //while the node is not a nullptr and has a coefficient of zero, remove it
        Node* next = coeff->next;
        delete coeff;
        coeff = next;
        degree--;
    }
}

//definition of functions
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
    Polynomial result = lhs;
    return result+=rhs; //use the += operator to conduct the + operator
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs){
    return !(lhs == rhs); //return the opposite of the value given by the == operator
}

void doNothing(Polynomial temp){} //literally do nothing

Polynomial::Node::Node(int data, Node *next):data(data),next(next){}