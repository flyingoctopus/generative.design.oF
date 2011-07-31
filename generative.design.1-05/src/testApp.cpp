#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	// how many rect shall be drawn horizontaly and
	tileCountX = 50;
	// verticaly
	tileCountY = 10;

	colors.resize( tileCountX );

	// fill the colors vector with random values
	for( int i = 0; i < tileCountX; i++ )
		colors[ i ] = ofColor( ofRandom( 0, 255 ), ofRandom( 0, 255 ), ofRandom( 0, 255 ) );

	// if you don't type cast the variables your rects will 
	// not fill the screen nicely
	rectWidth = static_cast<float>( ofGetWidth() ) / static_cast<float>( tileCountX );
	rectHeight = static_cast<float>( ofGetHeight() ) / static_cast<float>( tileCountY );
}

//--------------------------------------------------------------
void testApp::update(){
	// if you don't cast the first variable in the equation you'll
	// get a floating point exception. if you calculate with ints the
	// result will be an int even if you push it into a float.
	currentTileX = static_cast<float>( tileCountX ) / ofGetWidth() * mouseX;

	if( currentTileX == 0 )
		currentTileX = 3;

	counter = 0;
}

//--------------------------------------------------------------
void testApp::draw(){
	for( int gridY = 0; gridY < tileCountX; gridY++ ){
		for( int gridX = 0; gridX < tileCountX; gridX++ ){

			// alternate the choosen color according to the mouseX position
			index = counter % currentTileX;

			ofSetColor( colors.at( index ) );
			ofRect( gridX * rectWidth, gridY * rectHeight, rectWidth, rectHeight );

			counter++;
		}
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	// fill the colors vector a new, come up with your own options :)
	switch( key ){
		// from the first third of the hue wheel
		case 48:
			for( int i = 0; i < tileCountX; i++ )
				colors[ i ] = ofColor( ofRandom( 0, 255 ), ofRandom( 0, 255 ), ofRandom( 0, 255 ) );
			break;
		// from the second third of the hue wheel
		case 49:
			for( int i = 0; i < tileCountX; i++ )
				colors[ i ] = ofColor( ofRandom( 80, 180 ), ofRandom( 0, 255 ), ofRandom( 0, 255 ) );
			break;
		// from the third third of the hue wheel
		case 50:
			for( int i = 0; i < tileCountX; i++ )
				colors[ i ] = ofColor( ofRandom( 155, 255 ), ofRandom( 0, 255 ), ofRandom( 0, 255 ) );
			break;
	}
}
