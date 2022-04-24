#include "ButtomPanel.h"

ButtomPanel::ButtomPanel(const sf::Vector2f& l_size, 
						 const BAR_ALIGN& l_align, 
						 const sf::Color& l_background_color):
	//m_background(sf::RectangleShape(l_size))
	m_icon("./player_avatar.png"),
	m_stats_label(sf::Vector2f(0.0f, 0.0f), L"Stats:", 3.0f),
	m_bar_label(sf::Vector2f(0.0f, 0.0f), L"Energy:", 3.0f)
{
	

	SetBackgroundColor(l_background_color);

	//m_bar.SetSize(sf::Vector2f(GetSize().y / 4, GetSize().y / 2));
	SetSize(l_size);

	
	//SetAlign(l_align);

	m_bar.SetAlign(BAR_ALIGN::BUTTOM);
	m_item.SetAlign(BAR_ALIGN::TOP);
	m_icon.SetAlign(BAR_ALIGN::TOP);
	m_stats_label.SetAlign(BAR_ALIGN::TOP);
	m_bar_label.SetAlign(BAR_ALIGN::TOP);
	
	//SetSize(l_size);

	m_item.SetBorderColor(sf::Color::Green);
	m_icon.SetBorderColor(sf::Color::Magenta);
	m_stats_label.SetTextColor(sf::Color::Red);
	m_bar_label.SetTextColor(sf::Color::Red);

	m_stats_label.SetFont("./Tapestry-Regular.ttf");
	m_bar_label.SetFont("./Tapestry-Regular.ttf");

	SetAlign(l_align);
	SetPosition(sf::Vector2f(0.0f, 0.0f));
}

void ButtomPanel::SetPosition(const sf::Vector2f& l_pos)
{
	m_background.setPosition(l_pos);

	switch (m_align)
	{
		case BAR_ALIGN::TOP:
		{
			m_bar.SetPosition(sf::Vector2f(GetPosition().x, GetSize().y));
			m_item.SetPosition(sf::Vector2f(GetPosition().x + GetSize().x - m_item.GetSize().x, 
											GetPosition().y));
			m_icon.SetPosition(sf::Vector2f(GetPosition().x + (GetSize().x - m_icon.GetSize().x) / 2.0f,
											GetPosition().y));
			m_stats_label.SetPosition(sf::Vector2f(m_icon.GetPosition().x + m_icon.GetSize().x,
												   GetPosition().y));
			m_bar_label.SetPosition(sf::Vector2f(m_bar.GetPosition().x,
									m_bar.GetPosition().y - m_bar.GetSize().y - m_bar_label.GetSize().y));
			break;
		}
		case BAR_ALIGN::BUTTOM:
		{
			m_bar.SetPosition(GetPosition());
			m_item.SetPosition(sf::Vector2f(GetPosition().x + GetSize().x - m_item.GetSize().x,
											GetPosition().y - m_item.GetSize().y));
			m_icon.SetPosition(sf::Vector2f(GetPosition().x + (GetSize().x - m_icon.GetSize().x) / 2.0f,
											GetPosition().y - m_icon.GetSize().y));
			m_stats_label.SetPosition(sf::Vector2f(m_icon.GetPosition().x + m_icon.GetSize().x,
												   GetPosition().y - GetSize().y));
			m_bar_label.SetPosition(sf::Vector2f(m_bar.GetPosition().x,
				m_bar.GetPosition().y - m_bar.GetSize().y - m_bar_label.GetSize().y));
			break;
		}
		default:
		{
			break;
		}
	}
}

sf::Vector2f ButtomPanel::GetPosition()
{
	return m_background.getPosition();
}

void ButtomPanel::SetSize(const sf::Vector2f& l_size)
{
	m_background.setSize(l_size);
	m_bar.SetSize(sf::Vector2f(GetSize().y / 4.0f, GetSize().y / 2.0f));
	m_item.SetSize(sf::Vector2f(GetSize().y, GetSize().y));
	m_icon.SetSize(sf::Vector2f(GetSize().y, GetSize().y));
	m_stats_label.SetSize(sf::Vector2f(m_item.GetPosition().x - m_icon.GetPosition().x + m_icon.GetSize().x,
										GetSize().y / 4.0f));
	m_bar_label.SetSize(sf::Vector2f((GetSize().x - m_icon.GetSize().x) / 2.0f, GetSize().y / 2.0f));
}

sf::Vector2f ButtomPanel::GetSize()
{
	return m_background.getSize();
}

void ButtomPanel::SetBackgroundColor(const sf::Color& l_background_color)
{
	m_background.setFillColor(l_background_color);
}

void ButtomPanel::SetAlign(const BAR_ALIGN& l_align)
{
	m_align = l_align;

	switch (m_align)
	{
		case BAR_ALIGN::TOP:
		{
			m_background.setOrigin(sf::Vector2f(0.0f, 0.0f));

			break;
		}
		case BAR_ALIGN::BUTTOM:
		{
			m_background.setOrigin(sf::Vector2f(0.0f, m_background.getSize().y));

			break;
		}
		default:
		{
			break;
		}
	}
}

void ButtomPanel::Update()
{
}

void ButtomPanel::Draw(sf::RenderWindow& l_window)
{
	l_window.draw(m_background);
	m_bar.Draw(l_window);
	m_item.Draw(l_window);
	m_icon.Draw(l_window);
	m_stats_label.Draw(l_window);
	m_bar_label.Draw(l_window);
}
