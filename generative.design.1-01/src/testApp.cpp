#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	color.setHsb(0, 255, 255);
	antiColor.setHsb(0, 255, 255);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	// This calculation gives you a value between 0 and 360.
	// The value depens on the horizontal position of the mouse.
	float hue = ofMap( mouseX, 0, ofGetWidth(), 0, 255 );
	color.setHue( hue );

	// This draws you a nice rectangle starting in the top left corner
	// and filling the whole canvas as a background.
	ofSetRectMode( OF_RECTMODE_CORNER );
	ofSetColor( color );
	ofRect( 0, 0, ofGetWidth(), ofGetHeight() );

	// ...
	float antiHue = 255.0 - hue;
	antiColor.setHue( antiHue );
	// And that draws you a rectangle from the center on, it's size
	// depending on the vertical position of the mouse.
	ofSetRectMode( OF_RECTMODE_CENTER );
	ofSetColor( antiColor );
	ofRect( ofGetWidth() / 2, ofGetHeight() / 2, ofGetHeight() - mouseY, ofGetHeight() - mouseY );
}
