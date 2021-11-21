#include "CommonHeaders.hh"
#include "Character.hh"
#include "Candle.hh"
#include "TileGroup.hh"
#include "ButtonElement.hh"

Character* character1{};
GameObject* chest1{};
Candle* candle{};
Animation* candleIdle{};
TextAsset* text1{};

TileGroup* tileGroup{};

ButtonElement* buttonElement1{};
sf::View* view{};

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gameClock = new sf::Clock();
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  view = new sf::View(sf::FloatRect(0.f, 0.f, WINDOW_WIDTH, WINDOW_HEIGHT));

  sf::Image* iconTexture{new sf::Image()};
  iconTexture->loadFromFile(ICON);
  window->setIcon(32, 32, iconTexture->getPixelsPtr());

  gameObjects = new std::vector<GameObject*>();
  gameObjectsDeleteList = new std::vector<GameObject*>();

  tileGroup = new TileGroup(window, ASSETS_TILES, 16, 16, GAME_SCALE, 11, 10, ASSETS_TILE_GROUP_1);

  contactEventManager = new ContactEventManager(gameObjectsDeleteList);

  character1 = new Character(ASSETS_SPRITES, sf::Vector2f(100.f, 100.f), GAME_SCALE,
  16, 16, 0, 5, 200.f, window, world);
  chest1 = new GameObject(ASSETS_SPRITES, sf::Vector2(500.f, 300.f), GAME_SCALE, 16, 16, 6, 1, b2BodyType::b2_staticBody, window, world);
  candle = new Candle(ASSETS_SPRITES, sf::Vector2(500.f, 500.f), GAME_SCALE, 16, 16, 6, 3, window, world);

  text1 = new TextAsset(window, ASSETS_FONT, "ULSA Game Engine Sample",
  14, sf::Color::White, sf::Vector2f(50.f, 50.f));

  buttonElement1 = new ButtonElement(window, 100, 50, 600, 20, sf::Color::Black, sf::Color::Red, 2.f, 
  ASSETS_FONT, "Button1", sf::Color::White);
}

Game::~Game()
{
  delete world;
  delete gravity;
  delete window;
}

void Game::Start()
{
  character1->SetTagtName("character");
  chest1->SetTagtName("chest");
  candle->SetTagtName("candle");

  gameObjects->push_back(character1);
  gameObjects->push_back(chest1);
  gameObjects->push_back(candle);

  uint32 flags{};
  flags += b2Draw::e_shapeBit;

  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(flags);

  world->SetContactListener(contactEventManager);
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

    UpdatePhysics();
    InputHandle();
    Update();
    Render();
  }
}

  void Game::UpdatePhysics()
  {
    world->Step(deltaTime, 8, 8);
    world->ClearForces();
  }

  void Game::Update()
  {
    view->setCenter(character1->GetPosition());
    buttonElement1->Update();
    for(auto& gameObject : *gameObjects)
    {
      gameObject->Update(deltaTime);
    }
  }

  void Game::Render()
  {
    for(auto& gameObjectPendingDelete : *gameObjectsDeleteList)
    {
      gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameObjectPendingDelete), gameObjects->end());
      delete gameObjectPendingDelete;
    }
    gameObjectsDeleteList->clear();

    window->clear(sf::Color::Black);
    Draw();
    window->display();
  }

  void Game::Draw()
  {
    window->setView(*view);
    tileGroup->Draw();

    for(auto& gameObject : *gameObjects)
    {
      gameObject->Draw();
    }
    text1->Draw();
    world->DebugDraw();

    buttonElement1->Draw();
  }

  void Game::InputHandle()
  {

  }