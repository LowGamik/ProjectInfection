#include <cstddef>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>
using namespace std;

#ifdef _WIN32
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif


typedef enum{
    NONE,
    MINOR,
    NEGLIGIBLE,
    MEDIUM,
    MAJOR,
    CRITICAL
}InfectionLevel;

typedef enum{
    NORMAL,
    PERFECT,
    BLOODY,
    DARK
}InfectionLook;

InfectionLook intToInfectionLook(int number);
InfectionLevel intToInfectionLevel(int number);
void typeWriter(const string& sentence, int timeMillisecconds);

class Signs{
    private:
        InfectionLevel level;
        InfectionLook look;
    public:
        void makeInfection(bool isInfected, bool isVaccinated){
            if(isInfected){
                if(isVaccinated){
                    level = intToInfectionLevel(rand()%2+1);
                    look = intToInfectionLook(rand()%2);
                } else {
                    if((rand()%2)==1){
                    level = intToInfectionLevel(rand()%4+1);
                    look = intToInfectionLook(rand()%2+1);
                    }else{
                    level = intToInfectionLevel(rand()%4+2);
                    look = intToInfectionLook(rand()%3+1);
                    }
                }
            }else{
                level = intToInfectionLevel(rand()%3);
                look = intToInfectionLook(rand()%3);
            }
        }
        InfectionLevel getLevel() const { return level; }
        InfectionLook getLook() const { return look; }

        bool isDangerousInfection(bool isVaccinated) const {
        if(!isVaccinated) {
            return level >= MEDIUM; // Non-vaccinated: MEDIUM or higher is dangerous
        } else {
            return level >= MAJOR;  // Vaccinated: Only MAJOR or CRITICAL is dangerous
        }
    }
};

class Head{

};

class Torso{

};

class Hands{

};

class Legs{

};

class Guard{
    private:
        string name;
        int sanity;
    public:
        Guard(): name(""), sanity(45){}
        void setName(){
            cout << "What is your characters name?" <<endl;
            getline(cin, name);
        }
        string getName(){
            return name;
        }
        void setSanity(int inputSanity){
            sanity = inputSanity;
        }
        void addSanity(int inputSanity){
            sanity += inputSanity;
        }
        void reduceSanity(int inputSanity){
            sanity -= inputSanity;
        }
        int getSanity(){
            return sanity;
        }
};



class Visitor{
    private:
        string name;
        bool isInfected;
        bool isVaccinated;
        Head head;
        Torso torso;
        Hands leftHand;
        Hands rightHand;
        Legs leftLeg;
        Legs rightLeg;
    public:

};



int main(){
    Guard player;
    vector<Visitor> visitors;
    visitors.resize(3);

    srand(time(NULL));

    CLEAR_SCREEN();

    cout << "hello, world!" << endl;
    player.setName();

    CLEAR_SCREEN();

    typeWriter(player.getName() + "'s sanity is " + to_string(player.getSanity()), 50);
    return 0;
}

void typeWriter(const string& sentence, int timeMillisecconds) {
    for (char c : sentence) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(timeMillisecconds));
    }
    cout << endl;
}

InfectionLook intToInfectionLook(int number){
    switch (number) {
        case 0: return NORMAL;
        case 1: return PERFECT;
        case 2: return BLOODY;
        case 3: return DARK;
        default: return NORMAL;
    }
}
InfectionLevel intToInfectionLevel(int number){
    switch (number) {
        case 0: return NONE;
        case 1: return MINOR;
        case 2: return NEGLIGIBLE;
        case 3: return MEDIUM;
        case 4: return MAJOR;
        case 5: return CRITICAL;
        default: return NONE;
    }
}