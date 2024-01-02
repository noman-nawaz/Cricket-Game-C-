#include "Driver.h"
#include <cstdlib>
void Driver::setToss()
{
	int flag;
	srand(static_cast<unsigned>(time(0)));
	flag = rand() % 2;
	if (flag == 0)
	{
		toss = "Heads";
	}
	if (flag == 1)
	{
		toss = "Tails";
	}
}

string Driver::getToss()
{
	return toss;
}

void Driver::setIsStrike(int choice)
{
	if (choice == 1)
	{
		isStrike = true;
	}
	else
	{
		isStrike = false;
	}
}

void Driver::setBallLabel(int len, int wid, int height, int deviation)
{
	if (len > pitchLength)
	{
		ballLabel = "NoBall";
	}
	else if (wid > ballWidth)
	{
		ballLabel = "Wide";
	}
	else if (height <= ballHeight && deviation <= 1 && deviation >= -1)
	{
		ballLabel = "Out";
	}
	else if (height > ballHeight)
	{
		ballLabel = "Bouncer";
	}
	else if (deviation <= 5 && deviation >= -5)
	{
		ballLabel = "Spin";
	}
	else
	{
		ballLabel = "Normal";
	}
}

void Driver::drive(Team& t2)
{
	t2.balls--;

	if (ballLabel == "NoBall")
	{
		int temp;
		t2.balls += 1;
		t2.score += 1;
		if (isStrike == true)
		{
			temp = rand() % 3 + 4;
			while (temp == 5)
			{
				temp = rand() % 3 + 4;
			}
			t2.score += temp;
		}
		else
		{
			t2.score += 0;
		}
	}
	else if (ballLabel == "Wide")
	{
		if (isStrike == true)
		{
			t2.score += 4;
		}
		else
		{
			t2.score += 1;
			t2.balls += 1;
		}
	}
	else if (ballLabel == "Bouncer")
	{
		if (isStrike == true)
		{
			t2.score += 6;
		}
		else
		{
			t2.score += 0;
		}
	}
	else if (ballLabel=="Spin" || ballLabel=="Normal")
	{
		int temp;
		if (isStrike == true)
		{
			temp = rand() % 7;
			while (temp == 3 || temp == 5)
			{
				temp = rand() % 7;
			}
			t2.score += temp;
		}
		else
		{
			t2.score += 0;
		}
	}
	else if (ballLabel == "Out")
	{
		t2.score += 0;
		t2.wickets -= 1;
		if (isStrike == true)
		{
			cout << "That was catch Out" << endl;
		}
		else
		{
			cout << "That was Wicket Out." << endl;
		}
	}
}

void Driver::displayDriver()
{
	cout << "Ball Label is: " << ballLabel << endl;
	if (isStrike == true)
	{
		cout << "Strike flag= True" << endl;
	}
	else
	{
		cout << "Strike flag= False" << endl;
	}
}

bool Driver::getIsStrike()
{
	return isStrike;
}

string Driver::getBallLabel()
{
	return ballLabel;
}

int Driver::randomScoreGenerator(Team &t)
{
	int temp = rand() % t.score + 10;
	return temp;
}