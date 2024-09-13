#include <iostream>
using namespace std;
enum role{Citizen, Bloger, Pensioner, Revolutionary, Criminal};
const char* randname(int i) {
    switch (i) {
    case 1: {
        return "Jessie";
    }
    case 2: {
        return "Jack";
    }
    case 3: {
        return "Vlad";
    }
    case 4: {
        return "Walter";
    }
    case 5: {
        return "Isaac";
    }
    case 6: {
        return "Mike";
    }
    case 7: {
        return "Freddie";
    }
    case 8: {
        return "Elisabet";
    }
    case 9: {
        return "William";
    }
    case 10: {
        return "Bruno";
    }
    }
}
const char* randlname(int i) {
    switch (i) {
    case 1: {
        return "Brown";
    }
    case 2: {
        return "Northwest";
    }
    case 3: {
        return "Afton";
    }
    case 4: {
        return "Jones";
    }
    case 5: {
        return "Wilson";
    }
    case 6: {
        return "Smith";
    }
    case 7: {
        return "Miller";
    }
    case 8: {
        return "Swoford";
    }
    case 9: {
        return "Linkoln";
    }
    case 10: {
        return "Moore";
    }
    }
}
role randtype(int i) {
    switch (i) {
    case 1: {
        return Citizen;
    }
    case 2: {
        return Citizen;
    }
    case 3: {
        return Citizen;
    }
    case 4: {
        return Bloger;
    }
    case 5: {
        return Bloger;
    }
    case 6: {
        return Pensioner;
    }
    case 7: {
        return Pensioner;
    }
    case 8: {
        return Pensioner;
    }
    case 9: {
        return Revolutionary;
    }
    case 10: {
        return Criminal;
    }
    }
}
class Character {
    role what;
    bool checked;
public:
    Character() : checked(false), what(randtype(rand()%10+1)){}
    bool getCheck() {
        return checked;
    }
    void setCheck() {
        checked = true;
    }
    int getWhat() {
        return what;
    }
};
class Chel {
    static int num;
    char* name;
    char* surname;
    Character type;
public:
    Chel(const char* name, const char* surname) : name(new char[strlen(name) + 1]), surname(new char[strlen(surname) + 1]){
        num++;
        for (int i = 0; i < strlen(name) + 1; i++) {
            this->name[i] = name[i];
        }
        for (int i = 0; i < strlen(surname) + 1; i++) {
            this->surname[i] = surname[i];
        }
    }
    Chel() : Chel(randname(rand()%10+1), randlname(rand() % 10 + 1)) {}
    Chel(const Chel& other) : Chel(other.name, other.surname){}
    ~Chel() {
        delete[] name;
        delete[] surname;
    }
    char* getName() {
        return name;
    }
    char* getSurname() {
        return surname;
    }
    bool getChecked() {
        return type.getCheck();
    }
    void setChecked() {
        type.setCheck();
    }
    int getWhat() {
        return type.getWhat();
    }
    void setName(const char* c) {
        if (strlen(c) > strlen(name)) {
            delete[] name;
            name = new char[strlen(c) + 1];
        }
        for (int i = 0; i < strlen(name) + 1; i++) {
            name[i] = c[i];
        }
    }
    void setSurname(const char* c) {
        if (strlen(c) > strlen(surname)) {
            delete[] surname;
            surname = new char[strlen(c) + 1];
        }
        for (int i = 0; i < strlen(surname) + 1; i++) {
            surname[i] = c[i];
        }
    }
    void print() {
        std::cout << num << std::endl; 
        std::cout << name;
        std::cout << std::endl;
        std::cout << surname;
        std::cout << std::endl;
    }
};
int Chel::num = 0;
class Apartment {
    Chel ppl;
    bool water;
    bool electricity;
public:
    Apartment(const Chel& sm) : ppl(sm) {}
    Apartment() : water(false), electricity(false){}
    const char* getName() {
        return ppl.getName();
    }
    const char* getLname() {
        return ppl.getSurname();
    }
    bool getCheck() {
        return ppl.getChecked();
    }
    void setCheck() {
        ppl.setChecked();
    }
    int getWhat() {
        return ppl.getWhat();
    }
    bool getWater() {
        return water;
    }
    bool getElectr() {
        return electricity;
    }
    void setWater(bool c) {
        water = c;
    }
    void setElectr(bool c) {
        water = c;
    }
};
class ZHKH {
    Apartment* cmplx;
    int money, rep, frcheck, days;
    int check(int min=0, int max=1) {
        int c;
        do {
            cin >> c;
        } while (c < min || c > max);
        return c;
    }
public:
    ZHKH() : cmplx(new Apartment[7]), money(700), rep(10) {
    }
    ~ZHKH() { delete[] cmplx; }
    void todd(int i) {
        switch (i) {
            case 1:{
                cout << "<Todd>: Hey there. My name is Todd. I will give you commands so you wouldnt destroy this apartment complex. First of all, set in the apartment some ppl. 3 will be enough";
                break;
            };
            case 2: {
                cout << "<Todd>: Nice job. K i dont wanna spend too much time with you so have fun alone";
                break;
            }
            case 3: {
                cout << "<Todd>: we need more people in here \n \t\t\t -5 rep";
                rep -= 5;
                break;
            }
            case 4: {
                cout << "<Todd>: AFK is banned on this server \n \t\t\t -5 rep";
                rep -= 5;
                break;
            }
        }
    }
    void stats() {
        system("cls");
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t money-" << money << ", rep-" << rep << endl;
    }
    void print() {
        stats();
        for (int i = 0; i < 7; i++) {
            cout << i + 1 << '\t' << cmplx[i].getName() << ' ' << cmplx[i].getLname() << '\n';
        }
        cout << "8 \t Done, lets go next day\n";
    }
    void settings(int a) {
        system("cls");
        cout << "Water is -" << cmplx[a].getWater() << endl << "Electricity is -" << cmplx[a].getElectr() << endl << "0. redact water \n 1. redact electricity \n";
        int c;
        c = check();
        switch (c) {
        case 0:
            cout << "0-turn off water \t\t\t 1-turn on water (-10$ per move)";
            c = check();
            cmplx[a].setWater(c);
            break;
        case 1:
            cout << "0-turn off electricity \t\t\t 1-turn on electricity (-10$ per move)";
            c = check();
            cmplx[a].setElectr(c);
            break;
        }
    }
    int getMoney() {
        return money;
    }
    int getRep() {
        return rep;
    }
    void decision() {
        print();
        int c;
        cout << "type the number of the owner's name to communicate with it" << '\n';
        int a = check(0, 8);
                cout << cmplx[a].getName() << ' ' << cmplx[a].getLname() << '\n';
                if (cmplx[a].getCheck() == false) {
                    cout << "this persons role is unknown. \n 1. \t reveal the role (-10 rep) \n 2. \t settings \n 0.\t back\n";
                    c = check(0, 2);
                    switch (c) {
                    case 1: {
                        rep -= 10;
                        system("cls");
                        stats();
                        cmplx[a].setCheck();
                        break;
                    }
                    case 2: {
                        settings(a);
                    }
                    case 0: {
                        decision();
                        break;
                    }
                    }
                }
                else {
                    switch (cmplx[a].getWhat()) {
                    case Citizen:
                        cout << "this is a simple citizen. \n 1. \t settings \n 0.\t back";
                        c = check();
                        switch (c) {
                        case 1:
                            settings(a);
                            break;
                        case 0:
                            decision();
                        }
                    case Bloger:
                        cout << "this is a leader of opinions. His mood affects on other ppl. \n 1. \t settings \n 0.\t back";
                        cin >> c;
                        switch (c) {
                        case 1:
                            settings(a);
                            break;
                        case 0:
                            decision();
                        }
                    case Pensioner:
                        cout << "this is a pensioner. His mood is random and unstable. \n 1. \t settings \n 0.\t back";
                        cin >> c;
                        switch (c) {
                        case 1:
                            settings(a);
                            break;
                        case 0:
                            decision();
                        }
                    case Revolutionary:
                        cout << "this is a revolutionary. He will change your wages if you will supply him with water and electricity. \n 1. \t settings \n 0.\t back";
                        cin >> c;
                        switch (c) {
                        case 1:
                            settings(a);
                            break;
                        case 0:
                            decision();
                        }
                    }
                }
    }
};
int main() {
    srand(time(0));
    ZHKH game;
    cout << "They build your own statue in the centre of the town. You became a God";
    while (game.getMoney() > 0 && game.getRep() > 0 && game.getRep() <= 175) {
        game.decision();
    }
    cout << "Game over!\n";
    if (game.getRep() <= 0 || game.getMoney() <= 0)
        cout << "You got kicked out by your own citizens. Skill issue";
    else {
        cout << L"They build your own statue in the centre of the town. You became a God";
    }
}