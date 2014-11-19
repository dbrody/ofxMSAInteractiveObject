//
//  ofxMSAInteractiveWindow.h
//  TablePlatform
//
//  Created by David Brody on 11/7/14.
//
//

#ifndef __TablePlatform__ofxMSAInteractiveWindow__
#define __TablePlatform__ofxMSAInteractiveWindow__
#include "ofMain.h"
#include "WindowManager.h"
#include "ofxMSAInteractiveObject.h"


class ofxMSAInteractiveWindow : public ofxMSAInteractiveObject {
public:
	ofxMSAInteractiveWindow();			// constructor
	virtual ~ofxMSAInteractiveWindow();	// destructor
    
    void setWindow(int win_num);        // set window number this object belongs to
    bool isActive();                    // Is current window active for drawing
    
    void enableAllEvents();				// enable all event callbacks
	void disableAllEvents();			// disable all event callbacks
    
    void enableMouseEvents();			// call this if object should receive mouse events
	void disableMouseEvents();			// call this if object doesn't need to receive mouse events (default)
    
	void enableKeyEvents();				// call this if object should receive key events
	void disableKeyEvents();			// call this if object doesn't need to receive key events (default)
    
	void enableAppEvents();				// call this if object should update/draw automatically	(default)
	void disableAppEvents();			// call this if object doesn't need to update/draw automatically
    
	// you shouldn't need access to any of these unless you know what you are doing
	// (i.e. disable auto updates and call these manually)
	void _setup(ofEventArgs &e);
	void _update(ofEventArgs &e);
    void _draw(ofEventArgs &e);
	void _exit(ofEventArgs &e);
    
	void _mouseMoved(ofMouseEventArgs &e);
	void _mousePressed(ofMouseEventArgs &e);
	void _mouseDragged(ofMouseEventArgs &e);
	void _mouseReleased(ofMouseEventArgs &e);
    
	void _keyPressed(ofKeyEventArgs &e);
	void _keyReleased(ofKeyEventArgs &e);
    
    
protected:
    int         _window_num;
};

#endif

