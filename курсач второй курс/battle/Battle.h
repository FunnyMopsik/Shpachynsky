#ifndef Battle_s
#define Battle_s

void ppolef(char** pole);                                              //������� ��������� ����������� �������� ���� ����'�����
void fppolef(char** pole);                                              //������� ������ � ���� ���� �����������
void sppolef(char** pole);                                   //������� ���������� � ����� ���� �����������
int amountship(char** pole);                                //������� ��������� ������� ������������ �������                                

char hod_userhk();                               //������� �������� ������������� ���������� ������� �����������
int hod_uservk();                                //������� �������� ����������� ���������� ������� �����������
//������� �������� ��������� ������������
int userhit(char& horCoord, int& verCoord, char** arr, char** pole);

int hod_komphk();                                  //������� ��������� ������������� ���������� ������� ����'�����
int hod_kompvk();                                  //������� ��������� ����������� ���������� ������� ����'�����
int komphit(int& horCoor, int& verCoord, char** ar_user);                                     //�������� ��������� ����'�����
int amountSh(char** ar_user);                     //������� ��������� ������� ���������� �������

int choosehod();                                   // ������� ������ ����


#endif

