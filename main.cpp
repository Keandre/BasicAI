#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ai.hpp"
int main(){
  Perceptron p;
  std::vector<float> inputs = {-1,0.5};
  std::vector<Point> points;
  points.resize(100);
  sf::RenderWindow window(sf::VideoMode(500,500),"Artificial Intelligence");
  window.setVerticalSyncEnabled(true);
  std::cout<<p.guess(inputs);
  //line function
  sf::Vertex line[]=
  {
    sf::Vertex(sf::Vector2f(0.f,0.f)),
    sf::Vertex(sf::Vector2f(500.f,500.f))
  };
  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed) window.close();
    }
    window.clear(sf::Color::Black);
    for(auto &x : points) {
      p.train(std::vector<float>{x.x,x.y},x.label);
      if(p.guess(std::vector<float>{x.x,x.y}) == x.label) x.circle.setFillColor(sf::Color::Green);
      window.draw(x.circle);
    }
    window.draw(line,2,sf::Lines);
    window.display();
  }
}
