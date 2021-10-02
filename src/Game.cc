#include "CommonHeaders.hh"
#include "Character.hh"

sf::RectangleShape* rectangle{new sf::RectangleShape(sf::Vector2f(100.f, 100.f))};
Character* character1{new Character()};
TextAsset* text1{};

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gameClock = new sf::Clock();

  character1 = new Character(ASSETS_SPRITES, sf::Vector2f(100.f, 100.f), GAME_SCALE,
  16, 16, 0, 5, 200.f, window);
  text1 = new TextAsset(window, ASSETS_FONT, "ULSA Game Engine Sample", 
  14, sf::Color::White, sf::Vector2f(50.f, 50.f));
}

Game::~Game()
{
}

void Game::Run()
{
  Start();
  MainLoop();
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while (window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }

    deltaTime = gameClock->getElapsedTime().asSeconds();
    gameClock->restart();

    InputHandle();
    Update();
    Render();
  }
}

  void Game::Update()
  {
    //std::cout << "deltaTime: " << deltaTime << std::endl;
  }

  void Game::Start()
  {
    rectangle->setFillColor(sf::Color::Red);
    rectangle->setPosition(sf::Vector2f(300.f, 500.f));
  }

  void Game::Render()
  {
    window->clear(sf::Color::Black);
    Draw();
    window->display();
  }

  void Game::Draw()
  {
    character1->Draw();
    text1->Draw();
  }

  void Game::InputHandle()
  {
    character1->Movement(deltaTime);
  }