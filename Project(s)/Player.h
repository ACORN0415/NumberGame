#pragma once
class Player
{
public:
	int getMyScore() { return myScore; }
	int getYourScore() { return yourScore; }
	int getMyWinPoint() { return myWinPoint; }
	int getYourWinPoint() { return yourWinPoint; }

	void setMyScore(int number) { myScore = number; }
	void setyourScore(int number) { yourScore = number; }
	void setMyWinPoint(int number) { myWinPoint = number; }
	void setYourWinPoint(int number) { yourWinPoint = number; }
private:
	int myScore;
	int yourScore;
	int myWinPoint;
	int yourWinPoint;
};

