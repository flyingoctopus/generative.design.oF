#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground( 255 );
   // no background repainting
	ofSetBackgroundAuto( false );

   // some grafical niceness
   ofEnableAlphaBlending();
   ofEnableSmoothing();

   // how many agents we want on screen
	iAgents = 20;

	ofpAgents.resize( iAgents );
   ofcAgentColors.resize( iAgents );

   // the agents size and step size
   fAgentSize = 2.0;
   fAgentStep = 4.0;

   // initiate the agents position randomly
	for( int i = 0; i < ofpAgents.size(); i++ ){
		ofpAgents[ i ].x = ofRandomWidth();
		ofpAgents[ i ].y = ofRandomHeight();
	}

   // and get some random color for every agent
   for( int i = 0; i < ofcAgentColors.size(); i++ ){
      ofcAgentColors[ i ].setHsb( ofRandom( 255.0 ), 255.0, 255.0, 50.0 );
   }
}

//--------------------------------------------------------------
void testApp::update(){
	for( int i = 0; i < ofpAgents.size(); i++ ){
		iDirection = static_cast<int>( ofRandom( 0.0, 7.9 ) );

      // set the new position for the agent according to 
      // the random int we got above
		switch( iDirection ){
			case 0: // north
            ofpAgents[ i ].y -= fAgentStep;
            break;
			case 1: // north-east
            ofpAgents[ i ].x += fAgentStep;
            ofpAgents[ i ].y -= fAgentStep;
            break;
			case 2: // east
            ofpAgents[ i ].x += fAgentStep;
            break;
			case 3: // south-east
            ofpAgents[ i ].x += fAgentStep;
            ofpAgents[ i ].y += fAgentStep;
            break;
			case 4: // south
            ofpAgents[ i ].y += fAgentStep;
            break;
			case 5: // south-west
            ofpAgents[ i ].x -= fAgentStep;
            ofpAgents[ i ].y += fAgentStep;
            break;
			case 6: // west
            ofpAgents[ i ].x -= fAgentStep;
            break;
			case 7: // north-west
            ofpAgents[ i ].x -= fAgentStep;
            ofpAgents[ i ].y -= fAgentStep;
            break;
		}

      // in case the agent goes over canvas border set
      // it somewhere new randomly
      if( ofpAgents[ i ].x < 0 || ofpAgents[ i ].x > ofGetWidth() ){
         ofpAgents[ i ].x = ofRandomWidth();
      }
      if( ofpAgents[ i ].y < 0 || ofpAgents[ i ].y > ofGetHeight() ){
         ofpAgents[ i ].y = ofRandomHeight();
      }
	}
}

//--------------------------------------------------------------
void testApp::draw(){
   // loop through the two vectors and draw them a new
	for( int i = 0; i < ofpAgents.size(); i++ ){
      ofSetColor( ofcAgentColors[ i ] );
		ofCircle( ofpAgents[ i ].x, ofpAgents[ i ].y, 2 );
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
   // reset the canvas
   switch( key ){
      case 114:
         ofBackground( 255 );
         break;
   }
}
