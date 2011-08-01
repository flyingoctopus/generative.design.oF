#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);

		int resolution, radius;
		float angle;

		ofPoint p1, p2;
		ofColor color;
};
