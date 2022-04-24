#include "Text.h"

/**
* 
* WORKUNG VERSION = 1.0
* 
GUI_Text::GUI_Text(const std::wstring& l_text,
				   const std::string& l_path_to_font,
				   const float& l_width,
				   const BAR_ALIGN& l_align):
	m_align(l_align)
{
	sf::Font* src_font = new sf::Font();
	src_font->loadFromFile(l_path_to_font);

	m_text = sf::Text(l_text, *src_font, 45);
	m_text.setFillColor(sf::Color::Black);

	sf::FloatRect text_bounds = m_text.getGlobalBounds();
	m_background = sf::RectangleShape(sf::Vector2f(text_bounds.width, text_bounds.height));
	m_background.setPosition(sf::Vector2f(text_bounds.left, text_bounds.top));
	m_background.setFillColor(sf::Color::White);

	std::cout << text_bounds.width << ";" << text_bounds.height << std::endl;
	std::cout << m_text.getCharacterSize() << std::endl;
}

void GUI_Text::SetPostion(const sf::Vector2f& l_pos)
{
	m_text.setPosition(l_pos);

	sf::FloatRect text_bounds = m_text.getGlobalBounds();
	m_text.setPosition(sf::Vector2f(l_pos.x - (text_bounds.left - l_pos.x), 
									l_pos.y - (text_bounds.top - l_pos.y)));

	text_bounds = m_text.getGlobalBounds();
	m_background.setPosition(sf::Vector2f(text_bounds.left, text_bounds.top));
}

sf::Vector2f GUI_Text::GetPosition()
{
	return sf::Vector2f();
}

void GUI_Text::Draw(sf::RenderWindow& l_window)
{
	l_window.draw(m_background);
	l_window.draw(m_text);
}
**/

GUI_Text::GUI_Text(const sf::Vector2f& l_background_size, 
				   const std::wstring& l_text, 
				   const float& l_padding, 
				   const sf::Color& l_background_color, 
				   const sf::Color& l_text_color,
				   const BAR_ALIGN& l_align,
				   const std::string& l_path_to_font):
	//m_background(sf::RectangleShape(l_background_size)), 
	m_panding(l_padding)
	//m_align(l_align)
{
	//m_background.setFillColor(l_background_color);

	//sf::Font* src_font = new sf::Font();
	//src_font->loadFromFile(l_path_to_font);
	//m_font.loadFromFile(l_path_to_font);

	//m_text = sf::Text(l_text, *src_font);
	//m_text = sf::Text(l_text, m_font);
	
	SetFont(l_path_to_font);
	SetText(l_text);

	//m_text.setFillColor(l_text_color);
	SetBackgroundColor(l_background_color);
	SetTextColor(l_text_color);

	/**
	float scale_factor = (m_background.getSize().y - 2 * m_panding) / m_text.getLocalBounds().height;
	m_text.setScale(sf::Vector2f(scale_factor, scale_factor));
	**/

	SetSize(l_background_size);

	/**
	sf::FloatRect text_bounds = m_text.getGlobalBounds();
	m_text.setPosition(sf::Vector2f(0.0f - (text_bounds.left - 0.0f) + m_panding,
									0.0f - (text_bounds.top - 0.0f) + m_panding));
	**/

	SetAlign(l_align);
	SetPosition(sf::Vector2f(0.0f, 0.0f));
}

void GUI_Text::SetPosition(const sf::Vector2f& l_pos)
{
	m_text.setPosition(l_pos);
	sf::FloatRect text_bounds = m_text.getGlobalBounds();

	float sign = 0.0f;
	switch (m_align)
	{
		case BAR_ALIGN::TOP:
		{
			sign = -1.0f;
			break;
		}
		case BAR_ALIGN::BUTTOM:
		{
			sign = 1.0f;
			break;
		}
		default:
		{
			break;
		}
	}

	m_text.setPosition(sf::Vector2f(l_pos.x + sign * (text_bounds.left - l_pos.x) + m_panding,
									l_pos.y + sign * (text_bounds.top - l_pos.y) + -sign * m_panding));

	m_background.setPosition(l_pos);
}

sf::Vector2f GUI_Text::GetPosition()
{
	return m_background.getPosition();
}

void GUI_Text::SetSize(const sf::Vector2f& l_size)
{
	m_background.setSize(l_size);

	float scale_factor = (m_background.getSize().y - 2 * m_panding) / m_text.getLocalBounds().height;
	m_text.setScale(sf::Vector2f(scale_factor, scale_factor));
}

sf::Vector2f GUI_Text::GetSize()
{
	return m_background.getSize();
}

void GUI_Text::SetBackgroundColor(const sf::Color& l_background_color)
{
	m_background.setFillColor(l_background_color);
}

void GUI_Text::SetTextColor(const sf::Color& l_text_color)
{
	m_text.setFillColor(l_text_color);
}

void GUI_Text::SetFont(const std::string& l_path_to_font)
{
	m_font.loadFromFile(l_path_to_font);
	m_text.setFont(m_font);
}

void GUI_Text::SetText(const std::wstring& l_text)
{
	m_text.setString(l_text);
}

void GUI_Text::SetAlign(const BAR_ALIGN& l_align)
{
	m_align = l_align;

	switch (m_align)
	{
		case BAR_ALIGN::TOP:
		{
			m_text.setOrigin(sf::Vector2f(0.0f, 0.0f));
			m_background.setOrigin(sf::Vector2f(0.0f, 0.0f));

			break;
		}
		case BAR_ALIGN::BUTTOM:
		{
			//sf::FloatRect local_bounds(m_text.getLocalBounds());
			m_text.setOrigin(sf::Vector2f(0.0f, m_text.getLocalBounds().height));

			m_background.setOrigin(sf::Vector2f(0.0f, m_background.getLocalBounds().height));
			break;
		}
		default:
		{
			break;

		}
	}
}

void GUI_Text::Draw(sf::RenderWindow& l_window)
{
	l_window.draw(m_background);
	l_window.draw(m_text);
}
