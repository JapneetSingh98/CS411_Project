/*
 * C++ Program to Implement B+ Tree -- Test File
 */

#include<stdio.h>
#include<iostream>
#include <vector>
using namespace std;
#define bVal 4
struct Recipe {
  int id;
  string name;
  string instructions;
  int prepTime;
  int cookTime;
  int servings;
};

vector<Recipe> retrieve(vector<Recipe> &result) {
  Recipe r1;
  r1.id = 1;
  r1.name = "fried rice";
  r1.instructions = "fry the rice";
  r1.prepTime = 10;
  r1.cookTime = 30;
  r1.servings = 3;

  Recipe r2;
  r2.id = 2;
  r2.name = "fried egg";
  r2.instructions = "fry the egg";
  r2.prepTime = 5;
  r2.cookTime = 10;
  r2.servings = 13;

  Recipe r3;
  r3.id = 3;
  r3.name = "fries";
  r3.instructions = "fry the potatoes";
  r3.prepTime = 10;
  r3.cookTime = 30;
  r3.servings = 3;

  result.push_back(r1);
  result.push_back(r2);
  result.push_back(r3);

  return result;
}

 int main(int argc, char **argv) {
   vector<Recipe> result;
   retrieve(result);
   for (int i=0; i<result.size(); i++){
     cout << "search=" << argv[1] << "&id=" << result[i].id << "&name=" << result[i].name << "*";
   }
   return 0;

 }
