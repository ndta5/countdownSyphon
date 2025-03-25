#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Countdown Timer");
    ofBackground(128, 0);
    font.load("Lato-Regular.ttf", 36);
    countdown.load("Lato-Regular.ttf", 20);

    ofxXmlSettings settings;
    if(!ofFile().doesFileExist("settings.xml")){
        // 設定の保存
        settings.setValue("targetTime:year", 2025);
        settings.setValue("targetTime:mon", 12);
        settings.setValue("targetTime:mday", 31);
        settings.setValue("targetTime:hour", 23);
        settings.setValue("targetTime:min", 59);
        settings.setValue("targetTime:sec", 59);
        settings.save("settings.xml");
    }
    
    // 設定の読み込み
    settings.load("settings.xml");
    int year = settings.getValue("targetTime:year", 2025);
    int mon = settings.getValue("targetTime:mon", 12);
    int mday = settings.getValue("targetTime:mday", 31);
    int hour = settings.getValue("targetTime:hour", 23);
    int min = settings.getValue("targetTime:min", 59);
    int sec = settings.getValue("targetTime:sec", 59);

    // カウントダウン終了時刻を設定 (例: 2025年12月31日23時59分59秒)
    std::tm targetTimeStruct = {0};
    targetTimeStruct.tm_year = year - 1900; // 年は1900年からの経過年数
    targetTimeStruct.tm_mon = mon - 1; // 月は0から始まる (12月は11)
    targetTimeStruct.tm_mday = mday;
    targetTimeStruct.tm_hour = hour;
    targetTimeStruct.tm_min = min;
    targetTimeStruct.tm_sec = sec;
    targetTime = std::mktime(&targetTimeStruct);
    
    // GUI
    gui.setup();
    gui.add(fontSizeSlider.setup("Font size", 36, 10, 255));
    gui.add(color.set("color", ofColor(255, 255, 0)));
}

//--------------------------------------------------------------
void ofApp::update(){
    currentTime = std::time(nullptr);
    remainingTime = targetTime - currentTime;
    
    if(fontSize != fontSizeSlider){
        fontSize = fontSizeSlider;
        font.load("Lato-Regular.ttf", fontSize);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    std::stringstream ss;

    int day = remainingTime / 86400;
    int hours = (remainingTime % 86400) / 3600;
    int minutes = (remainingTime % 3600) / 60;
    int seconds = remainingTime % 60;
    
    if (day > 0) {
        ss << day << "day "
        << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << seconds;
    }else if (remainingTime > 0){
        ss << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << seconds;
    } else {
        ss << "Countdown finished!";
    }
    
    countdown.drawString("Countdown", px, py - image.getHeight() - font.stringHeight(ss.str()) - 5 );
    
    ofSetColor(color);
    font.drawString(ss.str(), px, py);

    //ここでSyphon送信
    output.publishScreen();
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

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
    px = x;
    py = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    px = x;
    py = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
