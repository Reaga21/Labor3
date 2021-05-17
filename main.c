/******************************************************************
* Projekt: Algorithmen und Datenstrukturen
* Dateiname: main.c
* Beschreibung: Programm zum Erstellen, Modifizeren und Lˆschen verketteter Listen
* Autor: Andrea Robitzsch
* Matr.-Nr.: 937543
* Zuletzt geaendert: 16.05.2021
******************************************************************/

/*********** Hinweis ***********/
/*
Einzelne Tests in CodeFreak k√∂nnen unerwartet fehlschlagen.
Das kann auch daran liegen, dass die Aufgabenstellung im Detail
unterschiedlich interpretiert werden kann. Beispielsweise setzen die
Tests voraus, dass bei einer leeren Liste immer ein Element an Position 1
eingef√ºgt werden kann.

Funktioniert das Programm in Ihren Augen korrekt, fragen Sie gern nach,
warum ein bestimmter Test fehlschl√§gt.
*/


#include <stdio.h>
#include <stdlib.h>

// Hier Konstanten und Statuscodes definieren
#define NOT_IMPLEMENTED_ERROR -1000
#define put_Entry_Success 1
#define put_Entry_Error -100

// to do

struct listnode{
	int nutzerDaten;
	struct listnode *pNext;
};

typedef struct listnode LISTNODE;

// globale Variablen

LISTNODE *pStart = NULL; // zeigt aus das erste Element der Liste
LISTNODE *pEnde = NULL;   // zeigt auf das letzte Element der Liste
LISTNODE *pRun = NULL;  // L‰uft durch die Liste durch
LISTNODE *pTmp = NULL; // Tempor‰rer Zeiger der Liste


// Vorgegebene Enumeration als Hilfestellung
enum DIRECTION { FORWARD, REVERSE } direction;


/* Vorgegebene Unterprogramme zur Verwaltung der verketteten Liste */
/* Die folgenden 6 Funktionen werden von CodeFreak erwartet.       */
/* Fehler sollten durch die R√ºckgabe eines negativen Statuscodes   */
/* kenntlich gemacht werden. */
int put_entry(int position, int aktdata);  /* Eintrag einfuegen */
int del_entry(int position);               /* Eintrag Loeschen  */
int find_entry(int value);                 /* Eintrag suchen    */
int del_list(void);                       /* Liste loeschen    */
int get_anzentries(void);                  /* Anzahl ermitteln  */
int printall(enum DIRECTION direction);    /* Liste ausgeben    */


int main(void)
{
int anzahl_Eintraege;
LISTNODE element1, element2, element3, element4;

pStart = &element1;
pEnde = &element4;
pRun = pStart;
pEnde->pNext = NULL;
element1.pNext = &element2;
element1.nutzerDaten = 1;
element2.pNext = &element3;
element2.nutzerDaten = 2;
element3.pNext = &element4;
element3.nutzerDaten = 3;
element4.nutzerDaten= 4;
put_entry(2, 5);
put_entry(4,100);
put_entry(5,40);
put_entry(20, 10000);
put_entry(9, 200);
//del_entry(3); --> diese Funktion funktioniert noch nicht
//del_list();


//put_entry(3, 50);

printall(FORWARD);

find_entry(30);

anzahl_Eintraege = get_anzentries();

printf("Die Anzahl der Eintraege in der Liste lautet %d", anzahl_Eintraege);


    return 0;
}


/* Unterprogramm zum Einfuegen eines Nutzdatenelements
*  Parameter: position = Einfuegepos.; 0 = vor pstart
*             aktdata  = einzufuegende Zahl
*/
int put_entry(int position, int aktdata) /* Einfuegen */
{
   LISTNODE *pNew;
   int j;
   pNew = (LISTNODE *)malloc(sizeof(LISTNODE));
   pNew->nutzerDaten = aktdata;
   pNew->pNext = NULL;
   pEnde->pNext = NULL;
	
	// wenn Liste noch gar kein Element enth‰lt -- setze es an die erste Stelle
	if(pStart == NULL){
		pStart = pNew;
		return 1;
		} else if( get_anzentries() < position){
	// wenn die Liste kleiner ist als die Position setze Elements an das Ende der Liste		
		pEnde->pNext = pNew;
		pEnde = pNew;
	return 1;		
	}else if (position == 1){
		pNew->pNext = pStart;
		pStart = pNew;
	}
	
	else{
		pRun = pStart;
	
   	for (j=1; j < position-1; j++){
   		pRun = pRun->pNext;
   		
	   }
	   
	   // einf¸gen des Elementes an Position position
	   
	   pNew->pNext = pRun->pNext;
	   pRun->pNext = pNew;
	   return 1;
   }
   
   
   
   
   return 0;
}


/* Unterprogramm zu Ausgabe aller Listenelemente
*  Parameter: direction  = FORWARD	vorwaerts
*                        = REVERSE	rueckwaerts
*  Return:    0          = alles OK
*         negative Werte = Fehler
*/
int printall(enum DIRECTION direction)
{
   int j=1;
   pRun = pStart;
   if(direction == FORWARD){
   
   while(pRun != NULL){
   		printf("Daten aus Element %d: %d\n", j, pRun->nutzerDaten);
	   pRun = pRun->pNext;
	   j++;
   }
   }
   return 0;
}


/* Unterprogramm zum Loeschen der gesamten Liste
*  Parameter: keine
*  Return:    0         = Loeschen OK
*         negative Werte = Fehler
*/
int del_list(void)  // TODO hat gar keinen R√ºckgabewert 
{
	pRun=pStart;
	while(pRun!=NULL){
		pTmp = pRun;
		pRun = pRun->pNext;
		free(pTmp);
		
	}
	return 0;
}


/* Unterprogramm zum Loeschen eines Nutzdatenelements
*  Parameter: position   = Loeschpos.;
*  Return:    0          = Loeschen OK
*         negative Werte = Fehler
*/
int del_entry(int position) /* Loeschen (delete) */
{
	int j;
	pTmp->pNext = NULL;
	// pTmp ist eine globale Variable
	pRun = pStart;
	if(pStart!= NULL){
		if (position == 1){
			pTmp = pStart;
			pStart = pTmp->pNext;
			free(pTmp);
			return 0;
		}else if (get_anzentries()>= position){
			pRun = pStart;
   			for (j=1; j < position-1; j++){
   			pRun = pRun->pNext;
	   		}
			pTmp = pRun->pNext;
			pRun->pNext = pRun->pNext->pNext;
			free(pTmp);
	
			return 0;
	
	} else{
		printf("\nEs gibt kein Element an der Position %d", position);
	return -1;
	}
   
}
}


/* Unterprogramm zur Ermittlung der Elementanzahl
*  Parameter: keine
*  Return:    aktuelle Anzahl der Element
*/
int get_anzentries(void)      /* Anzahl ermitteln  */
{
   pRun = pStart;
   int count = 0;
   pEnde->pNext = NULL;
   while (pRun != NULL){
   	++count;
   	pRun = pRun->pNext;
   }
   
   
   return count;
}


/* Unterprogramm zum Suchen eines Elementes
*  Parameter: value      = Zahl, nach der gesucht wird
*  Return:    0          = nicht gefunden
*         negative Werte = Fehler
*/
int find_entry(int value)
{
   pRun = pStart;
   pEnde->pNext = NULL;
   while ((pRun != NULL) && (pRun->nutzerDaten != value)){
   	pRun = pRun->pNext;
   }
   if(pRun != NULL){
   printf("Der gesuchte Wert %d befindet sich in der Liste\n", value);
   return 1;
   	
   }else{
   	printf("Der gesuchte Wert %d befindet sich nicht in der Liste\n", value);
 return 0;}
return -100; 
}




