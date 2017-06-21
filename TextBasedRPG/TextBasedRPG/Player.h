#pragma once
class Player
{
public:
	Player();
	~Player();

	const int &getHP() const;
	const int &getGold() const;

private:
	int hp;
	int gold;
};

