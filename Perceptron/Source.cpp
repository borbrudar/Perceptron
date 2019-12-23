#include <SFML/Graphics.hpp>
#include "Perceptron.h"
#include "Point.h"

using namespace sf;
int main() {
	
	RenderWindow window;
	window.create(VideoMode(400, 400), "Perceptron");
	Event event;

	std::vector<Point> points(100);
	Perceptron brain;

	RectangleShape line(Vector2f(570.f, 2.f));
	line.rotate(45);
	line.setPosition(Vector2f(0.f, 0.f));
	line.setFillColor(Color::Black);

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::MouseButtonReleased) {
				if (event.key.code == Mouse::Left){
					for (std::size_t i = 0; i < points.size(); ++i) {
						std::vector<float> inputs = { (float)points[i].x,(float)points[i].y };
						int target = points[i].label;
						brain.train(inputs, target);
					}
				}
			}
		}

		window.clear(Color::White);
		for (std::size_t i = 0; i < points.size(); ++i) {
			points[i].draw(window);
			std::vector<float> inputs = { (float)points[i].x,(float)points[i].y };
			int guess = brain.guess(inputs);
			CircleShape temp;
			temp.setRadius(4.f);
			temp.setPosition(points[i].x, points[i].y);
			if (guess == points[i].label) {
				temp.setFillColor(Color::Green);
				window.draw(temp);
			}
			else {
				temp.setFillColor(Color::Red);
				window.draw(temp);
			}
		}
		window.draw(line);
		window.display();
	}

	return 0;
}