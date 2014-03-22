#include "testApp.h"
//#include <boost/lambda/lambda.hpp>
//--------------------------------------------------------------
//ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());

void testApp::setup(){
    
    nextpageleft = false;
    nextpageright = false;
    
    numberflipsleft = 0;
    numberflipsright = 0;
    
    totalflips = 0;
    
    timeelapsed = 0;
    timeexit = 0;
    startpage = 0;
    stayonpage = false;
    
    resetrotate = false;
    for(int i = 0; i< 80; i++){
        rotateface = false;
        rotate.push_back(rotateface);
    }
    
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(10, 10, 10);
	ofEnableDepthTest();
    
    // turn on smooth lighting //
    bSmoothLighting     = true;
    ofSetSmoothLighting(true);
    
    // lets make a high-res sphere //
    // default is 20 //
    ofSetSphereResolution(128);
	
    // radius of the sphere //
	radius		= 180.f;
	center.set(ofGetWidth()*.5, ofGetHeight()*.5, 0);
    
    
    
    // Point lights emit light in all directions //
    // set the diffuse color, color reflected from the light source //
    pointLight.setDiffuseColor( ofColor(0.f, 255.f, 255.0f));
    
    // specular color, the highlight/shininess color //
	pointLight.setSpecularColor( ofColor(255.f, 255.f, 0.f));
	pointLight.setPointLight();
    
    
	
    spotLight.setDiffuseColor( ofColor(255.f, 0.f, 0.f));
	spotLight.setSpecularColor( ofColor(255.f, 255.f, 255.f));
    
    // turn the light into spotLight, emit a cone of light //
    spotLight.setSpotlight();
    
    // size of the cone of emitted light, angle between light axis and side of cone //
    // angle range between 0 - 90 in degrees //
    spotLight.setSpotlightCutOff( 50 );
    
    // rate of falloff, illumitation decreases as the angle from the cone axis increases //
    // range 0 - 128, zero is even illumination, 128 is max falloff //
    spotLight.setSpotConcentration( 45 );
    
    
    
    
	
    // Directional Lights emit light based on their orientation, regardless of their position //
	directionalLight.setDiffuseColor(ofColor(0.f, 0.f, 255.f));
	directionalLight.setSpecularColor(ofColor(255.f, 255.f, 255.f));
	directionalLight.setDirectional();
    
    // set the direction of the light
    // set it pointing from left to right -> //
	directionalLight.setOrientation( ofVec3f(0, 90, 0) );
    
	
	bShiny = true;
    // shininess is a value between 0 - 128, 128 being the most shiny //
	material.setShininess( 128);
    // the light highlight of the material //
	material.setSpecularColor(ofColor(255, 255, 255, 255));
	
	bPointLight = bSpotLight = bDirLight = true;
    
    // tex coords for 3D objects in OF are from 0 -> 1, not 0 -> image.width
    // so we must disable the arb rectangle call to allow 0 -> 1
    ofDisableArbTex();
    // load album covers to use as the texture //
    
	/*
     construction dictates that we have
     
     cover[19] is same as cover[0]
     
     cover[24] is same as cover[5]
     
     cover[29] is same as cover[10]
     
     cover[34] is same as cover[15]
     
     cover[39] is same as cover[20]
     
     cover[44] is same as cover[25]
     
     cover[49] is same as cover[30]
     
     cover[54] is same as cover[35]
     
     cover[59] is same as cover[40]
     */
    ofLogoImage.loadImage("eick.jpg");
    ofLogoImage2.loadImage("purcor.jpg");
    ofLogoImage3.loadImage("gustavsen.jpg");
    ofLogoImage4.loadImage("alaoui.jpg");
    ofLogoImage5.loadImage("ronin.jpg");
    
    ofLogoImage6.loadImage("silvestrov.jpg");
    ofLogoImage7.loadImage("scala.jpg");
    ofLogoImage8.loadImage("fort.jpg");
    ofLogoImage9.loadImage("mtoto.jpg");
    ofLogoImage10.loadImage("stronen.jpg")
    ;
    ofLogoImage11.loadImage("vitous.jpg");
    ofLogoImage12.loadImage("rypdal.jpg");
    ofLogoImage13.loadImage("wasilewski.jpg");
    ofLogoImage14.loadImage("strata.jpg");
    ofLogoImage15.loadImage("sheppard.jpg");
    
    ofLogoImage16.loadImage("fresu.jpg");
    ofLogoImage17.loadImage("balke.jpg");
    ofLogoImage18.loadImage("stenson.jpg");
    ofLogoImage19.loadImage("mazur.jpg");
    ofLogoImage20.loadImage("source.jpg");
    
    ofLogoImage21.loadImage("fresu.jpg");
    ofLogoImage22.loadImage("balke.jpg");
    ofLogoImage23.loadImage("stenson.jpg");
    ofLogoImage24.loadImage("mazur.jpg");
    ofLogoImage25.loadImage("source.jpg");
    
	ofLogoImage26.loadImage("fresu.jpg");
    ofLogoImage27.loadImage("balke.jpg");
    ofLogoImage28.loadImage("stenson.jpg");
    ofLogoImage29.loadImage("mazur.jpg");
    ofLogoImage30.loadImage("source.jpg");
    
	ofLogoImage31.loadImage("fresu.jpg");
    ofLogoImage32.loadImage("balke.jpg");
    ofLogoImage33.loadImage("stenson.jpg");
    ofLogoImage34.loadImage("mazur.jpg");
    ofLogoImage35.loadImage("source.jpg");
    
	ofLogoImage36.loadImage("fresu.jpg");
    ofLogoImage37.loadImage("balke.jpg");
    ofLogoImage38.loadImage("stenson.jpg");
    ofLogoImage39.loadImage("mazur.jpg");
    ofLogoImage40.loadImage("source.jpg");
    
	ofLogoImage41.loadImage("fresu.jpg");
    ofLogoImage42.loadImage("balke.jpg");
    ofLogoImage43.loadImage("stenson.jpg");
    ofLogoImage44.loadImage("mazur.jpg");
    ofLogoImage45.loadImage("source.jpg");
    
	ofLogoImage46.loadImage("fresu.jpg");
    ofLogoImage47.loadImage("balke.jpg");
    ofLogoImage48.loadImage("stenson.jpg");
    ofLogoImage49.loadImage("mazur.jpg");
    ofLogoImage50.loadImage("source.jpg");
    
	ofLogoImage51.loadImage("fresu.jpg");
    ofLogoImage52.loadImage("balke.jpg");
    ofLogoImage53.loadImage("stenson.jpg");
    ofLogoImage54.loadImage("mazur.jpg");
    ofLogoImage55.loadImage("source.jpg");
    
	ofLogoImage56.loadImage("fresu.jpg");
    ofLogoImage57.loadImage("balke.jpg");
    ofLogoImage58.loadImage("stenson.jpg");
    ofLogoImage59.loadImage("mazur.jpg");
    ofLogoImage60.loadImage("source.jpg");
    
	ofLogoImage61.loadImage("fresu.jpg");
    ofLogoImage62.loadImage("balke.jpg");
    ofLogoImage63.loadImage("stenson.jpg");
    
    ofLogoImage64.loadImage("mazur.jpg");
    ofLogoImage65.loadImage("source.jpg");
	ofLogoImage66.loadImage("source.jpg");
    
    
    
    ecmcovers.push_back(ofLogoImage);
	ecmcovers.push_back(ofLogoImage2);
	ecmcovers.push_back(ofLogoImage3);
	ecmcovers.push_back(ofLogoImage4);
	ecmcovers.push_back(ofLogoImage5);
	ecmcovers.push_back(ofLogoImage6);
	ecmcovers.push_back(ofLogoImage7);
	ecmcovers.push_back(ofLogoImage8);
	ecmcovers.push_back(ofLogoImage9);
	ecmcovers.push_back(ofLogoImage10);
	ecmcovers.push_back(ofLogoImage11);
	ecmcovers.push_back(ofLogoImage12);
	ecmcovers.push_back(ofLogoImage13);
	ecmcovers.push_back(ofLogoImage14);
	ecmcovers.push_back(ofLogoImage15);
	ecmcovers.push_back(ofLogoImage16);
	ecmcovers.push_back(ofLogoImage17);
	ecmcovers.push_back(ofLogoImage18);
	ecmcovers.push_back(ofLogoImage19);
	ecmcovers.push_back(ofLogoImage20);
	ecmcovers.push_back(ofLogoImage21);
	ecmcovers.push_back(ofLogoImage22);
	ecmcovers.push_back(ofLogoImage23);
	ecmcovers.push_back(ofLogoImage24);
	ecmcovers.push_back(ofLogoImage25);
	ecmcovers.push_back(ofLogoImage26);
	ecmcovers.push_back(ofLogoImage27);
	ecmcovers.push_back(ofLogoImage28);
	ecmcovers.push_back(ofLogoImage29);
	ecmcovers.push_back(ofLogoImage30);
	ecmcovers.push_back(ofLogoImage31);
	ecmcovers.push_back(ofLogoImage32);
	ecmcovers.push_back(ofLogoImage33);
	ecmcovers.push_back(ofLogoImage34);
	ecmcovers.push_back(ofLogoImage35);
	ecmcovers.push_back(ofLogoImage36);
	ecmcovers.push_back(ofLogoImage37);
	ecmcovers.push_back(ofLogoImage38);
	ecmcovers.push_back(ofLogoImage39);
	ecmcovers.push_back(ofLogoImage40);
	ecmcovers.push_back(ofLogoImage41);
	ecmcovers.push_back(ofLogoImage42);
	ecmcovers.push_back(ofLogoImage43);
	ecmcovers.push_back(ofLogoImage44);
	ecmcovers.push_back(ofLogoImage45);
	ecmcovers.push_back(ofLogoImage46);
	ecmcovers.push_back(ofLogoImage47);
	ecmcovers.push_back(ofLogoImage48);
	ecmcovers.push_back(ofLogoImage49);
	ecmcovers.push_back(ofLogoImage50);
	ecmcovers.push_back(ofLogoImage51);
	ecmcovers.push_back(ofLogoImage52);
	ecmcovers.push_back(ofLogoImage53);
	ecmcovers.push_back(ofLogoImage54);
	ecmcovers.push_back(ofLogoImage55);
	ecmcovers.push_back(ofLogoImage56);
	ecmcovers.push_back(ofLogoImage57);
	ecmcovers.push_back(ofLogoImage58);
	ecmcovers.push_back(ofLogoImage59);
	ecmcovers.push_back(ofLogoImage60);
	ecmcovers.push_back(ofLogoImage61);
	ecmcovers.push_back(ofLogoImage62);
	ecmcovers.push_back(ofLogoImage63);
	ecmcovers.push_back(ofLogoImage64);
	ecmcovers.push_back(ofLogoImage65);
	ecmcovers.push_back(ofLogoImage66);
    
    bUseTexture = true;
}

//--------------------------------------------------------------
void testApp::update() {
    pointLight.setPosition(cos(ofGetElapsedTimef()*.6f) * radius * 2 + center.x,
						   sin(ofGetElapsedTimef()*.8f) * radius * 2 + center.y,
						   -cos(ofGetElapsedTimef()*.8f) * radius * 2 + center.z);
	
    spotLight.setOrientation( ofVec3f( 0, cos(ofGetElapsedTimef()) * RAD_TO_DEG, 0) );
	spotLight.setPosition( mouseX, mouseY, 200);
    
    float x, y;
    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
    x = mouse.x;
    y = mouse.y;
    int page;
    
    
    //this is if the user leaves the cursor on the current album and goes to a next page, the rotation would linger unless we trigger a cleanup, this is called whenever we hit 'i' or 'u', the effects are only felt on the edges since there are infact 2 cubes, well actually that's not the real reason, real reason is that's the only part of the previous page visible to us..
    
    if(resetrotate){
        //cout<<"resetting!!"<<endl;
        for(int i = 0; i < rotate.size(); i++)
            rotate[i] = false;
        //I'm not sure why it doesn't work with the following in place I would think you only need to do this once before it's reactivated on the next page swipe, probably an issue with the application framerate and how update is called after a keyboard event..
        //resetrotate = false;
        
    }
    
    page = totalflips % 4;
    if (page == -3)
        page = 1;
    if (page == -2)
        page = 2;
    if (page == -1)
        page = 3;
    //cout<<"we are on page "<<page<<endl;
    //cout<<"mouse x is "<<x<<" and mouse y is "<<y<<endl;
    
    
    
    
    for( int j = 0; j < 3; j++){
        for(int i = 0; i < 5; i++){
            //depending on what 'page' we are on, we access different cubes, we can get the page based on the total number flips
			/*
             ______3______
             |		       |
             |			   |
             2|			   |4
             |		       |
             |_____________|
             1
             //so take page = totalflips%4
             //0 correspond to current page		which have indices 0-14
             //1 correspond to page 2			which have indices 15-29
             //2 correspond to page 3			which have indices 30-44
             //3 correspond to page 4			which have indices 45-59
             */
			//these are the coordinates on screen after being projected forward from depth of z=200
			//found by trial and error...
			if((x > 95+ (i*160)) && (x< 95+(i+1)*160)&& (y > 172+(j*160)) && (y < 172+ (j+1)*160)){
				if(page == 0){
					rotate[(j*5)+i] = true;
                }
				else if(page == 1){
                    //cout<<"actually we're in here and j is "<<j<<"and i is "<<i<<endl;
					rotate[(15+j*5) + i] = true;
                }
				else if(page == 2){
					rotate[(30+j*5) + i] = true;
                }
				else if(page == 3){
					rotate[(45+j*5) + i] = true;
                }
			}
            else{
				if(page == 0){
					rotate[(j*5) + i] = false;
                }
				else if(page == 1){
					rotate[(15+j*5) + i] = false;
                }
				else if(page == 2){
					rotate[(30+j*5) + i] = false;
                }
				else if(page == 3){
					rotate[(45+j*5) + i] = false;
                }
            }
        }
    }
    
    
    
}

//deperecated since "pushing forward" out of the screen is relative to orientation, not necessarily just changing the z component
void testApp::emerge(){
    ofTranslate(0,0,50);
}
//--------------------------------------------------------------
void testApp::draw(){
    // enable lighting //
    //ofEnableLighting();
    // enable the material, so that it applies to all 3D objects before material.end() call //
	material.begin();
    
    // activate the lights //
	//if (bPointLight) pointLight.enable();
	//if (bSpotLight) spotLight.enable();
	//if (bDirLight) directionalLight.enable();
    
    
	/*ofSetColor(255, 255, 255, 255);
     ofPushMatrix();
     ofTranslate(center.x, center.y, center.z-300);
     ofRotate(ofGetElapsedTimef() * 1* RAD_TO_DEG, 0, 1, 0);
     ofDrawSphere( 0,0,0, radius);
     ofPopMatrix();*/
	
    
    //move canvas to center of screen, this will serve as axis of rotation
    ofTranslate(500,00,00);
    
	//I can't remember what this is used for...
    if (axisrotate){
        ofRotate((ofGetElapsedTimef())*.8 * RAD_TO_DEG, 0, 1, 0);
        timeelapsed = ofGetElapsedTimef();
        //cout<<"time elapsed is"<<ofGetElapsedTimef()-timeexit<<endl;
        
    }
    else{
        ofRotate(timeelapsed*.8 * RAD_TO_DEG, 0, 1, 0);
        timeexit = ofGetElapsedTimef();
        //cout<<"timeexit is "<<timeexit<<endl;
    }
    
    
    
    //totalflips = numberflipsleft - numberflipsright;				//this doesn't seem to be working
    if(nextpageleft){
        //cout<<"totalflips is"<<totalflips<<endl;
        stayonpage = false;
        startpage += .05;											//speed of rotation
        if(startpage <=1)
            //ofRotate((90*(numberflipsleft-1)) + startpage * 90, 0, 1, 0);
            ofRotate(90*(totalflips) + startpage*90, 0,1,0);		//90*totalflip will give us current position from which we rotate another 90 degrees per page turn
        else {
            startpage = 0;
            nextpageleft = false;									//deactivate as to only turn when called upon
            stayonpage = true;
            //ofRotate(90, 0, 1, 0);
        }
    }
    
    
    
    
    if(nextpageright){
        //cout<<"totalflips is"<<totalflips<<endl;
        stayonpage = false;
        startpage += .05;
        if(startpage <=1)
            //ofRotate((-90*(numberflipsright-1)) + startpage * -90, 0, 1, 0);
            ofRotate(90*(totalflips) + startpage*(-90), 0,1,0);
        else {
            startpage = 0;
            nextpageright = false;
            stayonpage = true;
            //ofRotate(90, 0, 1, 0);
        }
    }
    
    
    //totalflips = numberflipsleft - numberflipsright;
    
	//triggered by both left and right page turns, should stay true as long as we are not in the motion of turning, this if might be redundant
    if(stayonpage){
        totalflips = numberflipsleft - numberflipsright;
        ofRotate(90*totalflips, 0, 1, 0);
    }
    
    
    //building the first face
    
    // grab the texture reference and bind it //
    // this will apply the texture to all drawing (vertex) calls before unbind() //
	
	for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(-200 + i*100, 300, 200);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[i]){
            //ofTranslate(0,0,50);
			//emerge();
			//aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
			ofTranslate(0,0,50);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[i].getTextureReference().unbind();
	}
    
    for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[5+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(-200 + i*100, 400, 200);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[5+i]){
			//emerge();
			//aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
			ofTranslate(0,0,50);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[5+i].getTextureReference().unbind();
	}
    
    for( int i = 0; i < 5; i++) {
		if(bUseTexture) ecmcovers[10+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(-200 + i*100, 500, 200);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[10+i]){
			//emerge();
			//aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
			ofTranslate(0,0,50);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[10+i].getTextureReference().unbind();
	}
	
    
    
    
    
    
	//building the second face (left wall) from back to front, top to bottom like you did the front face had you rotate it
	//so last cube is actually the first of our front wall, ie cover[19] is same as cover[0]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[15+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(-200, 300, -200+ i*100);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[15+i]){
            //ofTranslate(0,0,50);
			//emerge();
			//prior to rotation these are aligned on the z axis and facing "west" so to speak causing it to point out of screen with a counterclockwise turn
            ofTranslate(-50,0,0);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[15+i].getTextureReference().unbind();
	}
    
	//cover[24] is same as cover[5]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[20+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(-200, 400, -200+ i*100);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[20+i]){
            //ofTranslate(0,0,50);
			//emerge();
			//prior to rotation these are aligned on the z axis and facing "west" so to speak causing it to point out of screen with a counterclockwise turn
            ofTranslate(-50,0,0);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[20+i].getTextureReference().unbind();
	}
    
	//cover[29] is same as cover[10]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[25+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(-200, 500, -200+ i*100);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[25+i]){
            //ofTranslate(0,0,50);
			//emerge();
			//prior to rotation these are aligned on the z axis and facing "west" so to speak causing it to point out of screen with a counterclockwise turn
            ofTranslate(-50,0,0);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[25+i].getTextureReference().unbind();
	}
    
	
    
    
	//building the back wall such that had you rotate it, it'd be left to right top to bottom same construction
	//so really its right to left top to bottom here
	//cover[34] is same as cover[15]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[30+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(200 - i*100, 300, -200);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[30+i]){
            //ofTranslate(0,0,50);
			//emerge();
			//aligned on the x axis but facing into the screen resulting in outward normal upon a 2 page counterclockwise turn
            ofTranslate(0,0,-50);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[30+i].getTextureReference().unbind();
	}
    
	//cover[39] is same as cover[20]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[35+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(200 - i*100, 400, -200);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[35+i]){
            //ofTranslate(0,0,50);
			//emerge();
			//aligned on the x axis but facing into the screen resulting in outward normal upon a 2 page counterclockwise turn
            ofTranslate(0,0,-50);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[35+i].getTextureReference().unbind();
	}
    
	//cover[44] is same as cover[25]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[40+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(200 - i*100, 500, -200);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[40+i]){
            //ofTranslate(0,0,50);
			//emerge();
			//aligned on the x axis but facing into the screen resulting in outward normal upon a 2 page counterclockwise turn
            ofTranslate(0,0,-50);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[40+i].getTextureReference().unbind();
	}
    
    
    
    
    
	//building the final right wall from front to back top to bottom
	//cover[49] is same as cover[30]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[45+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(200, 300, 200 - i*100);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[45+i]){
            //ofTranslate(0,0,50);
			//emerge();
			//originally face "east"...same idea
            ofTranslate(50,0,0);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[45+i].getTextureReference().unbind();
	}
    
	//cover[54] is same as cover[35]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[50+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(200, 400, 200 - i*100);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[50+i]){
            //ofTranslate(0,0,50);
			//emerge();
			//originally face "east"...same idea
            ofTranslate(50,0,0);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[50+i].getTextureReference().unbind();
	}
    
	//cover[59] is same as cover[40]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
		if(bUseTexture) ecmcovers[55+i].getTextureReference().bind();
		ofPushMatrix();
		ofTranslate(200, 500, 200 - i*100);
		//ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
		if(rotate[55+i]){
            //ofTranslate(0,0,50);
			//emerge();
			//originally face "east"...same idea
            ofTranslate(50,0,0);
			ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
		}
		ofDrawBox(0, 0, 0, 100);
		ofPopMatrix();
		if(bUseTexture) ecmcovers[55+i].getTextureReference().unbind();
	}
    
    
    
    
	/*
     ofPushMatrix();
     ofTranslate(center.x, center.y, -900);
     ofRotate(ofGetElapsedTimef() * .2 * RAD_TO_DEG, 0, 1, 0);
     ofDrawBox( 0, 0, 0, 850);
     ofPopMatrix();*/
    
    if(bUseTexture) ofLogoImage.getTextureReference().unbind();
	
	if (!bPointLight) pointLight.disable();
	if (!bSpotLight) spotLight.disable();
	if (!bDirLight) directionalLight.disable();
	
    material.end();
	// turn off lighting //
    ofDisableLighting();
    
	ofSetColor( pointLight.getDiffuseColor() );
	if(bPointLight) pointLight.draw();
    
    ofSetColor(255, 255, 255);
	ofSetColor( spotLight.getDiffuseColor() );
	if(bSpotLight) spotLight.draw();
	
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("Point Light On (1) : "+ofToString(bPointLight) +"\n"+
					   "Spot Light On (2) : "+ofToString(bSpotLight) +"\n"+
					   "Directional Light On (3) : "+ofToString(bDirLight)+"\n"+
					   "Shiny Objects On (s) : "+ofToString(bShiny)+"\n"+
                       "Spot Light Cutoff (up/down) : "+ofToString(spotLight.getSpotlightCutOff(),0)+"\n"+
                       "Spot Light Concentration (right/left) : " + ofToString(spotLight.getSpotConcentration(),0)+"\n"+
                       "Smooth Lighting enabled (x) : "+ofToString(bSmoothLighting,0)+"\n"+
                       "Textured (t) : "+ofToString(bUseTexture,0),
					   20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
		case '1':
			bPointLight = !bPointLight;
			break;
		case '2':
			bSpotLight = !bSpotLight;
			break;
		case '3':
			bDirLight = !bDirLight;
			break;
		case 's':
			bShiny	= !bShiny;
			if (bShiny) material.setShininess( 120 );
			else material.setShininess( 30 );
			break;
        case 'o':
            axisrotate = true;
            break;
        case 'p':
            axisrotate = false;
            break;
        case 'u':
            nextpageleft = true;
            numberflipsleft++;
            resetrotate = true;
            break;
        case 'i':
            nextpageright = true;
            numberflipsright++;
            resetrotate = true;
            break;
        case 'x':
            bSmoothLighting = !bSmoothLighting;
            ofSetSmoothLighting(bSmoothLighting);
            break;
        case 't':
            bUseTexture = !bUseTexture;
            break;
        case OF_KEY_UP:
            // setSpotlightCutOff is clamped between 0 - 90 degrees //
            spotLight.setSpotlightCutOff(spotLight.getSpotlightCutOff()+1);
            break;
        case OF_KEY_DOWN:
            // setSpotlightCutOff is clamped between 0 - 90 degrees //
            spotLight.setSpotlightCutOff(spotLight.getSpotlightCutOff()-1);
            break;
        case OF_KEY_RIGHT:
            // setSpotConcentration is clamped between 0 - 128 //
            spotLight.setSpotConcentration(spotLight.getSpotConcentration()+1);
            break;
        case OF_KEY_LEFT:
            // setSpotConcentration is clamped between 0 - 128 //
            spotLight.setSpotConcentration(spotLight.getSpotConcentration()-1);
            break;
            
		default:
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}