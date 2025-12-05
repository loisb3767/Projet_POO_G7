<h1 align="center">JEU DE LA VIE - PROJET POO G7</h1>


## DESCRIPTION :
Le jeu de la vie est une automate cellulaire inventé par le mathématicien John Conway en 1970. La simulation se déroule sur une grille en deux dimensions dont les cases sont appellées "cellules". 
Le fonctionnement de l'automate est ancré sur deux règles, à un instant t (pour rappel une cellule à 8 cellules voisines) :
* Une cellule "morte" qui possède exactement trois cellules voisines vivantes devient "vivante"
* Une cellule "vivante" qui possède deux ou trois voisines vivantes reste "vivante" sinon elle devient "morte"



## RAPPEL CONSIGNES :
Pour notre projet de Programmation orientée objet, nous devions par binôme, créer un jeu de la vie en C++ en respectant les principes de la POO. Nous avons commencé par la partie Conception et Modélisation du projet en utilisant différents diagrammes UML/SYSML (cas d'utilisation, d'activité, de séquence et de classes), que nous avons fournis sur le repo github. Ensuite nous nous sommes repartis les tâches selon notre diagramme de classes fait au préalable. Afin de garantir une gestion propre du projet et éviter les problèmes avec git nous avions fais deux branches, en plus du main. Cela nous a permis de vérifier chacun de notre côté en local que notre code fonctionnait pour ensuite lorsqu'il était prêt et que nous nous étions mis d'accord, push sur la branche main du projet. Dans ce projet nous devions avoir une partie console et une partie graphique, choisi par l'utilisateur lors de l'execution du programme. Les deux modes prennent en entrée un fichier txt avec le format de la grille et l'état des cellules. Voici un modèle de fichier d'entrée : 

Fichier d'entrée : "planeur.txt"
```
20 20
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```
Donc après avoir choisi votre fichier en entrée, vous devez choisir entre deux modes soit le mode graphique qui permet d'afficher le jeu de la vie avec SFML. Ou alors en choisissant le mode console qui permet d'avoir un fichier par itération en sortie dans un dossier out, c'est l'utilisateur qui choisit le nombre d'itérations en mode console.

## COMPILATION
Requis : 
* Compilateur g++
* C++17 ou supérieur
* SFML

Pour compiler vous devrez avoir le compilateur g++, sfml et au minimum la version 17 C++. Pour relier SFML au programme et pour éviter les problèmes de linkage, vous devrez ajouter ces instructions :
"-lsfml-graphics -lsfml-window -lsfml-system" à la fin de la ligne de compilation.
Afin de compiler le code du projet vous devrez utiliser cette commande :
```
g++ -std=c++17 $(ls *.cpp | grep -v test.cpp) -lsfml-graphics -lsfml-window -lsfml-system -o jeu
```

## EXECUTION
Après avoir bien installé les différentes dépendances et après avoir compilé vous pourrez lancer le jeu en faisant ./jeu
Si vous vous trouvez dans le dossier /CODE et que vous voulez utiliser un modèle pour pouvez utiliser un des modèles comme planeur.txt, grand_planeur.txt ou canon.txt par exemple.



