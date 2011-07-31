#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyReleased(int key);

		ofImage image;
		vector<ofColor> colors;

		int steppa, steppaWidth, steppaHeight;
		float rectWidth, rectHeight;
		char sortMode;

		int frameCount;
};
