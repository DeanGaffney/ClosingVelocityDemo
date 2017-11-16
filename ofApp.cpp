#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	isRunning = false;
	reset();
}


void ofApp::reset() {
	t = 0.0f;
	p1StartPos = p1Pos = p1Vel = ofVec3f::zero();
	p2StartPos = p2Pos = ofVec3f(3, 3, 0);
	p2Vel = ofVec3f::zero();
	distanceVector = (p1Pos - p2Pos).normalize();
	closingVel = 0.0f;
	isRunning = false;
}


//--------------------------------------------------------------
void ofApp::update(){
	float dt = ofClamp(ofGetLastFrameTime(), 0.0, 0.02);
	if (!isRunning || dt == 0.0f) return;

	if (isRunning) {
		t += dt;
		p1Pos += dt * p1Vel;
		p2Pos += dt * p2Vel;
	}
	distanceVector = (p1Pos - p2Pos).normalize();
	closingVel = distanceVector.dot(p2Vel - p1Vel);
}

//--------------------------------------------------------------
void ofApp::draw(){
	//render gui first
	gui.begin();
	drawMainWindow();
	gui.end();

	float playAreaX = mainWindowRectangle.getMaxX();

	ofPushMatrix();
		ofSetColor(0, 0, 255);
		ofTranslate(playAreaX + (ofGetWindowWidth() - playAreaX) / 2, ofGetWindowHeight() / 2, 0);
		ofScale((ofGetWindowWidth() - mainWindowRectangle.getWidth()) / 10, ofGetWindowHeight() / 10);
		ofNoFill();
		ofDrawRectangle(-5, -5, 10, 10);
		ofFill();
		//particle 1 attributes
		ofSetColor(150, 100, 0);
		ofDrawCircle(p1Pos.x, p1Pos.y, 0.2);
		ofSetColor(255, 0, 0);
		ofDrawArrow(p1Pos, p1Pos + p1Vel);		//velocity arrow
		
		//particle 2 attributes
		ofSetColor(100, 150, 0);
		ofDrawCircle(p2Pos.x, p2Pos.y, 0.2);
		ofSetColor(255, 0, 0);
		ofDrawArrow(p2Pos, p2Pos + p2Vel);		//velocity arrow
		ofSetColor(0, 0, 255);
		ofDrawArrow(p2Pos, p2Pos + (p1Pos - p2Pos).getNormalized());		//direction arrow
	ofPopMatrix();
}

void ofApp::drawMainWindow() {

	ImGui::SetNextWindowSize(ImVec2(200, 300), ImGuiSetCond_FirstUseEver);
	if (ImGui::Begin("Main")) {

		if (ImGui::Button("Reset")) reset();
		ImGui::SameLine();
		if (ImGui::Button(isRunning ? "Stop" : " Go ")) isRunning = !isRunning;
		ImGui::SameLine();
		ImGui::Text("   Time = %8.1f", t);
		if (ImGui::Button("Quit")) quit();

		ImGui::SliderFloat2("P1Pos", &p1Pos.x, -5.0f, 5.0f);
		ImGui::SliderFloat2("P1Vel", &p1Vel.x, -1.0f, 1.0f);

		ImGui::SliderFloat2("P2Pos", &p2Pos.x, -5.0f, 5.0f);
		ImGui::SliderFloat2("P2Vel", &p2Vel.x, -1.0f, 1.0f);

		ImGui::Text("Distance Vec = (% 6.2f,% 6.2f) ", distanceVector.x, distanceVector.y);
		ImGui::Text("Closing Velocity = %.3f", closingVel);

		if (ImGui::SliderFloat("Time", &t, 0.0f, 20.0f)) {
			p1Pos = p1StartPos + p1Vel * t;
			p2Pos = p2StartPos + p2Vel * t;
		}
	}

	ImGui::SetWindowSize(ImVec2(0, 0));

	// store window size so that camera can ignore mouse clicks
	mainWindowRectangle.setPosition(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y);
	mainWindowRectangle.setSize(ImGui::GetWindowWidth(), ImGui::GetWindowHeight());
	ImGui::End();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

void ofApp::quit() {
	ofExit();
}
