#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	segments = 24;
	ofBackground( 255 );
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	// How many angles a segment should have.
	angleStep = 360 / segments;
	radius = ofGetWidth() / 2 - 25;

	centerX = ofGetWidth() / 2;
	centerY = ofGetHeight() / 2;

	for( int angle = 0; angle < 360; angle += angleStep ){
		// Some trigonometry.
		x1 = centerX + cos( angle * DEG_TO_RAD ) * radius;
		y1 = centerX + sin( angle * DEG_TO_RAD ) * radius;
		
		// Some more.
		x2 = centerX + cos(( angle + angleStep ) * DEG_TO_RAD ) * radius;
		y2 = centerX + sin(( angle + angleStep )* DEG_TO_RAD ) * radius;

		// The color is dependent on the angle and the mousepointer position.
		color.setHsb( 255.0 / 360 * angle, 255.0 / ofGetWidth() * mouseX, 255.0 / ofGetHeight() * mouseY );
		ofSetColor( color );
		ofTriangle( centerX, centerY, x1, y1, x2, y2 );
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	// We can switch the number of segments with numbers 1 - 5
	// segments should allways leave 360 divided through
	// segments without floating point.
	switch( key ){
		case 49: segments = 6; break;
		case 50: segments = 12; break;
		case 51: segments = 24; break;
		case 52: segments = 45; break;
		case 53: segments = 360; break;
	}
}
