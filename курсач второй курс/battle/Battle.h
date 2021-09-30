#ifndef Battle_s
#define Battle_s

void ppolef(char** pole);                                              //функція генерації початкового видимого поля комп'ютера
void fppolef(char** pole);                                              //функція запису у файл ходів користувача
void sppolef(char** pole);                                   //функція зчитування з файлу ходів користувача
int amountship(char** pole);                                //функція підрахунку підбитих користувачем кораблів                                

char hod_userhk();                               //функція введення горизонтальної координати пострілу користувача
int hod_uservk();                                //функція введення вертикальної координати пострілу користувача
//функція перевірки попадання користувачем
int userhit(char& horCoord, int& verCoord, char** arr, char** pole);

int hod_komphk();                                  //функція генерації горизонтальної координати пострілу комп'ютера
int hod_kompvk();                                  //функція генерації вертикальної координати пострілу комп'ютера
int komphit(int& horCoor, int& verCoord, char** ar_user);                                     //перевірка попадання комп'ютера
int amountSh(char** ar_user);                     //функція підрахунку підбитих комп’ютером кораблів

int choosehod();                                   // функція вибора ходу


#endif

