//
// Created by torup on 11/18/2025.
//
# include <iostream>
 using namespace std;
class Critter {
public:
    Critter(int hungry  = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);

private:
    int m_HUNGRY;
    int m_BORDOM;

    int GetMood() const;
    void PassTime(int time = 1);
};

Critter::Critter(int hungry, int boredom): m_HUNGRY(hungry), m_BORDOM(boredom){}
void Critter::Eat(int food) {
    cout << "Burp\n";
    m_HUNGRY -= food;
    if (m_HUNGRY < 0) { m_HUNGRY = 0; } PassTime();
}
int Critter::GetMood() const {
  return (m_HUNGRY+ m_BORDOM);
}

void Critter::PassTime(int time) {
    m_HUNGRY += time;
    m_BORDOM += time;
}

void Critter::Talk() {
    cout << "I’m a critter and I feel ";
    int mood = GetMood();
    if (mood > 15) {
        cout << "mad.\n";
    } else if (mood > 10) {
        cout << "frustrated.\n";
    } else if (mood > 5) {
        cout << "okay.\n";
    } else { }
    cout << "happy.\n"; PassTime();
}

void Critter::Play(int fun) {
    m_BORDOM -= fun;
    if (m_BORDOM < 0) { m_BORDOM = 0; } PassTime();
}

int main() {
    Critter crit;
    crit.Talk();
    int choice; do {
        cout << "\nCritter Caretaker\n\n";
        cout << "0- Quit\n";
        cout << "1- Listen to your critter\n";
        cout << "2- Feed your critter\n";
        cout << "3- Play with your critter\n\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Good-bye.\n";
                break;
            case 1:
                crit.Talk();
                break;
            case 2:
                crit.Eat();
                break;
            case 3: crit.Play();
                break;
            default:
                cout << "\nSorry, but " << choice << " isn’t a valid choice.\n";
        }
    } while (choice != 0); return 0;
}