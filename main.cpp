#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

string melangerLettres(string mot)
{
  string motMelange;
  int nbAleatoire;
  int nbLettres(mot.size());

  // Initialisation du générateur de nombres aléatoires
  srand(time(0));

  while (nbLettres > 0)
  {
    nbAleatoire = rand() % nbLettres;

    // Ajout de la lettre tirée aléatoirement au mot mélangé
    motMelange.push_back(mot[nbAleatoire]);

    // Suppression de la lettre déjà tirée (afin de ne plus la tirer)
    mot.erase(nbAleatoire,1);

    --nbLettres;
  }

  return motMelange;
}

int main()
{
  string mot;
  bool motTrouve(false);

  cout << "Saisissez un mot : " << endl;
  cin >> mot;
  cout << endl;

  while(!motTrouve)
  {
    string motPropose;

    cout << "Quel est le mot mystère ? " << melangerLettres(mot) << endl;
    cin >> motPropose;

    if (motPropose.compare(mot) == 0)
    {
      cout << "Bravo ! Vous avez trouvé le mot mystère !" << endl;
      cout << endl;
      motTrouve = true;
    }
    else
    {
      cout << "Ce n'est pas le mot mystère !" << endl;
      cout << endl;
    }
  }

  return 0;
}
