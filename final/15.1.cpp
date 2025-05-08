#include<iostream>
#include<string>
using namespace std;

class Employee {

    private:

        string name;
        int num;
        string hireDate;

    public:

        Employee() {

            cout<<"Default employee constructor called";
        }

        Employee(string name, int num, string hireDate) : name(name), num(num), hireDate(hireDate) {

            cout<<"Employee constructor called";
        }

        string getName() {
            return name;
        }

        int getNum() {
            return num;
        }

        string getHireDate() {
            return hireDate;
        }

        void setName(string name) {
            this->name = name;
        }

        void setNum(int num) {
            this->num = num;
        }

        void setHireDate(string hireDate) {
            this->hireDate = hireDate;
        }
};

class ProductionWorker : public Employee {


    private:
        int shift;
        double pay;

    public:

        ProductionWorker() : Employee("", 0, "") {

            cout<<"Default production worker constructor called";
        }

        ProductionWorker(int shift, double pay) : shift(shift), pay(pay) {

            cout<<"Production Worker constructor called";
        }

        ProductionWorker(string name, int num, string hireDate, int shift, double pay) : Employee(name, num, hireDate), shift(shift), pay(pay) {

            cout<<"Production Worker with Employee info constrtuctor called";
        }

        void setShift(int shift) {
            this->shift = shift;
        }

        void setPay(double pay) {
            this->pay = pay;
        }

        int getShift() {
            return shift;
        }

        double getPay() {
            return pay;
        }
};

int main() {

    ProductionWorker josh("Josh", 125, "May 5th 2025", 1, 23.50);

    cout<<"Printing information on employee #" <<josh.getNum()<<endl;

    cout<<"Name: "<<josh.getName()<<endl;
    cout<<"Hire Date: "<<josh.getHireDate()<<endl;
    cout<<"Shift: ";
    if (josh.getShift() == 1)
        cout<<"Day"<<endl;
    else
        cout<<"Night"<<endl;

    cout<<"Pay Rate: "<<josh.getPay()<<endl;
}