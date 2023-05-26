#include <iostream>

using namespace std;

class Account
{
protected:
    float balance;
    long ac_number;
    string ac_holder_name;
    string ifsc_code;
    string bank_name;

public:
    Account(long ac_number, string ac_holder_name, string ifsc_code, string bank_name);
    void deposit(float amount);
    void withdraw(float amount);
    long get_ac_number();
    string get_ac_holder_name();
    string get_ifsc_code();
    string get_bank_name();
    void display();
};

Account::Account(long ac_number, string ac_holder_name, string ifsc_code, string bank_name)
{
    this->balance = 0;
    this->ac_number = ac_number;
    this->ac_holder_name = ac_holder_name;
    this->ifsc_code = ifsc_code;
    this->bank_name = bank_name;
}

long Account::get_ac_number()
{
    return this->ac_number;
}

string Account::get_ac_holder_name()
{
    return this->ac_holder_name;
}

string Account::get_ifsc_code()
{
    return this->ifsc_code;
}

string Account::get_bank_name()
{
    return this->bank_name;
}

void Account::deposit(float amount)
{
    this->balance += amount;
}

void Account::withdraw(float amount)
{
    if (amount > this->balance)
    {
        cout << "Insufficient balance" << endl;
    }
    else
    {
        this->balance -= amount;
    }
}

void Account::display()
{
    cout << "Account Number: " << this->ac_number << endl;
    cout << "Account Holder Name: " << this->ac_holder_name << endl;
    cout << "IFSC Code: " << this->ifsc_code << endl;
    cout << "Bank Name: " << this->bank_name << endl;
}

class SavingsAccount : public Account
{
protected:
    float interest_rate;

public:
    SavingsAccount(float interest_rate, long ac_number, string ac_holder_name, string ifsc_code, string bank_name);
    void add_interest();
    void display();
};

SavingsAccount::SavingsAccount(float interest_rate, long ac_number, string ac_holder_name, string ifsc_code, string bank_name) : Account(ac_number, ac_holder_name, ifsc_code, bank_name)
{
    this->interest_rate = interest_rate;
};

void SavingsAccount::add_interest()
{
    this->balance += this->balance * this->interest_rate / 100;
}

void SavingsAccount::display()
{
    Account::display();
    cout << "Interest Rate: " << this->interest_rate << endl;
}

class CurrentAccount : public Account
{
protected:
    float overdraft_limit;

public:
    CurrentAccount(float overdraft_limit, long ac_number, string ac_holder_name, string ifsc_code, string bank_name);
    void withdraw(float amount);
    void display();
};

CurrentAccount::CurrentAccount(float overdraft_limit, long ac_number, string ac_holder_name, string ifsc_code, string bank_name) : Account(ac_number, ac_holder_name, ifsc_code, bank_name)
{
    this->overdraft_limit = overdraft_limit;
};

void CurrentAccount::withdraw(float amount)
{
    if (amount > this->balance + this->overdraft_limit)
    {
        cout << "Insufficient balance" << endl;
    }
    else
    {
        this->balance -= amount;
    }
}

void CurrentAccount::display()
{
    Account::display();
    cout << "Overdraft Limit: " << this->overdraft_limit << endl;
}

class FixedDeposit : public Account
{
protected:
    float interest_rate;
    int tenure;
    int months_passed;

public:
    FixedDeposit(float interest_rate, int tenure, long ac_number, string ac_holder_name, string ifsc_code, string bank_name);
    void add_interest();
    void display();
};

FixedDeposit::FixedDeposit(float interest_rate, int tenure, long ac_number, string ac_holder_name, string ifsc_code, string bank_name) : Account(ac_number, ac_holder_name, ifsc_code, bank_name)
{
    this->interest_rate = interest_rate;
    this->tenure = tenure;
    this->months_passed = 0;
};

void FixedDeposit::add_interest()
{
    this->months_passed++;
    if (this->months_passed == this->tenure)
    {
        this->balance += this->balance * this->interest_rate / 100;
    }
}

void FixedDeposit::display()
{
    Account::display();
    cout << "Interest Rate: " << this->interest_rate << endl;
    cout << "Tenure: " << this->tenure << endl;
    cout << "Months Passed: " << this->months_passed << endl;
}

class ShortTermFixedDeposit : public FixedDeposit
{
protected:
    float penalty_rate;

public:
    ShortTermFixedDeposit(float penalty_rate, float interest_rate, int tenure, long ac_number, string ac_holder_name, string ifsc_code, string bank_name);
    void withdraw(float amount);
    void display();
};

ShortTermFixedDeposit::ShortTermFixedDeposit(float penalty_rate, float interest_rate, int tenure, long ac_number, string ac_holder_name, string ifsc_code, string bank_name) : FixedDeposit(interest_rate, tenure, ac_number, ac_holder_name, ifsc_code, bank_name)
{
    this->penalty_rate = penalty_rate;
};

void ShortTermFixedDeposit::withdraw(float amount)
{
    if (this->months_passed < 6)
    {
        this->balance -= amount + amount * this->penalty_rate / 100;
    }
    else
    {
        this->balance -= amount;
    }
}

void ShortTermFixedDeposit::display()
{
    FixedDeposit::display();
    cout << "Penalty Rate: " << this->penalty_rate << endl;
}

class LongTermFixedDeposit : public FixedDeposit
{
protected:
    float bonus_rate;

public:
    LongTermFixedDeposit(float bonus_rate, float interest_rate, int tenure, long ac_number, string ac_holder_name, string ifsc_code, string bank_name);
    void add_interest();
    void display();
};

LongTermFixedDeposit::LongTermFixedDeposit(float bonus_rate, float interest_rate, int tenure, long ac_number, string ac_holder_name, string ifsc_code, string bank_name) : FixedDeposit(interest_rate, tenure, ac_number, ac_holder_name, ifsc_code, bank_name)
{
    this->bonus_rate = bonus_rate;
};

void LongTermFixedDeposit::add_interest()
{
    if (this->months_passed == this->tenure)
    {
        this->balance += this->balance * this->bonus_rate / 100;
    }
}

void LongTermFixedDeposit::display()
{
    FixedDeposit::display();
    cout << "Bonus Rate: " << this->bonus_rate << endl;
}

class MediumTermFixedDeposit : public FixedDeposit
{
protected:
    float bonus_rate;

public:
    MediumTermFixedDeposit(float bonus_rate, float interest_rate, int tenure, long ac_number, string ac_holder_name, string ifsc_code, string bank_name);
    void add_interest();
    void display();
};

MediumTermFixedDeposit::MediumTermFixedDeposit(float bonus_rate, float interest_rate, int tenure, long ac_number, string ac_holder_name, string ifsc_code, string bank_name) : FixedDeposit(interest_rate, tenure, ac_number, ac_holder_name, ifsc_code, bank_name)
{
    this->bonus_rate = bonus_rate;
};

void MediumTermFixedDeposit::add_interest()
{
    if (this->months_passed == this->tenure)
    {
        this->balance += this->balance * this->bonus_rate / 100;
    }
}

void MediumTermFixedDeposit::display()
{
    FixedDeposit::display();
    cout << "Bonus Rate: " << this->bonus_rate << endl;
}

int main()
{
    SavingsAccount s1(5, 123456789, "John", "IFSC123", "SBI");
    s1.deposit(10000);
    s1.add_interest();
    s1.display();
    cout << endl;

    CurrentAccount c1(10000, 123456789, "John", "IFSC123", "SBI");
    c1.deposit(10000);
    c1.withdraw(20000);
    c1.display();
    cout << endl;

    ShortTermFixedDeposit sfd1(5, 5, 12, 123456789, "John", "IFSC123", "SBI");
    sfd1.deposit(10000);
    sfd1.add_interest();
    sfd1.withdraw(1000);
    sfd1.display();
    cout << endl;

    LongTermFixedDeposit lfd1(5, 5, 12, 123456789, "John", "IFSC123", "SBI");
    lfd1.deposit(10000);
    lfd1.add_interest();
    lfd1.display();
    cout << endl;

    MediumTermFixedDeposit mfd1(5, 5, 12, 123456789, "John", "IFSC123", "SBI");
    mfd1.deposit(10000);
    mfd1.add_interest();
    mfd1.display();
    cout << endl;

    return 0;
}