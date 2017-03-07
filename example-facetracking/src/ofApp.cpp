#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	rs.setup(true, true,false, true, false);
	rs.open();
	//center the camera a bit
}

//--------------------------------------------------------------
void ofApp::update(){
	rs.update();
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	int num_landmarks = 0;
	int tracked_faces = rs.getNumTrackedFaces();
	stringstream output;
	if (tracked_faces) {

		num_landmarks = rs.getTrackedFaceLandmarks(0)->size();
		face_mesh.clear();
		// loop through landmarks and add to face mesh
		for (std::vector<ofxRSFace::Landmark>::const_iterator landmark = rs.getTrackedFaceLandmarks(0)->begin(); landmark != rs.getTrackedFaceLandmarks(0)->end(); ++landmark)
		{

			ofVec3f landmark_position = landmark->posWorld;
			// raw landmarks come back in mm.  scale them up a bit
			landmark_position.scale(100.0);
			face_mesh.addVertex(landmark_position);
			face_mesh.addColor(landmark->confidenceColor);

		}



	}
	
	ofVec2f draw_size = ofVec2f(rs.getColorPixelsRef().getWidth(), rs.getColorPixelsRef().getHeight());
	draw_size /= 3.0f;
	rs.drawColor(ofGetWidth() / 2.0 - draw_size.x / 2.0, ofGetHeight() / 2.0 - draw_size.y/2.0, draw_size.x, draw_size.y);
	output << "tracked faces : " << ofToString(tracked_faces) << "\n" << "num landmarks : " << ofToString(num_landmarks) << std::endl; 
	ofDrawBitmapString(output.str(), 100, 100);
	ofSetColor(255, 255);

	// center camera a bit
	camera.setPosition(-2.0,0.0, 235.0);
	camera.begin();
	face_mesh.setMode(OF_PRIMITIVE_POINTS);
	face_mesh.draw();
	camera.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	ofLogNotice() << "break" << std::endl;


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
