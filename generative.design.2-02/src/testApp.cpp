#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

   // I was originally using ofLine in this project first, but:
   //
   // ofLine has a natural maximum width depent on your grafic card
   // http://forum.openframeworks.cc/index.php?topic=3751.0
   // so we draw some rectangles and rotate them

	ofBackground( 255 );
   ofSetColor( 0 );
   ofEnableSmoothing();

   // how many tiles
	iTileCount = 20;
	fTileSize = static_cast<float>( ofGetWidth() ) / static_cast<float>( iTileCount );

   // the maximum width of the lines
	fMaxLineWidth = 20;

   // and now some trigonometry action to calculate the lines length
   // because we can't draw a line from point to point we have to calculate
   // the hypothenuse a² + b² = c²
   fLineLength = sqrt( pow( fTileSize, 2 ) + pow( fTileSize, 2 ) );

   // edgy or round edge? off by default
   drawRoundEdge = 0;

	vchDirections.resize( iTileCount * iTileCount );

   // get a random direction for each tile
   // 0 = topleft - bottomright
   // 1 = bottomleft - topright
	for( int iGridY = 0; iGridY < iTileCount; iGridY++ ){
		for( int iGridX = 0; iGridX < iTileCount; iGridX++ ){
			vchDirections[ iGridY * iTileCount + iGridX ] = static_cast<int>( ofRandom( 1.999 ) );
		}
	}
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	for( int iGridY = 0; iGridY < iTileCount; iGridY++ ){
		for( int iGridX = 0; iGridX < iTileCount; iGridX++ ){

			fX1 = iGridX * fTileSize;
			fX2 = fX1 + fTileSize;

			if( vchDirections[ iGridY * iTileCount + iGridX ] ){
				fY1 = iGridY * fTileSize;
				fY2 = fY1 + fTileSize;
				
				fLineWidth = ofMap( mouseX, 0.0, static_cast<float>( ofGetWidth() ), 1.0, fMaxLineWidth );
            fRotation = 45.0;
			} else {
				fY2 = iGridY * fTileSize;
				fY1 = fY2 + fTileSize;

				fLineWidth = ofMap( mouseY, 0.0, static_cast<float>( ofGetHeight() ), 1.0, fMaxLineWidth );
            fRotation = -45.0;
			}

         ofPushMatrix();
         ofTranslate( fX1, fY1 );
         ofRotate( fRotation );

         ofRect( 0.0, 0.0 - fLineWidth / 2.0, fLineLength, fLineWidth );

         ofPopMatrix();

         if( drawRoundEdge ){
            ofCircle( fX1, fY1, fLineWidth / 2.0 );
            ofCircle( fX2, fY2, fLineWidth / 2.0 );
         }

		}
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch( key ){
		case 114:
			for( int iGridY = 0; iGridY < iTileCount; iGridY++ ){
				for( int iGridX = 0; iGridX < iTileCount; iGridX++ ){
					vchDirections[ iGridY * iTileCount + iGridX ] = static_cast<int>( ofRandom( 1.999 ) );
				}
			}
			break;
      case 99: // draw round edges toggle
         drawRoundEdge ? drawRoundEdge = 0 : drawRoundEdge = 1;
         break;
	}
}
