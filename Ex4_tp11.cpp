
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Classe abstraite
class NoeudFichier {
public:
    virtual string nom() const = 0;
    virtual int taille() const = 0;

    virtual ~NoeudFichier() {}
};

// Classe Fichier
class Fichier : public NoeudFichier {
private:
    string nomFichier;
    int tailleFichier;

public:
    Fichier(string n, int t) {
        nomFichier = n;
        tailleFichier = t;
    }

    string nom() const override {
        return nomFichier;
    }

    int taille() const override {
        return tailleFichier;
    }
};

// Classe Dossier
class Dossier : public NoeudFichier {
private:
    string nomDossier;
    vector<NoeudFichier*> enfants;

public:
    Dossier(string n) {
        nomDossier = n;
    }

    string nom() const override {
        return nomDossier;
    }

    void ajouter(NoeudFichier* element) {
        enfants.push_back(element);
    }

    int taille() const override {
        int total = 0;

        for (NoeudFichier* enfant : enfants) {
            total += enfant->taille();
        }

        return total;
    }

    ~Dossier() {
        for (NoeudFichier* enfant : enfants) {
            delete enfant;
        }
    }
};

// Programme principal
int main() {

    string nomDossier, nomFichier;
    int tailleFichier;

    cout << "Donner le nom du dossier principal : ";
    cin >> nomDossier;

    Dossier* dossier = new Dossier(nomDossier);

    int nombre;

    cout << "Combien de fichiers voulez-vous ajouter ? ";
    cin >> nombre;

    for (int i = 0; i < nombre; i++) {
        cout << "\nNom du fichier : ";
        cin >> nomFichier;

        cout << "Taille du fichier (Ko) : ";
        cin >> tailleFichier;

        dossier->ajouter(new Fichier(nomFichier, tailleFichier));
    }

    // Creation d'un sous-dossier
    string nomSousDossier;

    cout << "\nDonner le nom du sous-dossier : ";
    cin >> nomSousDossier;

    Dossier* sousDossier = new Dossier(nomSousDossier);

    int nombreSous;

    cout << "Combien de fichiers dans le sous-dossier ? ";
    cin >> nombreSous;

    for (int i = 0; i < nombreSous; i++) {
        cout << "\nNom du fichier : ";
        cin >> nomFichier;

        cout << "Taille du fichier (Ko) : ";
        cin >> tailleFichier;

        sousDossier->ajouter(new Fichier(nomFichier, tailleFichier));
    }

    dossier->ajouter(sousDossier);

    // Affichage des tailles
    cout << "\n--- Resultat ---" << endl;

    cout << "Dossier : " << dossier->nom() << endl;
    cout << "Taille totale : " << dossier->taille() << " Ko" << endl;

    cout << "Sous-dossier : " << sousDossier->nom() << endl;
    cout << "Taille : " << sousDossier->taille() << " Ko" << endl;

    delete dossier;

    return 0;
}

