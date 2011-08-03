#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
	
	private:
		vector<ofPoint> ofpAgents;
      vector<ofColor> ofcAgentColors;
		int iAgents, iDirection;
      float fAgentSize, fAgentStep;
};
