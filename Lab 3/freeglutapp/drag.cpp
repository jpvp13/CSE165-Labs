
#include <math.h>
#include <deque>
#include "drag.h"
#include "Rect.h"



    
drag::drag(){
    x = 0;
    y = 0;
    w = 0;
    h = 0;  

    sqr.push_back(new Rect(0.0,0.0, 0.5,0.5, 0,0,1));
    sqr.push_back(new Rect(-0.8,0.8, 0.5, 0.5, 1,0,0));
    sqr.push_back(new Rect(0.4,-0.5, 0.5, 0.5, 0,1,0));
}

void drag::delta(float mx, float my){
        float Xdelta = abs(x - mx);
        float Ydelta = abs(y - my);
}


void drag::motion(float x, float y){
    float Xdelta;
    float Ydelta;

    for(std::deque<Rect*>::iterator i = sqr.begin(); i != sqr.end(); i++){
        (*i)->deselect();
    }
   
	for(std::deque<Rect*>::iterator i = sqr.begin(); i != sqr.end(); i++){
      
		if((*i)->contains(x,y)){

				//####### safe ##############
				(*i)->x = x - ((*i)->w/2);
				(*i)->y = y + ((*i)->h/2);
				// ###########################

				sqr.push_back(*i);
				break;
        }
    }
}

void drag::square(){
    for(int i = 0; i < sqr.size(); i++){
		sqr[i]->draw();
	}

}


void drag::click(float x, float y){

  for(std::deque<Rect*>::iterator i = sqr.begin(); i != sqr.end(); i++){
          
 
            (*i)->deselect();
  	}
    
    
    for(std::deque<Rect*>::iterator i = sqr.begin(); i != sqr.end(); i++){
        if((*i)->contains(x,y)){
           
 
            (*i)->select();
            // sqr.erase(i);
            sqr.push_front(*i);
            break;
        }
		
    }
}