#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	// we want to draw on the screen without background clearing
	ofSetBackgroundAuto( false );
	ofBackground( 255 );
	ofEnableSmoothing();

	// for a nicer drawing experience we put some alpha in the color
	color.setHsb( 0, 255, 255, 50 );
	ofSetLineWidth( 2 );

	resolution = 3;
	radius = ofGetWidth() / 2;
}

//--------------------------------------------------------------
void testApp::update(){
	// resolution depends on mouse x position
	resolution = 30.0 / ofGetWidth() * mouseX + 3;
	angle = 360.0 / static_cast<float>( resolution );
	// and the radius on mouse y position
	radius = static_cast<float>( ofGetHeight() / 2 ) / ofGetHeight() * mouseY;
}

//--------------------------------------------------------------
void testApp::draw(){
	// we want to draw from the center out
	ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );

	// color changing according to radius
	color.setHue( 255.0 / ( ofGetHeight() / 2 ) * radius );
	ofSetColor( color );

	for( int i = 0; i < resolution; i++ ){
		// some trigonometry -> look it up, very useful to know
		p1.set( cos( ofDegToRad( angle * i ) ) * radius,
			sin( ofDegToRad( angle * i ) ) * radius );

		p2.set( cos( ofDegToRad( angle * i + angle ) ) * radius,
			sin( ofDegToRad( angle * i + angle ) ) * radius );

		ofLine( p1.x, p1.y, p2.x, p2.y );
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch( key ){
		// reset with 'R'
		case 114:
			ofBackground( 255 );
			break;
	}
}
