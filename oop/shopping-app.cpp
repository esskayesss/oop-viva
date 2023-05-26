#include <iostream>
#include <vector>

using namespace std;

class ListEntry {
    private:
        int code;
        float price;

    public:
        ListEntry(int code, float price){
            this->code = code;
            this->price = price;
        }

        int getCode(){
            return code;
        }

        float getPrice(){
            return price;
        }
};

class ShoppingList {
    private:
        vector<ListEntry *> list;

    public:
        void addItem(int code, float price){
            list.push_back(new ListEntry(code, price));
        }

        void deleteItem(int code){
            for(int i = 0; i < list.size(); i++)
                if(code == list.at(i)->getCode()){
                    list.erase(list.begin() + i);
                    return;
                }
        }

        void displayList(){
            for(ListEntry *e: list)
                cout << e->getCode() << " - " << e->getPrice() << "\n";
        }

        float totalPrice(){
            float total = 0;
            for(ListEntry *e: list)
                total += e->getPrice();

            return total;
        }
};


void displayMenu(){
    cout << "menu.\n1. add an item.\n2. delete an item.\n3. display the shopping list.\n4. calculate the total price of the list.\ninput any other character to exit the program.\n";
}

int main(){
    ShoppingList list;

    char choice;
    int code;
    float price;
    do{
        displayMenu();
        cout << "enter your choice: ";
        cin >> choice;

        switch(choice){
            case '1':
                cout << "enter the code and price: ";
                cin >> code >> price;
                list.addItem(code, price);
                break;
            case '2':
                cout << "enter the code of the item to delete: ";
                cin >> code;
                list.deleteItem(code);
                break;
            case '3':
                list.displayList();
                break;
            case '4':
                cout << "the total price of the list is " << list.totalPrice() << endl;
                break;
            default:
                cout << "thanks for using the program..." << endl;
                return 0;
        }
    } while(1);
}
