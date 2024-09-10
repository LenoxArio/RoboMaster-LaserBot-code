#include <Arduino.h>
#include "capteur.h"

int capteur1; //gauche
int capteur2; //droite
int capteur3; //avant
int capteur4; //arrière


int capteurLeft(){
    capteur1 = analogRead(A0); //lire la broche A0 (photoresistance) et puis redéfinir la variable capteur1 avec la valeur obtenue 
    return capteur1; //retourner la valeur de capteur1
}

int capteurRight(){
    capteur2 = analogRead(A1); //lire la broche A1 (photoresistance) et puis redéfinir la variable capteur2 avec la valeur obtenue
    return capteur2; //retourner la valeur de capteur2
}

int capteurBefore(){
    capteur3 = analogRead(A2); //lire la broche A2 (photoresistance) et puis redéfinir la variable capteur3 avec la valeur obtenue
    return capteur3; //retourner la valeur de capteur3
}

int capteurBack(){
    capteur4 = analogRead(A3); //lire la broche A3 (photoresistance) et puis redéfinir la variable capteur4 avec la valeur obtenue
    return capteur4; //retourner la valeur de capteur4
}

int detectionShield(int capteurSensibilty){  //fonction pour si un capteur est toucher alors renvoie 1 sinon renvoie 0
  capteur1 = analogRead(A0); //lire la broche A0 (photoresistance) et puis redéfinir la variable capteur1 avec la valeur obtenue
  capteur2 = analogRead(A1); //lire la broche A1 (photoresistance) et puis redéfinir la variable capteur2 avec la valeur obtenue
  capteur3 = analogRead(A2); //lire la broche A2 (photoresistance) et puis redéfinir la variable capteur3 avec la valeur obtenue
  capteur4 = analogRead(A3); //lire la broche A3 (photoresistance) et puis redéfinir la variable capteur4 avec la valeur obtenue

  if(capteur1 <= capteurSensibilty){ //Si la valeur de capteur1 est inférieur à celle de la variable capteurSensibilty (si capteur toucher) alors renvoie 1
    return 1;
  }else if(capteur2 <= capteurSensibilty){ //Si la valeur de capteur2 est inférieur à celle de la variable capteurSensibilty (si capteur toucher) alors renvoie 2
    return 2;
  }else if(capteur3 <= capteurSensibilty){ //Si la valeur de capteur3 est inférieur à celle de la variable capteurSensibilty (si capteur toucher) alors renvoie 3
    return 3;
  }else if(capteur4 <= capteurSensibilty){ //Si la valeur de capteur4 est inférieur à celle de la variable capteurSensibilty (si capteur toucher) alors renvoie 4
    return 4;
  }else{ //Sinon si aucun capteur à été toucher alors renvoie 0
    return 0;
  }
}

