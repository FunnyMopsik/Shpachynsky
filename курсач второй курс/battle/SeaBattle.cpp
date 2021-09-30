#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <cstdlib>
#include "PlaceShip.h"
#include "Battle.h"
using namespace std;

int main()
{
	int m = 0;
	int ship, horCoordShip, verCoordShip, Orient;

	char** pole = new char* [10];
	for (int i = 0; i < 10; i++)
		pole[i] = new char[10];
	ppolef(pole);

	//--------- умовне поле для комп'ютера в невидимому варiантi ----------------
	char** ar = new char* [13];
	for (int i = 0; i < 13; i++)
		ar[i] = new char[13];

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			ar[i][j] = -2;
		}
	}
	//-------------------масив користувацького видимого поля----------------------
	char** ar_user = new char* [13];
	for (int i = 0; i < 13; i++)
		ar_user[i] = new char[13];

	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 13; j++)
		{
			ar_user[i][j] = -2;
		}
	cout << endl;
	
	//------------------вибираємо продовження гри або ж почати нову гру--------------
	int k;
	int t;
	
	char* str = new char[101];
	char* st = new char[101];
	setlocale(LC_ALL, "Ukrainian");
	cout << "Для продовження розпочатої гри виберiть 1\n";
	cout << "Для початку нової гри виберiть 2\n";
	setlocale(LC_ALL, ".OCP");
	cin >> t;
	
	switch (t)
	{
	case 1:

		readuser(ar_user);
		aruserpole(ar_user);
		break;
	case 2:
		setlocale(LC_ALL, "Ukrainian");
		cout << "Виберiть варiант розстановки кораблiв: автоматичний або ручний\n";
		cout << "Якщо автоматичний, виберiть - 1 \n";
		cout << "Якщо ручна розстановка, виберiть - 0 \n";
		setlocale(LC_ALL, ".OCP");
		cin >> k;
		//------------------------------------------------розстановка кораблiв користувачем---------------------------------	
		//------------------------------------------------автоматична---------------------------------------

		setlocale(LC_ALL, "Ukrainian");
		upload();
		int sum=0;
		switch (k)
		{
		case 1:
			// розмiщення 4-палубного корабля
			do
			{
				int testp = 0;
				int counter = 0;
				int ship = 4;
				Orient = chooseorient(k);
				horCoordShip = HorCoord(k);
				verCoordShip = VerCoord(k);
				for (int k = 0; k <= ship; k++)
					testp += test(ar_user, horCoordShip, verCoordShip, Orient, k, ship);
				if (testp == 0)
				{
					shipplace(ar_user, horCoordShip, verCoordShip, Orient, ship);
				}
				else continue;
				sum = amountshipp(ar_user);
			} while (sum < 4);
			// розмiщення 3-палубного корабля
			do
			{
				int testp = 0;
				int counter = 0;
				int ship = 3;
				Orient = chooseorient(k);
				horCoordShip = HorCoord(k);
				verCoordShip = VerCoord(k);
				for (int k = 0; k <= ship; k++)
					testp += test(ar_user, horCoordShip, verCoordShip, Orient, k, ship);
				if (testp == 0)
				{
					shipplace(ar_user, horCoordShip, verCoordShip, Orient, ship);
				}
				else continue;
				sum = amountshipp(ar_user);
			} while (sum < 10);

			// розмiщення 2-палубного корабля
			do
			{
				int testp = 0;
				int counter = 0;
				int ship = 2;
				Orient = chooseorient(k);
				horCoordShip = HorCoord(k);
				verCoordShip = VerCoord(k);
				for (int k = 0; k <= ship; k++)
					testp += test(ar_user, horCoordShip, verCoordShip, Orient, k, ship);
				if (testp == 0)
				{
					shipplace(ar_user, horCoordShip, verCoordShip, Orient, ship);
				}
				else continue;
				sum = amountshipp(ar_user);
			} while (sum < 16);

			// розмiщення 1-палубного корабля
			do
			{
				int testp = 0;
				horCoordShip = onehorCoord();
				verCoordShip = oneverCoord();

				testp += testone(horCoordShip, verCoordShip, ar_user);

				if (testp == 0)
				{
					placeone(horCoordShip, verCoordShip, ar_user);
				}
				else continue;

				sum = amountshipp(ar_user);
				
			} while (sum < 20);
			setlocale(LC_ALL, ".OCP");
			writeuser(ar_user);
			//readuser(ar_user);
			setlocale(LC_ALL, "Ukrainian");
			cout << "========== Ваше iгрове поле ==========" << endl;
			setlocale(LC_ALL, ".OCP");
			aruserpole(ar_user);
			break;
			
			//---------------------------------------------ручна розстановка-------------------------------------------
		case 0:
			setlocale(LC_ALL, "Ukrainian");
			cout << " Перед вами поле. Необхiдно здiйснити розстановку кораблiв. " << endl;

			setlocale(LC_ALL, ".OCP");
			aruserpole(ar_user);

			do
			{
				do
				{
					ship = chooseship();                    // вибiр типу корабля
					if (ship == 0) cout << " Error. Try again." << endl;
					else break;
				} while (1);
				switch (ship)
				{
				case 4:
					do
					{
						int count = 0;
						int testp = 0;
						Orient = chooseorient(k);                                      // вибiр орiєнтацiї корабля
						verCoordShip = VerCoord(k);                                    // вертикальна координата
						horCoordShip = HorCoord(k);                                    // горизонтальна координата

						do
						{

							testp += test(ar_user, horCoordShip, verCoordShip, Orient, count, ship);  //перевiрка можливостi розмiщення всiх пабул обраного корабля
							count++;

						} while (count < 4);
						if (testp > 0) continue;
						else if (testp == 0) break;

					} while (1);
					shipplace(ar_user, horCoordShip, verCoordShip, Orient, ship);
					writeuser(ar_user);
					//readuser(ar_user);
					system("cls");
					aruserpole(ar_user);


					break;
				case 3:
					do
					{
						int count = 0;
						int testp = 0;
						Orient = chooseorient(k);                    // вибiр орiєнтацiї корабля
						verCoordShip = VerCoord(k);                  // вертикальна координата
						horCoordShip = HorCoord(k);                        //горизонтальна координата

						do
						{

							testp += test(ar_user, horCoordShip, verCoordShip, Orient, count, ship);  //перевiрка можливостi розмiщення всiх пабул обраного корабля
							count++;
						} while (count < 3);
						if (testp > 0) continue;
						else if (testp == 0) break;

					} while (1);
					shipplace(ar_user, horCoordShip, verCoordShip, Orient, ship);
					writeuser(ar_user);
					//readuser(ar_user);
					system("cls");
					aruserpole(ar_user);

					break;
				case 2:
					do
					{
						int count = 0;
						int testp = 0;
						Orient = chooseorient(k);                    // вибiр орiєнтацiї корабля
						verCoordShip = VerCoord(k);                  // вертикальна координата
						horCoordShip = HorCoord(k);                        //горизонтальна координата                       

						do
						{
							testp += test(ar_user, horCoordShip, verCoordShip, Orient, count, ship);  //перевiрка можливостi розмiщення всiх пабул обраного корабля
							count++;
						} while (count < 2);
						if (testp > 0) continue;
						else if (testp == 0) break;

					} while (1);
					shipplace(ar_user, horCoordShip, verCoordShip, Orient, ship);
					writeuser(ar_user);
					//readuser(ar_user);
					system("cls");
					aruserpole(ar_user);

					break;
				case 1:

					do
					{
						int count = 0;
						int testp = 0;
						verCoordShip = VerCoord(k);                   // вертикальна координата
						horCoordShip = HorCoord(k);                   //горизонтальна координата
						testp += testone(horCoordShip, verCoordShip, ar_user);
						if (testp == 0)
						{
							placeone(horCoordShip, verCoordShip, ar_user);
							sum += 1;
							cout << "Розмiщено 1-палубний корабель" << endl;
						}
						else if (testp > 0) continue;
						//testp += test(ar_user, horCoordShip, verCoordShip, Orient, count, ship);  //перевiрка можливостi розмiщення всiх пабул обраного корабля
						//if (testp > 0) continue;
						//else if (testp == 0) break;

					} while (1);
					shipplace(ar_user, horCoordShip, verCoordShip, Orient, ship);
					writeuser(ar_user);
					//readuser(ar_user);
					system("cls");
					aruserpole(ar_user);

					break;
				}

				int summa = amountshipp(ar_user);
				if (summa == 20) break;
				m++;
			} while (1);
			cout << " You've done it! " << endl;

			break;
		}
	   
	   //-----------------автоматична разстановка кораблiв комп'ютера-----------
		setlocale(LC_ALL, "Ukrainian");
		upload();
		sum = 0;
		do
		{
			int testp = 0;
			int counter = 0;
			int ship = 4;
			Orient = orientKomp();
			horCoordShip = HorCoordK();
			verCoordShip = VerCoordK();
			for (int k = 0; k <= ship; k++)
				testp += testK(ar, horCoordShip, verCoordShip, Orient, k, ship);
			if (testp == 0)
			{
				shipplaceK(ar, horCoordShip, verCoordShip, Orient, ship);
			}
			else continue;
			sum = amountshippK(ar);
		} while (sum<4);

		do
		{
			int testp = 0;
			int counter = 0;
			int ship = 3;
			Orient = orientKomp();
			horCoordShip = HorCoordK();
			verCoordShip = VerCoordK();
			for (int k = 0; k <= ship; k++)
				testp += testK(ar, horCoordShip, verCoordShip, Orient, k, ship);
			if (testp == 0)
			{
				shipplaceK(ar, horCoordShip, verCoordShip, Orient, ship);
			}
			else continue;
			sum = amountshippK(ar);
		} while (sum < 10);
		
		do
		{
			int testp = 0;
			int counter = 0;
			int ship = 2;
			Orient = orientKomp();
			horCoordShip = HorCoordK();
			verCoordShip = VerCoordK();
			for (int k = 0; k <= ship; k++)
				testp += testK(ar, horCoordShip, verCoordShip, Orient, k, ship);
			if (testp == 0)
			{
				shipplaceK(ar, horCoordShip, verCoordShip, Orient, ship);
			}
			else continue;
			sum = amountshippK(ar);
		} while (sum < 16);

		do
		{
			int testp = 0;
			horCoordShip = onehorCoordK();
			verCoordShip = oneverCoordK();
			testp += testoneK(horCoordShip, verCoordShip, ar);
			if (testp == 0)
			{
				placeoneK(horCoordShip, verCoordShip, ar);
			}
			else continue;
			sum = amountshippK(ar);
		} while (sum < 20);
		setlocale(LC_ALL, ".OCP");
		writeK(ar);
		//readK(ar);
		fppolef(pole);
		/*arpole (ar);*/
		break;
	}
	cout << endl;
		
	//---------------------------------------органiзацiя бою------------------------------

	//----------------- сформуємо видиме для користувача поле -------------------------
	char horCoord = 0;
	int horCoor = 0;
	int verCoord = 0;
	int userHit = 0;

	
//---------------------------ходи користувача-------------------------------------------	
	do
	{
		//readuser(ar_user);
		setlocale(LC_ALL, "Ukrainian");
		cout << "===== Поле Вашого противника - комп'ютера =====" << endl;
		setlocale(LC_ALL, ".OCP");
		sppolef(pole);		
		//cout << "Реальне поле компа " << endl;
		//sppolef(ar);

		while (1)                                                         //хiд користувача
		{
			setlocale(LC_ALL, "Ukrainian");
			horCoord = hod_userhk();
			verCoord = hod_uservk();
			cout << endl;
			userHit = userhit(horCoord, verCoord, ar, pole);                        //перевiрка ходу на попадання
			setlocale(LC_ALL, ".OCP");
			if (userHit == 0)
			{
				
				cout << endl;
				pole[(int)horCoord - 65][verCoord - 1] = '*';
				//fppolef(pole);
				//system("cls");				
				sppolef(pole);
				setlocale(LC_ALL, "Ukrainian");
				cout << " Не попали! Спробуйте наступного разу! " << endl;
				setlocale(LC_ALL, ".OCP");
				break;

			}
			else if (userHit == 1)
			{

				
				cout << endl;
				pole[(int)horCoord - 65][verCoord - 1] = 'x';
				//fppolef(pole);
				//system("cls");
				sppolef(pole);
				setlocale(LC_ALL, "Ukrainian");
				cout << " Ви попали! Ходiть ще раз. " << endl;
				setlocale(LC_ALL, ".OCP");
				continue;
			}
			else if (userHit == -1)
			{
				setlocale(LC_ALL, "Ukrainian");
				cout << " Сюди вже стрiляли. Спробуйте ще раз! " << endl;

				setlocale(LC_ALL, ".OCP");
				continue;
			}
		}
		sppolef(pole);
		int amountShip = amountship(pole);                  //перевiрка кiлькостi пiдбитих палуб
		setlocale(LC_ALL, "Ukrainian");
		switch (amountShip)
		{
		case 1:
			cout << " Ой ... Я, здається, програв. Вiтаю, ти - переможець!" << endl;
			break;
		case 0:
			cout << " Граємо далi. Хiд за комп'ютером. " << endl;
			break;
		}
		setlocale(LC_ALL, ".OCP");

		// ---------------------------------ходи комп'ютера ---------------------------------------
		do
		{
			int stime;
			stime = (unsigned int)time(NULL) / 2;
			srand(stime);
			horCoor = rand() % 10+1;
			verCoord = rand() % 10+1;
			//horCoor = hod_komphk();
			//verCoord = hod_kompvk();
			cout << endl;
			userHit = komphit(horCoor, verCoord, ar_user);                       //перевiрка ходу на попадання

			if (userHit == 0)
			{
				//readuser(ar_user);
				cout << endl;
				ar_user[horCoor - 1][verCoord - 1] = '*';
				//writeuser(ar_user);
				//system("cls");
				setlocale(LC_ALL, "Ukrainian");
				cout << " Не попав! Спробую наступного разу! " << endl;
				setlocale(LC_ALL, ".OCP");
				break;

			}
			else if (userHit == 1)
			{

				//readuser(ar_user);
				cout << endl;
				ar_user[horCoor - 1][verCoord - 1] = 'x';
				//writeuser(ar_user);
				//system("cls");
				setlocale(LC_ALL, "Ukrainian");
				cout << " Ура !!! Попав! Знову мiй хiд. " << endl;

				setlocale(LC_ALL, ".OCP");
				continue;
			}
			else if (userHit == -1)
			{

				setlocale(LC_ALL, "Ukrainian");
				cout << "Ой ... Сюди вже стрiляв! Якщо не заперечуєш, спробую ще раз! " << endl;
				//system("cls");
				cout << " Почекай. Я задумався. " << endl;

				setlocale(LC_ALL, ".OCP");
				continue;
			}

		} while (1);
		//readuser(ar_user);
		aruserpole(ar_user);
		int amountShipus = amountSh(ar_user);
		setlocale(LC_ALL, "Ukrainian");
		switch (amountShipus)
		{
		case 1:
			cout << " Ви програли. Менi дуже шкода." << endl;
			break;
		case 0:
			cout << " Граємо далi. Твiй хiд, користувач. " << endl;
			break;
		}
		setlocale(LC_ALL, ".OCP");
		if (amountShipus == 1 || amountShip == 1)
		{
			cout << " Game over! " << endl;
			break;
		}
	} while (1);
	
	delete[]str;
	delete[]st;



	for (int i = 0; i < 13; i++)
		delete[]ar_user[i];
	delete[]ar_user;

	for (int i = 0; i < 13; i++)
		delete[]ar[i];
	delete[]ar;

	return 0;
}