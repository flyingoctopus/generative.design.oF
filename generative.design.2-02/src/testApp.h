#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);

	private:
		int iTileCount;

		float fTileSize;
		float fX1, fY1, fX2, fY2, fRotation;
		float fLineWidth, fLineLength, fMaxLineWidth;

		vector<char> vchDirections;

      Bool drawRoundEdge;
};
