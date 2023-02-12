#define _USE_MATH_DEFINES
#define _USE_MATH_DEFINES

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <GL/glut.h>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;

void setColor(int colorIndex) {
    switch (colorIndex) {
        case 1:
            glColor3f(0.863f, 0.208f, 0.208f); // red
            break;
        case 2:
            glColor3f(0.212f, 0.682f, 0.486f); // green
            break;
        case 3:
            glColor3f(0.094f, 0.455f, 0.596f); // blue
            break;
        case 4:
            glColor3f(0.976f, 0.851f, 0.137f); // yellow
            break;
        case 5:
            glColor3f(1.0f, 0.545f, 0.075f); // orange
            break;
        case 6:
            glColor3f(0.961f, 0.431f, 0.702f); // pink
            break;
        case 7:
            glColor3f(0.521f, 0.804f, 0.992f); // cyan
            break;
        case 8:
            glColor3f(0.651f, 0.294f, 0.165f); // brown
            break;
        default:
            glColor3f(1.0f, 1.0f, 1.0f); // white
    }
}

void setShape(vector<float> vertices, int shapeIndex, int colorIndex, int size) {
    //glClear(GL_COLOR_BUFFER_BIT); // clear the color buffer with current clearing color
    switch (shapeIndex) {
        case 1:
            glBegin(GL_LINES);
            break;
        case 2:
            glBegin(GL_TRIANGLES);
            break;
        case 3:
            glBegin(GL_QUADS);
            break;
        case 4:
            glBegin(GL_POLYGON);
            break;
        case 5:
            glBegin(GL_LINE_STRIP);
            break;
        case 6:
            glBegin(GL_TRIANGLE_FAN);
            break;
    }
    setColor(colorIndex);
    if (shapeIndex == 6) { // circle
        glVertex2f(vertices[0], vertices[1]); // center
        for (float i = 0.0f; i <= 360; i++)
            glVertex2f(vertices[2] * cos(M_PI * i / 180.0) + vertices[0], vertices[2] * sin(M_PI * i / 180.0) + vertices[1]);
    }
    else {
        for (int i = 0; i < size - 1; i += 2)
            glVertex2f(vertices[i], vertices[i + 1]);
    }
    glEnd();
    glFlush(); // render
}

void pass() { // input function
    system("cls");
    cout << ".......... OpenGL CLI Sample ..........\n" << endl
         << "(1) Line" << endl
         << "(2) Triangle" << endl
         << "(3) Rectangle" << endl
         << "(4) Polygon" << endl
         << "(5) Polyline" << endl
         << "(6) Circle" << endl
         << "--------------------" << endl
         << "(-1) Exit\n" << endl
         << "Shape index: ";
    int shapeIndex;
    cin >> shapeIndex;
    if (shapeIndex == -1) exit(0);

    cout << "\n(1) Red" << endl
         << "(2) Green" << endl
         << "(3) Blue" << endl
         << "(4) Yellow" << endl
         << "(5) Orange" << endl
         << "(6) Pink" << endl
         << "(7) Cyan" << endl
         << "(8) Brown" << endl
         << "--------------------" << endl
         << "(-1) Exit\n" << endl
         << "Color index: ";
    int colorIndex;
    cin >> colorIndex;
    if (colorIndex == -1) exit(0);

    cout << "Now, Enter the points in counterclockwise order:" << endl;
    vector<float> inputVertices;
    float in;
    if (shapeIndex == 1) {
        inputVertices.resize(4);
        for (int i = 0; i <= 2; i += 2) {
            cout << "Enter point - X: ";
            cin >> in;
            inputVertices[i] = in;
            cout << "Enter point - Y: ";
            cin >> in;
            inputVertices[i + 1] = in;
        }
        setShape(inputVertices, shapeIndex, colorIndex, 4);
    } 
    else if (shapeIndex == 2) {
        inputVertices.resize(6);
        for (int i = 0; i <= 4; i += 2) {
            cout << "Enter point - X: ";
            cin >> in;
            inputVertices[i] = in;
            cout << "Enter point - Y: ";
            cin >> in;
            inputVertices[i + 1] = in;
        }
        setShape(inputVertices, shapeIndex, colorIndex, 6);
    } 
    else if (shapeIndex == 3) {
        inputVertices.resize(8);
        cout << "Enter the location of bottom left corner point: " << endl;
        cout << "Enter point - X: ";
        cin >> in;
        inputVertices[0] = in;
        cout << "Enter point - Y: ";
        cin >> in;
        inputVertices[1] = in;
        cout << "Enter the location of upper right corner point: " << endl;
        cout << "Enter point - X: ";
        cin >> in;
        inputVertices[4] = in;
        cout << "Enter point - Y: ";
        cin >> in;
        inputVertices[5] = in;
        inputVertices[2] = inputVertices[4];
        inputVertices[3] = inputVertices[1];
        inputVertices[6] = inputVertices[0];
        inputVertices[7] = inputVertices[5];
        setShape(inputVertices, shapeIndex, colorIndex, 8);
    } 
    else if (shapeIndex == 4 || shapeIndex == 5) {
        cout << "Enter the number of points: ";
        int numOfPoints;
        cin >> numOfPoints;
        inputVertices.resize(numOfPoints * 2);
        for (int i = 0; i <= numOfPoints * 2 - 2; i += 2) {
            cout << "Enter point - X: ";
            cin >> in;
            inputVertices[i] = in;
            cout << "Enter point - Y: ";
            cin >> in;
            inputVertices[i + 1] = in;
        }
        setShape(inputVertices, shapeIndex, colorIndex, numOfPoints * 2);
    } 
    else if (shapeIndex == 6) {
        inputVertices.resize(3);
        cout << "Enter point - X: ";
        cin >> in;
        inputVertices[0] = in;
        cout << "Enter point - Y: ";
        cin >> in;
        inputVertices[1] = in;
        cout << "Enter radius - r: ";
        cin >> in;
        inputVertices[2] = in;
        setShape(inputVertices, shapeIndex, colorIndex, 1);
    }

    cout << "Do you want to continue [Y/n]?" << endl;
    char temp;
    cin >> temp;
    if (temp == 'Y')
        pass();
    else
        exit(0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // initialize GLUT
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Sample");
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
    glutDisplayFunc(pass);
    glLineWidth(3.0); // line width
    gluOrtho2D(-100, 100, -100, 100); // vertices x, y values | range (-100 ~ 100)
    glutMainLoop();
    return 0;
}