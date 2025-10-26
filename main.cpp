#ifdef _WIN32
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;
using namespace this_thread;

class Guard{
    private:
        string name;
        int sanity = 80;
    public:
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
        int getSanity(){
            return sanity;
        }
};



class Visitor{
    private:
        string name;
        bool isInfected;
        bool isVacinated;
    public:

};

void typeWriter(const string& sentence, int timeMillisecconds);

int main(){
    Guard player;
    vector<Visitor> visitors;
    visitors.resize(3);

    CLEAR_SCREEN();

    cout << "hello, world!" << endl;
    player.setName();

    CLEAR_SCREEN();

    typeWriter("Guard's name is " + player.getName(), 100);
    return 0;
}

void typeWriter(const string& sentence, int timeMillisecconds) {
    for (char c : sentence) {
        cout << c << flush;
        sleep_for(chrono::milliseconds(timeMillisecconds));
    }
    cout << endl;
}