#include <iostream>
#include <string>
using namespace std;

class Guard{
    private:
        string name;
        int sanity;
    public:
        void setName(string inputName){
            name = inputName;
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

int main(){
    Guard player;
    string name;
    cout << "hello, world!" << endl;
    getline(cin, name);
    cout << name << endl;
    player.setName(name);
    cout << "Guard's name is " << player.getName() << endl;
    return 0;
}