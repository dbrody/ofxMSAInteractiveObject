//
//  ofxMSAInteractiveWindow.cpp
//  TablePlatform
//
//  Created by David Brody on 11/7/14.
//
//

#include "ofxMSAInteractiveWindow.h"


ofxMSAInteractiveWindow::ofxMSAInteractiveWindow() : ofxMSAInteractiveObject() {
    ofxMSAInteractiveObject::disableAllEvents();
    //enableAppEvents();
}

ofxMSAInteractiveWindow::~ofxMSAInteractiveWindow() {
	disableAllEvents();
}

void ofxMSAInteractiveWindow::enableAllEvents() {
    enableMouseEvents();
	enableKeyEvents();
	enableAppEvents();
}

void ofxMSAInteractiveWindow::disableAllEvents() {
	disableMouseEvents();
	disableKeyEvents();
	disableAppEvents();
}

void ofxMSAInteractiveWindow::enableMouseEvents() {
	ofAddListener(ofEvents().mousePressed, this, &ofxMSAInteractiveWindow::_mousePressed);
	ofAddListener(ofEvents().mouseMoved, this, &ofxMSAInteractiveWindow::_mouseMoved);
	ofAddListener(ofEvents().mouseDragged, this, &ofxMSAInteractiveWindow::_mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &ofxMSAInteractiveWindow::_mouseReleased);
}

void ofxMSAInteractiveWindow::disableMouseEvents() {
	ofRemoveListener(ofEvents().mousePressed, this, &ofxMSAInteractiveWindow::_mousePressed);
	ofRemoveListener(ofEvents().mouseMoved, this, &ofxMSAInteractiveWindow::_mouseMoved);
	ofRemoveListener(ofEvents().mouseDragged, this, &ofxMSAInteractiveWindow::_mouseDragged);
	ofRemoveListener(ofEvents().mouseReleased, this, &ofxMSAInteractiveWindow::_mouseReleased);
}

void ofxMSAInteractiveWindow::enableKeyEvents() {
	ofAddListener(ofEvents().keyPressed, this, &ofxMSAInteractiveWindow::_keyPressed);
	ofAddListener(ofEvents().keyReleased, this, &ofxMSAInteractiveWindow::_keyReleased);
}

void ofxMSAInteractiveWindow::disableKeyEvents() {
	ofRemoveListener(ofEvents().keyPressed, this, &ofxMSAInteractiveWindow::_keyPressed);
	ofRemoveListener(ofEvents().keyReleased, this, &ofxMSAInteractiveWindow::_keyReleased);
}

void ofxMSAInteractiveWindow::enableAppEvents() {
    ofAddListener(ofEvents().setup, this, &ofxMSAInteractiveWindow::_setup);
	ofAddListener(ofEvents().update, this, &ofxMSAInteractiveWindow::_update);
	ofAddListener(ofEvents().draw, this, &ofxMSAInteractiveWindow::_draw);
	ofAddListener(ofEvents().exit, this, &ofxMSAInteractiveWindow::_exit);
}

void ofxMSAInteractiveWindow::disableAppEvents() {
	ofRemoveListener(ofEvents().setup, this, &ofxMSAInteractiveWindow::_setup);
	ofRemoveListener(ofEvents().update, this, &ofxMSAInteractiveWindow::_update);
	ofRemoveListener(ofEvents().draw, this, &ofxMSAInteractiveWindow::_draw);
	ofRemoveListener(ofEvents().exit, this, &ofxMSAInteractiveWindow::_exit);
}

void ofxMSAInteractiveWindow::setWindow(int win_num){
    _window_num = win_num;
}

void ofxMSAInteractiveWindow::_setup(ofEventArgs &e) {
    ofxMSAInteractiveObject::_setup(e);
}

void ofxMSAInteractiveWindow::_update(ofEventArgs &e) {
	//if(ofxIsWindowActive(_window_num)){
        ofxMSAInteractiveObject::_update(e);
    //}
}

void ofxMSAInteractiveWindow::_draw(ofEventArgs &e) {
    if(ofxIsWindowActive(_window_num)){
        ofxMSAInteractiveObject::_draw(e);
    }
}

void ofxMSAInteractiveWindow::_exit(ofEventArgs &e) {
	if(ofxIsWindowActive(_window_num)){
        ofxMSAInteractiveObject::_exit(e);
    }
}


void ofxMSAInteractiveWindow::_mouseMoved(ofMouseEventArgs &e) {
	int x = e.x;
	int y = e.y;
	int button = e.button;
	if(verbose) printf("ofxMSAInteractiveObject::_mouseMoved(x: %i, y: %i)\n", x, y);
	if(!enabled) return;
	
//    if(!ofxIsWindowActive(_window_num)){
//        return;
//    }
//
    
    //	_mouseX = x;
    //	_mouseY = y;
	
	if(hitTest(x, y)) {						// if mouse is over the object
		if(!_isMouseOver) {						// if wasn't over previous frame
			_isMouseOver = true;						// update flag
			onRollOver(x, y);						// call onRollOver
		}
		onMouseMove(x, y);						// and trigger onMouseMove
	} else if(_isMouseOver) {					// if mouse is not over the object, but the flag is true (From previous frame)
		onRollOut();							// call onRollOut
		_isMouseOver = false;						// update flag
	}
    
    _stateChangeTimestampMillis = ofGetElapsedTimeMillis();
    
    mouseMoved(x, y);
}

bool ofxMSAInteractiveWindow::isActive(){
    return ofxIsWindowActive(_window_num);
}


void ofxMSAInteractiveWindow::_mousePressed(ofMouseEventArgs &e) {
	if(ofxIsWindowActive(_window_num)){
        ofxMSAInteractiveObject::_mousePressed(e);
    }
}

void ofxMSAInteractiveWindow::_mouseDragged(ofMouseEventArgs &e) {
	if(ofxIsWindowActive(_window_num)){
        ofxMSAInteractiveObject::_mouseDragged(e);
    }
}

void ofxMSAInteractiveWindow::_mouseReleased(ofMouseEventArgs &e) {
	if(ofxIsWindowActive(_window_num)){
        ofxMSAInteractiveObject::_mouseReleased(e);
    }
}


void ofxMSAInteractiveWindow::_keyPressed(ofKeyEventArgs &e) {
	if(ofxIsWindowInFocus(_window_num)){
        ofxMSAInteractiveObject::_keyPressed(e);
    }
}


void ofxMSAInteractiveWindow::_keyReleased(ofKeyEventArgs &e) {
    if(ofxIsWindowInFocus(_window_num)){
        ofxMSAInteractiveObject::_keyReleased(e);
    }
}
