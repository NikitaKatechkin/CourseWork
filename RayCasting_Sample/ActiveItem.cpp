#include "ActiveItem.h"

ActiveItem::ActiveItem(const std::string l_path_to_img, 
					   const sf::Vector2f& l_size, const float& l_border_thickness,
					   const sf::Color& l_img_frame_color, const BAR_ALIGN& l_align):
	m_img_frame(l_size), m_align(l_align)
{
	m_img_frame.setFillColor(sf::Color(0, 0, 0, 0));

	m_img_frame.setOutlineThickness(l_border_thickness);
	m_img_frame.setOutlineColor(l_img_frame_color);

	sf::Texture* tmp_texture = new sf::Texture();
	if (!tmp_texture->loadFromFile(l_path_to_img))
	{
		std::cout << "ERROR" << std::endl;
	}

	m_sprite.setTexture(*tmp_texture);
	m_sprite.setScale(sf::Vector2f(l_size.x / tmp_texture->getSize().x,
								   l_size.y / tmp_texture->getSize().y));
}

void ActiveItem::SetPosition(const sf::Vector2f& l_pos)
{
	m_img_frame.setPosition(l_pos);
	m_sprite.setPosition(l_pos);
}

sf::Vector2f ActiveItem::GetPosition()
{
	return m_img_frame.getPosition();
}

void ActiveItem::SetSize(const sf::Vector2f& l_size)
{
	m_img_frame.setSize(l_size);

	sf::Vector2f scale = sf::Vector2f(l_size.x / m_sprite.getLocalBounds().width,
									  l_size.y / m_sprite.getLocalBounds().height);
	m_sprite.setScale(scale);
}

sf::Vector2f ActiveItem::GetSize()
{
	return m_img_frame.getSize();
}

void ActiveItem::SetBorderColor(const sf::Color& l_border_color)
{
	m_img_frame.setOutlineColor(l_border_color);
}

void ActiveItem::SetAlign(const BAR_ALIGN& l_align)
{
	m_align = l_align;

	switch (m_align)
	{
	case BAR_ALIGN::TOP:
		m_img_frame.setOrigin(sf::Vector2f(0.0f, 0.0f));
		m_sprite.setOrigin(sf::Vector2f(0.0f, 0.0f));

		break;
	case BAR_ALIGN::BUTTOM:
		m_img_frame.setOrigin(sf::Vector2f(0.0f, m_img_frame.getSize().y));
		m_sprite.setOrigin(sf::Vector2f(0.0f, m_sprite.getLocalBounds().height));

		break;
	default:
		break;
	}
}

void ActiveItem::Draw(sf::RenderWindow& l_window)
{
	l_window.draw(m_sprite);
	l_window.draw(m_img_frame);
}
