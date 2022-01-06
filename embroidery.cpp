#include <cs70/turtle.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include "embroidery.hpp"
using namespace std;


void rect(Turtle& t, float width, float height) {
    t.pendown();
    t.move(width, 0);
    t.move(0, height);
    t.move(-1*width, 0);
    t.move(0, -1*height);
}

void meetTurtle() {
    const float PATCH_WIDTH = 50;
    const float PATCH_HEIGHT = 40;
    const int EDGE_STITCH_SIZE = 2;
    const int TEXT_STITCH_SIZE = 1;
    const float FONT_SIZE = 1.0;
    const float SATIN_DELTA = 0.3;
    Turtle t;
    t.satinon(SATIN_DELTA);
    t.setStepSize(EDGE_STITCH_SIZE);
    rect(t, PATCH_WIDTH, PATCH_HEIGHT);
    t.setStepSize(TEXT_STITCH_SIZE);
    t.penup();
    t.gotopoint(PATCH_WIDTH/3, PATCH_HEIGHT/4);
    t.pendown();
    t.displayMessage("LO", FONT_SIZE);
    t.penup();
    t.gotopoint(PATCH_WIDTH/3, PATCH_HEIGHT/2);
    t.pendown();
    t.displayMessage("Bluh", FONT_SIZE);
    t.penup();
    t.gotopoint(PATCH_WIDTH/3, 3*PATCH_HEIGHT/4);
    t.pendown();
    t.displayMessage("IH", FONT_SIZE);
    t.end();
    t.save("meet_turtle.dst");
}

void plotExampleData() {
    const float PATCH_WIDTH = 50;
    const float PATCH_HEIGHT = 40;
    const int EDGE_STITCH_SIZE = 2;
    const float FONT_SIZE = 1.0;
    const float SATIN_DELTA = 0.3;
    const int PLOT_STITCH_SIZE = 1;
    const int NUM_DATA_POINTS = 59;
    const string INPUT_NAME = "/home/student/data/hw2/us_population_growth.txt";
    const string OUTPUT_NAME = "example_data.dst";
    ifstream inputFile;
    inputFile.open(INPUT_NAME);
    float data[NUM_DATA_POINTS];
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        inputFile >> data[i];
    }
    inputFile.close();
    float max = 0;
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    float availableHeight = PATCH_HEIGHT - EDGE_STITCH_SIZE;
    float normalized[NUM_DATA_POINTS];
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        normalized[i] = data[i] * availableHeight/max;
    }
    Turtle t;
    t.satinon(SATIN_DELTA);
    t.setStepSize(EDGE_STITCH_SIZE);
    rect(t, PATCH_WIDTH, PATCH_HEIGHT);
    t.setStepSize(PLOT_STITCH_SIZE);
    t.pendown();
    float x = (PATCH_WIDTH - EDGE_STITCH_SIZE)/NUM_DATA_POINTS;
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        t.gotopoint(x*(i+1), normalized[i]);
    }
    t.penup();
    t.gotopoint(PATCH_WIDTH/3, PATCH_HEIGHT-4*EDGE_STITCH_SIZE);
    t.pendown();
    t.displayMessage("1992", FONT_SIZE);
    t.end();
    t.save(OUTPUT_NAME);
}

void plotStudentData() {
    const float PATCH_WIDTH = 50;
    const float PATCH_HEIGHT = 40;
    const int EDGE_STITCH_SIZE = 2;
    const float FONT_SIZE = 1.0;
    const float SATIN_DELTA = 0.3;
    const int PLOT_STITCH_SIZE = 1;
    const int NUM_DATA_POINTS = 50;
    const string INPUT_NAME = "student_data.txt";
    const string OUTPUT_NAME = "student_data.dst";
    ifstream inputFile;
    inputFile.open(INPUT_NAME);
    float data[NUM_DATA_POINTS];
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        inputFile >> data[i];
    }
    inputFile.close();
    float max = 0;
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    float availableHeight = PATCH_HEIGHT - EDGE_STITCH_SIZE;
    float normalized[NUM_DATA_POINTS];
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        normalized[i] = data[i] * availableHeight/max;
    }
    Turtle t;
    t.satinon(SATIN_DELTA);
    t.setStepSize(EDGE_STITCH_SIZE);
    rect(t, PATCH_WIDTH, PATCH_HEIGHT);
    t.setStepSize(PLOT_STITCH_SIZE);
    t.pendown();
    float x = (PATCH_WIDTH - EDGE_STITCH_SIZE)/NUM_DATA_POINTS;
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        t.gotopoint(x*(i+1), normalized[i]);
    }
    t.penup();
    t.gotopoint(PATCH_WIDTH/3, PATCH_HEIGHT/2);
    t.pendown();
    t.displayMessage("TEMP", FONT_SIZE);
    t.end();
    t.save(OUTPUT_NAME);
}
