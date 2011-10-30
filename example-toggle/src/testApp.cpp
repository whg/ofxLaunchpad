#include "testApp.h"

void testApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(255);
	launchpad.setup(1);
}

void testApp::update(){
}

void testApp::draw(){
	ofBackground(0);
	launchpad.draw(0, 0);
}

void testApp::mousePressed(int x, int y, int button) {
	dragChange(x, y, button, true);
}

void testApp::mouseDragged(int x, int y, int button) {
	dragChange(x, y, button, false);
}

void testApp::dragChange(int x, int y, int button, int reset) {
	// remap from screen space to launchpad space
	x = round(ofMap(x, 0, ofGetWidth(), -.5, 8.5));
	y = round(ofMap(y, 0, ofGetHeight(), -1.5, 7.5));
	if(y == -1) {
		y = 8;
	}
	
	if(reset) {
		curColor = launchpad.getLedGrid(x, y).isOn() ? ofColor::black : ofColor::yellow;
	}
	launchpad.setLedGrid(x, y, curColor);
}