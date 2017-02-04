#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

string melangerLettres(string mot) {
  string motMelange;
  int nbAleatoire;
  int nbLettres(mot.size());

  // Initialisation du générateur de nombres aléatoires
  srand(time(0));

  while (nbLettres > 0) {
    nbAleatoire = rand() % nbLettres;

    // Ajout de la lettre tirée aléatoirement au mot mélangé
    motMelange.push_back(mot[nbAleatoire]);

    // Suppression de la lettre déjà tirée (afin de ne plus la tirer)
    mot.erase(nbAleatoire,1);

    --nbLettres;
  }

  return motMelange;
}

void nouvellePartie(bool & stop) {
  char reponse;
  cout << "Voulez-vous faire une autre partie ? (O/N)" << endl;
  cin >> reponse;
  cout << endl;

  if (reponse == 'N') {
    stop = true;
  } else if (reponse != 'O') {
    nouvellePartie(stop);
  }
}

int main() {
  string mot;
  bool motTrouve;
  bool stop(false);
  int essais;

  do {
    motTrouve = false;
    essais = 5;

    cout << "Saisissez un mot : " << endl;
    cin >> mot;
    cout << endl;

    while(!motTrouve) {
      string motPropose;

      cout << "Quel est le mot mystère ? " << melangerLettres(mot) << endl;
      cin >> motPropose;

      if (motPropose.compare(mot) == 0) {
        cout << "Bravo ! Vous avez trouvé le mot mystère !" << endl;
        cout << endl;
        motTrouve = true;

        nouvellePartie(stop);

      } else {
        cout << "Ce n'est pas le mot mystère !" << endl;
        cout << endl;

        if (essais > 1) {
          --essais;
          cout << "Il vous reste " << essais << " essai(s)." << endl;
          cout << endl;
        } else {
          motTrouve = true;
          cout << "Vous avez perdu !" << endl;
          cout << endl;

          nouvellePartie(stop);
        }
      }
    }

  } while (!stop);

  return 0;
}
