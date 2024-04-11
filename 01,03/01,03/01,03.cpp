#include <iostream>
#include <string>

using namespace std;

class Transport {
protected:
    string type;

public:
    Transport(string _type) : type(_type) {}

    virtual void displayInfo() {
        cout << "Тип транспортного засобу: " << type << endl;
    }

    virtual void fuelConsumption() = 0;
};

class Airplane : public Transport {
public:
    Airplane() : Transport("Самолет") {}

    void displayInfo() override {
        Transport::displayInfo();
    }

    void fuelConsumption() override {
        cout << "Розхід палива самолета" << endl;
    }
};

class Ship : public Transport {
public:
    Ship() : Transport("Судно") {}

    void displayInfo() override {
        Transport::displayInfo();
    }

    void fuelConsumption() override {
        cout << "Розхід палива судна" << endl;
    }
};

class Truck : public Transport {
public:
    Truck() : Transport("Грузовик") {}

    void displayInfo() override {
        Transport::displayInfo();
    }

    void fuelConsumption() override {
        cout << "Розхід палива грузовика" << endl;
    }
};

class Bicycle : public Transport {
public:
    Bicycle() : Transport("Велосипед") {}

    void displayInfo() override {
        Transport::displayInfo();
    }

    void fuelConsumption() override {
        cout << "Велосипед не використовує паливо" << endl;
    }
};

class Car : public Transport {
public:
    Car() : Transport("Легковий автомобіль") {}

    void displayInfo() override {
        Transport::displayInfo();
    }

    void fuelConsumption() override {
        cout << "Розхід палива легкового автомобіля" << endl;
    }
};

int main() {
    Transport* transport;

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Створити самолет" << endl;
        cout << "2. Створити судно" << endl;
        cout << "3. Створити грузовик" << endl;
        cout << "4. Створити велосипед" << endl;
        cout << "5. Створити легковий автомобіль" << endl;
        cout << "0. Вихід" << endl;
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            transport = new Airplane();
            break;
        case 2:
            transport = new Ship();
            break;
        case 3:
            transport = new Truck();
            break;
        case 4:
            transport = new Bicycle();
            break;
        case 5:
            transport = new Car();
            break;
        case 0:
            cout << "До побачення!" << endl;
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
            break;
        }

        if (choice != 0) {
            transport->displayInfo();
            transport->fuelConsumption();
            delete transport;
        }
    } while (choice != 0);

    return 0;
}
