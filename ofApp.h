#pragma once

#include "ofMain.h"
#include "ofxImGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxImGui::Gui gui;                           // single entery to ImGUI subsystem
		ofRectangle mainWindowRectangle;
		void drawMainWindow();
		void reset();
		void quit();

		bool isRunning;
		float t;
		bool animate;

		ofVec3f p1StartPos, p1Pos, p1Vel;
		ofVec3f p2StartPos, p2Pos, p2Vel;
		ofVec3f distanceVector;
		float closingVel;
};
