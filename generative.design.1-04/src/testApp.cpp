#include "testApp.h"

//--------------------------------------------------------------
// sort by hue function
bool sortHue( ofColor a, ofColor b){
	return( a.getHue() < b.getHue() );
}

//--------------------------------------------------------------
// sort by saturation function
bool sortSaturation( ofColor a, ofColor b){
	return( a.getSaturation() < b.getSaturation() );
}

//--------------------------------------------------------------
// sort by brightness function
bool sortBrightness( ofColor a, ofColor b){
	return( a.getBrightness() < b.getBrightness() );
}

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate( 5 );

	frameCount = 0;
	steppa = 10;
	sortMode = 'H';
	image.loadImage( "images/001.jpg" );
}

//--------------------------------------------------------------
void testApp::update(){

	frameCount++;

	if( steppa == 0)
		steppa = 1;

	colors.resize( steppa * steppa );

	steppaWidth = image.width / steppa;
	steppaHeight = image.height / steppa;

	rectWidth = static_cast<float>( ofGetWidth() ) / static_cast<float>( steppa );
	rectHeight = static_cast<float>( ofGetHeight() ) / static_cast<float>( steppa );

	// pull colors from image
	for( int gridY = 0; gridY < steppa; gridY++ ){
		for( int gridX = 0; gridX < steppa; gridX++ ){
			// simulate multidimensional vector, altought i have
			// to admit that vector< vector<ofColor> > is a
			// god damn cool construct.
			colors[ gridY * steppa + gridX ] = image.getColor( gridX * steppaWidth, gridY * steppaHeight );
		}
	}

	// sort the picked colors after Hue, Saturation or Brightness
	switch( sortMode ){
		case 'H':
			// sort after hue
			sort( colors.begin(), colors.end(), sortHue );
			break;
		case 'S':
			// sort after saturation
			sort( colors.begin(), colors.end(), sortSaturation );
			break;
		case 'B':
			// sort after brightness
			sort( colors.begin(), colors.end(), sortBrightness );
			break;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	// draw colors on screen
	for( int gridY = 0; gridY < steppa; gridY++ ){
		for( int gridX = 0; gridX < steppa; gridX++ ){
			ofSetColor( colors[ gridY * steppa + gridX ] );
			ofRect( gridX * rectWidth, gridY * rectHeight, rectWidth, rectHeight );
		}
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	switch( key ){
		// how many colors shall be picked: 1 - 9
		case 49: steppa = 10; break;
		case 50: steppa = 20; break;
		case 51: steppa = 30; break;
		case 52: steppa = 40; break;
		case 53: steppa = 50; break;
		case 54: steppa = 60; break;
		case 55: steppa = 70; break;
		case 56: steppa = 80; break;
		case 57: steppa = 90; break;
		case 58: steppa = 100; break;

		// for faster computers: 0
		case 48: steppa = 200; break;

		// choose different sort mode with H, S & B
		case 104: sortMode = 'H'; break;
		case 115: sortMode = 'S'; break;
		case 98: sortMode = 'B'; break;

		// load different pictures with Q, W & E
		case 113: image.loadImage( "images/001.jpg" ); break;
		case 119: image.loadImage( "images/002.jpg" ); break;
		case 101: image.loadImage( "images/003.jpg" ); break;
	}

	cout << key << endl;
}
