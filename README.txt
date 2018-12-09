Projet LIFAP4 - SoCarre
Auteurs : Côme DEMOLLIERE (p1613231), Lucas FERRAGUT (p1605245), Alexia GIRARD (p1604097)
Projet GIT : p1613231 (Côme DEMOLLIERE)


Plus d'informations sur le jeu dans le fichier src/core/documentation.h à ouvrir avec un éditeur de texte par exemple

PRESENTATION DU JEU
-------------------
Le jeu présenté se nomme SoCarre, c'est un jeu d'arcade comportant plusieurs mondes avec chacun des niveaux de difficulté différents et un monde record. Le but du jeu est de faire sauter son personnage pour franchir des obstacles afin d'arriver à la fin du monde représentée par un drapeau. Le personnage meurt au contact d'un triangle et lorsqu'il touche complétement un carré, mais il peut cependant sauter sur un carré.
Les touches permettant le saut du personnage sont la touche ESPACE ou la flèche du haut (en version SDL).

Sur le menu, on peut retrouver les différents mondes, ainsi qu'un bouton aide qui nous renvoie sur une page d'explications liée au jeu, ou également la gestion du son ou non. Il suffit de cliquer à l'aide de la souris sur l'intitulé d'un monde pour y accéder; on peut quitter la page du menu en utilisant la touche ECHAP ou en cliquant sur la croix de la page en haut à droite.


ORGANISATION DES FICHIERS
-------------------
Nous retrouvons divers dossiers à partir de la racine du dossier SoCarre qui constitue notre jeu. 
Nous avons les dossiers :
	- ./src : on y trouve tous les fichiers liés au code source de notre jeu, les .h et .cpp définissant nos différentes classes
	- ./bin : on y trouve tous les fichiers concernant les exécutables de notre jeu, sous différentes versions (version TXT ou version 			SDL2) ainsi que les différents exécutables selon le système d'exploitation de votre machine
	- ./data : on y trouve tous les fichiers annexes à notre projert comme des images du jeu, ou des sons. On y retrouve également les 			fichiers liés aux différents mondes du jeu et leur structure
	- ./doc : on y trouve notre diaporama lié à notre présentation orale, le diagramme des classes de notre jeu ainsi que le GANTT qui 			représente notre organisation durant ce projet. On peut y trouver également un lien direct vers notre documentation en ligne 			du jeu, le chemin est ./doc/html/index.html; ce fichier s'ouvre avec un navigateur comme Mozilla Firefox par exemple

Vous trouverez également le makefile qui servira pour compiler le jeu, directement à la racine du dossier SoCarre ainsi que le README que vous êtes en train de lire.


COMPILATION 
-------------------
Code écrit sur C++ à l'aide d'un environnement de développement. Jeu développé sous Linux et Windows.
Code compilé à l'aide d'un makefile se trouvant au chemin : ./Makefile en faisant la commande make dans un terminal sous LINUX.
Sous WINDOWS pour compiler, il faut : installer MinGW, se rendre dans panneau de configuration et ajouter le chemin vers MinGW au PATH, puis ouvrir l'invite de commandes de Windows dans le dossier SoCarre et taper la commande mingw32-make.

Code peut être également compilé en ouvrant le projet avec CodeBlocks et en faisant F9.

Avant de lancer un exécutable, bien penser à recompiler avec la commande make



SOUS LINUX :
Pour lancer l'exécutable lié à l'affichage en version TXT :
	Aucun prérequis
	Faire les commandes : cd bin
			      ./SoCarreTXT

Pour lancer l'exécutable lié aux tests regressions de nos différentes classes :
	Faire les commandes : cd bin
			      ./testRegression

Pour lancer l'exécutable lié à l'affichage graphique à l'aide de la bibliothèque SDL :
	Télécharger la bibliothèque SDL2 à l'aide de la commande : 
		sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
	Plus d'informations sur le site SDL : https://www.libsdl.org/  http://www.libsdl.org/
	Faire les commandes : cd bin
			      ./SoCarreSDL

Afin de générer la documentation :
	Télécharger doxygen : http://www.stack.nl/~dimitri/doxygen/
	Puis effectuer les commandes : 	cd doc
					doxygen doxyfile
	Puis aller à la page : ./doc/html/index.html



SOUS WINDOWS : 
Pour lancer l'exécutable lié à l'affichage en version TXT :
	Se rendre dans le dossier /bin
	Cliquer sur l'exécutable : SoCarreTXT.exe

Pour lancer l'exécutable lié aux tests regressions de nos différentes classes :
	Se rendre dans le dossier /bin
	Cliquer sur l'exécutable : testRegression.exe

Pour lancer l'exécutable lié à l'affichage en version SDL :
	Se rendre dans le dossier /bin
	Cliquer sur l'exécutable : SoCarreSDL.exe



