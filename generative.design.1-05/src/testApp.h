#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);

		vector<ofColor> colors;

		int tileCountX, tileCountY, currentTileX, counter, index;
		float rectWidth, rectHeight;
};
