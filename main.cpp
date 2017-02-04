#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"

using namespace std;

int main() {
  string mot;
  bool motTrouve;
  bool stop(false);
  int essais;

  do {
    motTrouve = false;
    essais = 5;

    // Ouverture du fichier en lecture seule
    ifstream fichier("dico.txt");

    if (!fichier) {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
      return 0;
    }

    mot = motAleatoire(fichier);

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
          cout << "Vous avez perdu ! Le mot mystère était : " << mot << endl;
          cout << endl;

          nouvellePartie(stop);
        }
      }
    }

  } while (!stop);

  return 0;
}
