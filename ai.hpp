#ifndef AI_HPP
#define AI_HPP
#include <vector>
#include <time.h>
#include <random>
#include <SFML/Graphics.hpp>
std::mt19937 rng(time(0));
std::uniform_int_distribution<> number(-1,1);
std::uniform_int_distribution<> dimension(0,500);
std::uniform_int_distribution<> dimension2(0,500);
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
    x = dimension(rng); 
    y = dimension2(rng);
    label = (x>y)? 1:-1;
    circle.setRadius(2);
    if(label==1) circle.setFillColor(sf::Color::Magenta); else circle.setFillColor(sf::Color::Red);
    circle.setPosition(x,y);
  }
};
#endif
