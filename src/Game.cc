#include "CommonHeaders.hh"
#include "Player.hh"
#include "Animation.hh"
#include "TileGroup.hh"

//Rectangle* rectangle{new Rectangle(100, 100, 200, 100, sf::Color::Red)};

//Physics Init
b2Vec2* gravity{new b2Vec2(0.f, 0.f)};
b2World* world{new b2World(*gravity)};
b2Draw* drawPhysics{};

std::vector<GameObject*>* Game::gameObjects{new std::vector<GameObject*>()};

sf::CircleShape* circle{new sf::CircleShape()};

TextObject* textObj1{new TextObject(ASSETS_FONT_ARCADECLASSIC, 14, sf::Color::White, sf::Text::Bold)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{};
GameObject* chest1{};
GameObject* light1{};
Animation* idleAnimation{new Animation()};
Animation* runAnimation{new Animation()};

TileGroup* tileGroup{};
Tile* tile1{};

uint32 flags{};
    //flags += b2Draw::e_aabbBit;
    //flags += b2Draw::e_shapeBit;
    //flags += b2Draw::e_centerOfMassBit;
    //flags += b2Draw::e_pairBit;
    //flags += b2Draw::e_jointBit;

Animation* lightIdle{};

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  drawPhysics = new DrawPhysics(window);

  player1 = new Player(ASSETS_SPRITES, 4.f, 16, 16, 0, 5, 100, 25, 200.f, b2BodyType::b2_dynamicBody, world, window);
  chest1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 1, 300, 500, b2BodyType::b2_staticBody, world, window);
  light1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 500, 500, b2BodyType::b2_staticBody, world, window);

  tileGroup = new TileGroup(window, 10, 10, ASSETS_MAPS, 4.f, 16, 16, ASSETS_TILES);

  //tile1 = new Tile("../assets/tiles.png", 4.f, 16, 16, 0, 2, 0, 0, window);

  AddGameObject(player1);
  AddGameObject(chest1);
  AddGameObject(light1);

  lightIdle = new Animation(light1->GetSprite(), 6, 11, 0.1f, 3);
}

Game::~Game()
{
}

//Starting things
void Game::Start()
{
  flags += b2Draw::e_shapeBit;
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(flags);

  textObj1->SetTextStr("Hello game engine");
  idleAnimation = new Animation(player1->GetSprite(), 0, 5, 0.05f, 5);
  runAnimation = new Animation(player1->GetSprite(), 0, 5, 0.08f, 6);

  circle->setRadius(2.f);
  circle->setFillColor(sf::Color::Green);
  circle->setOutlineColor(sf::Color::Green);
}

void Game::Initialize()
{
  Start();
  MainLoop();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
}

//Logic, animations
void Game::Update()
{
  deltaTime = gameClock->getElapsedTime().asSeconds();
  gameClock->restart();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Update(deltaTime);
  }

  circle->setPosition(player1->GetSprite()->getPosition());

  lightIdle->Play(deltaTime);

  if(std::abs(InputSystem::Axis().x) > 0 || std::abs(InputSystem::Axis().y) > 0)
  {
    runAnimation->Play(deltaTime);
  }
  else
  {
    idleAnimation->Play(deltaTime);
  }
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while(window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }

    UpdatePhysics();
    Input();
    Update();
    Render();
  }
  Destroy();
}

void Game::Render()
{
  window->clear(sf::Color::Black);
  Draw();
  window->display();
}

//Drawing sprites or gemetry.
void Game::Draw()
{
  //player1->Draw();
  //window->draw(*circle);

  tileGroup->Draw();
  //tile1->Draw();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Draw();
  }

  window->draw(*textObj1->GetText());
  //world->DebugDraw();
}

//Keyboard, joysticks, etc.
void Game::Input()
{
  //player1->Move();
}

void Game::Destroy()
{
  delete window;
  delete event;
}

void Game::AddGameObject(GameObject* gameObject)
{
  gameObjects->push_back(gameObject);
}