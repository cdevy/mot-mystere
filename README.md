# mot-mystere

TP Mot Mystère du cours OpenClassrooms Découverte de la programmation en C++        
http://exercices.openclassrooms.com/assessment/65?login=7558350&tk=2992112753d7eb4edaef60b3831e5963&sbd=2016-02-01&sbdtk=fa78d6dd3126b956265a25af9b322d55

Auteur

	Charlotte DEVY

Compile

	g++ main.cpp utils.cpp -o mot_mystere

Execute

	./mot_mystere

## Versions

### Version originale   
Le premier joueur choisit un mot puis le deuxième tente de le retrouver à partir des lettres mélangées.

### Bonus 1 : Proposer au joueur de faire une nouvelle partie   
Une fois le mot mystère trouvé, on propose au joueur de jouer une nouvelle partie en tapant 'O' ou d'arrêter de jouer en tapant 'N'. Tout autre caractère est considéré comme une erreur et repose la question au joueur.  

### Bonus 2 : Fixer un nombre maximal de coups
On contraint le joueur à 5 essais pour trouver le mot mystère ou bien il perd la partie. 

### Bonus 3 : Piocher le mot dans un fichier-dictionnaire  
On modifie le jeu pour qu'il n'y ait qu'un seul joueur. Le mot est généré aléatoirement à partir d'un fichier-dictionnaire.
