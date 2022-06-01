#pragma once
#include <SFML/Graphics.hpp>

class TextObject
{
	public:
		void SetColour(sf::Color fillColour);
		void SetText(sf::String string);
		void DrawObject(sf::RenderWindow& window);
		
		TextObject(sf::Vector2f size, sf::Vector2f pos, sf::Color fillColour, sf::Text oText);

	private:
		sf::RectangleShape rectShape;
		sf::Text text;
};

void TextObject::SetText(sf::String string)
{
	text.setString(string);
}

void TextObject::SetColour(sf::Color fillColour)
{
	rectShape.setFillColor(fillColour);
}

void TextObject::DrawObject(sf::RenderWindow& window)
{
	window.draw(rectShape);
	window.draw(text);
}

TextObject::TextObject(sf::Vector2f size, sf::Vector2f pos, sf::Color fillColour, sf::Text oText)
{
	rectShape = sf::RectangleShape(size);
	rectShape.setPosition(pos);
	rectShape.setFillColor(fillColour);
	text = oText;

	// Center text
	text.setPosition(pos);
	float difX = (rectShape.getGlobalBounds().width - text.getGlobalBounds().width) / 4;
	float difY = (rectShape.getGlobalBounds().height - text.getGlobalBounds().height) / 6;
	text.move(difX, difY);
}