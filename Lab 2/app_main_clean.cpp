#include <iostream>
#include <math.h>
#include "Rect.h"
#include "winner.h"
#include <vector>
// #include "click.h"

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


vector<Rect> rects;
Rect click;
// Click click;
Winner stat;

bool machine = true;
bool flag = true;
bool occupied = true;
bool result = false;
bool player = true;


bool checkStat(vector<Rect> rects){
	if(stat.Xwinner(rects)){
		cout << "Player 1 (X) wins" << endl;
		result = true;
		cout << "Rematch?? Press (a) to play against computer" << endl;
		cout << "Player vs. Player (Press p)" << endl;
		cout << "Press ESC to exit" << endl;
	} 

	if(stat.Owinner(rects)){
		cout << "O wins" << endl;
		// cout << "Rematch??" << endl;
		// cout << "Press (a) to play against computer" << endl;
		// cout << "Player vs. Player (Press p)" << endl;
		if(machine == true){
			//AI goes here
			cout << "Machine won!" << endl;
			cout << "Rematch?? Press (a) to play against computer" << endl;
			cout << "Player vs. Player (Press p)" << endl;
			cout << "Press ESC to exit" << endl;
			

			
		} else {
			// Text(GLUT_BITMAP_TIMES_ROMAN_24, "Player 2 won", 95, 185);
			cout << "Player 2 (O)Won!" << endl;
			cout << "Rematch?? Press (a) to play against computer" << endl;
			cout << "Player vs. Player (Press p)" << endl;
			cout << "Press ESC to exit" << endl;
		}
		
		result = true;
	}

	if(result != true){
		flag = true;
		for(int i = 0; i < rects.size(); i++){
			if(rects[i].occupied != true){
				flag = false;
				break;
			}
		}

		if(flag){
			result = true;
			cout << "Its a tie!" << endl;
			cout << "Press ESC to exit" << endl;
			// cout << "Rematch?? Press (a)" << endl;
			// cout << "Player vs. Player (Press p)" << endl;
			// cout << "Player vs. Machine" << endl;
		}
	}
}


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


	

	 for(int i = 0; i < rects.size(); i++){
		
		rects[i].draw();

	}

	// one.draw();
	// two.draw();


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
								//b = 0 when left clicked down	
								// b = 2 when right clicked
								//s = 0 when clicked
								//s = 1 when let go
	windowToScene(mx, my);

	// click.player1((x), (y), (b), (s), (player), (machine), (result));


if(b == 0 && b != 2){			//player 1
	
	if(s == 0){
		for(int i = 0; i < rects.size(); i++){
			if((result != true)){
				if(rects[i].contains(mx,my)){
					if(rects[i].occupied != true){
						if(player && rects[i].occupied != true){						//checks player 1
							if(machine == false){
							cout << "Player 2's turn!" << endl;
							cout << "###########################" << endl;
							}
							rects[i].shape = EX;
							rects[i].occupied = true;
							player = !player;
						}

					

						
						rects[i].occupied = true;
						player = !player;
					}

					checkStat(rects);	


					if(!player && result != true){
						for(int i = 0; i < rects.size(); i++){
							if(rects[i].occupied != true){
								rects[i].shape = Circ;
								rects[i].occupied = true;
								player = player;

								//cout << "Player 2's turn!" << endl;
								break;
								}
							}		
							rects[i].shape = Circ;
						} else {					
							rects[i].shape = EX;
					}


						//this is how the AI makes decisons
					if(machine && result != true){
						for(int i = 0; i < rects.size(); i++){
							int choose = (rand() % (rects.size() + 1)) ;
							if(rects[choose].occupied != true){
								rects[choose].shape = Circ;
								rects[choose].occupied = true;
								player = !player;
								break;
							}
						}
						checkStat(rects);
					}
					break;
				}
			}
		}
	}
}


if(b == 2 && machine == false){			//for player 2
	// cout << "Player 2's turn!" << endl;
	if(s == 0){
		
		for(int i = 0; i < rects.size(); i++){
			if((result != true)){
				if(rects[i].contains(mx,my)){
					if(rects[i].occupied != true){
						if(player != false && rects[i].occupied != true){				//checks player 1
							if(machine == false){
							cout << "Player 1's turn!" << endl;
							cout << "###########################" << endl;
							}
							rects[i].shape = Circ;
							rects[i].occupied = true;
							player = !player;
							// cout << "Player 1's turn!" << endl;
						}
						// cout << "Player 1's turn!" << endl;
						// cout << "###########################" << endl;
					

						
						rects[i].occupied = true;
						player = !player;
					}

					checkStat(rects);	

				}
			}
		}
	}
}


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
	case 'a':										//play again??

	cout << endl;cout << endl;
	cout << "#########################" << endl;
	cout << "Machine vs. Player selected" << endl;
	cout << "#########################" << endl;

		if(result){
			
			for(int i = 0; i < rects.size(); i++){
				
				rects[i].shape = none;
				rects[i].occupied = false;
				result = false;
				player = true;
			}
			machine = true;
			
		}
		break;
	
	case 'p':			//PvP

	cout << endl;
	cout << endl;
	cout << "#########################" << endl;
	cout << "PvP selected" << endl;
	cout << "#########################" << endl;
	cout << "Player 1 left-click" << endl;
	cout << "Player 2 right-click" << endl;
		if(result){

			
			
				for(int i = 0; i < rects.size(); i++){
					rects[i].shape = none;
					rects[i].occupied = false;
					result = false;
					player = true;
				}
				machine = false;
			
			}

			//appMouseFunc(set, 0, x, y);
			break;
	case 'z':
	cout << endl;
	cout << endl;
		cout << "#########################" << endl;
		cout << "Machine vs. Player selected" << endl;
		cout << "#########################" << endl;
		if(result){
			
			
			for(int i = 0; i < rects.size(); i++){
				
				rects[i].shape = none;
				rects[i].occupied = false;
				result = false;
				player = true;
			}
			machine = true;
			
		}
		break;

	case 'x':
	cout << endl;
	cout << endl;
		cout << "#########################" << endl;
		cout << "PvP selected" << endl;
		cout << "#########################" << endl;
		cout << "Player 1 left-click" << endl;
		cout << "Player 2 right-click" << endl;
		if(result){
			
				for(int i = 0; i < rects.size(); i++){
					rects[i].shape = none;
					rects[i].occupied = false;
					result = false;
					player = true;
				}
				machine = false;
			
			}

			//appMouseFunc(set, 0, x, y);
			break;

    case 27:
		exit(0);
		break;
		// More cases here if you need...
	}
	// After all the state changes, redraw the scene
	glutPostRedisplay();
}

void idle(){

}


int main(int argc, char** argv) {
	
	cout << "Press z for Machine vs. Player" << endl;
	cout << "Press x for Player vs. Player" << endl;

	// cout << "Click screen to begin machine vs. player first" << endl;


	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// stat.Xwinner(vector<Rect> (rects));

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


    rects.push_back(Rect(-0.9, 0.9, 0.55, 0.55));
  	rects.push_back(Rect(-0.3, 0.9, 0.55, 0.55));
  	rects.push_back(Rect(0.3, 0.9, 0.55, 0.55));
  
 	rects.push_back(Rect(-0.9, 0.3, 0.55, 0.55));
  	rects.push_back(Rect(-0.3, 0.3, 0.55, 0.55));
  	rects.push_back(Rect(0.3, 0.3, 0.55, 0.55));
  
  	rects.push_back(Rect(-0.9, -0.3, 0.55, 0.55));
  	rects.push_back(Rect(-0.3, -0.3, 0.55, 0.55));
  	rects.push_back(Rect(0.3, -0.3, 0.55, 0.55));



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

	// // This gets triggered when we release a keyboard key
	// glutKeyboardUpFunc(appKeyboardUpFunc);
    
	// Resize your window to the desired size (bug in macOS Catalina)
    glutReshapeWindow(width, height);

	// Set the idle function. It gets called repeatedly all the time
	glutIdleFunc(idle);

	// Start the main loop
	glutMainLoop();
}
