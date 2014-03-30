#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void emerge();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofLight pointLight;
	ofLight spotLight;
	ofLight directionalLight;
	
	ofMaterial material;
    ofImage ofLogoImage;
    ofImage ofLogoImage2;
    ofImage ofLogoImage3;
    ofImage ofLogoImage4;
    ofImage ofLogoImage5;
	ofImage ofLogoImage6;
    ofImage ofLogoImage7;
    ofImage ofLogoImage8;
    ofImage ofLogoImage9;
    ofImage ofLogoImage10;
    ofImage ofLogoImage11;
    ofImage ofLogoImage12;
    ofImage ofLogoImage13;
    ofImage ofLogoImage14;
    ofImage ofLogoImage15;
    
    ofImage ofLogoImage16;
    ofImage ofLogoImage17;
    ofImage ofLogoImage18;
    ofImage ofLogoImage19;
    ofImage ofLogoImage20;
    
    ofImage ofLogoImage21;
    ofImage ofLogoImage22;
    ofImage ofLogoImage23;
    ofImage ofLogoImage24;
    ofImage ofLogoImage25;
    
    ofImage ofLogoImage26;
    ofImage ofLogoImage27;
    ofImage ofLogoImage28;
    ofImage ofLogoImage29;
    ofImage ofLogoImage30;
    
    ofImage ofLogoImage31;
    ofImage ofLogoImage32;
    ofImage ofLogoImage33;
    ofImage ofLogoImage34;
    ofImage ofLogoImage35;
    
    ofImage ofLogoImage36;
    ofImage ofLogoImage37;
    ofImage ofLogoImage38;
    ofImage ofLogoImage39;
    ofImage ofLogoImage40;
    
    ofImage ofLogoImage41;
    ofImage ofLogoImage42;
    ofImage ofLogoImage43;
    ofImage ofLogoImage44;
    ofImage ofLogoImage45;
    
    ofImage ofLogoImage46;
    ofImage ofLogoImage47;
    ofImage ofLogoImage48;
    ofImage ofLogoImage49;
    ofImage ofLogoImage50;
    
    ofImage ofLogoImage51;
    ofImage ofLogoImage52;
    ofImage ofLogoImage53;
    ofImage ofLogoImage54;
    ofImage ofLogoImage55;
    
    ofImage ofLogoImage56;
    ofImage ofLogoImage57;
    ofImage ofLogoImage58;
    ofImage ofLogoImage59;
    ofImage ofLogoImage60;
    
    ofImage ofLogoImage61;
    ofImage ofLogoImage62;
    ofImage ofLogoImage63;
    ofImage ofLogoImage64;
    ofImage ofLogoImage65;
    ofImage ofLogoImage66;
    vector<ofImage> ecmcovers;
    
    bool swipe;
    
    float enlarge;
    
    float timeelapsed;
    float timeexit;
    
    float startpage;
    bool nextpageleft;
    bool stayonpage;
    int numberflipsleft;
    
    
    bool nextpageright;
    int numberflipsright;
    
    int totalflips;
    int page;
    
    int nextiteri, nextiterj;
    
    std::vector<float> mousedrag;
    bool mouse;
    bool mouseclick;
    
    bool draw_wall0, draw_wall1, draw_wall2, draw_wall3;
    bool drawwalls;
    
	float radius;
	ofVec3f center;
	bool bShiny;
    bool bSmoothLighting;
	bool bPointLight, bSpotLight, bDirLight;
    bool bUseTexture;
    
    int rownumber;
    
    vector<bool> loadmenu;
    vector<bool> rotate;
    vector<bool> freeze;
    bool scrollcubes;
    bool scrolltracks;
    bool playsong;
    bool selectsong;
    
    ofSoundPlayer song;
    ofSoundPlayer song2;
    ofSoundPlayer song3;
    ofSoundPlayer song4;
    ofSoundPlayer song5;
    ofSoundPlayer song6;
    ofSoundPlayer song7;
    ofSoundPlayer song8;
    ofSoundPlayer song9;
    ofSoundPlayer song10;
    ofSoundPlayer song11;
    ofSoundPlayer song12;
    
    vector<ofSoundPlayer> listing;
    
    
    string test1;
    string test2;
    string test3;
    string test4;
    string test5;
    string test6;
    string test7;
    string test8;
    string test9;
    string test10;
    string test11;
    string test12;
    vector<string> location;
    int songnumber;
    
    int cube;
    
    bool resetrotate;
    bool rotateface;
	bool axisrotate;
    
    int width = 6;
    
    float fontsize;
    ofTrueTypeFont  logo;
    ofTrueTypeFont  logo2;
    ofTrueTypeFont	font;
    ofTrueTypeFont  font2;
    ofTrueTypeFont	font3;
    ofTrueTypeFont	font4;
    ofTrueTypeFont	font5;
    ofTrueTypeFont	font6;
    ofTrueTypeFont	font7;
    ofTrueTypeFont	font8;
    ofTrueTypeFont	font9;
    ofTrueTypeFont	font10;
    
    
    int trans;
    
    ofTrueTypeFont  author;
    ofTrueTypeFont  date;
    ofTrueTypeFont  signature;
    vector<ofTrueTypeFont> songs;
    vector<string> tracks;
    
    vector<string> descriptions;
    ofTrueTypeFont caption;
    int captionindex;
    bool togglecaption;
    ofImage heat;
    
    ofColor songcolor;
    
    vector<ofColor>trackcolors1;
	vector<ofColor>trackcolors2;
    vector<ofColor>trackcolors;			//this will assume one of the above 3 depending on the current page

    vector<vector<ofColor> > albumcolors;
    vector<ofColor> pagecolors;
    vector<ofColor> highlightcolors;
    
    
    
    
};
