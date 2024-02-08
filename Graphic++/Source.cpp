#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(800, 600), "Main");

	Texture texture1;
	texture1.loadFromFile("Button1.png");

	Texture texture2;
	texture2.loadFromFile("Button2.png");

	Texture texture3;
	texture3.loadFromFile("Button3.png");

	Sprite sprite1(texture1);
	sprite1.setPosition(Vector2f(0, 0));

	Sprite sprite2(texture2);

	Sprite sprite3(texture3);
	sprite2.setPosition(Vector2f(0, 180));
	
	sprite3.setPosition(Vector2f(240, 345));
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
				/*std::cout << " Mouse x - " << position.x << '\t' << " Mouse y - " << position.y << std::endl;
				std::cout << " Rectangle x - " << sprite1.getPosition().x << '\t' << " Rectangle y - " << sprite1.getPosition().y << std::endl;*/


				if (position.x > sprite1.getPosition().x && position.x < 642 && position.y > sprite1.getPosition().x && position.y < 132)
				{
					Texture fhoto1;
					fhoto1.loadFromFile("awp.png");
					Sprite spritefhoto1(fhoto1);
					spritefhoto1.setPosition(Vector2f(80, 200));
					RenderWindow window1(VideoMode(1920, 1080), "First photo");
					
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
						window1.draw(spritefhoto1);
						window1.display();
					}

				}
				if (position.x > sprite2.getPosition().x && position.x < 637 && (position.y-180) > sprite2.getPosition().x && (position.y-180) < /*314*/134)
				{
					Texture fhoto2;
					fhoto2.loadFromFile("huntshowdown.png");
					Sprite spritefhoto2(fhoto2);
					RenderWindow window2(VideoMode(1980, 1080), "Second photo");
					while (window2.isOpen())
					{
						Event even;
						while (window2.pollEvent(even))
						{
							if (even.type == Event::Closed)
							{
								window2.close();
							}
						}

						window2.clear(Color(255, 255, 255));
						window2.draw(spritefhoto2);
						window2.display();
					}

				}
				if (position.x -240> sprite2.getPosition().x && position.x-240 < 186 && (position.y - 345) > sprite2.getPosition().x && (position.y - 345) < 183)
				{
					Texture fhoto3;
					fhoto3.loadFromFile("Crysis3.png");
					Sprite spritefhoto3(fhoto3);
					RenderWindow window3(VideoMode(700, 580), "Third photo");
					while (window3.isOpen())
					{
						Event even;
						while (window3.pollEvent(even))
						{
							if (even.type == Event::Closed)
							{
								window3.close();
							}
						}

						window3.clear(Color(0, 0, 0));
						window3.draw(spritefhoto3);
						window3.display();
					}

				}
			}

		}
		window.clear(Color(255, 255, 255));

		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.display();
	}
	return 0;
}