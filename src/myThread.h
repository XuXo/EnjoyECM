//
//  myThread.h
//  enjoyECM
//
//  Created by XuXo on 3/30/14.
//
//

//
//  myThread.h
//  soundPlayerExample
//
//  Created by XuXo on 3/29/14.
//
//
#include "ofMain.h"


class myThread: public ofThread, public ofImage {
public:
	string fileName;
    ofSoundPlayer tune;
	void threadedFunction() {
        
		//while(isThreadRunning()){
        
        
        //}
        if(lock()){
            cout<<"Im in the thread number "<<fileName<<endl;
            //tune.loadSound(fileName);
        }
        else{
            //cout<<"myThread seems to be locked at the moment"<<endl;
        }
        //cout<<"wtf"<<endl;
        stopThread();
	}
    
    void load(string songname, ofSoundPlayer song){
        //cout<<"Im here"<<endl;
        fileName = songname;
        startThread(true, false);
        song.loadSound(songname, true);
        //tune = song;
        
    }
};
