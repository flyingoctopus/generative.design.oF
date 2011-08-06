#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
   ofBackground( 255 );
   ofSetColor( 0, 0, 0, 60 );
   ofSetLineWidth( 3 );
   ofNoFill();

   // we want the rectangles to overlap nicely
   // if alpha blending is not on (default off)
   // the shapes drawn by ofBegin/EndShape have no
   // alpha in their colors
   ofEnableAlphaBlending();
   ofEnableSmoothing();

   mode = 'C';
   tileCount = 20;
   tileSize = ofGetWidth() / tileCount;
}

//--------------------------------------------------------------
void testApp::update(){}

//--------------------------------------------------------------
void testApp::draw(){
   for( int gridY = 0; gridY <= tileCount; gridY++ ){
      for( int gridX = 0; gridX <= tileCount; gridX++ ){
         if( mode == 'C' ){
            posX = tileSize * gridX;
            posY = tileSize * gridY;

            // we randomize the circles position a bit
            shiftX = ofRandom( -mouseX, mouseX ) / 20.0;
            shiftY = ofRandom( -mouseX, mouseX ) / 20.0;

            ofCircle( posX + shiftX, posY + shiftY, mouseY / 15 );
         } else if( mode == 'R' ) {
            posX = tileSize * gridX;
            posY = tileSize * gridY;

            // for every of the 4 points of the rectangle
            // we randomize its position a bit
            shiftX1 = ofRandom( -mouseX, mouseX ) / 20.0;
            shiftY1 = ofRandom( -mouseX, mouseX ) / 20.0;
            shiftX2 = ofRandom( -mouseX, mouseX ) / 20.0;
            shiftY2 = ofRandom( -mouseX, mouseX ) / 20.0;
            shiftX3 = ofRandom( -mouseX, mouseX ) / 20.0;
            shiftY3 = ofRandom( -mouseX, mouseX ) / 20.0;
            shiftX4 = ofRandom( -mouseX, mouseX ) / 20.0;
            shiftY4 = ofRandom( -mouseX, mouseX ) / 20.0;

            ofBeginShape();

            ofVertex( posX + shiftX1, posY + shiftY1 );
            ofVertex( posX + tileSize + shiftX2, posY + shiftY2 );
            ofVertex( posX + tileSize + shiftX3, posY + tileSize + shiftY3 );
            ofVertex( posX + shiftX4, posY + tileSize + shiftY4 );

            ofEndShape();
         }
      }
   }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
   switch( key ){
      case 114: // draw rectangles
         mode = 'R';
         ofFill();
         ofSetLineWidth( 0 );
         break;
      case 99: // draw circles
         mode = 'C';
         ofNoFill();
         ofSetLineWidth( 3 );
         break;
   }
}
