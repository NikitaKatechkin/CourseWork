#pragma once

#include "IncludeMe.h"
#include "Bar.h"
#include "ActiveItem.h"
#include "Text.h"

class ButtomPanel
{
public:
	ButtomPanel(const sf::Vector2f& l_size,
				const BAR_ALIGN& l_align = BAR_ALIGN::TOP,
				const sf::Color& l_background_color = sf::Color::Yellow);
	~ButtomPanel() = default;

	void SetPosition(const sf::Vector2f& l_pos);
	sf::Vector2f GetPosition();

	void SetSize(const sf::Vector2f& l_size);
	sf::Vector2f GetSize();

	void SetBackgroundColor(const sf::Color& l_background_color);
	
	void SetAlign(const BAR_ALIGN& l_align);

	void Update();
	void Draw(sf::RenderWindow& l_window);
private:
	sf::RectangleShape m_background;
	BAR_ALIGN m_align;

	Bar m_bar;
	ActiveItem m_item;
	ActiveItem m_icon;

	GUI_Text m_stats_label;
	GUI_Text m_bar_label;
};