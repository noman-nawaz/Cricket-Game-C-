/*Name: NOMAN NAWAZ
 Roll No: BCSF20M032
 Section: CS_MORNING*/

#include "Team.h"
#include "Driver.h"
#include "menu.h"
#include "Player.h"
#include <fstream>

int main()
{
	int choice, choice1;
	do
	{
		choice = choice1 = 0;
		welcomeBoard();
		choice = selectChoice();
		system("CLS");
		menu(choice);
		if (choice == 2)
		{
			cout << "1. Go to main menu " << endl;
			cout << "0. Exit " << endl;
			choice1 = selectChoice();
			system("CLS");
			if (choice1 == 0)
			{
				menu(choice1);
			}
		}
		else if (choice == 3)
		{
			exit(0);
		}

	} while (choice1 == 1);

	string teams[5];
	teams[0] = "Pakistan";
	teams[1] = "Australia";
	teams[2] = "New Zealand";
	teams[3] = "Zimbabwe";
	teams[4] = "Sri Lanka";

	displayTeams();
	choice = selectChoice();
	system("CLS");

	Team t1;           // Team 1
	t1.setTeamId(teams[choice - 1]);
	t1.setWickets(10);
	t1.setBalls(15);
	cout << "Your Team is: " << t1.getTeamId()<<endl;

	string totalPlayer[80];
	ifstream in("TeamPlayers.txt", ios::in | ios::app | ios::binary);
	for (int i = 0; i < 80; i++)
	{
		in >> totalPlayer[i];
	}

	displayPlayers(choice);
	Player p[11];            //Team of 11 Players

	cout << "Enter the number to select the relevant player." << endl;
	int temp, arr[11] = { 0 };
	for (int i = 0; i < 11; i++)
	{
		if (choice == 1)
		{  
			cout << "Player " << i + 1 << ": ";
			temp = selectPlayer();
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					cout << "Already taken. Enter again: ";
					temp=selectPlayer();
					if (i != 1)
					{
						j=0;
						j--;
					}
					else
					{
						j--;
					}
				}
			}
			arr[i] = temp;
			p[i].setPlayerId(totalPlayer[temp - 1]);
		}
		else if (choice == 2)
		{
			cout << "Player " << i + 1 << ": ";
			temp = selectPlayer();
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					cout << "Already taken. Enter again: ";
					temp = selectPlayer();
					if (i != 1)
					{
						j = 0;
						j--;
					}
					else
					{
						j--;
					}
				}
			}
			arr[i] = temp;
			p[i].setPlayerId(totalPlayer[16 + (temp - 1)]);
		}
		else if (choice == 3)
		{
			cout << "Player " << i + 1 << ": ";
			temp = selectPlayer();
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					cout << "Already taken. Enter again: ";
					temp = selectPlayer();
					if (i != 1)
					{
						j = 0;
						j--;
					}
					else
					{
						j--;
					}
				}
			}
			arr[i] = temp;
			p[i].setPlayerId(totalPlayer[32 + (temp - 1)]);
		}
		else if (choice == 4)
		{
			cout << "Player " << i + 1 << ": ";
			temp = selectPlayer();
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					cout << "Already taken. Enter again: ";
					temp = selectPlayer();
					if (i != 1)
					{
						j = 0;
						j--;
					}
					else
					{
						j--;
					}
				}
			}
			arr[i] = temp;
			p[i].setPlayerId(totalPlayer[48 + (temp - 1)]);
		}
		else if (choice == 5)
		{
			cout << "Player " << i + 1 << ": ";
			temp = selectPlayer();
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					cout << "Already taken. Enter again: ";
					temp = selectPlayer();
					if (i != 1)
					{
						j = 0;
						j--;
					}
					else
					{
						j--;
					}
				}
			}
			arr[i] = temp;
			p[i].setPlayerId(totalPlayer[64 + (temp - 1)]);
		}
	}

	system("CLS");
	cout << endl << "Here is your selected team players: " << endl;

	for (int i = 0; i < 11; i++)
	{
		cout << i + 1 << " : ";
		p[i].display();
	}

	char flag;
	int id, position;

	do {
		cout << "Do you want to modify the batting order? (y/n)." << endl;
		cin >> flag;
		while (flag != 'y' && flag != 'n')
		{
			cout << "Enter correct choice: ";
			cin >> flag;
		}

		if (flag == 'y')
		{
			Player temp;
			cout << "Please enter the id number of the player which needs to be modified:";
			cin >> id;
			cout << "Please specify the position number in the team to insert the player: ";
			cin >> position;

			temp.setPlayerId(p[position - 1].getPlayerId());
			p[position - 1].setPlayerId(p[id - 1].getPlayerId());
			p[id - 1].setPlayerId(temp.getPlayerId());

		}
		else
		{
			break;
		}
	} while (flag == 'y');

	system("CLS");
	cout << endl << "Here is Batting order of players: " << endl;

	for (int i = 0; i < 11; i++)
	{
		cout << i + 1 << " : ";
		p[i].display();
	}


	bool flag1;
	flag1 = doToss();
	cout << "___________Now, Let's Start your Game_____________";
	Driver d;
	int totalBalls = t1.getBalls();

	switch (flag1)
	{
		// For Bowling First
	//"_________________________________________________________________________________________"
	//"_________________________________________________________________________________________"
	case false:
		int length, width, height, deviation;

		int temp;

		for (int i = 1; i <= totalBalls; i++)
		{
			cout << "\n###__________________________________________________________________###" << endl;
			
			cout << "Enter ball Length to be delivered (1-50). (>50 No ball): ";
			cin >> length;
			cout << "Enter ball width to be delivere (1-5). (>5 Wide): ";
			cin >> width;
			cout << "Enter ball height to be delivered (1-5). (>5 Bouncer):  ";
			cin >> height;
			cout << "Enter ball deviation to be delivered:(-5, 5). (Otherwise Normal):  ";
			cin >> deviation;
			system("CLS");
			cout << "Previous Ball Statistics: \n\n";
			if (d.getBallLabel() == "NoBall" || (d.getBallLabel() == "Wide" && d.getIsStrike() != true))
			{
				i--;
			}

			d.setBallLabel(length, width, height, deviation);

			temp = rand() % 2;
			d.setIsStrike(temp);
			d.drive(t1);
			cout << "###__________________________________________###" << endl;
			d.displayDriver();
			cout << "###__________________________________________###" << endl;
			t1.display();

			if (i == totalBalls)
			{
				cout <<endl << "Target given to your team is: " << t1.getScore() + 1<< endl;
			}

		}

		if (d.randomScoreGenerator(t1) > t1.getScore())
		{
			t1.setStatusWin(0);
			cout << "Your team score is: " << d.randomScoreGenerator(t1) << endl;
		}
		else if (d.randomScoreGenerator(t1) < t1.getScore())
		{
			t1.setStatusWin(1);
			cout << "Your team score is: " << d.randomScoreGenerator(t1) << endl;
		}
		else
		{
			t1.setStatusWin(2);
			cout << "Your team score is: " << d.randomScoreGenerator(t1) << endl;
		}
		t1.decisionOfGame2();
		break;
		// For Batting First
	//"_________________________________________________________________________________________"
	//"_________________________________________________________________________________________"
	case true:

		int len, wid, hei, dev;
		int tBalls = t1.getBalls();

		int temp1;
		int strike;

		for (int i = 1; i <= tBalls; i++)
		{
			len = rand() % 53;
			wid = rand() % 8;
			hei = rand() % 7;
			dev = rand() % 15 - 5;

			cout << "\nEnter 1 to Strike or Enter 0 to skip: ";
			cin >> strike;
			//cout << "\n###__________________________________________________________________###" << endl;
			//cout << "###__________________________________________________________________###" << endl;
			cout << "###__________________________________________________________________###" << endl;
			cout << "Ball Length= " << len << endl;
			cout << "Ball Width= " << wid << endl;
			cout << "Ball Height= " << hei << endl;
			cout << "Angle of Deviation= " << dev << endl;

			cout << "###__________________________________________###" << endl;
			system("CLS");
			cout << "Previous Ball Statistics: \n\n";
			d.setIsStrike(strike);
			d.setBallLabel(len, wid, hei, dev);

			if (d.getBallLabel() == "NoBall" || (d.getBallLabel() == "Wide" && d.getIsStrike() != true))
			{
				i--;
			}

			d.drive(t1);
			cout << "###__________________________________________###" << endl;
			d.displayDriver();
			cout << "###__________________________________________###" << endl;
			t1.display();

			if (i == tBalls)
			{
				cout << endl << "Target given to opponent team is: " << t1.getScore() + 1 << endl;;
			}
		}

		if (d.randomScoreGenerator(t1) > t1.getScore())
		{
			t1.setStatusWin(0);
			cout << "Opponent team score is: " << d.randomScoreGenerator(t1) << endl;

		}
		else if(d.randomScoreGenerator(t1)< t1.getScore())
		{
			t1.setStatusWin(1);
			cout << "Opponent team score is: " << d.randomScoreGenerator(t1) << endl;

		}
		else
		{
			t1.setStatusWin(2);
			cout << "Opponent team score is: " << d.randomScoreGenerator(t1) << endl;
		}
		t1.decisionOfGame1();
		break;
	}
	return 0;
}