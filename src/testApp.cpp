


#include "testApp.h"
//#include <boost/lambda/lambda.hpp>
//--------------------------------------------------------------
//ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());

void testApp::setup(){
    
    
    trans = 255;
    togglecaption = false;
    captionindex = 0;
    ofSetWindowShape(1400,1000);
    
    //logo.loadFont("froufrou.ttf", 32);
    logo.loadFont("type/verdana.ttf", 25, true, false, true, 0.1, 102);
    //author.loadFont("froufrou.ttf", 15);
    author.loadFont("type/verdana.ttf", 8, true, false, true, 0.1, 102);
    //font.loadFont("sans-serif", 30);
    //caption.loadFont("type/verdana.ttf", 8, true, false, true, 0.1, 102);
    caption.loadFont("verdana.ttf", 10, true, true);
	caption.setLineHeight(14.0f);
	caption.setLetterSpacing(1.035);
    
    rownumber = 1;
    
    
    
    fontsize = 4;
    font.loadFont("type/verdana.ttf", fontsize, true, false, true, 0.05, 182);
    font2.loadFont("type/verdana.ttf", fontsize, true, false, true, 0.05, 182);
    font3.loadFont("type/verdana.ttf", fontsize, true, false, true, 0.05, 182);
    font4.loadFont("type/verdana.ttf", fontsize, true, false, true, 0.05, 182);
    font5.loadFont("type/verdana.ttf", fontsize, true, false, true, 0.05, 182);
    font6.loadFont("type/verdana.ttf", fontsize, true, false, true, 0.05, 182);
    font7.loadFont("type/verdana.ttf", fontsize, true, false, true, 0.05, 182);
    font8.loadFont("type/verdana.ttf", fontsize, true, false, true, 0.05, 182);
    font9.loadFont("type/verdana.ttf", fontsize, true, false, true, 0.05, 182);
    font10.loadFont("type/verdana.ttf", fontsize, true, false, true, 0.05, 182);
    
    songs.push_back(font);
    songs.push_back(font2);
    songs.push_back(font3);
    songs.push_back(font4);
    songs.push_back(font5);
    songs.push_back(font6);
    songs.push_back(font7);
    songs.push_back(font8);
    songs.push_back(font9);
    songs.push_back(font10);
    
    
    tracks.push_back("01. eick");
    tracks.push_back("02. matheny");
    tracks.push_back("03. gustavsen");
    tracks.push_back("04. holland");
    tracks.push_back("05. motian");
    tracks.push_back("06. rypdal");
    tracks.push_back("07. negros");
    tracks.push_back("08. condori");
    tracks.push_back("09. micus");
    tracks.push_back("10. sclavis");
    
    
    descriptions.push_back("Trygve Seim\nAndreas Utnem\nPurcor\n\nTrygve Seim tenor and soprano saxophones\nAndreas Utnem piano, harmonium");
    descriptions.push_back("Roscoe Mitchell\nThe Note Factory\nFar Side\n\nRoscoe Mitchell saxophones, flutes\nCorey Wilkes trumpet, flugelhorn\nCraig Taborn piano\nVijay Iyer piano\nHarrison Bankhead cello, double-bass\nJaribu Shahid double-bass\nTanni Tabbal drums\nVincent Davis drums");
    
    descriptions.push_back("Vassilis Tsabropoulos\nAnja Lechner\nU. T. Gandhi\nMelos\n\nVassilis Tsabropoulos piano\nAnja Lechner violoncello\nU. T. Gandhi percussion");
    
    descriptions.push_back("Tord Gustavsen Trio\nBeing There\n\nTord Gustavsen piano\nHarald Johnsen double-bass\nJarle Vespestad drums");
    
    descriptions.push_back("Marcin Wasilewski Trio\nJanuary\n\nMarcin Wasilewski piano\nSlawomir Kurkiewicz double-bass\nMichal Miskiewicz drums");
    
    descriptions.push_back("Andy Sheppard\nMovements in Colour\n\nAndy Sheppard soprano and tenor saxophones\nJohn Parricelli acoustic and electric guitars\nEivind Aarset guitar, electronics\nArild Andersen double-bass, electronics\nKuljit Bhamra tabla, percussion");
    
    descriptions.push_back("Michael Formanek\nSmall Places\n\nTim Berne alto saxophone\nCraig Taborn piano\nMichael Formanek double-bass\nGerald Cleaver drums, shruti bo");
    
    descriptions.push_back("Trygve Seim\nFrode Haltli\nYeraz\n\nTrygve Seim soprano and tenor saxophones\nFrode Haltli accordion ");
    
    descriptions.push_back("Jon Balke\nBook of Velocities\n\nJon Balke piano");
    
    descriptions.push_back("Keith Jarrett\nGary Peacock\nJack DeJohnette\nAlways Let Me Go\n\nKeith Jarrett piano\nGary Peacock double-bass\nJack DeJohnette drums");
    
    descriptions.push_back("Andy Sheppard\nMichel Benita\nSebastian Rochford\nTrio Libero\n\nAndy Sheppard tenor and soprano saxophones\nMichel Benita double-bass\nSebastian Rochford drums");
    
    descriptions.push_back("Miroslav Vitous\nUniversal Syncopations II\n\nBob Mintzer tenor saxophone, bass clarinet\nGary Campbell soprano and tenor saxophones\nBob Malach tenor saxophone\nRandy Brecker trumpet\nDaniele di Bonaventura bandoneon\nVesna Vasko-Caceres voice\nGerald Cleaver drums\nAdam Nussbaum drums\nMiroslav Vitous double-bass");
    
    descriptions.push_back("Rolf Lislevand\nDiminuito\n\nRolf Lislevand lutes, vihuela de mano\nLinn Andrea Fuglseth voice\nAnna Maria Friman voice\nGiovanna Pessi triple harp\nMarco Ambrosini nyckelharpa\nThor-Harald Johnsen chitarra battente, vihuela de mano, lutes\nMichael Behringer clavichord, organ\nBjørn Kjellemyr colascione\nDavid Mayoral percussion");
    
    descriptions.push_back("Food\nQuiet Inlet\nThomas Strønen drums, live-electronics\nIain Ballamy tenor- and soprano saxophones\nNils Petter Molvær trumpet, electronics\nChristian Fennesz guitar, electronics\nSebastian Rochford drums");
    
    descriptions.push_back("Iva Bittová\n\nIva Bittová voilin, voice, kalimba");
    
    descriptions.push_back("Julia Hülsmann Trio\nImprint\nJulia Hülsmann piano\nMarc Muellbauer double-bass\nHeinrich Köbberling drums");
    descriptions.push_back("Bobo Stenson Trio\nIndicum\nBobo Stenson piano\nAnders Jormin double-bass\nJon Fält drums");
    descriptions.push_back("Jon Balke\nBatagraf\nSay And Play\nJon Balke piano, keyboards, electronics, tungoné, darbouka, percussion\nHelge Andreas Norbakken sabar, gorong, djembe, talking drum, shakers, percussion\nEmilie Stoesen Christensen vocals\nErland Dahlen drums\nTorgeir Rebolledo Pedersen poetry reading");
    descriptions.push_back("John Abercrombie\nClass Trip\nJohn Abercrombie guitar\nMark Feldman violin\nMarc Johnson double-bass\nJoey Baron drums");
    
    
    mouse =false;
    
    enlarge = 100;
    nextpageleft = false;
    nextpageright = false;
    
    numberflipsleft = 0;
    numberflipsright = 0;
    
    totalflips = 0;
    page = 0;
    
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
    
    //blurry and smooth
    ofLogoImage.loadImage("leipzig.jpg");
    ofLogoImage2.loadImage("melos.jpg");
    ofLogoImage3.loadImage("gustavsen.jpg");
    ofLogoImage4.loadImage("canopee.jpg");
    ofLogoImage5.loadImage("bartsch.jpg");
    
    ofLogoImage6.loadImage("january.jpg");
    ofLogoImage7.loadImage("colour.jpg");
    ofLogoImage8.loadImage("formanek.jpg");
    ofLogoImage9.loadImage("farside.jpg");
    ofLogoImage10.loadImage("seim.jpg")
    ;
    ofLogoImage11.loadImage("play.jpg");
    ofLogoImage12.loadImage("velocities.jpg");
    ofLogoImage13.loadImage("darkeyes.jpg");
    ofLogoImage14.loadImage("letmego.jpg");
    ofLogoImage15.loadImage("purcor.jpg");
    
    //red
    ofLogoImage16.loadImage("schubert.jpg");
    ofLogoImage17.loadImage("monk.jpg");
    ofLogoImage18.loadImage("eleni.jpg");
    ofLogoImage19.loadImage("gesualdo.jpg");
    ofLogoImage20.loadImage("anyder.jpg");
    
    ofLogoImage21.loadImage("micus.jpg");
    ofLogoImage22.loadImage("romaria.jpg");
    ofLogoImage23.loadImage("hollinger.jpg");
    ofLogoImage24.loadImage("andras.jpg");
    ofLogoImage25.loadImage("trovesi.jpg");
    
	ofLogoImage26.loadImage("yannatou.jpg");
    ofLogoImage27.loadImage("williams.jpg");
    ofLogoImage28.loadImage("condori.jpg");
    ofLogoImage29.loadImage("sclavis.jpg");
    ofLogoImage30.loadImage("perenyi.jpg");
    
    //black and white
	ofLogoImage31.loadImage("smith.jpg");
    ofLogoImage32.loadImage("clavier.jpg");
    ofLogoImage33.loadImage("rio.jpg");
    ofLogoImage34.loadImage("negros.jpg");
    ofLogoImage35.loadImage("dresden.jpg");
    
	ofLogoImage36.loadImage("stubss.jpg");
    ofLogoImage37.loadImage("sleeper.jpg");
    ofLogoImage38.loadImage("sunrise.jpg");
    ofLogoImage39.loadImage("katuche.jpg");
    ofLogoImage40.loadImage("janacek.jpg");
    
	ofLogoImage41.loadImage("testament.jpg");
    ofLogoImage42.loadImage("mediaval.jpg");
    ofLogoImage43.loadImage("lascala.jpg");
    ofLogoImage44.loadImage("metamusik.jpg");
    ofLogoImage45.loadImage("rypdal.jpg");
    
    //grainy
	ofLogoImage46.loadImage("libero.jpg");
    ofLogoImage47.loadImage("vitous.jpg");
    ofLogoImage48.loadImage("diminuito.jpg");
    ofLogoImage49.loadImage("food.jpg");
    ofLogoImage50.loadImage("bittova.jpg");
    
	ofLogoImage51.loadImage("imprint.jpg");
    ofLogoImage52.loadImage("indicum.jpg");
    ofLogoImage53.loadImage("vanel.jpg");
    ofLogoImage54.loadImage("batagraf.jpg");
    ofLogoImage55.loadImage("magnetic.jpg");
    
	ofLogoImage56.loadImage("young.jpg");
    ofLogoImage57.loadImage("classtrip.jpg");
    ofLogoImage58.loadImage("giger.jpg");
    ofLogoImage59.loadImage("bach.jpg");
    ofLogoImage60.loadImage("berg.jpg");
    
    
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
    //ofBackground(185,184,174);            website color
    pointLight.setPosition(cos(ofGetElapsedTimef()*.6f) * radius * 2 + center.x,
						   sin(ofGetElapsedTimef()*.8f) * radius * 2 + center.y,
						   -cos(ofGetElapsedTimef()*.8f) * radius * 2 + center.z);
	
    spotLight.setOrientation( ofVec3f( 0, cos(ofGetElapsedTimef()) * RAD_TO_DEG, 0) );
	spotLight.setPosition( mouseX, mouseY, 200);
    
    float x, y;
    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
    x = mouse.x;
    y = mouse.y;
    
    
    
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
            
            //this needs to be fixed, we shifted 230 before projecting forward, so it's not really 230...
			if((x > 95+230+ (i*160)) && (x< 95+230+(i+1)*160)&& (y > 172+(j*160)) && (y < 172+ (j+1)*160)){
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
    
    
    
    //turning page with swiping, this is a little buggy so I'm gonna leave it out for now
    /*if(mousedrag.size() >= 2){
     float x1 = mousedrag[0];
     float x2 = mousedrag[1];
     if (x1- x2 < 0){
     nextpageleft = true;
     numberflipsleft++;
     resetrotate = true;
     }
     else{
     nextpageright = true;
     numberflipsright++;
     resetrotate = true;
     }
     mousedrag.clear();
     
     }*/
}

//deperecated since "pushing forward" out of the screen is relative to orientation, not necessarily just changing the z component
void testApp::emerge(){
    ofTranslate(0,0,enlarge);
}
//--------------------------------------------------------------
void testApp::draw(){
    
    
    if(togglecaption){
        
        ofSetColor(51, 102, 133);
        //ofSetColor(255,0,0);
        //caption.drawString(descriptions[0],20, 170);
        
        ofDrawBitmapString(descriptions[captionindex], 20,170);        //seems to look much better also does not get eclipsed by anything
        togglecaption = false;
    }
    
    ofTranslate(230,0,0);
    
    ofSetColor(255,0,0);
    //logo.setLetterSpacing(1.2);
    logo.drawStringAsShapes(" Enjoy ECM ", 393,50);
    //ofSetColor(255,255,255);
    ofSetColor(176,196,222);
    author.drawStringAsShapes(" (by Tian Xu)", 500,68);
    
    
    
    
    
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    // enable lighting //
    //ofEnableLighting();
    // enable the material, so that it applies to all 3D objects before material.end() call //
	material.begin();
    
    
    
    /*ofPushMatrix();
     ofTranslate(0, 0, 500);
     //font.drawString("test", ofGetWidth()/2 - 20, ofGetHeight()/2);
     font.drawStringAsShapes("what is wrong with this track", ofGetWidth()/2 + 20, ofGetHeight()/2);
     ofPopMatrix();*/
    
    
    
    //cout<<"we are currently on page # "<<page<<endl;
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
        startpage += .1;											//speed of rotation
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
        startpage += .1;
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
	
    
    float deg;
    int height;
    if(rownumber == 1)
        height = -100;
    else if (rownumber == 2)
        height = -100;
    else
        height = 125;
    ofColor textcolor(176,196,222);
    float translatex, translatez;
    
	for( int i = 0; i<5; i++){
        if( (page != 1) || (i != 0) ){
            if( (page != 3) || (i != 4) ){
                
                ofPushMatrix();
                ofTranslate(-200 + i*100, 300, 200);
                //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
                if(rotate[i]){
                    //ofTranslate(0,0,50);
                    //emerge();
                    //aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
                    togglecaption = true;
                    captionindex = 10+i;
                    
                    trans = 100;
                    //emerge();
                    //aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
                    ofTranslate(0,0,enlarge);
                    
                    
                    ofPushMatrix();
                    //ofRotate(-60, 1,0,0);
                    ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);         //this is 180/pi
                    
                    
                    //ofSetColor(51, 102, 183);
                    for(int i = 0; i<tracks.size(); i++){
                        ofPushMatrix();
                        
                        //deg = ofGetElapsedTimef()*.6 * RAD_TO_DEG;
                        //deg = deg * pi / 180;
                        deg = 360/tracks.size();
                        deg *= i;
                        deg = deg * pi / 180;
                        //cout<<"angle is"<<deg;
                        //cout<<" and x is"<<50*sqrt(2)*cos(deg)<<"and y is"<<-50*sqrt(2)*sin(deg)<<endl;
                        
                        translatex = 20*sqrt(2)*cos(deg);
                        translatez = -20*sqrt(2)*sin(deg);
                        
                        
                        ofTranslate(translatex,125 + 35*sqrt(2)*cos(deg/2),translatez);
                        ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                        
                        ofSetColor(textcolor);
                        songs[i].drawStringAsShapes(tracks[i], 0,0);
                        
                        ofSetColor(255,255,255);
                        ofPopMatrix();
                        
                        trans = 100;
                    }
                    ofPopMatrix();
                    
                    trans = 255;
                    ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
                }
                ofSetColor(255,255,255,trans);    //turn on transparency
                if(bUseTexture) ecmcovers[i].getTextureReference().bind();
                ofDrawBox(0, 0, 0, 100);
                ofPopMatrix();
                if(bUseTexture) ecmcovers[i].getTextureReference().unbind();
            }
        }
	}
    
    for( int i = 0; i<5; i++){
        if( (page != 1) || (i != 0) ){
            if( (page != 3) || (i != 4) ){
                
                ofPushMatrix();
                ofTranslate(-200 + i*100, 400, 200);
                //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
                if(rotate[5+i]){
                    //emerge();
                    //aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
                    //ofTranslate(0,0,enlarge);
                    //ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
                    
                    togglecaption = true;
                    captionindex = 10+i;
                    
                    trans = 100;
                    //emerge();
                    //aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
                    ofTranslate(0,0,enlarge);
                    
                    
                    ofPushMatrix();
                    //ofRotate(-60, 1,0,0);
                    ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);         //this is 180/pi
                    
                    
                    //ofSetColor(51, 102, 183);
                    for(int i = 0; i<tracks.size(); i++){
                        ofPushMatrix();
                        
                        //deg = ofGetElapsedTimef()*.6 * RAD_TO_DEG;
                        //deg = deg * pi / 180;
                        deg = 360/tracks.size();
                        deg *= i;
                        deg = deg * pi / 180;
                        //cout<<"angle is"<<deg;
                        //cout<<" and x is"<<50*sqrt(2)*cos(deg)<<"and y is"<<-50*sqrt(2)*sin(deg)<<endl;
                        
                        translatex = 20*sqrt(2)*cos(deg);
                        translatez = -20*sqrt(2)*sin(deg);
                        
                        
                        ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
                        ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                        
                        ofSetColor(textcolor);
                        songs[i].drawStringAsShapes(tracks[i], 0,0);
                        
                        ofSetColor(255,255,255);
                        ofPopMatrix();
                        
                        trans = 100;
                    }
                    ofPopMatrix();
                    
                    trans = 255;
                    ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
                    
                }
                ofSetColor(255,255,255,trans);    //turn on transparency
                
                if(bUseTexture) ecmcovers[5+i].getTextureReference().bind();
                ofDrawBox(0, 0, 0, 100);
                if(bUseTexture) ecmcovers[5+i].getTextureReference().unbind();
                ofPopMatrix();
            }
        }
	}
    
    
    
    
    ofColor blue = ofColor(51, 102, 183);
    for( int i = 0; i < 5; i++) {
        if( (page != 1) || (i != 0) ){
            if( (page != 3) || (i != 4) ){
                
                ofPushMatrix();
                ofTranslate(-200 + i*100, 500, 200);
                //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
                
                
                if(rotate[10+i]){
                    
                    togglecaption = true;
                    captionindex = 10+i;
                    
                    trans = 100;
                    //emerge();
                    //aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
                    ofTranslate(0,0,enlarge);
                    
                    
                    ofPushMatrix();
                    //ofRotate(-60, 1,0,0);
                    ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);         //this is 180/pi
                    
                    
                    //ofSetColor(51, 102, 183);
                    for(int i = 0; i<tracks.size(); i++){
                        ofPushMatrix();
                        
                        //deg = ofGetElapsedTimef()*.6 * RAD_TO_DEG;
                        //deg = deg * pi / 180;
                        deg = 360/tracks.size();
                        deg *= i;
                        deg = deg * pi / 180;
                        //cout<<"angle is"<<deg;
                        //cout<<" and x is"<<50*sqrt(2)*cos(deg)<<"and y is"<<-50*sqrt(2)*sin(deg)<<endl;
                        
                        translatex = 20*sqrt(2)*cos(deg);
                        translatez = -20*sqrt(2)*sin(deg);
                        
                        
                        ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
                        ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                        
                        ofSetColor(textcolor);
                        songs[i].drawStringAsShapes(tracks[i], 0,0);
                        
                        ofSetColor(255,255,255);
                        ofPopMatrix();
                        
                        trans = 100;
                    }
                    ofPopMatrix();
                    
                    trans = 255;
                    ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
                }
                
                //ofSetColor(255,255,255);
                if(bUseTexture) ecmcovers[10+i].getTextureReference().bind();
                ofDrawBox(0, 0, 0, 100);
                
                if(bUseTexture) ecmcovers[10+i].getTextureReference().unbind();
                ofPopMatrix();
                //togglecaption = false;
            }
        }
	}
	
    
    
    
    
    
	//building the second face (left wall) from back to front, top to bottom like you did the front face had you rotate it
	//so last cube is actually the first of our front wall, ie cover[19] is same as cover[0]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
        if( (page != 2) || (i != 0) ){
            if(bUseTexture) ecmcovers[15+i].getTextureReference().bind();
            ofPushMatrix();
            ofTranslate(-200, 300, -200+ i*100);
            //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
            if(rotate[15+i]){
                //ofTranslate(0,0,enlarge);
                //emerge();
                //prior to rotation these are aligned on the z axis and facing "west" so to speak causing it to point out of screen with a counterclockwise turn
                ofTranslate(-enlarge,0,0);
                ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
            }
            ofDrawBox(0, 0, 0, 100);
            ofPopMatrix();
            if(bUseTexture) ecmcovers[15+i].getTextureReference().unbind();
        }
	}
    
	//cover[24] is same as cover[5]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
        if( (page != 2) || (i != 0) ){
            if(bUseTexture) ecmcovers[20+i].getTextureReference().bind();
            ofPushMatrix();
            ofTranslate(-200, 400, -200+ i*100);
            //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
            if(rotate[20+i]){
                //ofTranslate(0,0,enlarge);
                //emerge();
                //prior to rotation these are aligned on the z axis and facing "west" so to speak causing it to point out of screen with a counterclockwise turn
                ofTranslate(-enlarge,0,0);
                ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
            }
            ofDrawBox(0, 0, 0, 100);
            ofPopMatrix();
            if(bUseTexture) ecmcovers[20+i].getTextureReference().unbind();
        }
	}
    
	//cover[29] is same as cover[10]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
        if( (page != 2) || (i != 0) ){
            if(bUseTexture) ecmcovers[25+i].getTextureReference().bind();
            ofPushMatrix();
            ofTranslate(-200, 500, -200+ i*100);
            //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
            if(rotate[25+i]){
                //ofTranslate(0,0,enlarge);
                //emerge();
                //prior to rotation these are aligned on the z axis and facing "west" so to speak causing it to point out of screen with a counterclockwise turn
                ofTranslate(-enlarge,0,0);
                ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
            }
            ofDrawBox(0, 0, 0, 100);
            ofPopMatrix();
            if(bUseTexture) ecmcovers[25+i].getTextureReference().unbind();
        }
	}
    
	
    
    
	//building the back wall such that had you rotate it, it'd be left to right top to bottom same construction
	//so really its right to left top to bottom here
	//cover[34] is same as cover[15]
	//make sure you load the same image..
    
	for( int i = 0; i<5; i++){
        if( (page != 3) || (i != 0) ){
            if(bUseTexture) ecmcovers[30+i].getTextureReference().bind();
            ofPushMatrix();
            ofTranslate(200 - i*100, 300, -200);
            //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
            if(rotate[30+i]){
                //ofTranslate(0,0,enlarge);
                //emerge();
                //aligned on the x axis but facing into the screen resulting in outward normal upon a 2 page counterclockwise turn
                ofTranslate(0,0,-enlarge);
                ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
            }
            ofDrawBox(0, 0, 0, 100);
            ofPopMatrix();
            if(bUseTexture) ecmcovers[30+i].getTextureReference().unbind();
        }
	}
    
	//cover[39] is same as cover[20]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
        if( (page != 3) || (i != 0) ){
            if(bUseTexture) ecmcovers[35+i].getTextureReference().bind();
            ofPushMatrix();
            ofTranslate(200 - i*100, 400, -200);
            //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
            if(rotate[35+i]){
                //ofTranslate(0,0,enlarge);
                //emerge();
                //aligned on the x axis but facing into the screen resulting in outward normal upon a 2 page counterclockwise turn
                ofTranslate(0,0,-enlarge);
                ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
            }
            ofDrawBox(0, 0, 0, 100);
            ofPopMatrix();
            if(bUseTexture) ecmcovers[35+i].getTextureReference().unbind();
        }
	}
    
	//cover[44] is same as cover[25]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
        if( (page != 3) || (i != 0) ){
            if(bUseTexture) ecmcovers[40+i].getTextureReference().bind();
            ofPushMatrix();
            ofTranslate(200 - i*100, 500, -200);
            //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
            if(rotate[40+i]){
                //ofTranslate(0,0,enlarge);
                //emerge();
                //aligned on the x axis but facing into the screen resulting in outward normal upon a 2 page counterclockwise turn
                ofTranslate(0,0,-enlarge);
                ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
            }
            ofDrawBox(0, 0, 0, 100);
            ofPopMatrix();
            if(bUseTexture) ecmcovers[40+i].getTextureReference().unbind();
        }
	}
    
    
    
    
    
	//building the final right wall from front to back top to bottom
	//cover[49] is same as cover[30]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
        //if( (page != 0) || (i != 0) ){
        if(bUseTexture) ecmcovers[45+i].getTextureReference().bind();
        ofPushMatrix();
        ofTranslate(200, 300, 200 - i*100);
        //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
        if(rotate[45+i]){
            //ofTranslate(0,0,enlarge);
            //emerge();
            //originally face "east"...same idea
            ofTranslate(enlarge,0,0);
            ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
        }
        ofDrawBox(0, 0, 0, 100);
        ofPopMatrix();
        if(bUseTexture) ecmcovers[45+i].getTextureReference().unbind();
        //}
	}
    
	//cover[54] is same as cover[35]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
        //if( (page != 0) || (i != 0) ){
        if(bUseTexture) ecmcovers[50+i].getTextureReference().bind();
        ofPushMatrix();
        ofTranslate(200, 400, 200 - i*100);
        //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
        if(rotate[50+i]){
            //ofTranslate(0,0,enlarge);
            //emerge();
            //originally face "east"...same idea
            ofTranslate(enlarge,0,0);
            ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
        }
        ofDrawBox(0, 0, 0, 100);
        ofPopMatrix();
        if(bUseTexture) ecmcovers[50+i].getTextureReference().unbind();
        //}
	}
    
	//cover[59] is same as cover[40]
	//make sure you load the same image..
	for( int i = 0; i<5; i++){
        //if( (page != 0) || (i != 0) ){
        if(bUseTexture) ecmcovers[55+i].getTextureReference().bind();
        ofPushMatrix();
        ofTranslate(200, 500, 200 - i*100);
        //ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 1, 0, 0);
        if(rotate[55+i]){
            //ofTranslate(0,0,enlarge);
            //emerge();
            //originally face "east"...same idea
            ofTranslate(enlarge,0,0);
            ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
        }
        ofDrawBox(0, 0, 0, 100);
        ofPopMatrix();
        if(bUseTexture) ecmcovers[55+i].getTextureReference().unbind();
        //}
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
	
    ofPopMatrix();
	ofSetColor(255, 255, 255);
    
	/*ofDrawBitmapString("Point Light On (1) : "+ofToString(bPointLight) +"\n"+
     "Spot Light On (2) : "+ofToString(bSpotLight) +"\n"+
     "Directional Light On (3) : "+ofToString(bDirLight)+"\n"+
     "Shiny Objects On (s) : "+ofToString(bShiny)+"\n"+
     "Spot Light Cutoff (up/down) : "+ofToString(spotLight.getSpotlightCutOff(),0)+"\n"+
     "Spot Light Concentration (right/left) : " + ofToString(spotLight.getSpotConcentration(),0)+"\n"+
     "Smooth Lighting enabled (x) : "+ofToString(bSmoothLighting,0)+"\n"+
     "Textured (t) : "+ofToString(bUseTexture,0),
     20, 20);*/
    
    
    
    //drawing panel, deprecated as I opted for the helical track display
    /*
     int rows = 10;
     int last = 0;
     
     ofTranslate(-50, 350, 450);
     
     for(int i = 0; i< rows-1; i++){
     if(i%2 == 1){
     ofSetColor(176,196,222,100);
     ofRect(0,width*i,100,width);
     
     
     ofSetColor(255,255,255);
     //ofDrawBitmapString("Track " + ofToString(i)+". testing", 5, i*width+6);
     //ofDrawBitmapString("Track " + ofToString(i)+". testing", 5.25, i*width+6);     //crude bolding effect
     ofTranslate(0,0,1);
     ofSetColor(51, 102, 183);
     font.drawStringAsShapes("Track " + ofToString(i)+". testing", 10, i*width+5);
     
     ofTranslate(0,0,-1);
     }
     else{
     if(i != 0){
     ofSetColor(112,128,144,100);
     ofRect(0,width*i,100,width);
     ofSetColor(255,255,255,255);
     ofTranslate(0,0,1);
     ofSetColor(51, 102, 183);
     font.drawStringAsShapes("Track " + ofToString(i)+". testing", 10, i*width+5);
     ofTranslate(0,0,-1);
     //ofDrawBitmapString("Track " + ofToString(i)+". testing", 5, i*width+6);
     //ofDrawBitmapString("Track " + ofToString(i)+". testing", 5.25, i*width+6);     //again..
     }
     }
     }
     
     ofSetColor(176,196,222,100);
     ofRectangle myRect;
     myRect.x = 0;
     myRect.y = 0;
     myRect.width = 100;
     myRect.height = width*rows;
     ofRectRounded( myRect, 2 );
     */
    
    
    
    
    /*
     ofTranslate(-50, 350, 450);
     ofSetColor(176,196,222,100);
     ofRect(0,0,100,10);
     
     ofSetColor(119,136,153,100);
     ofRect(0,10,100,10);
     
     ofSetColor(176,196,222,100);
     ofRect(0,20,100,10);
     
     ofSetColor(119,136,153,100);
     ofRect(0,30,100,10);
     
     ofSetColor(176,196,222,100);
     ofRect(0,40,100,10);
     
     ofSetColor(119,136,153,100);
     ofRect(0,50,100,10);
     
     ofSetColor(176,196,222,100);
     ofRect(0,60,100,10);
     
     ofSetColor(119,136,153,100);
     ofRect(0,70,100,10);
     
     ofSetColor(176,196,222,100);
     ofRect(0,80,100,10);
     
     ofSetColor(119,136,153,100);
     ofRect(0,90,100,10);
     */
    
    ofSetColor(255,255,255);
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
        case 'n':
            nextpageleft = true;
            numberflipsleft++;
            resetrotate = true;
            break;
        case 'm':
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
    /*cout<<"dragging at location x = "<<x<<" and y = "<<y<<endl;
     mousedrag.push_back(x);
     */
}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    /*cout<<"pressed at location x = "<<x<<" and y = "<<y<<endl;
     mouse = true;
     mousedrag.push_back(x);*/
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    /*cout<<"released at location x = "<<x<<" and y = "<<y<<endl;
     //mousedrag.clear();
     mouse = false;*/
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