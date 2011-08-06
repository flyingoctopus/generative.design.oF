#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);

   private:
      char mode;

      int tileCount, tileSize;
      // for the circles
      float shiftX, shiftY, posX, posY;
      // for the rectangles
      float shiftX1, shiftX2, shiftX3, shiftX4;
      float shiftY1, shiftY2, shiftY3, shiftY4;
};
