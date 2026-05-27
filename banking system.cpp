#include<iostream>
using namespace std;

class Transaction{
public:
    string type;
    float amount;

    Transaction(){
        type = "";
        amount = 0;
    }
};

class Account{
public:
    int accountNo;
    float balance;
    Transaction history[10];
    int count;

    Account(){
        accountNo = 0;
        balance = 0;
        count = 0;
    }

    void createAccount(int accNo, float bal){
        accountNo = accNo;
        balance = bal;

        cout << "Account Created Successfully" << endl;
    }

    void deposit(float amt){
        balance = balance + amt;

        history[count].type = "Deposit";
        history[count].amount = amt;
        count++;

        cout << "Amount Deposited" << endl;
    }

    void withdraw(float amt){
        if(amt > balance){
            cout << "Insufficient Balance" << endl;
            return;
        }

        balance = balance - amt;

        history[count].type = "Withdraw";
        history[count].amount = amt;
        count++;

        cout << "Amount Withdrawn" << endl;
    }

    void transfer(Account &a, float amt){
        if(amt > balance){
            cout << "Insufficient Balance" << endl;
            return;
        }

        balance = balance - amt;
        a.balance = a.balance + amt;

        history[count].type = "Transfer";
        history[count].amount = amt;
        count++;

        cout << "Transfer Successful" << endl;
    }

    void displayTransactions(){
        cout << "Transaction History" << endl;

        for(int i = 0; i < count; i++){
            cout << history[i].type << " : " << history[i].amount << endl;
        }
    }

    void displayInfo(){
        cout << "Account Number: " << accountNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Customer{
public:
    string name;
    Account acc;

    void createCustomer(string n, int accNo, float bal){
        name = n;
        acc.createAccount(accNo, bal);
    }

    void displayCustomer(){
        cout << "Customer Name: " << name << endl;
        acc.displayInfo();
    }
};

int main(){
    Customer c1, c2;

    c1.createCustomer("Ali",101, 5000);
    c2.createCustomer("Ahmed",102, 3000);
    cout << endl;
    c1.displayCustomer();
    cout << endl;
    c1.acc.deposit(2000);
    c1.acc.withdraw(1000);
    c1.acc.transfer(c2.acc, 1500);
    cout << endl;
    c1.displayCustomer();
    cout << endl;
    c1.acc.displayTransactions();

    return 0;
}
