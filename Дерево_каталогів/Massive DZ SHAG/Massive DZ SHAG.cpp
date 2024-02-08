
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
#include<list>
#include<vector>
#include<map>
#include"time.h"
#include<algorithm>
#include<iterator>
#include<io.h>
using namespace std;
class Card
{
	string name;
	char suit;//масть
	int point;
public:
	Card(string n, char s, int p):name(n),suit(s),point(p){}
	void Show()
	{
		cout << this->name << this->suit;
	}
	int GetPoint()
	{
		return this->point;
	}
	string GetName()
	{
		return name;
	}
	
};

class Game21
{
	int bank_bankir;
	vector<Card>koloda;
	vector<Card>koloda_player;
	vector<Card>koloda_bankir;
	void ShowKolodaBankirDark()
	{
		cout << "Koloda Bankira\n";
		cout << "*\n";
	}
	void ShowKolodaBankir()
	{
		cout << "Koloda Bankira\n";
		for (int i = 0; i < koloda_bankir.size(); i++)
		{
			koloda_bankir[i].Show();
			cout << " ";
		}
		cout << endl;
	}
	void ShowKolodaPlayer()
	{
		cout << "Your koloda\n";
		for (int i = 0; i < koloda_player.size(); i++)
		{
			koloda_player[i].Show();
			cout << " ";
		}
		cout << endl;
	}
	int SumaPointBankir()
	{
		int suma = 0;
		for (int i = 0; i < koloda_bankir.size(); i++)
		{
			suma += koloda_bankir[i].GetPoint();
		}
		return suma;
	}
	int SumaPointPlayer()
	{
		int suma = 0;
		for (int i = 0; i < koloda_player.size(); i++)
		{
			suma += koloda_player[i].GetPoint();
		}
		return suma;
	}
	void HangingOut()
	{
		random_shuffle(koloda.begin(), koloda.end());
		random_shuffle(koloda.begin(), koloda.end());
		random_shuffle(koloda.begin(), koloda.end());
		random_shuffle(koloda.begin(), koloda.end());
	}
	void Show()
	{
		for (int i = 0; i < koloda.size(); i++)
		{
			koloda[i].Show();
		}
	}
public:
	Game21()
	{
		this->bank_bankir = 0;
		koloda.push_back(Card("6", 3, 6));
		koloda.push_back(Card("6", 4, 6));
		koloda.push_back(Card("6", 5, 6));
		koloda.push_back(Card("6", 6, 6));

		koloda.push_back(Card("7",3, 7));
		koloda.push_back(Card("7", 4, 7));
		koloda.push_back(Card("7", 5, 7));
		koloda.push_back(Card("7", 6, 7));

		koloda.push_back(Card("8", 3, 8));
		koloda.push_back(Card("8", 4, 8));
		koloda.push_back(Card("8", 5, 8));
		koloda.push_back(Card("8", 6, 8));

		koloda.push_back(Card("9", 3, 9));
		koloda.push_back(Card("9", 4, 9));
		koloda.push_back(Card("9", 5, 9));
		koloda.push_back(Card("9", 6, 9));

		koloda.push_back(Card("10", 3, 10));
		koloda.push_back(Card("10", 4, 10));
		koloda.push_back(Card("10", 5, 10));
		koloda.push_back(Card("10", 6, 10));

		koloda.push_back(Card("J", 3, 2));
		koloda.push_back(Card("J", 4, 2));
		koloda.push_back(Card("J", 5, 2));
		koloda.push_back(Card("J", 6, 2));

		koloda.push_back(Card("Q", 3, 3));
		koloda.push_back(Card("Q", 4, 3));
		koloda.push_back(Card("Q", 5, 3));
		koloda.push_back(Card("Q", 6, 3));

		koloda.push_back(Card("K", 3, 4));
		koloda.push_back(Card("K", 4, 4));
		koloda.push_back(Card("K", 5, 4));
		koloda.push_back(Card("K", 6, 4));

		koloda.push_back(Card("A", 3, 11));
		koloda.push_back(Card("A", 4, 11));
		koloda.push_back(Card("A", 5, 11));
		koloda.push_back(Card("A", 6, 11));
	}
	
	
	void StartGame(int bank_player)
	{
		bool b = false, c=false,m=false;
		this->bank_bankir = bank_player;
		int  stavka,iterator=0,k=0;
		HangingOut();
		cout << "Enter bet->";
		cin >> stavka;
		while (stavka > bank_player)
		{
			cout << "Error bet!\n";
			cout << "Enter bet->";
			cin >> stavka;
		}
		while (true)
		{
			system("cls");
			if (iterator == koloda.size())
			{
				iterator = 0;
				HangingOut();
			}
			this->koloda_bankir.push_back(koloda[iterator]);
			iterator++;
			if (iterator == koloda.size())
			{
				iterator = 0;
				HangingOut();
			}
			ShowKolodaBankirDark();
			this->koloda_player.push_back(koloda[iterator]);
			iterator++;
			if (iterator == koloda.size())
			{
				iterator = 0;
				HangingOut();
			}
			ShowKolodaPlayer();
			if (koloda_player[0].GetName() == "6")
			{
				cout << "Play in DARK?(1-Yes,2-No)->";
				cin >> k;
				if (k == 1)
				{
					system("cls");
					ShowKolodaBankirDark();
					this->koloda_player.push_back(koloda[iterator]);
					iterator++;
					ShowKolodaPlayer();
					if (iterator == koloda.size())
					{
						iterator = 0;
						HangingOut();
					}
					if (SumaPointPlayer() == 17)
					{
						system("cls");
						ShowKolodaBankir();
						ShowKolodaPlayer();
						cout << "You win\n";
						cout << "+" << stavka << endl;
						bank_player += stavka;
						cout << "your bank: " << bank_player << endl;
						c = true;
					}
					else
						m = true;
					

				}

			}
			if (!c)
			{
				if (!m)
				{
					while (true)
					{
						cout << "Take another card(1-Yes,2-No)->";
						cin >> k;
						if (k == 1)
						{
							this->koloda_player.push_back(koloda[iterator]);
							iterator++;
							if (iterator == koloda.size())
							{
								iterator = 0;
								HangingOut();
							}
							if (SumaPointPlayer() == 21)
							{
								b = true;
								system("cls");
								ShowKolodaBankir();
								ShowKolodaPlayer();
								cout << "You win\n";
								cout << "+" << stavka << endl;
								bank_player += stavka;
								cout << "your bank: " << bank_player << endl;
								Sleep(2000);
								break;
							}

							if (SumaPointPlayer() > 21 && !(SumaPointPlayer() == 22 && koloda_player.size() == 2))
							{
								b = true;
								system("cls");
								ShowKolodaBankir();
								ShowKolodaPlayer();
								cout << "Suma > 21\nYou lose\n";
								cout << "-" << stavka << endl;
								bank_player -= stavka;
								cout << "your bank: " << bank_player<<endl;
								Sleep(3000);
								break;
							}
							system("cls");
							ShowKolodaBankirDark();
							ShowKolodaPlayer();
							continue;
						}
						break;
					}


					system("cls");
					ShowKolodaBankir();
					ShowKolodaPlayer();
					if (SumaPointPlayer() == 22 && koloda_player.size() == 2)
					{
						b = true;
						cout << "You win\n";
						cout << "+" << stavka << endl;
						bank_player += stavka;
						cout << "your bank: " << bank_player << endl;
					}
				}
				if (!b) {
					while (SumaPointBankir() <= 16)
					{
						/*Sleep(2000);*/
						
						Sleep(2000);
						this->koloda_bankir.push_back(koloda[iterator]);
						iterator++;
						if (iterator == koloda.size())
						{
							iterator = 0;
							HangingOut();
						}
						system("cls");
						ShowKolodaBankir();
						ShowKolodaPlayer();
						
						//Sleep(2000);//fghfghggfh

					}
					if (!m)
					{
						if (SumaPointBankir() == 22 && koloda_bankir.size() == 2)
						{
							cout << "You lose\n";
							cout << "-" << stavka << endl;
							bank_player -= stavka;
							cout << "your bank: " << bank_player << endl;
						}
						else if (SumaPointBankir() > 21)
						{
							cout << "You win\n";
							cout << "+" << stavka << endl;
							bank_player += stavka;
							cout << "your bank: " << bank_player << endl;
						}
						else if (SumaPointBankir() == 21)
						{
							cout << "You lose\n";
							cout << "-" << stavka << endl;
							bank_player -= stavka;
							cout << "your bank: " << bank_player << endl;
						}
						else if (SumaPointPlayer() > SumaPointBankir() && SumaPointPlayer() < 21)
						{
							cout << "You win\n";
							cout << "+" << stavka << endl;
							bank_player += stavka;
							cout << "your bank: " << bank_player << endl;
						}
						else if (SumaPointBankir() > SumaPointPlayer() && SumaPointBankir() < 21)
						{
							cout << "You lose\n";
							cout << "-" << stavka << endl;
							bank_player -= stavka;
							cout << "your bank: " << bank_player << endl;
						}
						else if (SumaPointBankir() == SumaPointPlayer())
						{
							cout << "You lose\n";
							cout << "-" << stavka << endl;
							bank_player -= stavka;
							cout << "your bank: " << bank_player << endl;
						}
					}
					else
					{
						if (SumaPointBankir() == 22 && koloda_bankir.size() == 2)
						{
							cout << "You lose\n";
							cout << "-" << stavka << endl;
							bank_player -= stavka;
							cout << "your bank: " << bank_player << endl;
						}
						else if (SumaPointBankir() > 21)
						{
							cout << "You win\n";
							cout << "+" << stavka << endl;
							bank_player += stavka;
							cout << "your bank: " << bank_player << endl;
						}
						else if (SumaPointBankir() == 21)
						{
							cout << "You lose\n";
							cout << "-" << stavka << endl;
							bank_player -= stavka;
							cout << "your bank: " << bank_player << endl;
						}
						else if (SumaPointPlayer()+5 > SumaPointBankir() && SumaPointPlayer()+5 < 21)
						{
							cout << "You win\n";
							cout << "+" << stavka << endl;
							bank_player += stavka;
							cout << "your bank: " << bank_player << endl;
						}
						else if (SumaPointBankir() > SumaPointPlayer()+5 && SumaPointBankir() < 21)
						{
							cout << "You lose\n";
							cout << "-" << stavka << endl;
							bank_player -= stavka;
							cout << "your bank: " << bank_player << endl;
						}
						else if (SumaPointBankir() == SumaPointPlayer()+5)
						{
							cout << "You lose\n";
							cout << "-" << stavka << endl;
							bank_player -= stavka;
							cout << "your bank: " << bank_player << endl;
						}
					}
				}
			}
			b = false;
			c = false;
			m = false;
			
			cout << "Continue game (1-Yes,2-No)->";
				cin >> k;
				if (k == 1)
				{
					cout << "Enter bet->";
					cin >> stavka;
					while (stavka > bank_player)
					{
						cout << "Error bet!\n";
						cout << "Enter bet->";
						cin >> stavka;
					}
					koloda_player.clear();
					koloda_bankir.clear();
				}
				else
					break;


		}


	}
};

int main()
{
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	srand(time(0));
	Game21 a;
	int bank;
	cout << "Enter your bank->";
	cin >> bank;
	a.StartGame(bank);
		
	
	system("pause");
	return 0;
}


