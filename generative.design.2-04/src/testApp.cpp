#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
   ofBackground( 255 );
   ofSetColor( 0, 0, 0, 75 );
   ofEnableAlphaBlending();
   ofSetLineWidth( 2 );

   // important for later
   ofSetRectMode( OF_RECTMODE_CENTER );

   tileCount = 4.0;
   tileSize = ofGetWidth() / tileCount;
   tileSizeHalf = tileSize / 2.0;
   steps = 20;
}

//--------------------------------------------------------------
void testApp::update(){
   // rotation angles and recursion steps are depentend
   // on mouse position
   angle = ofMap( mouseX, 0.0, ofGetWidth(), -25.0, 25.0 );
   steps = ofMap( mouseY, 0.0, ofGetHeight(), 1, 20 );
}

//--------------------------------------------------------------
void testApp::draw(){
   // first the usual two foor loops for drawing a grid
   for( int gridY = 0; gridY < tileCount; gridY++ ){
      for( int gridX = 0; gridX < tileCount; gridX++ ){
         // an additional loop for the recursion
         for( int i = 0; i < steps; i ++ ){
            // let's save the original coordinate system so we can
            // apply different settings for every single rectangle
            // we draw
            ofPushMatrix();

            posX = gridX * tileSize;
            posY = gridY * tileSize;

            // we put x:0 and y:0 to the center of were the newly
            // drawn rectangle will be be in order to be able to
            // rotate it nicely
            ofTranslate( posX + tileSizeHalf, posY + tileSizeHalf );
            ofRotate( i * angle );

            // to make them funky rectangles shrink we just divide their
            // size through the growing variable i
            ofRect( 0.0, 0.0, tileSize / i, tileSize / i );

            // and don't forget to put the matrix back in it's place
            // or ofTranslate and ofRotate will cummulate and mess up 
            // your artwork
            ofPopMatrix();
         }
      }
   }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
   // choose between filled or outlined
   // rectangles
   switch( key ){
      case 115: // 'S' for outline (like in stroke)
         ofNoFill();
         break;
      case 102: // 'F' for filled
         ofFill();
         break;
   }
}
