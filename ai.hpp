#ifndef AI_HPP
#define AI_HPP
#include <vector>
#include <time.h>
#include <random>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
//to do, make everything under the line a certain color and everything over it a certain color
std::mt19937 rng(time(0));
std::uniform_real_distribution<> number(-1,1);
float map(float n, float start1, float stop1, float start2, float stop2){
 return ((n - start1) / (stop1 - start1)) * (stop2 - start2) + start2;
}

float f(float x){
  return x;
}
class Perceptron{
public:
  std::vector<float> weights;
  float lr = 0.1;
  Perceptron(){
    weights.resize(2);
    for(auto& x: weights) x = number(rng); 
  }
  int guess(std::vector<float> inputs){
    float sum = 0;
    for(int i = 0; i < inputs.size(); i++){
      sum += weights[i]*inputs[i];
    }
    return (sum>=0)? 1:-1;    
  }
  void train(std::vector<float> inputs, int target){
    int error = target - guess(inputs);
    for(int i = 0; i < weights.size(); i++) weights[i] += error * inputs[i] * lr;
  }
};
struct Point{
  float x,y;
  int label;
  sf::CircleShape circle;
  Point(){
    x = map(number(rng),-1,1,0,500); 
    y = map(number(rng),-1,1,500,0);
    label=(y>f(x))? 1:-1;
    circle.setRadius(2);
    circle.setPosition(x,y);
    if(label==1) circle.setFillColor(sf::Color::Magenta); else if(label==-1) circle.setFillColor(sf::Color::Red);
    std::cout<<"y: " + std::to_string(y) << "\nf(x): " + std::to_string(f(x))<<"\n";
  }
  Point(float x, float y) : x(x),y(y){
    this->x = map(this->x,-1,1,0,500);
    this->y = map(this->y,-1,1,500,0);
    circle.setRadius(2);
    circle.setPosition(this->x,this->y);
  }
};
#endif
