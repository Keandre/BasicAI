#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
std::mt19937 rng(time(0));
std::uniform_int_distribution<> number(-1,1);
std::uniform_int_distribution<> width(0,500);
std::uniform_int_distribution<> height(0,500);
struct Point{
	float x,y;
	int label;
	sf::CircleShape shape;
	Point(){
		x = width(rng);
		y = height(rng);
		if(x > y){
			label = 1;
			shape.setFillColor(sf::Color::Blue);
		}
		else{
			label = -1;
			shape.setFillColor(sf::Color::Magenta);
		}
		shape.setPosition(x,y);
		shape.setRadius(5);
	}
};
		
class Perceptron{
	std::vector<float> weights;
	float lr = 0.1;
	public:
	Perceptron(){
		weights.resize(2);
		for(auto &x:weights) x = number(rng);
	}
	int guess(std::vector<float> inputs){
		float sum = 0;
		for(int i = 0; i < weights.size(); i++){
			sum += inputs[i] * weights[i];
		}
		return (sum>=0)? 1:-1;
	}
	void train(std::vector<float> inputs, int target){
		int error = target - guess(inputs);
		for(int i = 0; i < weights.size(); i++){
			weights[i] += error * inputs[i]*lr;
		}
	}
};
int main(){
	std::vector<float> inputs = {-1,0.5};
	std::vector<Point> points;
	points.resize(100);
	Perceptron p;
	std::cout<<p.guess(inputs);
	
	//Sfml stuff
	sf::RenderWindow window(sf::VideoMode(500,500),"My window");
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed) window.close();
		}
	window.clear(sf::Color::Black);
	for(auto &x:points) window.draw(x.shape);
	for(auto &x:points){
		std::vector<float> inputs = {x.x,x.y};
		p.train(inputs,x.label);
		int attempt = p.guess(inputs);
		if(attempt == x.label){
			x.shape.setFillColor(sf::Color::Green);
		}
		else x.shape.setFillColor(sf::Color::Red);
	}
	window.display();
	}
}
