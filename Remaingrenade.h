#ifndef REMAINGRENADE_H
#define REMAINGRENADE_H
class Remaingrenade
{
private:
	int gCounter = 30;

public:
	bool isShooting = false;
	int GetCounter() { return gCounter; }
	void SetCounter(int counter) { gCounter = counter; }

};
#endif