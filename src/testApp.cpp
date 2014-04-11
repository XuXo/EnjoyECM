
//@author tian xu

/*A simple music player for my favorite music label ECM.  It was really to showcase the gorgeous album covers so the music playing functionality
 has been kept to a minimal level.  You can read about it from http://www.amazon.com/Windfall-Light-The-Visual-Language/dp/3037781572.  In keeping
 with its turn for a darker more sinewy feel and reliance on more distilled colors and textures, I have removed some of the original design which
 was a bit too busy and opted for a more stoic look.  few colors, simple fonts, squared edges, minimal interplay of light and shadows.  The title
 comes from "Enjoy Incubus" which I always really liked.
 
 This code is not robust, I will definitely refactor it at some point but right now all
 I care about is the aesthetics, looking slick without crushing fps would be good.
 */

bool toggleprevious, togglenext, togglestop;
bool shrink;

#include "testApp.h"
//#include <boost/lambda/lambda.hpp>

void testApp::setup(){
    
	toggleprevious = false;
	togglenext = false;
	togglestop = false;
    
	shrink = false;
    
    alpha = 255;
    
	//starttime = 0;
	//endtime = 0;
	timeelapsed = 0;
    
    drawwalls = false;
    songnumber = 0;
    currentsong = 0;
    
    trans = 255;
    togglecaption = false;
    captionindex = 0;
    ofSetWindowShape(1400,1000);
    
    logo.loadFont("type/verdana.ttf", 22, true, false, true, 0.1, 102);
    logo2.loadFont("type/verdana.ttf", 6, true, false, true, 0.1, 102);
    author.loadFont("type/verdana.ttf", 5.8, true, false, true, 0.1, 102);
    signature.loadFont("type/verdana.ttf", 6, true, false, true, 0.1, 102);
    date.loadFont("type/dinen.ttf", 10, true, false, true, 0.1, 102);
    date.setLetterSpacing(1.3);
    
    caption.loadFont("verdana.ttf", 8, true, true);
	caption.setLineHeight(14.0f);
	caption.setLetterSpacing(1.035);
    
    rownumber = 0;
    songcolor = ofColor(176,196,222);
    
    cube = 0;
    
    
	/*Font has to be loaded in setup() but later on in draw() after projecting forward with oftranslate (0,0,500), the font is blown up (rightly so I guess).
     size 5 (along whatever initial z plane projected forward would give me the right size after projection but it has pretty bad resolution.Once I translate
     forward, it just projects each of those pixels and so loses a lot of density.  Ended up using drawStringAsShapes() but still doesn't look very sharp
     */
	int fontsize = 4;
	int dpi = 182;
	float alias = 0.05;
    
	
	//don't need individual fonts for each song...
	trackfont.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
    
	/*font.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
     font2.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
     font3.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
     font4.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
     font5.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
     font6.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
     font7.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
     font8.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
     font9.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
     font10.loadFont("type/verdana.ttf", fontsize, true, false, true, alias, dpi);
     
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
     */
    
    
	//actual track names to be displayed
    tracks.push_back("01. Barcarole");
    tracks.push_back("02. Are You Going With Me");
    tracks.push_back("03. Au Lait");
    tracks.push_back("04. Eighteen");
    tracks.push_back("05. Offramp");
    tracks.push_back("06. James");
    tracks.push_back("07. The Bat, Part 2");
    tracks.push_back("08. condori");
    tracks.push_back("09. micus");
    tracks.push_back("10. sclavis");
    
	//actual location and song names in directory
    test1 ="songs/01 Barcarole.mp3";
    test2 ="songs/02 Are You Going With Me_.mp3";
    test3 ="songs/03 Au Lait.mp3";
    test4 ="songs/04 Eighteen.mp3";
    test5 ="songs/05 Offramp.mp3";
    test6 ="songs/06 James.mp3";
    test7 ="songs/01 Barcarole.mp3";
    test8 ="songs/03 Au Lait.mp3";
    test9 ="songs/04 Eighteen.mp3";
    test10 ="songs/01 Barcarole.mp3";
    
    location.push_back(test1);
    location.push_back(test2);
    location.push_back(test3);
    location.push_back(test4);
    location.push_back(test5);
    location.push_back(test6);
    location.push_back(test7);
    location.push_back(test8);
    location.push_back(test9);
    location.push_back(test10);
    location.push_back(test11);
    location.push_back(test12);
    
    //these are just soundstreams so empty right now
    listing.push_back(song1);
    listing.push_back(song2);
    listing.push_back(song3);
    listing.push_back(song4);
    listing.push_back(song5);
    listing.push_back(song6);
    listing.push_back(song7);
    listing.push_back(song8);
    listing.push_back(song9);
    listing.push_back(song10);
    listing.push_back(song11);
    listing.push_back(song12);
    
    //load each track in a separate thread even though this is uncompletely unnecessary it seems
    for (int i =0; i<location.size(); i++){
        thread1.load(location[i],listing[i]);
    }
    
	//color for track listings
	ofColor bckgrnd1 = ofColor(51,102,193);
    for(int i = 0; i<tracks.size(); i++){
		trackcolors1.push_back(bckgrnd1);
	}
	
	ofColor bckgrnd2 = ofColor(176, 196, 222);
    for(int i = 0; i<tracks.size(); i++){
		trackcolors2.push_back(bckgrnd2);
	}
    
    //so only page 1 is different
    albumcolors.push_back(trackcolors2);
    albumcolors.push_back(trackcolors1);
    albumcolors.push_back(trackcolors2);
    albumcolors.push_back(trackcolors2);
    
    //pagecolors should be same as albumcolors, thats what the color should revert back to when not scroll-locked
    pagecolors.push_back(ofColor(176, 196, 222));
    pagecolors.push_back(ofColor(51, 102, 193));
    pagecolors.push_back(ofColor(176, 196, 222));
    pagecolors.push_back(ofColor(176, 196, 222));
    
    //these are the colors for the highlighted tracks depending on the page number
    highlightcolors.push_back(ofColor(200,0,0));
    highlightcolors.push_back(ofColor(211,211,211));
    highlightcolors.push_back(ofColor(0,0,120));
    highlightcolors.push_back(ofColor(200,0,0));
    
    
	//loading the captions to be displayed when mouse scrolls over any particualr track, to do: include cover number and year produced as well..also need a better way to control the line breaks as I did
	//these manually based on the position of the cube
    /*******************
     page 1
     *******************/
    
    
    descriptions.push_back("Ketil Bjornstad\nTerje Rypdal\nLife in Leipzig\n\nKetil Bjornstad piano\nTerje Rypdal guitar");
    
    descriptions.push_back("Vassilis Tsabropoulos\nAnja Lechner\nU. T. Gandhi\nMelos\n\nVassilis Tsabropoulos piano\nAnja Lechner violoncello\nU. T. Gandhi percussion");
    
    descriptions.push_back("Tord Gustavsen Trio\nBeing There\n\nTord Gustavsen piano\nHarald Johnsen double-bass\nJarle Vespestad drums");
    
    descriptions.push_back("Dans les arbres\nCanopee\n\nXavier Charles clarinet, harmonica\nIvar Grydeland acoustic guitar, banjo, scruti box\nChristian Wallumrod prepared piano, harmonium\nIngar Zach gran cassa, percussion");
    
    descriptions.push_back("Nik Bartsch's Ronin\nStoa\n\nNik Bartsch piano\nSha contrabass and bass clarinets\nBjorn Meyer bass\nKaspar Rast drums\nAndi Pupato percussion");
    
    descriptions.push_back("Marcin Wasilewski Trio\nJanuary\n\nMarcin Wasilewski piano\nSlawomir Kurkiewicz double-bass\nMichal Miskiewicz drums");
    
    descriptions.push_back("Andy Sheppard\nMovements in Colour\n\nAndy Sheppard soprano and tenor saxophones\nJohn Parricelli acoustic and electric guitars\nEivind Aarset guitar, electronics\nArild Andersen double-bass, electronics\nKuljit Bhamra tabla, percussion");
    
    descriptions.push_back("Michael Formanek\nSmall Places\n\nTim Berne alto saxophone\nCraig Taborn piano\nMichael Formanek double-bass\nGerald Cleaver drums, shruti box");
    
    descriptions.push_back("Roscoe Mitchell\nThe Note Factory\nFar Side\n\nRoscoe Mitchell saxophones, flutes\nCorey Wilkes trumpet, flugelhorn\nCraig Taborn piano\nVijay Iyer piano\nHarrison Bankhead cello, double-bass\nJaribu Shahid double-bass\nTanni Tabbal drums\nVincent Davis drums");
    
    descriptions.push_back("Trygve Seim\nFrode Haltli\nYeraz\n\nTrygve Seim soprano and tenor saxophones\nFrode Haltli accordion ");
    
    descriptions.push_back("Jon Balke\nBatagraf\nSay And Play\nJon Balke piano, keyboards, electronics, tungone, \ndarbouka, percussion\nHelge Andreas Norbakken sabar, gorong, djembe, \ntalking drum, shakers, percussion\nEmilie Stoesen Christensen vocals\nErland Dahlen drums\nTorgeir Rebolledo Pedersen poetry reading");
    
    descriptions.push_back("Jon Balke\nBook of Velocities\n\nJon Balke piano");
    
    descriptions.push_back("Tomasz Stanko Quintet\nDark Eyes\n\nTomasz Stanko trumpet\nAlexi Tuomarila piano\nJakob Bro guitar\nAnders Christensen bass\nOlavi Louhivuori drums");
    
    descriptions.push_back("Keith Jarrett\nGary Peacock\nJack DeJohnette\nAlways Let Me Go\n\nKeith Jarrett piano\nGary Peacock double-bass\nJack DeJohnette drums");
    
    descriptions.push_back("Trygve Seim\nAndreas Utnem\nPurcor\n\nTrygve Seim tenor and soprano saxophones\nAndreas Utnem piano, harmonium");
    
    
    
    /*******************
     page 2
     *******************/
    
    
    descriptions.push_back("Franz Schubert\nFantasie C-Dur\nRondo h-Moll\nSonata A-Dur\n\nCarolin Widmann violin\nAlexander Lonquich piano");
    
    descriptions.push_back("Meredith Monk\nSongs of Ascension\n\nMeredith Monk and Vocal Ensemble voices\nTodd Reynolds Quartet string quartet\nThe M6 voices\nMontclair State University Singers ");
    
    descriptions.push_back("Eleni Karaindrou\nTrojan Women\n\nSocratis Sinopoulos Constantinople lyra, laouto\nChristos Tsiamoulis ney, suling, outi\nPanos Dimitrakopoulos kanonaki\nAndreas Katsiyiannis santouri\nMaria Bildea harp\nAndreas Papas bendir, daouli\nVeronika Iliopoulou soprano\nEleni Karaindrou\nAntonis Kontogeorgiou chorus director");
    
    descriptions.push_back("Carlo Gesualdo\nQuinto Libro di Madrigali\n\nThe Hilliard Ensemble\nMonika Mauch soprano\nDavid James countertenor\nDavid Gould countertenor\nRogers Covey-Crump tenor\nSteven Harrold tenor\nGordon Jones baritone");
    
    descriptions.push_back("Stefano Battaglia Trio\nThe River of Anyder\n\nStefano Battaglia piano\nSalvatore Maiore double-bass\nRoberto Dani drums");
    
    descriptions.push_back("Stephan Micus\nBold As Light\n\nStephan Micus raj nplaim, bass zither, chord zither, \nbavarian zither, nohkan, sho, \nvoice, kalimba, shakuhachi, sinding");
    
    descriptions.push_back("The Dowland Project\nRomaria\n\nJohn Potter tenor \nMilos Valent violin, viola\nJohn Surman soprano saxophone, \nbass clarinet, tenor and bass recorders\nStephen Stubbs baroque guitar, vihuela");
    
    descriptions.push_back("Heinz Holliger\nLauds and Lamentations\nMusic of Elliott Carter\nand Isang Yun\n\nHeinz Holliger oboe, English horn\nThomas Zehetmair violin\nRuth Killius viola\nThomas Demenga cello");
    
    descriptions.push_back("Andras Schiff\nIn Concert - Robert Schumann\n\nAndras Schiff piano");
    
    descriptions.push_back("Gianluigi Trovesi\nGianni Coscia\nFrere Jacques - Round about Offenbach\n\nGianluigi Trovesi piccolo and alto clarinets\nGianni Coscia accordion");
    
    descriptions.push_back("Savina Yannatou\nPrimavera en Salonico\nSumiglia\n\nSavina Yannatou voice\nPrimavera en Salonico\nKostas Vomvolos accordion, qanun, kalimba\nYannis Alexandris tamboura, oud, guitar\nMichalis Siganidis double-bass\nKyriakos Gouventas violin, viola\nHarris Lambrakis ney\nKostas Theodorou percussion");
    
    descriptions.push_back("Robin Williamson\nThe Iron Stone\n\nRobin Williamson vocals, Celtic harp, Mohan vina, \nChinese flute, whistles, tabwrdd drum\nMat Maneri viola, Hardanger fiddle\nBarre Phillips double-bass\nAle Moller mandola, accordion, clarino, \nshawm, natural flutes, drone flutes, \nwhistles, jaw harps");
    
    descriptions.push_back("Dino Saluzzi Group\nJuan Condori\n\nDino Saluzzi bandoneon\nFelix 'Cuchara' Saluzzi tenor and soprano saxophones, clarinet\nJose Maria Saluzzi acoustic and electric guitars\nMatias Saluzzi double-bass, bass guitar\nU. T. Gandhi drums, percussion");
    
    descriptions.push_back("Louis Sclavis\nLost on the Way\n\nLouis Sclavis clarinets, soprano saxophone\nMatthias Metzger soprano and alto saxophones\nMaxime Delpierre guitar\nOlivier Lete bass\nFrancois Merville drums");
    
    descriptions.push_back("Miklos Perenyi\nBritten Bach Ligeti\n\nMiklos Perenyi violoncello");
    
    
    
    
    /*******************
     page 3
     *******************/
    
    
    descriptions.push_back("Wadada Leo Smith\nKulture Jazz\n\nWadada Leo Smith trumpet, fluegelhorn, \nkoto, mbira, harmonica, bamboo notch flute, \npercussion, vocal");
    
    descriptions.push_back("Johann Sebastian Bach\nDas Wohltemperierte Clavier\n\nAndras Schiff piano");
    
    descriptions.push_back("Keith Jarrett\nRio\n\nKeith Jarrett piano");
    
    descriptions.push_back("Dino Saluzzi\nAnja Lechner\nOjos Negros\n\nDino Saluzzi bandoneon\nAnja Lechner violoncello");
    
    descriptions.push_back("Jan Garbarek Group\nDresden - In Concert\n\nJan Garbarek soprano and tenor saxophone\nRainer Bruninghaus piano, keyboards\nYuri Daniel bass\nManu Katche drums");
    
    descriptions.push_back("Stephen Stubbs\nTeatro Lirico\n\nMilos Valent violin, viola\nErin Headley viola da gamba, lirone\nMaxine Eilander Spanish and Italian harps\nStephen Stubbs chitarrone, baroque guitar");
    
    descriptions.push_back("Keith Jarrett\nSleeper\n\nKeith Jarrett piano\nJan Garbarek tenor and soprano saxophones, flute, percussion\nPalle Danielsson double-bass\nJon Christensen drums, percussion");
    
    descriptions.push_back("Masabumi Kikuchi Trio\nSunrise\n\nMasabumi Kikuchi piano\nThomas Morgan double bass\nPaul Motian drums");
    
    descriptions.push_back("Manu Katche\nManu Katche\n\nJim Watson piano, Hammond B3 organ\nNils Petter Molvar trumpet, loops\nTore Brunborg tenor and soprano saxophones\nManu Katche drums, piano solo on Dusk On Carnon");
    
    descriptions.push_back("Andras Schiff\nLeos Janacek\nA Recollection\n\nAndras Schiff piano");
    
    descriptions.push_back("Keith Jarrett\nParis/London - Testament\n\nKeith Jarrett piano");
    
    descriptions.push_back("Trio Mediaeval\nFolk Songs\n\nAnna Maria Friman\nLinn Andrea Fuglseth\nTorunn Ostrem Ossum\nBirger Mistereggen percussion and jew's harp");
    
    descriptions.push_back("Keith Jarrett\nLa Scala\n\nKeith Jarrett piano");
    
    descriptions.push_back("Valentin Silvestrov\nMetamusik\nPostludium\n\nAlexei Lubimov piano\nValentin Silvestrov\nDennis Russell Davies conductor");
    
    descriptions.push_back("Terje Rypdal\nCrime Scene\n\nTerje Rypdal electric guitar\nPalle Mikkelborg trumpet\nStale Storlokken Hammond B-3 organ\nPaolo Vinaccia drums, sampling\nBergen Big Band\nOlav Dale conductor");
    
    
    /*******************
     page 4
     *******************/
    
    
    
    descriptions.push_back("Andy Sheppard\nMichel Benita\nSebastian Rochford\nTrio Libero\n\nAndy Sheppard tenor and \nsoprano saxophones\nMichel Benita double-bass\nSebastian Rochford drums");
    
    descriptions.push_back("Miroslav Vitous\nUniversal Syncopations II\n\nBob Mintzer tenor saxophone, bass clarinet\nGary Campbell soprano and tenor saxophones\nBob Malach tenor saxophone\nRandy Brecker trumpet\nDaniele di Bonaventura bandoneon\nVesna Vasko-Caceres voice\nGerald Cleaver drums\nAdam Nussbaum drums\nMiroslav Vitous double-bass");
    
    descriptions.push_back("Rolf Lislevand\nDiminuito\n\nRolf Lislevand lutes, \nvihuela de mano\nLinn Andrea Fuglseth voice\nAnna Maria Friman voice\nGiovanna Pessi triple harp\nMarco Ambrosini nyckelharpa\nThor-Harald Johnsen chitarra battente, vihuela de mano, lutes\nMichael Behringer clavichord, organ\nBjorn Kjellemyr colascione\nDavid Mayoral percussion");
    
    descriptions.push_back("Food\nQuiet Inlet\nThomas Stronen drums, live-electronics\nIain Ballamy tenor- and soprano saxophones\nNils Petter Molver trumpet, electronics\nChristian Fennesz guitar, electronics\nSebastian Rochford drums");
    
    descriptions.push_back("Iva Bittova\n\nIva Bittova voilin, voice, kalimba");
    
    descriptions.push_back("Julia Hulsmann Trio\nImprint\nJulia Hulsmann piano\nMarc Muellbauer double-bass\nHeinrich Kobberling drums");
    
    descriptions.push_back("Bobo Stenson Trio\nIndicum\nBobo Stenson piano\nAnders Jormin double-bass\nJon Falt drums");
    
    descriptions.push_back("Louis Sclavis\nDans La Nuit, Music for the Silent Movie by Charles Vanel\n\nLouis Sclavis clarinets\nJean Louis Matinier accordion\nDominique Pifarely violin\nVincent Courtois cello\nFrancois Merville percussion, marimba");
    
    descriptions.push_back("Batagraf\nJon Balke\nStatements\n\nFrode Nymo alto saxophone\nKenneth Ekornes percussion\nHarald Skullerud percussion\nHelge Andreas Norbakken percussion\nIngar Zach percussion\nJon Balke keyboards, percussion, vocals, sound processing\nArve Henriksen trumpet\nSidsel Endresen text recitals in English\nMiki N'Doye text recital in\nJocely Sete Camara Silva voice\nJennifer Myskja Balke voice");
    
    descriptions.push_back("Jon Balke\nMagnetic Works 1993-2001\n\nJon Balke piano, keyboards, percussion, electronics\nJens Petter Antonsen trumpet\nPer Jorgensen trumpet, vocals\nArve Henriksen trumpet, vocals\nMorten Halle alto saxophone, flute\nTore Brunborg tenor and soprano saxophones\nGertrud Okland violin\nHenrik Hannisdal violin\nOdd Hannisdal violin\nTrond Villa viola\nMarek Konstantynowicz viola\nJonas Franke-Blom violoncello\nSvante Henryson violoncello\nMorten Hannisdal violoncello\nAnders Jormin double-bass\nMarilyn Mazur percussion\nAudun Kleive drums");
    
    descriptions.push_back("Jacob Young\nEvening Falls\n\nJacob Young guitar\nMathias Eick trumpet\nVidar Johansen bass clarinet\nMats Eilertsen double-bass\nJon Christensen drums");
    
    descriptions.push_back("John Abercrombie\nClass Trip\nJohn Abercrombie guitar\nMark Feldman violin\nMarc Johnson double-bass\nJoey Baron drums");
    
    descriptions.push_back("Paul Giger\nRobert Dick\nSatoshi Takeishi\nVindonissa\n\nPaul Giger violin, violino d'amore, viola d'amore, footbells\nRobert Dick c-flute, glissando flute, bass flute in c, bass flute in f, contrabass flute\nSatoshi Takeishi percussion");
    
    descriptions.push_back("Johann Sebastian Bach\nJohn Holloway\nThe Sonatas and Partitas\nfor violin solo\n\nJohn Holloway violin");
    
    descriptions.push_back("Denes Varjon\nPrecipitando\n\nDenes Varjon piano");
    
    
    
    
    swipe = false;
    
    enlarge = 100;
    nextpageleft = false;
    nextpageright = false;
    
    numberflipsleft = 0;
    numberflipsright = 0;
    
    totalflips = 0;
    page = 0;
    
    
    timeexit = 0;
    startpage = 0;
    stayonpage = false;
    
    resetrotate = false;
    for(int i = 0; i< 80; i++){
        rotateface = false;
        rotate.push_back(rotateface);
    }
    
    
    for(int i = 0; i< 80; i++){
        freeze.push_back(false);
    }
    
    ofSetVerticalSync(true);
	ofSetFrameRate(60);					//do your best!
	ofBackground(10, 10, 10);
	ofEnableDepthTest();
    
    // turn on smooth lighting //
    bSmoothLighting = true;
    ofSetSmoothLighting(true);
    
    
    
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
    
    
	//right now there are 4 categories ( blurry/smooth, grainy, red/black, black/white) each being a 5x3 rectangular face of album covers.  The first two are textures and arguably same for black/white but the red/black
	//is tacky almost too obvious, will probably change it later.  I do like that it adds some contrast but it's inconsistent with the theme, was thinking of something arranged by brushstrokes, like thick watercolor
	//vs oil pastels vs charcoal-like etc..  There are simply too many gorgeous covers to choose from and I did the best I could.  I own maybe 20% of these.
    
    //blurry and smooth
	//these are loaded one row at a time, should be all automatic
    ofLogoImage1.loadImage("leipzig.jpg");
    ofLogoImage2.loadImage("melos.jpg");
    ofLogoImage3.loadImage("gustavsen.jpg");
    ofLogoImage4.loadImage("canopee.jpg");
    ofLogoImage5.loadImage("bartsch.jpg");
    
    ofLogoImage6.loadImage("january.jpg");
    ofLogoImage7.loadImage("colour.jpg");
    ofLogoImage8.loadImage("formanek.jpg");
    ofLogoImage9.loadImage("farside.jpg");
    ofLogoImage10.loadImage("seim.jpg");
    
    ofLogoImage11.loadImage("play.jpg");
    ofLogoImage12.loadImage("velocities.jpg");
    ofLogoImage13.loadImage("darkeyes.jpg");
    ofLogoImage14.loadImage("letmego.jpg");
    ofLogoImage15.loadImage("purcor.jpg");
    
    //red/black
    ofLogoImage16.loadImage("schubert.jpg");
    ofLogoImage17.loadImage("monk.jpg");
    ofLogoImage18.loadImage("eleni.jpg");
    ofLogoImage19.loadImage("gesualdo.jpg");
    ofLogoImage20.loadImage("anyder.jpg");
    
    ofLogoImage21.loadImage("micus.jpg");
    ofLogoImage22.loadImage("romaria.jpg");
    ofLogoImage23.loadImage("holliger.jpg");
    ofLogoImage24.loadImage("andras.jpg");
    ofLogoImage25.loadImage("trovesi.jpg");
    
	ofLogoImage26.loadImage("yannatou.jpg");
    ofLogoImage27.loadImage("williamson.jpg");
    ofLogoImage28.loadImage("condori.jpg");
    ofLogoImage29.loadImage("sclavis.jpg");
    ofLogoImage30.loadImage("perenyi.jpg");
    
    //black/white
	ofLogoImage31.loadImage("smith.jpg");
    ofLogoImage32.loadImage("clavier.jpg");
    ofLogoImage33.loadImage("rio.jpg");
    ofLogoImage34.loadImage("negros.jpg");
    ofLogoImage35.loadImage("dresden.jpg");
    
	ofLogoImage36.loadImage("stubss.jpg");
    ofLogoImage37.loadImage("sleeper.jpg");
    ofLogoImage38.loadImage("sunrise.jpg");
    ofLogoImage39.loadImage("katche.jpg");
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
    
    //uhh definitely a better way to do this
    ecmcovers.push_back(ofLogoImage1);
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
    //ofBackground(185,184,174);           true website color I pulled
    /*pointLight.setPosition(cos(ofGetElapsedTimef()*.6f) * radius * 2 + center.x,
     sin(ofGetElapsedTimef()*.8f) * radius * 2 + center.y,
     -cos(ofGetElapsedTimef()*.8f) * radius * 2 + center.z);
     
     spotLight.setOrientation( ofVec3f( 0, cos(ofGetElapsedTimef()) * RAD_TO_DEG, 0) );
     spotLight.setPosition( mouseX, mouseY, 200);
     */
    
    
    float x, y;
    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
    x = mouse.x;
    y = mouse.y;
    //cout<<"current x is "<<x<<" and current y is "<<y<<endl;      //for debugging
    
    
    //this is if the user leaves the cursor on the current album and goes to a next page, the rotation would linger unless we trigger a cleanup, this is called whenever we hit 'i' or 'u', the effects are only felt on the edges since there are infact 2 cubes, well actually that's not the real reason, real reason is that's the only part of the previous page visible to us..
    if(resetrotate){
        for(int i = 0; i < rotate.size(); i++)
            rotate[i] = false;
        //I'm not sure why it doesn't work with the following in place I would think you only need to do this once before it's reactivated on the next page swipe, probably an issue with the application framerate and how update is called after a keyboard event..
        //resetrotate = false;
        
    }
    
	//page determines colors, dimensions, orientation basically very important to keep track, totalflips is kept by mousePressed()
    page = totalflips % 4;
    if (page == -3){
		page = 1;}
	else if (page == -2){
		page = 2;}
    else if (page == -1){
		page = 3;}
    
    
	//page gives us the front wall facing the user this is the only one we should be drawing, we can definitely turn off the back wall but we might want the sides for turning animations, turns out we can deanimate
	//the side walls as only, only draw them while we are turning pages
	draw_wall0 = draw_wall1 = draw_wall2 = draw_wall3 = false;
	
    
	if(page == 0){
		draw_wall0 = true;}
	else if(page == 1){
		draw_wall1 = true;}
	else if(page == 2){
		draw_wall2 = true;}
	else if(page == 3){
		draw_wall3 = true;}
    
    
    
	//instead of doing 15 iterations everytime like a for loop and testing each condition we can just find the i and j corresponding to its position
	//actually its fast enough already and I don't think this would make much difference
	/*if(page == 0){
     rotate[(nextiterj*5)+nextiteri] = true;
     }
     else if(page == 1){
     rotate[(15+nextiterj*5) + nextiteri] = true;
     }
     else if(page == 2){
     rotate[(30+nextiterj*5) + nextiteri] = true;
     }
     else if(page == 3){
     rotate[(45+nextiterj*5) + nextiteri] = true;
     }
     
     int i, j;
     if(scrollcubes){
     if((x-359>0) && (y-245 > 0)){
     i = ((int)x-359)%157;
     j = ((int)y-245)%157;
     if((i<5) && (j<3)){
     nextiteri = i;		//this is so that we can reset it to false on the next iteration, we can't do that here since we need to animate it in draw() before we turn it off, gotta be a better way to do this
     nextiterj = j;
     rownumber = j+1;
     if(page == 0){
     rotate[(j*5)+i] = true;
     }
     else if(page == 1){
     rotate[(15+j*5) + i] = true;
     }
     else if(page == 2){
     rotate[(30+j*5) + i] = true;
     }
     else if(page == 3){
     rotate[(45+j*5) + i] = true;
     }
     }
     }
     }
     */
    
    //scrollcubes controlled by mousePressed(), deactivated once we've selected an album cover with track listings for selection
	if(scrollcubes){
		for( int j = 0; j < 3; j++){
			for(int i = 0; i < 5; i++){
				//depending on what 'page' we are on, we access different cubes, we can get the page based on the total number flips
				//
				// ________3________
				// |		       |
				// |			   |
				//2|			   |4
				// |		       |
				// |_______________|
				//         1
                //so take page = totalflips%4		with 15 cubes per page
                //0 correspond to current page		which have indices 0-14
                //1 correspond to page 2			which have indices 15-29
                //2 correspond to page 3			which have indices 30-44
                //3 correspond to page 4			which have indices 45-59
                
				//these are the coordinates on screen after being projected forward from depth of z=200
				//found by trial and error...
				if((x >= 359+ (i*157)) && (x< 359+(i+1)*157)&& (y >= 245+(j*157)) && (y < 245+ (j+1)*157)){
					rownumber = j+1;
					if(page == 0){
						rotate[(j*5)+i] = true;
					}
					else if(page == 1){
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
	
    
    
	//animation for playback control
	if((x>=685) && (x<=710) && (y>=748) && (y<=788)){
        toggleprevious = true;
    }
    else if((x>=786) && (x<=812) && (y>=748) && (y<=788)){
        togglenext = true;
    }
    else if((x>=735) && (x<=757) && (y>=748) && (y<=788)){
        togglestop = true;
    }
    
    
    
    
    
    
    
    //highlighting track from scrolling through a list
    ofColor highlight = highlightcolors[page];
    if(scrolltracks)
    {
        
        //as of this point of having been activated, rownumber already exists from last iteration, as does page
        //preserve the original color since it needs to be restored when the cursor comes off..
		ofColor original = albumcolors[page][0];
        
        //cout<<"original color is"<<original<<endl;
        
        /*depending on row number, track listings have different y coordinates found by trial and error
         top row 400 to 630
         middle row 185 to 415
         bottom row 350 to 580
         */
        if(rownumber == 1){
			for(int j = 0; j< tracks.size(); j++){
				//how do I toggle text color without creating a unique color for each track..yea that's not possible..so I did just that
				if((y >= 400+(j*23)) && (y < 400 + (j+1)*23))
					albumcolors[page][9-j] = highlight;				//track turns white when highlighted, otherwise takes the default color set in setup()
				else
					albumcolors[page][9-j]  = pagecolors[page];
			}
		}
		else if(rownumber == 2){
			for(int j = 0; j< tracks.size(); j++){
				if((y >= 185+(j*23)) && (y < 185 + (j+1)*23))
					albumcolors[page][9-j]  = highlight;
				else
					albumcolors[page][9-j]  = pagecolors[page];
			}
		}
		else if(rownumber == 3){
			for(int j = 0; j< tracks.size(); j++){
				if((y >= 350+(j*23)) && (y < 350+ (j+1)*23))
					albumcolors[page][9-j]  = highlight;
				else
					albumcolors[page][9-j]  = pagecolors[page];
			}
		}
    }
    
    
    
    
    
    //turning page with swiping, need at least 4 points to indicate a swipe and not some accidental click.  also just realized this should be tripped only after mouse is released. this is a little buggy so I'm gonna leave it out for now
    if((swipe) && (mousedrag.size() >= 3)){
		float x1 = mousedrag[0];
		float x2 = mousedrag[3];		//don't use the 2nd point mousedrag[1] since [0] represents the very first click so the next point might be too close to judge
        
		//if x2 > x1 then we are swiping left to right so a counterclockwise turn
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
        
		mousedrag.clear();			//mouseReleased() should clear..
		swipe = false;
    }
}

//deperecated since "pushing forward" out of the screen is relative to orientation, not necessarily just changing the z-component
void testApp::emerge(){
    ofTranslate(0,0,enlarge);
}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofEnableAlphaBlending();
    if(togglecaption){
        
        ofSetColor(51, 102, 133);
        caption.drawString(descriptions[captionindex],20, 170);
        
        togglecaption = false;
    }
    
    ofTranslate(230,50,0);
    
    
	//title and logo.
	/*to give credit where it's due, the style for the logo and features were taken from the Miami Vice movie promo (I don't even think it works very well in that poster to be honest and the movie was just..).
     But for some reason, I like the look.  On its own, it's clean and intrepid.  Used a slightly less saturated blue, pulled the original font for the date (or what I could make out - dinen medium, someone correct
     me if I'm wrong), used the same sizing and in the spirit of the letterings and their meaning, I have replaced 'Colin Farrell/Jamie Foxx' with 'elation/introspection'.  kitshc? passe? conceited? ill placed?
     what does that even mean? I'm not really sure.  Elation goes first because the E lines up nicely with the rectangle, nothing more.  'A Michael Mann Film' has been replaced with 'a Manfred Eicher tribute'
     and the release date with his D.O.B. which I thought was a nice touch, initially, a bit saccharine perhaps.
     
     I tried a bunch of variations and they look like shit basically.  It'd be interesting to show this to someone and ask for their opinion without acknowledgement of my thievery.  No doubt my
     love for everything Mann touches may have put some preponderance on its effectiveness.
     */
	float logox = 400;
	float logoy = 20;
    ofSetColor(176,196,222,100);
	logo2.drawStringAsShapes("ELATION                INTROSPECTION",logox, logoy);
    ofSetColor(51, 102, 133, alpha);
    ofRect(logox, logoy+10, 240, 45);
	ofTranslate(0,0,1);
    ofSetColor(255,255,255, alpha);
    logo.drawStringAsShapes(" ENJOY ECM ", logox+7,logoy+45);
    ofTranslate(0,0,-1);
	ofSetColor(176,196,222, alpha);
	author.drawStringAsShapes("A MANFRED EICHER TRIBUTE", logox+68,logoy+70);
    date.drawStringAsShapes("07.09.43",logox+101, logoy+95);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    ofSetColor(150,0,0, alpha);
    signature.drawStringAsShapes("By Tian Xu", 1060,700);
    signature.drawStringAsShapes("(XuXo)", 1076,712);
    
    
    
	//draw the playback buttons, only 3 basic features keeping it simple
	ofColor red = ofColor(200,0,0);
	ofColor dim = ofColor(60,0,0);
    
    
	ofSetColor(red);
	float leftx = 467, lefty = 700;
	ofFill();
	ofTriangle(leftx, lefty, leftx+5, lefty-5, leftx+5, lefty+5);
	ofTriangle(leftx+6, lefty, leftx+11, lefty-5, leftx+11, lefty+5);
	ofRect(leftx-4, lefty-5,2,10);
    
	if(toggleprevious){
		ofTranslate(0,0,1);
		ofSetColor(dim);
		float sleftx = leftx+2, slefty = lefty+2;
		ofFill();
		ofTriangle(sleftx, slefty, sleftx+5, slefty-5, sleftx+5, slefty+5);
		ofTriangle(sleftx+6, slefty, sleftx+11, slefty-5, sleftx+11, lefty+5);
		ofRect(sleftx-4, slefty-5,2,10);
		ofTranslate(0,0,-1);
	}
	toggleprevious = false;
    
    
	ofSetColor(red);
	ofRect(leftx + 45, lefty-5, 10,10);
    
	if(togglestop){
		ofTranslate(0,0,1);
		ofSetColor(dim);
		ofRect(leftx + 44, lefty-2, 12,10);
		ofTranslate(0,0,-1);
	}
	togglestop = false;
    
    
	ofSetColor(red);
	float rightx = leftx+100, righty = 700;
	ofTriangle(rightx, righty, rightx-5, righty-5, rightx-5, righty+5);
	ofTriangle(rightx-6, righty, rightx-11, righty-5, rightx-11, righty+5);
	ofRect(rightx+2, righty-5,2,10);
    
	if(togglenext){
		ofTranslate(0,0,1);
		ofSetColor(dim);
		float srightx = rightx-2, srighty = righty +2;
		ofFill();
		ofTriangle(srightx, srighty, srightx-5, srighty-5, srightx-5, srighty+5);
		ofTriangle(srightx-6, srighty, srightx-11, srighty-5, srightx-11, srighty+5);
		ofRect(srightx+2, righty-5,2,10);
		ofTranslate(0,0,-1);
	}
    togglenext = false;
    
	
    
	
    
    
    //old title and logo...actually I like this better but it doesn't look too good with the red/black page.  Against my better judgement and true instincts, I'm deprecating this one for now and trying
	//to make the miami vice one work.
    
    /*ofSetColor(255,0,0);
     //logo.setLetterSpacing(1.2);
     logo.drawStringAsShapes(" Enjoy ECM ", 393,50);
     //ofSetColor(255,255,255);
     ofSetColor(176,196,222);*/
    
    // enable lighting //
    //ofEnableLighting();
    // enable the material, so that it applies to all 3D objects before material.end() call //
	material.begin();
    
    
    //some lighting effects I took from an example project multiLight, actually makes this look too busy, left out for now
    /*
	 ofPushMatrix();
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
	
    
    ofTranslate(500,00,00);
    
	//rotating continuously on display
    //I seriously can't remember what this is used for...
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
    
    
    if(nextpageleft){
		
		//so we should have some trigger in here to draw the walls only if we are mid rotation, once we are done and are only exposed to the front wall, we don't really the rotatoion even
        drawwalls= true;
        stayonpage = false;
        startpage += .1;											//speed of rotation
        if(startpage <=1)
            //ofRotate((90*(numberflipsleft-1)) + startpage * 90, 0, 1, 0);
            ofRotate(90*(totalflips) + startpage*90, 0,1,0);		//90*totalflip will give us current position from which we rotate another 90 degrees per page turn
        else {
            startpage = 0;
            nextpageleft = false;									//deactivate as to only turn when called upon
            stayonpage = true;
        }
    }
    
    
    if(nextpageright){
        
		drawwalls= true;
        
        stayonpage = false;
        startpage += .1;
        if(startpage <=1)
            //ofRotate((-90*(numberflipsright-1)) + startpage * -90, 0, 1, 0);
            ofRotate(90*(totalflips) + startpage*(-90), 0,1,0);
        else {
            startpage = 0;
            nextpageright = false;
            stayonpage = true;
        }
    }
    
    
	//triggered by both left and right page turns, should stay true as long as we are not in the motion of turning, this if might be redundant
    if(stayonpage){
        totalflips = numberflipsleft - numberflipsright;
        ofRotate(90*totalflips, 0, 1, 0);
    }
    
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	//DRAWING CUBE -- this is where the cube and all the internals are constructed, need to be refactored at some point
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	float deg;
    int height;
    float translatex, translatez;
    
	//depending on which row, the spinning text in staircase fashion needs to be displayed above or below the cube
    if(rownumber == 1)
        height = 125;
    else if ((rownumber == 2) || (rownumber == 3))	//probably need to control the helical spacing as well
        height = -100;
    
    
    /*##################################
     1st WALL
     ##################################*/
    
	//building the first face
	//to make this a bit faster, we don't have to draw all the walls since only the front is visible to us.  We definitely don't need to draw the back wall but might want the adjacent side
	//ones for animation when we are turning page, we should only be drawing the adjacent ones if we're in mid rotation which is what drawwalls indicates
    
    //ofRotate(20, 1,0,0);      //for debugging purposes
    
    
	ofPushMatrix();
	//this is for displaying an album cover in its original size front and center, we will push the entire cube back and to the right but still visible and create a projection effect.
	if(shrink){
		ofTranslate(1800,-500,-2000);
	}
	if(draw_wall0 || drawwalls){
        
		//row1
		for( int i = 0; i<5; i++){
			if( (page != 1) || (i != 0) ){
				if( (page != 3) || (i != 4) ){
                    
					ofPushMatrix();
					ofTranslate(-200 + i*100, 300, 200);
					if(rotate[i] || freeze[i]){
                        
						//aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
						togglecaption = true;
						captionindex = i;
                        
						trans = 100;
						ofTranslate(0,0,enlarge);										//poject it forward
                        
						ofPushMatrix();
						ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);         //this is 180/pi
                        
						for(int i = 0; i<tracks.size(); i++){
							ofPushMatrix();
                            
							//spread the tracks out evenly across the circumference of the circle
							deg = 360/tracks.size();
							deg *= i;
							deg = deg * pi / 180;
                            
							//20 controls the radius, trial and error to make sure the text doesn't sink into the cube behind it causing it to disappear
							translatex = 20*sqrt(2)*cos(deg);
							translatez = -20*sqrt(2)*sin(deg);
                            
							//the y component gives us the helical shape so the user can see all the track listings and has the ability to select, 35 gives the right spacing
							ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
							ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                            
							//songcolor controlled by page number
							ofSetColor(albumcolors[page][i]);
							trackfont.drawStringAsShapes(tracks[i], 0,0);
                            
							//for some reason cube takes on the color of the text if not reset even though the binding of the texture happens outside of the iteration???
							ofSetColor(255,255,255,alpha);
							ofPopMatrix();
                            
							trans = 100;
						}
						ofPopMatrix();
                        
						//original plan was to fade out the rest of the cube for legibility when the selected album is brought to foreground but seems unnecessary now, left it here as an option
						trans = 255;
						ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
					}
					ofSetColor(255,255,255,alpha);    //turn on transparency
                    
					// grab the texture reference and bind it, putting this anywhere but here will cause trouble//
					if(bUseTexture) ecmcovers[i].getTextureReference().bind();
					ofDrawBox(0, 0, 0, 100);
					ofPopMatrix();
					if(bUseTexture) ecmcovers[i].getTextureReference().unbind();
				}
			}
		}
        
		//row2
		for( int i = 0; i<5; i++){
			if( (page != 1) || (i != 0) ){
				if( (page != 3) || (i != 4) ){
                    
					ofPushMatrix();
					ofTranslate(-200 + i*100, 400, 200);
					if(rotate[5+i] || freeze[5+i]){
                        
						//aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
						togglecaption = true;
						captionindex = 5+i;
                        
						trans = 100;
						ofTranslate(0,0,enlarge);
                        
						ofPushMatrix();
						ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                        
						for(int i = 0; i<tracks.size(); i++){
							ofPushMatrix();
                            
							deg = 360/tracks.size();
							deg *= i;
							deg = deg * pi / 180;
                            
							translatex = 20*sqrt(2)*cos(deg);
							translatez = -20*sqrt(2)*sin(deg);
                            
							ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
							ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                            
							ofSetColor(albumcolors[page][i]);
							trackfont.drawStringAsShapes(tracks[i], 0,0);
                            
							ofSetColor(255,255,255, alpha);
							ofPopMatrix();
                            
							trans = 100;
						}
						ofPopMatrix();
                        
						trans = 255;
						ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
					}
					ofSetColor(255,255,255,alpha);
                    
					if(bUseTexture) ecmcovers[5+i].getTextureReference().bind();
					ofDrawBox(0, 0, 0, 100);
					if(bUseTexture) ecmcovers[5+i].getTextureReference().unbind();
					ofPopMatrix();
				}
			}
		}
        
        //row3
		ofColor blue = ofColor(51, 102, 183);
		for( int i = 0; i < 5; i++) {
			if( (page != 1) || (i != 0) ){
				if( (page != 3) || (i != 4) ){
                    
					ofPushMatrix();
					ofTranslate(-200 + i*100, 500, 200);
					if(rotate[10+i] || freeze[10+i]){
                        
						//aligned on the x axis and no rotation required, so "pushing out" is increasing z natually
						togglecaption = true;
						captionindex = 10+i;
                        
						trans = 100;
						ofTranslate(0,0,enlarge);
                        
						ofPushMatrix();
						ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                        
						for(int i = 0; i<tracks.size(); i++){
							ofPushMatrix();
                            
							deg = 360/tracks.size();
							deg *= i;
							deg = deg * pi / 180;
                            
							translatex = 20*sqrt(2)*cos(deg);
							translatez = -20*sqrt(2)*sin(deg);
                            
							ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
							ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                            
							ofSetColor(albumcolors[page][i]);
							trackfont.drawStringAsShapes(tracks[i], 0,0);
                            
							ofSetColor(255, 255, 255, alpha);
							ofPopMatrix();
                            
							trans = 100;
						}
						ofPopMatrix();
                        
						trans = 255;
						ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
					}
					ofSetColor(255, 255, 255, alpha);
                    
					if(bUseTexture) ecmcovers[10+i].getTextureReference().bind();
					ofDrawBox(0, 0, 0, 100);
					if(bUseTexture) ecmcovers[10+i].getTextureReference().unbind();
					ofPopMatrix();
				}
			}
		}
	}
    
    /*##################################
     2nd WALL
     ##################################*/
    
	//building the second face (left wall) from back to front, top to bottom like the front face had it been rotated
	if(draw_wall1 || drawwalls){
        
		//row1
		for( int i = 0; i<5; i++){
			if( (page != 2) || (i != 0) ){
                
				ofPushMatrix();
				ofTranslate(-200, 300, -200+ i*100);
				if(rotate[15+i] || freeze[15+i]){
                    
					//prior to rotation these are aligned on the z axis and facing "west" so to speak causing it to point out of screen with a counterclockwise turn
					togglecaption = true;
					captionindex = 15+i;
                    
					trans = 100;
					ofTranslate(-enlarge,0,0);
                    
					ofPushMatrix();
					ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                    
					for(int i = 0; i<tracks.size(); i++){
						ofPushMatrix();
                        
						deg = 360/tracks.size();
						deg *= i;
						deg = deg * pi / 180;
                        
						translatex = 20*sqrt(2)*cos(deg);
						translatez = -20*sqrt(2)*sin(deg);
                        
						ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
						ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG-90, 0, 1, 0);
                        
						ofSetColor(albumcolors[page][i]);
						trackfont.drawStringAsShapes(tracks[i], 0, 0);
                        
						ofSetColor(255, 255, 255, alpha);
						ofPopMatrix();
                        
						trans = 100;
					}
					ofPopMatrix();
                    
					trans = 255;
					ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
				}
				ofSetColor(255, 255, 255, alpha);
                
				if(bUseTexture) ecmcovers[15+i].getTextureReference().bind();
				ofDrawBox(0, 0, 0, 100);
				if(bUseTexture) ecmcovers[15+i].getTextureReference().unbind();
				ofPopMatrix();
			}
		}
        
        //row2
		for( int i = 0; i<5; i++){
			if( (page != 2) || (i != 0) ){
                
				ofPushMatrix();
				ofTranslate(-200, 400, -200+ i*100);
				if(rotate[20+i] || freeze[20+i]){
                    
					//prior to rotation these are aligned on the z axis and facing "west" so to speak causing it to point out of screen with a counterclockwise turn
					togglecaption = true;
					captionindex = 20+i;
                    
					trans = 100;
					ofTranslate(-enlarge,0,0);
                    
					ofPushMatrix();
					ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                    
					for(int i = 0; i<tracks.size(); i++){
						ofPushMatrix();
                        
						deg = 360/tracks.size();
						deg *= i;
						deg = deg * pi / 180;
                        
						translatex = 20*sqrt(2)*cos(deg);
						translatez = -20*sqrt(2)*sin(deg);
                        
						ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
						ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG-90, 0, 1, 0);
                        
						ofSetColor(albumcolors[page][i]);
						trackfont.drawStringAsShapes(tracks[i], 0,0);
                        
						ofSetColor(255,255,255, alpha);
						ofPopMatrix();
                        
						trans = 100;
					}
					ofPopMatrix();
                    
					trans = 255;
					ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
				}
				ofSetColor(255, 255,255,alpha);
                
				if(bUseTexture) ecmcovers[20+i].getTextureReference().bind();
				ofDrawBox(0, 0, 0, 100);
				if(bUseTexture) ecmcovers[20+i].getTextureReference().unbind();
				ofPopMatrix();
			}
		}
        
		//row3
		for( int i = 0; i<5; i++){
			if( (page != 2) || (i != 0) ){
                
				ofPushMatrix();
				ofTranslate(-200, 500, -200+ i*100);
				if(rotate[25+i] || freeze[25+i]){
                    
					//prior to rotation these are aligned on the z axis and facing "west" so to speak causing it to point out of screen with a counterclockwise turn
					togglecaption = true;
					captionindex = 25+i;
                    
					trans = 100;
					ofTranslate(-enlarge,0,0);
                    
					ofPushMatrix();
					ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                    
					for(int i = 0; i<tracks.size(); i++){
						ofPushMatrix();
                        
						deg = 360/tracks.size();
						deg *= i;
						deg = deg * pi / 180;
                        
						translatex = 20*sqrt(2)*cos(deg);
						translatez = -20*sqrt(2)*sin(deg);
                        
						ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
						ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG-90, 0, 1, 0);
                        
						ofSetColor(albumcolors[page][i]);
						trackfont.drawStringAsShapes(tracks[i], 0,0);
                        
						ofSetColor(255, 255, 255, alpha);
						ofPopMatrix();
                        
						trans = 100;
					}
					ofPopMatrix();
                    
					trans = 255;
					ofRotate(ofGetElapsedTimef()*.8 * RAD_TO_DEG, 0, 1, 0);
				}
				ofSetColor(255, 255, 255, alpha);
                
				if(bUseTexture) ecmcovers[25+i].getTextureReference().bind();
				ofDrawBox(0, 0, 0, 100);
				if(bUseTexture) ecmcovers[25+i].getTextureReference().unbind();
				ofPopMatrix();
			}
		}
	}
	
    /*##################################
     3rd WALL
     ##################################*/
    
	//building the back wall such that had you rotate it, it'd be left to right top to bottom same construction
	//so really its right to left top to bottom here
    
	if(draw_wall2 | drawwalls){
        
		//row1
		for( int i = 0; i<5; i++){
			if( (page != 3) || (i != 0) ){
                
				ofPushMatrix();
				ofTranslate(200 - i*100, 300, -200);
                
				if(rotate[30+i] || freeze[30+i]){
                    
					togglecaption = true;
					captionindex = 30+i;
                    
					trans = 100;
					ofTranslate(0,0,-enlarge);
                    
					ofPushMatrix();
					ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                    
					for(int i = 0; i<tracks.size(); i++){
						ofPushMatrix();
                        
						deg = 360/tracks.size();
						deg *= i;
						deg = deg * pi / 180;
                        
						translatex = 20*sqrt(2)*cos(deg);
						translatez = -20*sqrt(2)*sin(deg);
                        
						ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
						ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG-180, 0, 1, 0);
                        
						ofSetColor(albumcolors[page][i]);
						trackfont.drawStringAsShapes(tracks[i], 0,0);
                        
						ofSetColor(255, 255, 255, alpha);
						ofPopMatrix();
                        
						trans = 100;
					}
					ofPopMatrix();
                    
					trans = 255;
					ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
				}
				ofSetColor(255,255,255,alpha);
                
				if(bUseTexture) ecmcovers[30+i].getTextureReference().bind();
				ofDrawBox(0, 0, 0, 100);
				if(bUseTexture) ecmcovers[30+i].getTextureReference().unbind();
				ofPopMatrix();
			}
		}
        
		//row2
		for( int i = 0; i<5; i++){
			if( (page != 3) || (i != 0) ){
                
				ofPushMatrix();
				ofTranslate(200 - i*100, 400, -200);
                
				if(rotate[35+i] || freeze[35+i]){
                    
					togglecaption = true;
					captionindex = 35+i;
                    
					trans = 100;
					ofTranslate(0,0,-enlarge);
                    
					ofPushMatrix();
					ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                    
					for(int i = 0; i<tracks.size(); i++){
						ofPushMatrix();
                        
						deg = 360/tracks.size();
						deg *= i;
						deg = deg * pi / 180;
                        
						translatex = 20*sqrt(2)*cos(deg);
						translatez = -20*sqrt(2)*sin(deg);
                        
						ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
						ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG-180, 0, 1, 0);
                        
						ofSetColor(albumcolors[page][i]);
						trackfont.drawStringAsShapes(tracks[i], 0,0);
                        
						ofSetColor(255 ,255, 255, alpha);
						ofPopMatrix();
                        
						trans = 100;
					}
					ofPopMatrix();
                    
					trans = 255;
					ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
				}
				ofSetColor(255, 255, 255, alpha);
                
				if(bUseTexture) ecmcovers[35+i].getTextureReference().bind();
				ofDrawBox(0, 0, 0, 100);
				if(bUseTexture) ecmcovers[35+i].getTextureReference().unbind();
				ofPopMatrix();
			}
		}
        
		//row3
		for( int i = 0; i<5; i++){
			if( (page != 3) || (i != 0) ){
                
				ofPushMatrix();
				ofTranslate(200 - i*100, 500, -200);
                
				if(rotate[40+i] || freeze[40+i]){
                    
					togglecaption = true;
					captionindex = 40+i;
                    
					trans = 100;
					ofTranslate(0,0,-enlarge);
                    
					ofPushMatrix();
					ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                    
					for(int i = 0; i<tracks.size(); i++){
						ofPushMatrix();
                        
						deg = 360/tracks.size();
						deg *= i;
						deg = deg * pi / 180;
                        
						translatex = 20*sqrt(2)*cos(deg);
						translatez = -20*sqrt(2)*sin(deg);
                        
						ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
						ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG-180, 0, 1, 0);
                        
						ofSetColor(albumcolors[page][i]);
						trackfont.drawStringAsShapes(tracks[i], 0,0);
                        
						ofSetColor(255 ,255,255, alpha);
						ofPopMatrix();
                        
						trans = 100;
					}
					ofPopMatrix();
                    
					trans = 255;
					ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
				}
				ofSetColor(255, 255, 255, alpha);
                
				if(bUseTexture) ecmcovers[40+i].getTextureReference().bind();
				ofDrawBox(0, 0, 0, 100);
				if(bUseTexture) ecmcovers[40+i].getTextureReference().unbind();
				ofPopMatrix();
			}
		}
	}
    
    
    /*##################################
     4th WALL
     ##################################*/
    
	//building the final right wall from front to back top to bottom
	if(draw_wall3 || drawwalls){
        
		//row1
		for( int i = 0; i<5; i++){
			//if( (page != 0) || (i != 0) ){
            
			ofPushMatrix();
			ofTranslate(200, 300, 200 - i*100);
            
			if(rotate[45+i] || freeze[45+i]){
                
				togglecaption = true;
				captionindex = 45+i;
                
				trans = 100;
				ofTranslate(enlarge,0,0);
                
				ofPushMatrix();
				ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                
				for(int i = 0; i<tracks.size(); i++){
					ofPushMatrix();
                    
					deg = 360/tracks.size();
					deg *= i;
					deg = deg * pi / 180;
                    
					translatex = 20*sqrt(2)*cos(deg);
					translatez = -20*sqrt(2)*sin(deg);
                    
					ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
					ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG-270, 0, 1, 0);
                    
					ofSetColor(albumcolors[page][i]);
					trackfont.drawStringAsShapes(tracks[i], 0,0);
                    
					ofSetColor(255, 255, 255, alpha);
					ofPopMatrix();
                    
					trans = 100;
				}
				ofPopMatrix();
                
				trans = 255;
				ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
			}
			ofSetColor(255, 255, 255, trans);
            
			if(bUseTexture) ecmcovers[45+i].getTextureReference().bind();
			ofDrawBox(0, 0, 0, 100);
			if(bUseTexture) ecmcovers[45+i].getTextureReference().unbind();
			ofPopMatrix();
		}
        
        //row2
		for( int i = 0; i<5; i++){
			//if( (page != 0) || (i != 0) ){
            
			ofPushMatrix();
			ofTranslate(200, 400, 200 - i*100);
            
			if(rotate[50+i] || freeze[50+i]){
                
				togglecaption = true;
				captionindex = 50+i;
                
				trans = 100;
				ofTranslate(enlarge,0,0);
                
				ofPushMatrix();
				ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                
				for(int i = 0; i<tracks.size(); i++){
					ofPushMatrix();
                    
					deg = 360/tracks.size();
					deg *= i;
					deg = deg * pi / 180;
                    
					translatex = 20*sqrt(2)*cos(deg);
					translatez = -20*sqrt(2)*sin(deg);
                    
					ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
					ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG-270, 0, 1, 0);
                    
					ofSetColor(albumcolors[page][i]);
					trackfont.drawStringAsShapes(tracks[i], 0,0);
                    
					ofSetColor(255,255,255, alpha);
					ofPopMatrix();
                    
					trans = 100;
				}
				ofPopMatrix();
                
				trans = 255;
				ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
			}
			ofSetColor(255, 255, 255, alpha);
            
			if(bUseTexture) ecmcovers[50+i].getTextureReference().bind();
			ofDrawBox(0, 0, 0, 100);
			if(bUseTexture) ecmcovers[50+i].getTextureReference().unbind();
			ofPopMatrix();
		}
        
        //row3
		for( int i = 0; i<5; i++){
			//if( (page != 0) || (i != 0) ){
            
			ofPushMatrix();
			ofTranslate(200, 500, 200 - i*100);
            
			if(rotate[55+i] || freeze[55+i]){
                
				togglecaption = true;
				captionindex = 55+i;
                
				trans = 100;
				ofTranslate(enlarge,0,0);
                
				ofPushMatrix();
				ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
                
				for(int i = 0; i<tracks.size(); i++){
					ofPushMatrix();
                    
					deg = 360/tracks.size();
					deg *= i;
					deg = deg * pi / 180;
                    
					translatex = 20*sqrt(2)*cos(deg);
					translatez = -20*sqrt(2)*sin(deg);
                    
					ofTranslate(translatex,height + 35*sqrt(2)*cos(deg/2),translatez);
					ofRotate(-ofGetElapsedTimef()*.6 * RAD_TO_DEG-270, 0, 1, 0);
                    
					ofSetColor(albumcolors[page][i]);
					trackfont.drawStringAsShapes(tracks[i], 0,0);
                    
					ofSetColor(255, 255, 255, alpha);
					ofPopMatrix();
                    
					trans = 100;
				}
				ofPopMatrix();
                
				trans = 255;
				ofRotate(ofGetElapsedTimef()*.6 * RAD_TO_DEG, 0, 1, 0);
			}
			ofSetColor(255, 255, 255, alpha);
            
			if(bUseTexture) ecmcovers[55+i].getTextureReference().bind();
			ofDrawBox(0, 0, 0, 100);
			if(bUseTexture) ecmcovers[55+i].getTextureReference().unbind();
			ofPopMatrix();
		}
	}
    drawwalls = false;		//to be reset to true only by turning a page
    ofPopMatrix();			//matches the one before the drawing of the first wall
	/*
     ofPushMatrix();
     ofTranslate(center.x, center.y, -900);
     ofRotate(ofGetElapsedTimef() * .2 * RAD_TO_DEG, 0, 1, 0);
     ofDrawBox( 0, 0, 0, 850);
     ofPopMatrix();*/
    
    if(bUseTexture) ofLogoImage1.getTextureReference().unbind();
	
	if (!bPointLight) pointLight.disable();
	if (!bSpotLight) spotLight.disable();
	if (!bDirLight) directionalLight.disable();
	
    material.end();
    
    
    /*
     // turn off lighting //
     ofDisableLighting();
     
     ofSetColor( pointLight.getDiffuseColor() );
     if(bPointLight) pointLight.draw();
     
     ofSetColor(255, 255, 255);
     ofSetColor( spotLight.getDiffuseColor() );
     if(bSpotLight) spotLight.draw();
     
     ofPopMatrix();
     ofSetColor(255, 255, 255);*/
    
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
    cout<<"dragging at location x = "<<x<<" and y = "<<y<<endl;
    //we only care about the x component to determine a leftward or rightward swipe
    mousedrag.push_back(x);
    
}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //cout<<"x is "<<x<<"and y is"<<y<<endl;
    //mousedrag.push_back(x);		don't want to push points clicked only points in mouseDragged to simulate swiping, otherwise stack will get populated by bunch of junk clicks
	int k = 60;
	int left = 359;
	int right = 359 + 5*157;
	int bottom  = 245;
	int top = 245 + 3*157;
    
	//selectsong controls playability, initialized as false; this if{} chain is actually set off by the if{} below this block, this should stay active as in user can hop around between as many songs as he wants until he clicks
	//outside of the "panel"
	if(selectsong){
		if(rownumber == 1){
			if((y>400) && (y<630)){
				for(int j = 0; j< tracks.size(); j++){
					//how do I toggle text color without creating a unique color for each track..yea that's not really possible..so I did just that
					if((y >= 400+(j*23)) && (y < 400 + (j+1)*23)){
						listing[currentsong].stop();
                        listing[j].play();
                        currentsong =  j;
                    }
				}
			}
			else
				//so once you leave the horizantal strip of tracks, you gotta start over
				selectsong = false;
		}
		else if(rownumber == 2){
			if((y>185) && (y<415)){
				for(int j = 0; j< tracks.size(); j++){
					//how do I toggle text color without creating a unique color for each track..yea that's not possible..so I did just that
					if((y >= 185+(j*23)) && (y < 185 + (j+1)*23)){
                        listing[currentsong].stop();
						listing[j].play();
                        currentsong =  j;
                    }
				}
			}
			else
				selectsong = false;
		}
		else if(rownumber == 3){
			if((y>350) && (y<580)){
				for(int j = 0; j< tracks.size(); j++){
					//how do I toggle text color without creating a unique color for each track..yea that's not possible..so I did just that
					if((y >= 350+(j*23)) && (y < 350+ (j+1)*23)){
                        listing[currentsong].stop();
						listing[j].play();
                        currentsong =  j;
                    }
				}
			}
			else
				selectsong = false;
		}
	}
	else
	{
		//keep track of which cube is activated through index cube
        
		//activating cube, also need to make sure we disable all other cubes as we scroll over the track listings..so we can disable the
		//part in update() where we search for which cube to bring forth and animate.  Won't be a problem since the animation in draw()
		//will still get tripped by the freeze[]
		if((x>left) && (x<right) && (y > bottom) && (y<top)){
			//cout<<"we are in"<<endl;
			scrollcubes = false;
			scrolltracks = true;
			selectsong = true;		//maybe this should be activated only by scrolltracks in update(), and notice this is the key above whose negation controls whether this block gets executed, kind of confusing
			for( int j = 0; j < 3; j++){
				for(int i = 0; i < 5; i++){
					if((x >= 359+ (i*157)) && (x< 359+(i+1)*157)&& (y >= 245+(j*157)) && (y < 245+ (j+1)*157)){
						rownumber = j+1;
						if(page == 0){
							freeze[(j*5)+i] = true;
							cube = (j*5)+i;
						}
						else if(page == 1){
							freeze[(15+j*5) + i] = true;
							cube = (15+j*5) + i;
						}
						else if(page == 2){
							freeze[(30+j*5) + i] = true;
							cube = (30+j*5) + i;
						}
						else if(page == 3){
							freeze[(45+j*5) + i] = true;
							cube = (45+j*5) + i;
						}
					}
				}
			}
			//cout<<"this is cube number"<<cube<<endl;
		}
		else{
			//so we only deactivate the last clickable one. any random click outside of the click will trigger this
			//but it won't really register anything since all false by default
			freeze[cube] = false;
			scrollcubes = true;
			scrolltracks = false;
			//should now kick off scrolling track listings..
		}
	}
    
	//this area for song selection is always off limits no matter what mode you're in
	if((x>=694) && (x<=710) && (y>=748) && (y<=788)){
        listing[currentsong].stop();
        if (currentsong+1<=tracks.size()-1){
            listing[currentsong+1].play();
            currentsong++;
        }
        else
            listing[currentsong].play();
    }
    else if((x>=786) && (x<=802) && (y>=748) && (y<=788)){
        listing[currentsong].stop();
        if(currentsong - 1 >=0){
            listing[currentsong-1].play();
            currentsong--;
        }
        else
            listing[currentsong].play();
    }
    else if((x>=742) && (x<=752) && (y>=748) && (y<=788)){
        listing[currentsong].stop();
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	//I'm not sure if it makes sense to wipe this as soon as your finger leaves the mousepad..I'm assuming this is only called after a mousedrag, not after any mouseclick
    //cout<<"mouse released at location x = "<<x<<" and y = "<<y<<endl;
    //mousedrag.clear();
    swipe = true;
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