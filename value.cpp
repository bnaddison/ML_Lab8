// ADDBRA001 ML Lab 7

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <memory>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;



float value_s (float y, float r, float current_value) {
  float ans = y*current_value + r;
  return ans;
}

void value_iteration(vector < pair<float,vector<int> > > states) {
  int count = 1;
  int iteration_counter = 1;
  while (count > 0) {
    cout << "Iteration " << iteration_counter << ":" << endl;
    count = 0;
    for (int i = 0; i < states.size(); i++) {
      for (int j = 0; j < states[i].second.size(); j++) {
        float r = 0.0f;
        if (i == 5 && states[i].second[j] == -3) {
          //cout << 100 << endl;
          r = 100;
        }
        if (i == 1 && states[i].second[j] == 1) {
          //cout << 50 << endl;
          r = 50;
        }
        int direction = (states[i].second[j]);
        float s_val = value_s(0.8f, r, states[i+direction].first);
        //float s_val = 0.0f;
        if (s_val > states[i].first) {
          states[i].first = s_val;
          count++;
        }
      }
    }
    //cout << fixed << setprecision(6) << setfill(' ');
    for (int i = 0; i < 2; i++) {
      for (int j = 0 + i*3; j < 3 + i*3; j++) {
        cout << "| ";
        cout << setw(4) << states[j].first;
        cout << " |";
      }
      cout << endl << "========================" << endl;
    }
    iteration_counter++;
  }
}



/*

  - -3 -> UP
  - +1 -> RIGHT
  - +3 -> DOWN
  - -1 -> LEFT

*/

// 0 1 2
// 3 4 5

int main () {
  float y = 0.8f;
  float r = 0;
  float threshold;
  float P = 1;
  //pair
  vector <int> s1_dir = {3,1};
  vector <int> s2_dir = {-1,3,1};
  vector <int> s3_dir = {0};
  vector <int> s4_dir = {-3,1};
  vector <int> s5_dir = {-1,-3,1};
  vector <int> s6_dir = {-1,-3};

  pair< float , vector<int> > s1(0.0f,s1_dir);
  pair< float , vector<int> > s2(0.0f,s2_dir);
  pair< float , vector<int> > s3(0.0f,s3_dir);
  pair< float , vector<int> > s4(0.0f,s4_dir);
  pair< float , vector<int> > s5(0.0f,s5_dir);
  pair< float , vector<int> > s6(0.0f,s6_dir);

  vector < pair<float,vector<int> > > states;

  states.push_back(s1);
  states.push_back(s2);
  states.push_back(s3);
  states.push_back(s4);
  states.push_back(s5);
  states.push_back(s6);

  cout << "Initial grid state:" << endl;
  for (int i = 0; i < 2; i++) {
    for (int j = 0 + i*3; j < 3 + i*3; j++) {
      cout << "| ";
      cout << setw(4) << states[j].first;
      cout << " |";
    }
    cout << endl << "========================" << endl;
  }
  cout << endl;

  value_iteration(states);



/*
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      //grid.push_back(0.0f);
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0 + i*3; j < 3 + i*3; j++) {
      cout << "| " << states[j].first << j << " |";
    }
    cout << endl << "===============" << endl;
  }
  */

}
