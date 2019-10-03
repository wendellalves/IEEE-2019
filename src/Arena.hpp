#ifndef ARENA_HPP
#define ARENA_HPP

#include <Arduino.h>

enum CONTAINER_SIDE {
	clawSide = 1,
	otherSide = 0
};

struct Ship {
	uint8_t currentPile = 0;
	uint8_t currentHeight = 1;

	void increment () {
		currentHeight++;

		if (currentHeight == 5) {
			currentPile = 1;
			currentHeight = 0;
		}
	}
};

struct ContainerZone {
	uint8_t clawSide[2] = {4, 4};
	uint8_t otherSide[2] = {4, 4};

	bool isEmpty(uint8_t side) {
		if (side) {
			if (clawSide[1] == 0) 
                return true;
			else 
                return false;

		} else {
			if (otherSide[1] == 0) 
                return true;
			else 
                return false;
		}
	}

	uint8_t getHeight(uint8_t side) {
		if (side) {
			if (clawSide[0] == 0) 
                return clawSide[1];

			return clawSide[0];

		} else {
			if (otherSide[0] == 0) 
                return otherSide[1];
			
            return otherSide[0];
		}
	}

	void updateHeight(uint8_t side) {
		if (side) {
			if (clawSide[0] == 0)
				clawSide[1]--;
			else
				clawSide[0]--;
		
		} else {
			if (otherSide[0] == 0)
				otherSide[1]--;
			else
				otherSide[0]--;	
		}
	}
};

/*
	side: true ==> green | blue
		  false ==> blue | green
*/

struct Arena {
	ContainerZone containers[3];
	Ship greenShip;
	Ship blueShip;

	bool side = true;
};

#endif // ARENA_HPP