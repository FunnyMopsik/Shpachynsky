#ifndef Place_Ship
#define Place_Ship
//-----------------------------------структура для ручної розстановки кораблів----------------------------------

struct ship_user
{
    bool d;                        //орієнтації корабля - вертикально (0) або горизонтально (1)
    char x;                         //горизонтальна координата х(рядок)
    int y;                         //вертикальна координата у (стовпчик)

};

//---------------------------прототипи функцій------------------------------------------------

//-------------------------функції користувацької ручної і автоматичної розстановки кораблів---------------------------

void aruserpole(char** ar_user);                                  // поле користувача
int chooseship();                                                 // функція вибору типу корабля
int chooseorient(int& k);                                               // функція вибору орієнтації корабля
int HorCoord(int& k);                                                   // функція введення горизонтальної координати
int VerCoord(int& k);                                                   // функція введення вертикальної координати
int test(char** ar_user, int& horCoordShip, int& verCoordShip, int& Orient, int& count, int& sh);    // функція перевірки існування палуб
void shipplace(char** ar_user, int& horCoordShip, int& verCoordShip, int& Orient, int& sh);          // функція розміщення корабля
int amountshipp(char** ar_user);                                   // функція підрахунку палуб
void writeuser(char** ar_user);                                    // функція запису в файл поля користувача
void readuser(char** ar_user);                                     // функція зчитування з файлу поля користувача
int testone(int& horCoordShip, int& verCoordShip, char** ar_user); // функція перевірки однопалубника
void placeone(int& horCoordShip, int& verCoordShip, char** ar_user); //Функція розміщення однопалубника
int onehorCoord();                                                   //функція введення горизонтальної координати однопалубника
int oneverCoord();                                                   //функція введення вертикальної координати однопалубника
void upload();                                                       //функція вивеження повідомлення про завантаження

//-------------------------функції автоматичної розстановки для комп'ютера-------------------------
void arpole(char** ar);            // поле комп'ютера
int orientKomp();                  //функція вибору орієнтації корабля комп’ютера
int HorCoordK();                   //функція генерації горизонтальної координати корабля комп’ютера
int VerCoordK();                   //функція генерації вертикальної координати корабля комп’ютера
int testK(char** ar, int& horCoordShip, int& verCoordShip, int& Orient, int& counter, int& Ship); //функція перевірки існування палуб
void shipplaceK(char** ar, int& horCoordShip, int& verCoordShip, int& Orient, int& Ship);        //функція розміщення корабля на полі комп’ютера
int amountshippK(char** ar);                //функція підрахунку палуб на полі комп’ютера
void writeK(char** ar);                     //функція запису в файл поля комп’ютера
void readK(char** ar);                      //функція зчитування з файлу поля комп’ютера
int testoneK(int& horCoordShip, int& verCoordShip, char** ar);   // функція перевірки однопалубника
void placeoneK(int& horCoordShip, int& verCoordShip, char** ar); //Функція розміщення однопалубника
int onehorCoordK();                             //функція генерації горизонтальної координати однопалубника
int oneverCoordK();                             //функція генерації вертикальної координати однопалубника

#endif