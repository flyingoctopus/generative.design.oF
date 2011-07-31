#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);

		int segments, radius, angleStep;
		float centerX, centerY, x1, y1, x2, y2;
		ofColor color;
};
