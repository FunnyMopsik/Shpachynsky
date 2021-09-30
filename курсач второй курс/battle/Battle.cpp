#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

#include "Battle.h"
using namespace std;
//----------------------------------------функцiї користувача--------------------------
//----------------------------------------функцiя генерацiї початкового видимого поля комп'ютера------------------------
void ppolef ( char **pole )
{
	 
	//заповнимо поле
	 for ( int i = 0; i < 10; i ++)
		 for ( int j = 0; j < 10; j ++ )
			 pole [i][j] = -2;


}
//----------------------------------функцiя запису у файл ходiв користувача------------------------------

void fppolef (char **pole)                                        // функция записи поля
{
   FILE *f;
   f = fopen ("seabattle1.txt", "w");
   if (f != NULL)
   {
        for ( int i = 0; i < 10; i ++)
			for( int j = 0; j < 10; j ++)
			     fputc (pole [i][j], f);
   }
   else
   {
         cout << " Помилка. Не можу вiдкрити файл. " << endl;
   }
  
   fclose (f);
}
//----------------------------------функцiя зчитування з файлу ходiв користувача------------------------------

void sppolef (char **pole)                                       
{
   /*FILE *f;
   f = fopen ("seabattle1.txt", "r");
   if (f!=NULL)
   {
         for ( int i = 0; i < 10; i ++ )
		 {
			 for( int j = 0; j < 10; j ++)
			 {
			    pole[i][j] = fgetc(f);   
			 }
		 }
   }
   else
   {
         cout << " Помилка. Не можу вiдкрити файл. " << endl;
   }
fclose (f);*/
	//cout << "=== Поле вашого противника - комп'ютера ===" << endl;
   for ( int i = 0; i < 2; i ++)
		 cout << ' ';
	 for ( int i = 0; i < 10; i ++)
		 cout << i + 1<<" ";
	 cout << endl;

   for ( int i = 0; i < 10; i ++)
	{
		cout << char(i + 65) << ' ';
		for ( int j = 0; j < 10; j ++)
		{
			cout <<pole [i][j]<< " ";
		}
     cout <<endl;
   }

  
}
//--------------------------------------функцiя пiдрахунку пiдбитих користувачем кораблiв-----------------------------
int amountship (char **pole)
{
    int count = 0;
	int sum = 0;

	for ( int i = 0; i < 10; i ++)
		for ( int j = 0; j < 10; j ++)
		{
		     count = ( pole [i][j] == 'x')? 1:0;
			 sum += count;
		}
	if (sum == 18) return 1;
	if (sum < 18) return 0;

}
//-----------------------------------------функцiя введення горизонтальної координати пострiлу користувача------------------------------
char hod_userhk ( )  

{
    
	char a;
	
    cout << " Введiть координати " << endl;

	cout << " Для горизонтальної координати введiть букву латинського алфавiту (вiд A до K - в верхньому регiстрi) " << endl;

while (1)
{
	cin >> a;
	if (((int) a < 65) || ((int) a > 74) )
		{
			cout << " Помилка. Ви ввели невiрну координату! Спробуйте ще раз. " << endl;
			
			continue;
	    }
	else
	    {
           cout << " Горизонтальна координата - " << a;

		   break;
	    }

}
  return a;
}
//----------------------------------------функцiя введення горизонтальної координати пострiлу користувача--------------------------
int hod_uservk ()                                        
{
	int k;	
	
	cout << " Для вертикальної координати введiть цифру (вiд 1 до 10) " << endl;

while (1)
{
   cin >> k;

   if ( k < 1 || k > 10)
   {
      cout << " Помилка. Ви ввели невiрну координату! Спробуйте ще раз. " << endl;

	  continue;
   }
   else 
   {
      cout << " Вертикальна координата - " << k << endl;

	  break;
   }
}
   
   return k;
}
//--------------------------------------------функцiя перевiрки попадання-------------------------------------------------------
int userhit ( char &horCoord, int &verCoord, char ** ar,char **pole)                             //проверка хода пользователя насчет попадания
{
	
	for (int i = 0; i < 2; i++)
		cout << ' ';
	for (int i = 0; i < 10; i++)
		cout << i + 1 << " ";
	cout << endl;

	for (int i = 1; i < 11; i++)
	{
		cout << char(i + 64) << ' ';
		for (int j = 1; j < 11; j++)
		{
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
	//cout << "horCoor = "<< horCoord<<"verCoord = " << verCoord<< " " << ar[horCoord][verCoord]<<endl;
	if ( ar [(int)horCoord - 65][verCoord - 1] == 127) 
	{
		return 1;
	}
	else if ( pole [(int)horCoord - 65][verCoord - 1] == '*' || pole [(int)horCoord - 65][verCoord - 1] == 'x')
	{
	    return -1;
	}
	else 
	{
        return 0;
	}
}

//--------------------------------функцiї комп'ютера---------------------------------------
//--------------------------------функцiя генерацiї горизонтальної координати пострiлу комп'ютера--------------------
int hod_komphk ()
{
   
   int ar_time [100];
   srand (time (NULL));

   for (int i = 0; i < 99; i++)
	   ar_time [i] = rand ()%10 + 1;

   return ar_time [rand ()%100];
}
//----------------------------------функцiя генерацiї вертикальної координати пострiлу комп'ютера-----------------------
int hod_kompvk ()
{
	
   int ar_time [100];
   srand (time (NULL));
   
   for (int i = 0; i < 99; i ++)
	   ar_time [i] = rand ()%10 + 1;

   return ar_time [rand ()%100];
}
//------------------------------------  перевiрка попадання комп'ютера-----------------------------------
int komphit (int &horCoor, int &verCoord, char **ar_user)
{
	/*for (int i = 0; i < 2; i++)
		cout << ' ';
	for (int i = 0; i < 10; i++)
		cout << i + 1 << " ";
	cout << endl;

	for (int i = 1; i < 11; i++)
	{
		cout << char(i + 64) << ' ';
		for (int j = 1; j < 11; j++)
		{
			cout << ar_user[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << "horCoor = "<< horCoor<<"verCoord = " << verCoord<< " " << ar_user[horCoor][verCoord]<<endl;
	cout << (ar_user[horCoor][verCoord]== '■') << endl;
	/////////////////////////////////////////////

	if ( ar_user [horCoor][verCoord] == '■')
	{
		return 1;
	}
	else if ( ar_user [horCoor][verCoord] == '*' || ar_user [horCoor][verCoord] == 'x')
	{
	    return -1;
	}
	else 
	{
        return 0;
	}

}

int amountSh (char **ar_user)
{
    int count = 0;
	int sum = 0;

	for ( int i = 0; i < 10; i ++)
		for ( int j = 0; j < 10; j ++)
		{
		     count = ( ar_user [i][j] == 'x')? 1:0;
			 sum += count;
		}
	if (sum == 18) return 1;
	if (sum < 18) return 0;
}
