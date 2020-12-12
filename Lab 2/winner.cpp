#include <iostream>
// #include <math.h>
#include "winner.h"
#include <vector>
#include "Rect.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

std::vector<Rect> grid;
enum temp {count, EXXx, OOO };

Winner::Winner(){
    // X = true;
    // O = true;
    
    temp = enu;

}

bool Winner::Xwinner(std::vector<Rect> grid){
  temp = EXX;
  if (grid[0].shape == temp && grid[1].shape == temp && grid[2].shape == temp) {
    return true;
  } else if (grid[3].shape == temp && grid[4].shape == temp && grid[5].shape == temp) {
    return true;
  } else if (grid[6].shape == temp && grid[7].shape == temp && grid[8].shape == temp) {
    return true;
  } else if (grid[0].shape == temp && grid[3].shape == temp && grid[6].shape == temp) {
    return true;
  } else if (grid[1].shape == temp && grid[4].shape == temp && grid[7].shape == temp) {
    return true;
  } else if (grid[2].shape == temp && grid[5].shape == temp && grid[8].shape == temp) {
    return true;
  } else if (grid[0].shape == temp && grid[4].shape == temp && grid[8].shape == temp) {
    return true;
  } else if (grid[2].shape == temp && grid[4].shape == temp && grid[6].shape == temp) {
    return true;
  }

  // for(int k = 0; k < 9; k++){
  //   for(int i = 0; i < 3; i++){
  //     for(int j = 0; j < 3; j++){
  //       if(grid[k].shape == temp && grid[i].shape == temp && grid[j].shape == temp){
  //         return true;
  //       }
  //     }
  //   }
  // }
}


bool Winner::Owinner(std::vector<Rect> grid){
  temp = OO;
  if (grid[0].shape == temp && grid[1].shape == temp && grid[2].shape == temp) {
    return true;
  } else if (grid[3].shape == temp && grid[4].shape == temp && grid[5].shape == temp) {
    return true;
  } else if (grid[6].shape == temp && grid[7].shape == temp && grid[8].shape == temp) {
    return true;
  } else if (grid[0].shape == temp && grid[3].shape == temp && grid[6].shape == temp) {
    return true;
  } else if (grid[1].shape == temp && grid[4].shape == temp && grid[7].shape == temp) {
    return true;
  } else if (grid[2].shape == temp && grid[5].shape == temp && grid[8].shape == temp) {
    return true;
  } else if (grid[0].shape == temp && grid[4].shape == temp && grid[8].shape == temp) {
    return true;
  } else if (grid[2].shape == temp && grid[4].shape == temp && grid[6].shape == temp) {
    return true;
  }

//  for(int k = 0; k < 8; k++){
//     for(int i = 0; i < 3; i++){
//       for(int j = 0; j < 3; j++){
//         if(grid[k].shape == temp && grid[i].shape == temp && grid[j].shape == temp){
//           return true;
//         }
//       }
//     }
//   }


  }
