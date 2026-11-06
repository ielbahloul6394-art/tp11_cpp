
#include <iostream>
#include <vector>
using namespace std;

// Classe abstraite
class Animal {
public:
    virtual void crier() const = 0;

    void info() const {
        cout << "Je suis un animal." << endl;
    }

    virtual ~Animal() {}
};

// Classe Chien
class Chien : public Animal {
public:
    void crier() const override {
        cout << "Wouf !" << endl;
    }
};

// Classe Chat
class Chat : public Animal {
public:
    void crier() const override {
        cout << "Miaou !" << endl;
    }
};

// Classe Vache
class Vache : public Animal {
public:
    void crier() const override {
        cout << "Meuh !" << endl;
    }
};

// Programme principal
int main() {

    vector<Animal*> animaux;

    // Creation des animaux
    animaux.push_back(new Chien());
    animaux.push_back(new Chat());
    animaux.push_back(new Vache());

    // Affichage des informations et des cris
    for (Animal* a : animaux) {
        a->info();
        a->crier();
        cout << "----------------" << endl;
    }

    // Liberation de la memoire
    for (Animal* a : animaux) {
        delete a;
    }

    return 0;
}
