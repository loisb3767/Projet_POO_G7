<h1 align="center">JEU DE LA VIE - PROJET POO G7</h1>


## DESCRIPTION :
Le jeu de la vie est une automate cellulaire inventé par le mathématicien John Conway en 1970. La simulation se déroule sur une grille en deux dimensions dont les cases sont appellées "cellules". 
Le fonctionnement de l'automate est ancré sur deux règles, à un instant t (pour rappel une cellule à 8 cellules voisines) :
* Une cellule "morte" qui possède exactement trois cellules voisines vivantes devient "vivante"
* Une cellule "vivante" qui possède deux ou trois voisines vivantes reste "vivante" sinon elle devient "morte"



## RAPPEL CONSIGNES :
Pour notre projet de Programmation orientée objet, nous devions par binôme, créer un jeu de la vie en C++ en respectant les principes de la POO. Nous avons commencé par la partie Conception et Modélisation du projet en utilisant différents diagrammes UML/SYSML (cas d'utilisation, d'activité, de séquence et de classes), que nous avons fournis sur le repo github. Ensuite nous nous sommes repartis les tâches selon notre diagramme de classes fait au préalable. Afin de garantir une gestion propre du projet et éviter les problèmes avec git nous avions fais deux branches, en plus du main. Cela nous a permis de vérifier chacun de notre côté en local que notre code fonctionnait pour ensuite lorsqu'il était prêt et que nous nous étions mis d'accord, push sur la branche main du projet.


## COMPILATION
Requis : 
* Compilateur g++
* C++17 ou supérieur
* SFML

Pour compiler vous devrez avoir le compilateur g++, sfml et au minimum la version 17 C++. Pour relier SFML au programme et pour éviter les problèmes de linkage, vous devrez ajouter ces instructions :
"-lsfml-graphics -lsfml-window -lsfml-system" à la fin de la ligne de compilation.
Afin de compiler le code du projet vous devrez utiliser cette commande :
g++ -std=c++17 *.cpp -o jeu -lsfml-graphics -lsfml-window -lsfml-system


## EXECUTION
Après la compilation lancer le jeu en faisant ./jeu



