#ifndef REMAINBUULET_H
#define REMAINBULLET_H
class Remainbullet
{
private:
	int bCounter = 5;
	
public:
	bool isShooting = false;
	int GetCounter() { return bCounter; }
	void SetCounter(int counter) { bCounter = counter; }

};
#endif

