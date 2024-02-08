#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Map.h"
using namespace sf;
int main()
{
	bool ex = true;
	while (ex)
	{
		bool winner_is = false;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = 0;
			}
		}
		Image s_x1;
		Image s_x2;
		Image s_x3;
		Image s_x4;
		Image s_x5;
		Image s_x6;
		Image s_x7;
		Image s_x8;
		Image s_x9;
		Texture symbol1;
		Texture symbol2;
		Texture symbol3;
		Texture symbol4;
		Texture symbol5;
		Texture symbol6;
		Texture symbol7;
		Texture symbol8;
		Texture symbol9;
		Texture symbol10;
		Sprite symbolsprite1pos;
		Sprite symbolsprite2pos;
		Sprite symbolsprite3pos;
		Sprite symbolsprite4pos;
		Sprite symbolsprite5pos;
		Sprite symbolsprite6pos;
		Sprite symbolsprite7pos;
		Sprite symbolsprite8pos;
		Sprite symbolsprite9pos;
		int X_O = 1;
		int pos1 = 1;
		int pos2 = 1;
		int pos3 = 1;
		int pos4 = 1;
		int pos5 = 1;
		int pos6 = 1;
		int pos7 = 1;
		int pos8 = 1;
		int pos9 = 1;
		Texture fhoto1;
		fhoto1.loadFromFile("XiO.png");
		Sprite spritefhoto1(fhoto1);
		RenderWindow window(VideoMode(612, 612), "Menu");

		Texture texture1;
		texture1.loadFromFile("play_3.png");
		Sprite play(texture1);
		play.scale(Vector2f(0.2, 0.2));
		play.setPosition(Vector2f(245, 215));

		Texture texture2;
		texture2.loadFromFile("exit_3.png");
		Sprite exit(texture2);
		exit.scale(Vector2f(0.2, 0.2));
		exit.setPosition(Vector2f(245, 315));
		while (window.isOpen())
		{
			Event even;
			while (window.pollEvent(even))
			{
				if (even.type == Event::Closed)
				{
					window.close();
					ex = false;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2i position = sf::Mouse::getPosition(window);




					if (position.x > play.getPosition().x && position.x < play.getPosition().x + 133 && position.y > play.getPosition().y && position.y < play.getPosition().y + 83)
					{

						Texture Walper;
						Walper.loadFromFile("ik.jpg");

						Sprite walpersprite(Walper);

						Texture fhoto1;
						fhoto1.loadFromFile("play_3.png");

						Sprite spritefhoto1(fhoto1);

						RenderWindow window1(VideoMode(927, 693), "Game");
						spritefhoto1.scale(Vector2f(0.2, 0.2));


						Image map_image;
						map_image.loadFromFile("Pole.png");
						map_image.createMaskFromColor(Color(255, 255, 255));

						map_image.createMaskFromColor(Color(80, 80, 233));
						Texture map;
						map.loadFromImage(map_image);

						Sprite pole;
						pole.setTexture(map);
						pole.setPosition(Vector2f(200, 100));

						sleep(milliseconds(400));
						window1.draw(walpersprite);
						window1.draw(pole);
						window1.display();


						Font font;
						font.loadFromFile("CyrilicOld.ttf");
						Text text("", font, 40);
						
						text.setStyle(Text::Bold);

						Font font2;
						font2.loadFromFile("CyrilicOld.ttf");
						Text text2("", font2, 40);
						
						text2.setStyle(Text::Bold);

						Clock gameTimeClock;
						int gameTime = 0;
						

						while (window1.isOpen())
						{
							
							gameTime = gameTimeClock.getElapsedTime().asSeconds();

							Event even;
							while (window1.pollEvent(even))
							{
								if (even.type == Event::Closed)
								{
									window1.close();
									window.close();
								}
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									sf::Vector2i position = sf::Mouse::getPosition(window1);

									if (position.x > 200 && position.x < 369 && position.y>100 && position.y < 268 && pos1 == 1)
									{

										if (X_O == 1)
										{
											arr[0][0] = 1;

											s_x1.loadFromFile("X.png");
											s_x1.createMaskFromColor(Color(255, 255, 255));
											symbol1.loadFromImage(s_x1);

											symbolsprite1pos.setTexture(symbol1);

											symbolsprite1pos.setPosition(Vector2f(240, 140));
										}
										else
										{
											arr[0][0] = 2;
											s_x1.loadFromFile("O.png");
											s_x1.createMaskFromColor(Color(255, 255, 255));
											symbol1.loadFromImage(s_x1);

											symbolsprite1pos.setTexture(symbol1);

											symbolsprite1pos.setPosition(Vector2f(240, 140));
										}
										pos1 = !pos1;
										X_O = !X_O;
										if (Win_or_not_win(arr, X_O == 1 ? 2 : 1))
										{
											if (X_O == 1)
											{
												winner_is = true;
												text2.setString(  "Виграв O");
												
											}
											else
											{
												winner_is = true;
												text2.setString("Виграв X");
												
											}
											pos2 = pos3 = pos4 = pos5 = pos6 = pos7 = pos8 = pos9 = 0;
										}

									}
									if (position.x > 200 + 168 && position.x < 369 + 168 && position.y>100 && position.y < 268 && pos2 == 1)
									{

										if (X_O == 1)
										{
											arr[0][1] = 1;

											s_x2.loadFromFile("X.png");
											s_x2.createMaskFromColor(Color(255, 255, 255));
											symbol2.loadFromImage(s_x2);

											symbolsprite2pos.setTexture(symbol2);

											symbolsprite2pos.setPosition(Vector2f(408, 140));
										}
										else
										{
											arr[0][1] = 2;
											s_x2.loadFromFile("O.png");
											s_x2.createMaskFromColor(Color(255, 255, 255));
											symbol2.loadFromImage(s_x2);

											symbolsprite2pos.setTexture(symbol2);

											symbolsprite2pos.setPosition(Vector2f(408, 140));
										}
										pos2 = !pos2;
										X_O = !X_O;
										if (Win_or_not_win(arr, X_O == 1 ? 2 : 1))
										{
											if (X_O == 1)
											{
												winner_is = true;
												text2.setString("Виграв O");
												
											}
											else
											{
												winner_is = true;
												text2.setString("Виграв X");
												
											}
											pos1 = pos3 = pos4 = pos5 = pos6 = pos7 = pos8 = pos9 = 0;
										}

									}
									if (position.x > 200 + 168 + 168 && position.x < 369 + 168 + 168 && position.y>100 && position.y < 268 && pos3 == 1)
									{

										if (X_O == 1)
										{
											arr[0][2] = 1;

											s_x3.loadFromFile("X.png");
											s_x3.createMaskFromColor(Color(255, 255, 255));
											symbol3.loadFromImage(s_x3);

											symbolsprite3pos.setTexture(symbol3);

											symbolsprite3pos.setPosition(Vector2f(570, 140));
										}
										else
										{
											arr[0][2] = 2;
											s_x3.loadFromFile("O.png");
											s_x3.createMaskFromColor(Color(255, 255, 255));
											symbol3.loadFromImage(s_x3);

											symbolsprite3pos.setTexture(symbol3);

											symbolsprite3pos.setPosition(Vector2f(570, 140));
										}
										pos3 = !pos3;
										X_O = !X_O;
										if (Win_or_not_win(arr, X_O == 1 ? 2 : 1))
										{
											if (X_O == 1)
											{
												winner_is = true;
												text2.setString("Виграв O");
												
											}
											else
											{
												winner_is = true;
												text2.setString("Виграв X");
												
											}
											pos1 = pos2 = pos4 = pos5 = pos6 = pos7 = pos8 = pos9 = 0;
										}

									}
									if (position.x > 200 && position.x < 369 && position.y>100 + 168 && position.y < 268 + 168 && pos4 == 1)
									{

										if (X_O == 1)
										{
											arr[1][0] = 1;

											s_x4.loadFromFile("X.png");
											s_x4.createMaskFromColor(Color(255, 255, 255));
											symbol4.loadFromImage(s_x4);

											symbolsprite4pos.setTexture(symbol4);

											symbolsprite4pos.setPosition(Vector2f(240, 140 + 168));
										}
										else
										{
											arr[1][0] = 2;
											s_x4.loadFromFile("O.png");
											s_x4.createMaskFromColor(Color(255, 255, 255));
											symbol4.loadFromImage(s_x4);

											symbolsprite4pos.setTexture(symbol4);

											symbolsprite4pos.setPosition(Vector2f(240, 140 + 168));
										}
										pos4 = !pos4;
										X_O = !X_O;
										if (Win_or_not_win(arr, X_O == 1 ? 2 : 1))
										{
											if (X_O == 1)
											{
												winner_is = true;
												text2.setString("Виграв O");
												
											}
											else
											{
												winner_is = true;
												text2.setString("Виграв X");
												
											}
											pos1 = pos2 = pos3 = pos5 = pos6 = pos7 = pos8 = pos9 = 0;
										}

									}
									if (position.x > 200 + 168 && position.x < 369 + 168 && position.y>100 + 168 && position.y < 268 + 168 && pos5 == 1)
									{

										if (X_O == 1)
										{
											arr[1][1] = 1;

											s_x5.loadFromFile("X.png");
											s_x5.createMaskFromColor(Color(255, 255, 255));
											symbol5.loadFromImage(s_x5);

											symbolsprite5pos.setTexture(symbol5);

											symbolsprite5pos.setPosition(Vector2f(240 + 168, 140 + 168));
										}
										else
										{
											arr[1][1] = 2;
											s_x5.loadFromFile("O.png");
											s_x5.createMaskFromColor(Color(255, 255, 255));
											symbol5.loadFromImage(s_x5);

											symbolsprite5pos.setTexture(symbol5);

											symbolsprite5pos.setPosition(Vector2f(240 + 168, 140 + 168));
										}
										pos5 = !pos5;
										X_O = !X_O;
										if (Win_or_not_win(arr, X_O == 1 ? 2 : 1))
										{
											if (X_O == 1)
											{
												winner_is = true;
												text2.setString("Виграв O");
												
											}
											else
											{
												winner_is = true;
												text2.setString("Виграв X");
												
											}
											pos1 = pos2 = pos3 = pos4 = pos6 = pos7 = pos8 = pos9 = 0;
										}

									}
									if (position.x > 200 + 168 + 168 && position.x < 369 + 168 + 168 && position.y>100 + 168 && position.y < 268 + 168 && pos6 == 1)
									{

										if (X_O == 1)
										{
											arr[1][2] = 1;

											s_x6.loadFromFile("X.png");
											s_x6.createMaskFromColor(Color(255, 255, 255));
											symbol6.loadFromImage(s_x6);

											symbolsprite6pos.setTexture(symbol6);

											symbolsprite6pos.setPosition(Vector2f(240 + 168 + 165, 140 + 168));
										}
										else
										{
											arr[1][2] = 2;
											s_x6.loadFromFile("O.png");
											s_x6.createMaskFromColor(Color(255, 255, 255));
											symbol6.loadFromImage(s_x6);

											symbolsprite6pos.setTexture(symbol6);

											symbolsprite6pos.setPosition(Vector2f(240 + 168 + 165, 140 + 168));
										}
										pos6 = !pos6;
										X_O = !X_O;
										if (Win_or_not_win(arr, X_O == 1 ? 2 : 1))
										{
											if (X_O == 1)
											{
												winner_is = true;
												text2.setString("Виграв O");
												
											}
											else
											{
												winner_is = true;
												text2.setString("Виграв X");
												
											}
											pos1 = pos2 = pos3 = pos4 = pos5 = pos7 = pos8 = pos9 = 0;
										}

									}
									if (position.x > 200 && position.x < 369 && position.y>100 + 168 + 168 && position.y < 268 + 168 + 168 && pos7 == 1)
									{

										if (X_O == 1)
										{
											arr[2][0] = 1;

											s_x7.loadFromFile("X.png");
											s_x7.createMaskFromColor(Color(255, 255, 255));
											symbol7.loadFromImage(s_x7);

											symbolsprite7pos.setTexture(symbol7);

											symbolsprite7pos.setPosition(Vector2f(240, 140 + 168 + 160));
										}
										else
										{
											arr[2][0] = 2;
											s_x7.loadFromFile("O.png");
											s_x7.createMaskFromColor(Color(255, 255, 255));
											symbol7.loadFromImage(s_x7);

											symbolsprite7pos.setTexture(symbol7);

											symbolsprite7pos.setPosition(Vector2f(240, 140 + 168 + 160));
										}
										pos7 = !pos7;
										X_O = !X_O;
										if (Win_or_not_win(arr, X_O == 1 ? 2 : 1))
										{
											if (X_O == 1)
											{
												winner_is = true;
												text2.setString("Виграв O");
												
											}
											else
											{
												winner_is = true;
												text2.setString("Виграв X");
												
											}
											pos1 = pos2 = pos3 = pos4 = pos5 = pos6 = pos8 = pos9 = 0;
										}

									}
									if (position.x > 200 + 168 && position.x < 369 + 168 && position.y>100 + 168 + 168 && position.y < 268 + 168 + 168 && pos8 == 1)
									{

										if (X_O == 1)
										{
											arr[2][1] = 1;

											s_x8.loadFromFile("X.png");
											s_x8.createMaskFromColor(Color(255, 255, 255));
											symbol8.loadFromImage(s_x8);

											symbolsprite8pos.setTexture(symbol8);

											symbolsprite8pos.setPosition(Vector2f(240 + 168, 140 + 168 + 160));
										}
										else
										{
											arr[2][1] = 2;
											s_x8.loadFromFile("O.png");
											s_x8.createMaskFromColor(Color(255, 255, 255));
											symbol8.loadFromImage(s_x8);

											symbolsprite8pos.setTexture(symbol8);

											symbolsprite8pos.setPosition(Vector2f(240 + 168, 140 + 168 + 160));
										}
										pos8 = !pos8;
										X_O = !X_O;
										if (Win_or_not_win(arr, X_O == 1 ? 2 : 1))
										{
											if (X_O == 1)
											{
												winner_is = true;
												text2.setString("Виграв O");
												
											}
											else
											{
												winner_is = true;
												text2.setString("Виграв X");
												
											}
											pos1 = pos2 = pos3 = pos4 = pos5 = pos6 = pos7 = pos9 = 0;
										}

									}
									if (position.x > 200 + 168 + 168 && position.x < 369 + 168 + 168 && position.y>100 + 168 + 168 && position.y < 268 + 168 + 168 && pos9 == 1)
									{

										if (X_O == 1)
										{
											arr[2][2] = 1;

											s_x9.loadFromFile("X.png");
											s_x9.createMaskFromColor(Color(255, 255, 255));
											symbol9.loadFromImage(s_x9);

											symbolsprite9pos.setTexture(symbol9);

											symbolsprite9pos.setPosition(Vector2f(240 + 168 + 164, 140 + 168 + 160));
										}
										else
										{
											arr[2][2] = 2;
											s_x9.loadFromFile("O.png");
											s_x9.createMaskFromColor(Color(255, 255, 255));
											symbol9.loadFromImage(s_x9);

											symbolsprite9pos.setTexture(symbol9);

											symbolsprite9pos.setPosition(Vector2f(240 + 168 + 164, 140 + 168 + 160));
										}
										pos9 = !pos9;
										X_O = !X_O;
										if (Win_or_not_win(arr, X_O == 1 ? 2 : 1))
										{
											if (X_O == 1)
											{
												winner_is = true;
												text2.setString("Виграв O");
												
											}
											else
											{
												winner_is = true;
												text2.setString("Виграв X");
												
											}
											pos1 = pos2 = pos3 = pos4 = pos5 = pos6 = pos7 = pos8 = 0;
										}

									}
								}




							}


							window1.draw(walpersprite);
							window1.draw(pole);
							if (!pos1)
								window1.draw(symbolsprite1pos);
							if (!pos2)
								window1.draw(symbolsprite2pos);
							if (!pos3)
								window1.draw(symbolsprite3pos);
							if (!pos4)
								window1.draw(symbolsprite4pos);
							if (!pos5)
								window1.draw(symbolsprite5pos);
							if (!pos6)
								window1.draw(symbolsprite6pos);
							if (!pos7)
								window1.draw(symbolsprite7pos);
							if (!pos8)
								window1.draw(symbolsprite8pos);
							if (!pos9)
								window1.draw(symbolsprite9pos);
							if (winner_is)
							{
								text2.setPosition(370, 20);
								window1.draw(text2);
							}
							if (pos1 == 0 && pos2 == 0 && pos3 == 0 && pos4 == 0 && pos5 == 0 && pos6 == 0 && pos7 == 0 && pos8 == 0 && pos9 == 0&& !winner_is)
							{
								text2.setString("Нiчия");
								text2.setPosition(390, 20);
								window1.draw(text2);
							}
							std::ostringstream gameTimeString;
							gameTimeString << gameTime;
							text.setString("Час: " + gameTimeString.str());
							text.setPosition(0, 0);
							window1.draw(text);
							window1.display();
							window1.clear();
						}
						
					}

					if (position.x > exit.getPosition().x && position.x < exit.getPosition().x + 134 && position.y > exit.getPosition().y && position.y < exit.getPosition().y + 83)
					{
						window.close();
						ex = false;

					}


				}
			}




			window.draw(spritefhoto1);
			window.draw(play);
			window.draw(exit);
			window.display();



		}
	}
	return 0;
}