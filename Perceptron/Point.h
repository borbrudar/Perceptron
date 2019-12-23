#pragma once
#include <SFML/Graphics.hpp>
#include <random>

class Point {
public:
	int x, y;
	int label;

	Point() {
		std::random_device rd;
		std::default_random_engine generator(rd());
		std::uniform_int_distribution<int> dist(0, 400);

		x = dist(generator);
		y = dist(generator);

		if (x > y) {
			label = 1;
		}
		else {
			label = -1;
		}
		circle.setPosition(x, y);
		circle.setOutlineThickness(3.f);
		circle.setOutlineColor(sf::Color::Black);
		circle.setRadius(5.f);
	}

	void draw(sf::RenderWindow &window) {
		if (label == 1) {
			circle.setFillColor(sf::Color::Black);
		}
		else {
			circle.setFillColor(sf::Color::White);
		}
		window.draw(circle);
	}
	sf::CircleShape circle;
};
