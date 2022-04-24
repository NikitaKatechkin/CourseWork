#pragma once

#include "IncludeMe.h"
#include <string>

/**
* 
* WORKUNG VERSION = 1.0
* 
class GUI_Text
{
public:
	GUI_Text(const std::wstring& l_text = L"",
			 const std::string& l_path_to_font = "./SquarePeg-Regular.ttf",
			 const float& l_width = 0,
			 const BAR_ALIGN& l_align = BAR_ALIGN::TOP);
	~GUI_Text() = default;

	void SetPostion(const sf::Vector2f& l_pos);
	sf::Vector2f GetPosition();

	void Draw(sf::RenderWindow& l_window);
protected:
	sf::RectangleShape m_background;
	sf::Text m_text;

	BAR_ALIGN m_align;
};
**/

class GUI_Text
{
public:
	GUI_Text(const sf::Vector2f& l_background_size,
			 const std::wstring& l_text,
			 const float& l_padding = 0.0f,
			 const sf::Color& l_background_color = sf::Color::Transparent,
			 const sf::Color& l_text_color = sf::Color::Black, 
			 const BAR_ALIGN& l_align = BAR_ALIGN::TOP,
			 const std::string& l_path_to_font = "./SquarePeg-Regular.ttf");
	~GUI_Text() = default;

	void SetPosition(const sf::Vector2f& l_pos);
	sf::Vector2f GetPosition();

	void SetSize(const sf::Vector2f& l_size);
	sf::Vector2f GetSize();

	void SetBackgroundColor(const sf::Color& l_background_color);
	void SetTextColor(const sf::Color& l_text_color);

	void SetFont(const std::string& l_path_to_font);
	void SetText(const std::wstring& l_text);

	void SetAlign(const BAR_ALIGN& l_align);

	void Draw(sf::RenderWindow& l_window);
protected:
	sf::RectangleShape m_background;
	float m_panding;

	sf::Text m_text;
	sf::Font m_font;

	BAR_ALIGN m_align;
};