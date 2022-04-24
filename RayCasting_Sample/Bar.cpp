#include "Bar.h"

/**
* 
* WORKING VERSION = 1.0
* 
Bar::Bar(const sf::Vector2f& l_size, const sf::Vector2f& l_padding, const BAR_ALIGN& l_align, 
		 const size_t& l_num_of_cells, 
		 const sf::Color& l_background_color, const sf::Color& l_cells_color):
	m_background(sf::RectangleShape(l_size)), m_align(l_align), m_num_of_cells(l_num_of_cells),
	m_cells(new sf::RectangleShape[l_num_of_cells]), m_padding(l_padding)
{
	//Set up color
	SetBackgroundColor(l_background_color);
	SetCellsColor(l_cells_color);

	//Set up cells size
	SetSize(m_background.getSize());

	//Set up cells position
	SetAlign(m_align);

	SetPosition(m_background.getPosition());
}

Bar::~Bar()
{
	delete[] m_cells;
}

void Bar::SetPosition(const sf::Vector2f& l_pos)
{
	m_background.setPosition(l_pos);

	float sign = 0.0f;
	switch (m_align)
	{
	case BAR_ALIGN::TOP:
		sign = 1.0f;
		break;
	case BAR_ALIGN::BUTTOM:
		sign = -1.0f;
		break;
	default:
		break;
	}
	float inner_padding_y = (m_background.getSize().y * m_padding.y);

	for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
	{
		float inner_padding_x = (m_background.getSize().x / m_num_of_cells) * (cell_index + m_padding.x);

		m_cells[cell_index].setPosition(sf::Vector2f(m_background.getPosition().x + inner_padding_x,
													m_background.getPosition().y + sign * inner_padding_y));
	}
}

sf::Vector2f Bar::GetPosition()
{
	return m_background.getPosition();
}

void Bar::SetSize(const sf::Vector2f& l_size)
{
	m_background.setSize(l_size);

	float cell_width = (m_background.getSize().x / m_num_of_cells) * (1.0f - m_padding.x * 2);
	float cell_height = m_background.getSize().y * (1.0f - m_padding.y * 2);
	for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
	{
		m_cells[cell_index].setSize(sf::Vector2f(cell_width, cell_height));
	}
}

sf::Vector2f Bar::GetSize()
{
	return m_background.getSize();
}

void Bar::SetBackgroundColor(const sf::Color& l_background_color)
{
	m_background.setFillColor(l_background_color);
}

void Bar::SetCellsColor(const sf::Color& l_cells_color)
{
	for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
	{
		m_cells[cell_index].setFillColor(l_cells_color);
	}
}

void Bar::SetAlign(const BAR_ALIGN& l_align)
{
	m_align = l_align;

	switch (m_align)
	{
	case BAR_ALIGN::TOP:
		m_background.setOrigin(sf::Vector2f(0.0f, 0.0f));

		for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
		{
			m_cells[cell_index].setOrigin(sf::Vector2f(0.0f, 0.0f));
		}

		break;
	case BAR_ALIGN::BUTTOM:
		m_background.setOrigin(sf::Vector2f(0.0f, m_background.getSize().y));

		for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
		{
			m_cells[cell_index].setOrigin(sf::Vector2f(0.0f, m_cells[cell_index].getSize().y));
		}

		break;
	default:
		break;
	}
}

void Bar::Update()
{
	//Set up cells size
	SetSize(m_background.getSize());

	//Set up cells position
	SetAlign(m_align);

	SetPosition(m_background.getPosition());
}

void Bar::Draw(sf::RenderWindow* l_window)
{
	l_window->draw(m_background);
	for (size_t index = 0; index < m_num_of_cells; index++)
	{
		l_window->draw(m_cells[index]);
	}
}

**/

Bar::Bar(const sf::Vector2f& l_size,
		 const float& l_padding,
		 const BAR_ALIGN& l_align,
		 const size_t& l_num_of_cells,
		 const sf::Color& l_background_color,
		 const sf::Color& l_cells_color):
	m_num_of_cells(l_num_of_cells), m_align(l_align), m_cells(new sf::RectangleShape[l_num_of_cells])
{
	//m_cells = new sf::RectangleShape[m_num_of_cells];


	for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
	{
		m_cells[cell_index].setSize(l_size);
		m_cells[cell_index].setOutlineThickness(-1.0f * l_padding * m_cells[cell_index].getSize().x);
	}

	SetBackgroundColor(l_background_color);
	SetCellsColor(l_cells_color);

	SetAlign(m_align);
	SetPosition(m_cells[0].getPosition());
}

Bar::~Bar()
{
	delete[] m_cells;
}

void Bar::SetPosition(const sf::Vector2f& l_pos)
{
	for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
	{
		if (cell_index == 0)
		{
			m_cells[cell_index].setPosition(l_pos);
		}
		else
		{
			m_cells[cell_index].setPosition(sf::Vector2f(
				(l_pos.x + (cell_index * m_cells[cell_index].getSize().x + 
					cell_index * m_cells[cell_index].getOutlineThickness())),
				l_pos.y));
		}
	}
}

sf::Vector2f Bar::GetPosition()
{
	return m_cells[0].getPosition();
}

void Bar::SetSize(const sf::Vector2f& l_size)
{
	float scale = m_cells[0].getOutlineThickness() / m_cells[0].getSize().x;

	for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
	{
		m_cells[cell_index].setSize(l_size);
		m_cells[cell_index].setOutlineThickness(scale * m_cells[cell_index].getSize().x);
	}
}

sf::Vector2f Bar::GetSize()
{
	return m_cells[0].getSize();
}

void Bar::SetBackgroundColor(const sf::Color& l_background_color)
{
	for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
	{
		m_cells[cell_index].setOutlineColor(l_background_color);
	}
}

void Bar::SetCellsColor(const sf::Color& l_cells_color)
{
	for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
	{
		m_cells[cell_index].setFillColor(l_cells_color);
	}
}

void Bar::SetAlign(const BAR_ALIGN& l_align)
{
	m_align = l_align;

	switch (m_align)
	{
	case BAR_ALIGN::TOP:
		for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
		{
			m_cells[cell_index].setOrigin(sf::Vector2f(0.0f, 0.0f));
		}
		break;
	case BAR_ALIGN::BUTTOM:
		for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
		{
			m_cells[cell_index].setOrigin(sf::Vector2f(0.0f, m_cells[cell_index].getSize().y));
		}
		break;
	default:
		break;
	}
}

void Bar::Update()
{
	
	SetSize(GetSize());

	SetBackgroundColor(m_cells[0].getOutlineColor());
	SetCellsColor(m_cells[0].getFillColor());
	

	SetAlign(m_align);
	SetPosition(GetPosition());
	
}

void Bar::Draw(sf::RenderWindow& l_window)
{
	for (size_t cell_index = 0; cell_index < m_num_of_cells; cell_index++)
	{
		l_window.draw(m_cells[cell_index]);
	}
}
