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
  //line function
  Point p1(-1,f(-1));
  Point p2(1,f(1));
  sf::Vertex line[]=
  {
    sf::Vertex(p1.circle.getPosition()),
    sf::Vertex(p2.circle.getPosition())
  };
  sf::Font font;
  font.loadFromFile("/usr/share/feh/fonts/yudit.ttf");
  sf::Text text;
  text.setFont(font);
  text.setFillColor(sf::Color::White);
  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed) window.close();
    }
    text.setString("(" + std::to_string(sf::Mouse::getPosition().x) + "," + std::to_string(sf::Mouse::getPosition().y)+")");
    window.clear(sf::Color::Black);
    //draw points
    for(auto &x:points){
      p.train(std::vector<float>{x.x,x.y},x.label);
      //if(p.guess(std::vector<float>{x.x,x.y}) == x.label) x.circle.setFillColor(sf::Color::Green);
      window.draw(x.circle);
    }
    window.draw(line,2,sf::Lines);
    window.draw(text);
    window.display();
  }
}
