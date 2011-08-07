#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);

   private:
      char mode;

      int steps;
      float tileCount, tileSize, tileSizeHalf, posX, posY, angle;
};
