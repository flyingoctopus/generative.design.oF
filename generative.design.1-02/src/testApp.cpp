#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	int stepX = mouseX + 2;
	int stepY = mouseY + 2;
	
	// Draws a grid of rectangles, their color depending
	// on their position in the grid. The horizontal defines
	// the hue and the vertical the saturation.
	for( int gridY = 0; gridY < ofGetHeight(); gridY += stepY ){
		for( int gridX = 0; gridX < ofGetWidth(); gridX += stepX ){

			color.setHsb( 255.0 / ofGetWidth() * gridX, 255.0 - 255.0 / ofGetHeight() * gridY, 255 );
			ofSetColor( color );
			ofRect( gridX, gridY, stepX, stepY );
		}
	}
}
