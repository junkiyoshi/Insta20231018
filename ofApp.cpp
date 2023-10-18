#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);

	ofEnableDepthTest();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	auto param = ofGetFrameNum() % 50;
	if (param > 12 && param < 38) {

		if (param < 25) {

			this->noise_step += ofMap(param, 12, 25, 0, 0.125);
		}
		else if (param > 25) {

			this->noise_step += ofMap(param, 25, 38, 0.125, 0);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int width = 350;
	int height = 350;
	int len = 15;
	for (int z = -300; z <= 600; z += 10) {

		ofPushMatrix();
		ofTranslate(0, 0, z);
		ofRotate(ofMap(ofNoise((z + 300) * 0.0015 + this->noise_step), 0, 1, -360, 360));

		ofFill();
		ofSetColor(0);

		ofBeginShape();

		ofVertex(glm::vec2(width * -0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * 0.5));
		ofVertex(glm::vec2(width * -0.5, height * 0.5));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -0.5 + len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 0.5 - len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 0.5 - len, height * 0.5 - len));
		ofVertex(glm::vec2(width * -0.5 + len, height * 0.5 - len));

		ofEndShape(true);

		ofNoFill();
		ofSetColor(255, ofMap(z, -300, 600, 0, 255));

		ofBeginShape();

		ofVertex(glm::vec2(width * -0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * 0.5));
		ofVertex(glm::vec2(width * -0.5, height * 0.5));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -0.5 + len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 0.5 - len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 0.5 - len, height * 0.5 - len));
		ofVertex(glm::vec2(width * -0.5 + len, height * 0.5 - len));

		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}