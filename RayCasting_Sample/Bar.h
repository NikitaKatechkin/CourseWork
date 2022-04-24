#pragma once

#include "IncludeMe.h"

class Bar
{
public:
	/**
	* 
	* WORKING VERSION = 1.0
	* 
	Bar(const sf::Vector2f& l_size = sf::Vector2f(160.0f, 40.0f),
		const sf::Vector2f& l_padding = sf::Vector2f(0.125f, 0.09f),
		const BAR_ALIGN& l_align = BAR_ALIGN::TOP,
		const size_t& l_num_of_cells = 8,
		const sf::Color& l_background_color = sf::Color::Green,
		const sf::Color& l_cells_color = sf::Color::Red);
	~Bar();

	void SetPosition(const sf::Vector2f& l_pos);
	sf::Vector2f GetPosition();

	void SetSize(const sf::Vector2f& l_size);
	sf::Vector2f GetSize();

	void SetBackgroundColor(const sf::Color& l_background_color);
	void SetCellsColor(const sf::Color& l_cells_color);

	void SetAlign(const BAR_ALIGN& l_align);

	void Update();
	void Draw(sf::RenderWindow* l_window);
	**/
	Bar(const sf::Vector2f& l_size = sf::Vector2f(160.0f, 40.0f),
		const float& l_padding = 0.1f,
		const BAR_ALIGN& l_align = BAR_ALIGN::TOP,
		const size_t& l_num_of_cells = 8,
		const sf::Color& l_background_color = sf::Color::Green,
		const sf::Color& l_cells_color = sf::Color::Red);
	~Bar();

	void SetPosition(const sf::Vector2f& l_pos);
	sf::Vector2f GetPosition();

	void SetSize(const sf::Vector2f& l_size);
	sf::Vector2f GetSize();

	void SetBackgroundColor(const sf::Color& l_background_color);
	void SetCellsColor(const sf::Color& l_cells_color);

	void SetAlign(const BAR_ALIGN& l_align);

	void Update();
	void Draw(sf::RenderWindow& l_window);
private:
	/**
	* 
	* WORKING VERSION = 1.0
	* 
	sf::RectangleShape m_background;
	BAR_ALIGN m_align;

	sf::RectangleShape* m_cells;
	size_t m_num_of_cells;

	sf::Vector2f m_padding;
	**/
	sf::RectangleShape* m_cells;
	size_t m_num_of_cells;

	BAR_ALIGN m_align;
};
