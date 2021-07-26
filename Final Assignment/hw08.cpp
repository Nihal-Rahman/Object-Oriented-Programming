#include <iostream>
#include <vector>

using namespace std;

class Polynomial{
    friend ostream& operator<<(ostream& os, const Polynomial& polynomial);

    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
private:
    struct Node{
        Node(int data = 0, Node* next = nullptr):data(data), next(next){}

        int data;
        Node* next;
    };

    void clear();

    void cleanUp();

    Node* coeff;
    size_t degree;
public:
    Polynomial(const vector<int>& coefficients);

    Polynomial();

    Polynomial& operator=(const Polynomial& rhs);

    ~Polynomial();

    Polynomial(const Polynomial& rhs);

    int evaluate(int value);

    Polynomial& operator+=(const Polynomial& poly2);


};

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
void doNothing(Polynomial temp) {}

int main() {
    //test constructor
    Polynomial p1({17});                 // 17
    Polynomial p2({1, 2});               // x + 2
    Polynomial p3({-1, 5});              // -1x + 5
    Polynomial p4({5, 4, 3, 2, 1});      // 5x^4 + 4x^3 + 3x^2 + 2x + 1
    Polynomial has_a_zero({4, 0, 1, 7}); // 4x^3 + x + 7

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
    cout << "has_a_zero: " << has_a_zero << endl;
    cout << "p2 + p3: " << (p2+p3) << endl;
    cout << "p2 + p4: " << (p2+p4) << endl;
    cout << "p4 + p2: " << (p4+p2) << endl;


    //test copy constructor - the statement below uses the copy constructor
    //to initialize poly3 with the same values as poly4

    Polynomial p5(p4);
    p5 += p3;
    cout << "Polynomial p5(p4);\n"
         << "p5 += p3;\n";

    cout << "p4: " << p4 << endl;
    cout << "p5: " << p5 << endl;

    cout << "Calling doNothing(p5)\n";
    doNothing(p5);
    cout << "p5: " << p5 << endl;


    //tests the assignment operator

    Polynomial p6;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;  // Causes bools true and false to be printed that way.
    cout << "(p4 == p6) is " << (p4 == p6) << endl;
    p6 = p4;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;
    cout << "(p4 == p6) is " << (p4 == p6) << endl;


    //test the evaluaton
    int x = 5;
    cout << "Evaluating p1 at " << x << " yields: " << p1.evaluate(5) << endl;
    cout << "Evaluating p2 at " << x << " yields: " << p2.evaluate(5) << endl;

    Polynomial p7({3, 2, 1});           // 3x^2 + 2x + 1
    cout << "p7: " << p7 << endl;
    cout << "Evaluating p7 at " << x << " yields: " << p7.evaluate(5) << endl;

    cout << boolalpha;
    cout << "(p1 == p2) is " << (p1 == p2) << endl;
    cout << "(p1 != p2) is " << (p1 != p2) << endl;



    /*=================================================================
    NEW TEST CODE - test if cleaning the leading 0s
    ===================================================================*/

    Polynomial p8({ 1, 1 });
    Polynomial p9({ -1, 1 });
    Polynomial p10({ 0, 0, 2 });
    //p8 + p9 tests if += does the cleanup()
    //p10 tests if constructor does the cleanup()
    cout << boolalpha;
    cout << "((p8 + p9) == p10) is " << ((p8 + p9) == p10) << endl;
    cout << endl;

    return 0;
}


//definition of friend functions
ostream& operator<<(ostream& os, const Polynomial& polynomial){
    Polynomial::Node* node = polynomial.coeff;
    size_t count = polynomial.degree;
    while(count > 0){
        if(node->data == -1){
            os << "-x";
        }
        else if(node->data == 1){
            os << "x";
        }
        else if(node->data > 1){
            os << node->data << "x";
        }
        else if(node->data < -1){
            os << node->data * -1 << "x";
        }
        if(count > 1 && node->data != 0){
            os << "^" << count;
        }
        if(node->data != 0){
            if(node->next->data > 0){
                os << " + ";
            }
            else{
                os << " - ";
            }
        }
        count--;
        node = node->next;
    }
    if(node->data > 0){
        cout << node->data << endl;
    }
    else{
        cout << node->data * -1 << endl;
    }
    return os;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs){
    if(lhs.degree == rhs.degree){
        Polynomial::Node* poly1 = lhs.coeff;
        Polynomial::Node* poly2 = rhs.coeff;
        while(poly1!= nullptr && poly2 != nullptr){
            if(poly1->data != poly2->data){
                return false;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        return true;
    }
    return false;
}

//constructors + big 3
Polynomial::Polynomial(const vector<int> &coefficients):coeff(nullptr),degree(coefficients.size()-1) {
        coeff= new Node(coefficients[0]);
        Node* temp = coeff;
        for(size_t i = 1; i < coefficients.size(); ++i){
            Node* next = new Node(coefficients[i]);
            temp->next = next;
            temp = temp->next;
        }
        cleanUp();
}

Polynomial::Polynomial():coeff(new Node),degree(0){}

Polynomial & Polynomial::operator=(const Polynomial &rhs) {
    if (this != &rhs) {
        clear();
        coeff = new Node(rhs.coeff->data);
        Node* rhs_node = rhs.coeff->next;
        Node* lhs = coeff;
        while (rhs_node != nullptr) {
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
    clear();
}

Polynomial::Polynomial(const Polynomial &rhs):coeff(nullptr), degree(rhs.degree){
    coeff = new Node(rhs.coeff->data);
    Node* rhs_node= rhs.coeff->next;
    Node* lhs = coeff;
    while(rhs_node != nullptr){
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
    while(node != nullptr){
        if(exponent == 0){
            return node->data + result;
        }
        if(exponent == 1){
            result = result + (val * node->data);
            exponent --;
            node = node->next;
        }
        else{
            while (exponent > 1){
                val = val * value;
                exponent = exponent - 1;
            }
            result = result + (val * node->data);
            val = value;
            node = node->next;
        }
    }


    return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& poly2) {
    Node* lhs = coeff;
    Node* rhs = poly2.coeff;
    if(degree > poly2.degree){
        size_t diff = degree - poly2.degree;
        for(size_t i = 0; i < diff; ++i){
            lhs = lhs->next;
        }
    }
    else if(poly2.degree > degree){
        size_t diff = poly2.degree - degree;
        for(size_t i = 0; i < diff; ++i){
            Node* newcoeff = new Node;
            newcoeff->next = coeff;
            coeff = newcoeff;
            degree++;
        }
        lhs = coeff;
    }
    while(lhs != nullptr){
        lhs->data = lhs->data + rhs->data;
        lhs = lhs->next;
        rhs = rhs->next;
    }
    cleanUp();
    return *this;
}

//definitions of methods in private


void Polynomial::clear(){
    Node* p = coeff;
    coeff = nullptr;
    while(p != nullptr){
        Node* next = p->next;
        delete p;
        p = next;
    }
    degree = 0;
}


void Polynomial::cleanUp() {
    while(coeff != nullptr && coeff->data == 0){
        Node* next = coeff->next;
        delete coeff;
        coeff = next;
        degree--;
    }
}

//definition of functions
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
    Polynomial result = lhs;
    return result+=rhs;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs){
    return !(lhs == rhs);
}