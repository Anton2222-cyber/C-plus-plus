#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(800, 600), "First project");

	Texture texture1;
	texture1.loadFromFile("E:\\awp.png");

	Texture texture2;
	texture2.loadFromFile("images\\but2.png");

	Sprite sprite1(texture1);
	sprite1.setPosition(Vector2f(0, 0));

	Sprite sprite2(texture2);
	sprite2.setPosition(Vector2f(100, 200));
	sprite2.setScale(0.1, 0.1);

	while (window.isOpen())
	{
		Event even;
		while (window.pollEvent(even))
		{
			if (even.type == Event::Closed)
			{
				window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i position = sf::Mouse::getPosition(window);
				std::cout << " Mouse x - " << position.x << '\t' << " Mouse y - " << position.y << std::endl;
				std::cout << " Rectangle x - " << sprite1.getPosition().x << '\t' << " Rectangle y - " << sprite1.getPosition().y << std::endl;


				if (position.x > sprite1.getPosition().x && position.x < 100 && position.y > sprite1.getPosition().x && position.y < 40)
				{
					RenderWindow window1(VideoMode(1920, 1080), "First project");
					while (window1.isOpen())
					{
						Event even;
						while (window1.pollEvent(even))
						{
							if (even.type == Event::Closed)
							{
								window1.close();
							}
						}

						window1.clear(Color(0, 0, 0));
						window1.draw(sprite1);
						window1.display();
					}
				}
			}

		}
		window.clear(Color(255, 255, 255));

		window.draw(sprite1);
		window.draw(sprite2);

		window.display();
	}
	return 0;
}