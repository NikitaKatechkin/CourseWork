#pragma once

#include "IncludeMe.h"

class ActiveItem
{
public:
	ActiveItem(const std::string l_path_to_img = "./book_pixel_art.jpg",
			   const sf::Vector2f& l_size = sf::Vector2f(160.0f, 160.0f),
			   const float& l_border_thickness = -10.0f,
			   const sf::Color& l_img_frame_color = sf::Color::Black,
			   const BAR_ALIGN& l_align = BAR_ALIGN::TOP);
	~ActiveItem() = default;

	void SetPosition(const sf::Vector2f& l_pos);
	sf::Vector2f GetPosition();

	void SetSize(const sf::Vector2f& l_size);
	sf::Vector2f GetSize();

	void SetBorderColor(const sf::Color& l_border_color);

	void SetAlign(const BAR_ALIGN& l_align);

	void Draw(sf::RenderWindow& l_window);
private:
	sf::RectangleShape m_img_frame;
	sf::Sprite m_sprite;

	BAR_ALIGN m_align;
};