#include <iostream>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


using namespace std;


// Store the width and height of the window
int width = 640, height = 640;

//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Your code here...

	glColor3f(0.12, 0.65, 0.21);
	glBegin(GL_POLYGON);

	// top of J
	glVertex2f(-0.7,0.7); //starting point top left of J *
	glVertex2f(-0.3, 0.7);
	glVertex2f(-0.3,0.6);
	glVertex2f(-0.7, 0.6);
	glVertex2f(-0.7, 0.7);

	glEnd();

	// straight of J
	glBegin(GL_POLYGON);

	glVertex2f(-0.55, 0.7);
	glVertex2f(-0.45, 0.7);
	glVertex2f(-0.45, 0.0);
	glVertex2f(-0.55, 0.0);
	glVertex2f(-0.55, 0.7);
	
	glEnd();

	//the bottom of the "Curve" of J
	glBegin(GL_POLYGON);

	glVertex2f(-0.45,0.0);
	glVertex2f(-0.8, 0.0);
	glVertex2f(-0.8, 0.1);
	glVertex2f(-0.45, 0.1);
	glVertex2f(-0.45, 0.0);

	glEnd();

	//the little bump in the "curve"
	glBegin(GL_POLYGON);

	glVertex2f(-0.8, 0.09);
	glVertex2f(-0.8, 0.2);
	glVertex2f(-0.72, 0.2);
	glVertex2f(-0.72, 0.09);
	glVertex2f(-0.8, 0.09);

	glEnd();


	glColor3f(0.576470588, 0.439215686,0.858823529);
	//This it the straight for the P
	glBegin(GL_POLYGON);
	glVertex2f(-0.3, 0.3);
	glVertex2f(-0.19, 0.3);
	glVertex2f(-0.19, -0.3);
	glVertex2f(-0.3, -0.3);
	glVertex2f(-0.3, 0.3);

	glEnd();


	glColor3f(0,0,0);
	//white square in P
	glBegin(GL_POLYGON);
	glVertex2f(-0.19, 0.24);
	glVertex2f(-0.05, 0.24);
	glVertex2f(-0.05, 0.09);
	glVertex2f(-0.19, 0.09);
	glVertex2f(-0.19, 0.24);

	glEnd();


glColor3f(0.576470588, 0.439215686,0.858823529);
	//"curve"of the P
	glBegin(GL_POLYGON);
	glVertex2f(-0.3, 0.3);
	glVertex2f(0.0, 0.3);
	glVertex2f(0.0, 0.0);
	glVertex2f(-0.3,0.0);
	glVertex2f(-0.3, 0.3);

	glEnd();

	//Left of V
	glColor3f(1,0.154645,0.546165186);
	glBegin(GL_POLYGON);

	glVertex2f(0.5, -0.15);
	glVertex2f(0.3, 0.6);
	glVertex2f(0.2, 0.55);
	glVertex2f(0.4, -0.15);
	glVertex2f(0.5, -0.1);


	glEnd();


	//right of V
	glBegin(GL_POLYGON);

	glVertex2f(0.4, -0.15);
	glVertex2f(0.6, 0.6);
	glVertex2f(0.7, 0.55);
	glVertex2f(0.5, -0.15);
	glVertex2f(0.4, -0.15);

	glEnd();

	// glColor3f(0,0,0);
	// //This dark space for the V
	// glBegin(GL_POLYGON);
	// glVertex2f(0.2, 0.5);
	// glVertex2f(0.6, 0.5);
	// glVertex2f(0.45, 0.0);
	// glVertex2f(0.2, 0.5);

	// glEnd();


	// glColor3f(1,0.154645,0.546165186);
	// //This is the V for my last name
	// glBegin(GL_POLYGON);
	// glVertex2f(0.2, 0.5);
	// glVertex2f(0.6, 0.5);
	// glVertex2f(0.4, -0.3);
	// glVertex2f(0.6, 0.5);
	// glVertex2f(0.7, 0.5);
	// // glVertex2f()

	// glEnd();



	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments: 	
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float& x, float& y) {
	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h) {
	// Window size has changed
	width = w;
	height = h;

	double scale, center;
	double winXmin, winXmax, winYmin, winYmax;

	// Define x-axis and y-axis range
	const double appXmin = -1.0;
	const double appXmax = 1.0;
	const double appYmin = -1.0;
	const double appYmax = 1.0;

	// Define that OpenGL should use the whole window for rendering
	glViewport(0, 0, w, h);

	// Set up the projection matrix using a orthographic projection that will
	// maintain the aspect ratio of the scene no matter the aspect ratio of
	// the window, and also set the min/max coordinates to be the disered ones
	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;

	if ((appXmax - appXmin) / w < (appYmax - appYmin) / h) {
		scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
		center = (appXmax + appXmin) / 2;
		winXmin = center - (center - appXmin)*scale;
		winXmax = center + (appXmax - center)*scale;
		winYmin = appYmin;
		winYmax = appYmax;
	}
	else {
		scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
		center = (appYmax + appYmin) / 2;
		winYmin = center - (center - appYmin)*scale;
		winYmax = center + (appYmax - center)*scale;
		winXmin = appXmin;
		winXmax = appXmax;
	}

	// Now we use glOrtho to set up our viewing frustum
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);
}


//-------------------------------------------------------
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y) {
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	// Your code here...

	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments: 	
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y) {
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	// Your code here...

	// Again, we redraw the scene
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments: 	
//	key  - the key that was pressed
//	x, y - coordinates of the mouse when key is pressed
//-------------------------------------------------------
void appKeyboardFunc(unsigned char key, int x, int y) {
	// Define what should happen for a given key press 
	switch (key) {
		// Escape was pressed. Quit the program
	case 27:
		exit(0);
		break;
		// More cases here if you need...
	}
	// After all the state changes, redraw the scene
	glutPostRedisplay();
}


int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	// Start with a slightly smaller window (bug in macOS Catalina)
	glutInitWindowSize(width-1, height-1);

	// Create the window
	glutCreateWindow("CSE165 OpenGL Demo");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);


	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);

	// Set callback for resizing th window
	glutReshapeFunc(appReshapeFunc);

	// Set callback to handle mouse clicks
	glutMouseFunc(appMouseFunc);

	// Set callback to handle mouse dragging
	glutMotionFunc(appMotionFunc);

	// Set callback to handle keyboad events
	glutKeyboardFunc(appKeyboardFunc);
    
	// Resize your window to the desired size (bug in macOS Catalina)
    glutReshapeWindow(width, height);

	// Start the main loop
	glutMainLoop();
}
