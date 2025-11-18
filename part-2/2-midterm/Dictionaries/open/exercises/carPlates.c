#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 7   /* number of buckets; small on purpose to force collisions */

typedef struct {
    char owner[32];  /* owner full name */
    int  plate;      /* numeric plate for simplicity, e.g., 231047 */
} carType;

typedef struct node {
    carType car;
    struct node *link;
} *openCar;

typedef openCar Dic[MAX];

/* ===== prototypes ===== */
void initDictionary(Dic D);
int  hashF(int plate);                      /* TODO #1 */
void parkCar(Dic D, carType car);           /* TODO #2 */
bool isParked(Dic D, int plate);            /* TODO #3 */

/* optional */
bool unparkCar(Dic D, int plate);

void display(Dic D);

/* ===== main driver (sample) ===== */
int main(void) {
    Dic lot = {};
    initDictionary(lot);

    carType c1 = { "Kyer Ivan Jayme", 231048 };
    carType c2 = { "Kentward Maratas", 231003 };
    carType c3 = { "Clareicne Diangzco", 231045 };
    carType c4 = { "John Mark Gerozaga", 713974 };
    carType c5 = { "John Cena", 251042 };

    /* inserts */
    parkCar(lot, c1);
    parkCar(lot, c2);
    parkCar(lot, c3);
    parkCar(lot, c4);
    parkCar(lot, c5);

    /* duplicate plate -> should UPDATE owner instead of inserting */
    carType c1_fix = { "Kyer I. Jayme", 231048 };
    parkCar(lot, c1_fix);

    printf("Index\tPlates (ascending within bucket)\n");
    display(lot);

    /* lookups */
    printf("\nLookups:\n");
    printf("231003 -> %s\n", isParked(lot, 231003) ? "PRESENT" : "ABSENT");
    printf("999999 -> %s\n", isParked(lot, 999999) ? "PRESENT" : "ABSENT");

    /* optional delete demo */
    unparkCar(lot, 231003);
    printf("\nAfter unpark(231003):\n");
    display(lot);

    return 0;
}

/* ===== your tasks ===== */

/* TODO #1: hash function
   Return an index in [0..MAX-1].
   Keep it simple and reasonable for numeric plates.
   Example idea (make your own):
       int last3 = plate % 1000;
       return last3 % MAX;
*/
int hashF(int plate) { // a numeric plate
    int hash = 0;
    while(hash != 0) {
        hash = hash + (plate % 10);
        hash = hash / 10;
    }
    return hash; 
}

/* TODO #2: insert/update with chaining, sorted by plate (ascending).
   Rules:
     - Find the bucket with hashF(plate).
     - Traverse with pointer-to-pointer.
     - If same plate is found: update owner, do NOT create a duplicate.
     - Otherwise, allocate a node and insert in ascending order by plate.
*/
void parkCar(Dic D, carType car) {
    int key = hashF(car.plate);
    openCar *trav = &D[key]; 

    /* pointer-to-pointer traversal to keep list sorted */
    for (; *trav !=NULL && (*trav)->car.plate < car.plate; trav = &(*trav)->link){}

    if (*trav != NULL && (*trav)->car.plate == car.plate){
        printf("DUPLICATE FOUND BRUH\n");
        strcpy((*trav)->car.owner, car.owner); //dont inseret and update the old owner to the new owner
        return;
    }
    /* if plate exists, update owner */

    /* insert new node before first larger plate (or at end) */
    openCar newNode = (openCar)malloc(sizeof(struct node));
        if (newNode != NULL){
            newNode->car = car; // assign 
            newNode->link = *trav; //link to the next 
            *trav = newNode; // link to the new node
        }
    
}

/* TODO #3: membership by plate only. */
bool isParked(Dic D, int plate) {
    int key = hashF(plate);
    openCar trav;

    for (trav = D[key]; trav != NULL && trav->car.plate != plate; trav = trav->link){}
    return (trav != NULL) ? true : false;
}

/* ===== optional: delete by plate ===== */
bool unparkCar(Dic D, int plate) {
    int key = hashF(plate);
    openCar *trav;

    for (trav = &D[key]; *trav != NULL && (*trav)->car.plate != plate; trav = &(*trav)->link){}
    
    if (*trav != NULL){ //meaning there is and equal plate
        openCar temp = *trav;
        *trav = temp->link;
        free(temp);
        return 1;
    }
    return 0;
}

/* ===== provided: init + printer ===== */
void initDictionary(Dic D) {
    for (int i = 0; i < MAX; ++i) {
        D[i] = NULL;
    }
}

void display(Dic D) {
    for (int i = 0; i < MAX; ++i) {
        printf("[%d]\t", i + 1);
        if (D[i] == NULL) {
            printf("NULL\n");
        } else {
            openCar trav;
            for (trav = D[i]; trav != NULL; trav = trav->link) {
                printf("%d%s", trav->car.plate, trav->link ? " -> " : ".\n");
            }
        }
    }
}
