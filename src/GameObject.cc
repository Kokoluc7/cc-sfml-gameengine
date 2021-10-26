#include "GameObject.hh"

GameObject::GameObject()
{

}

GameObject::GameObject(const char* textureUrl, sf::Vector2f position, float scale, float width, float height, int col, int row,
b2BodyType bodyType, sf::RenderWindow*& window, b2World*& world)
{
  this->window = window;
  drawable = new Drawable(textureUrl, position, scale, width, height, col, row);

  rigidbody = new Rigidbody(world, new b2Vec2(position.x, position.y), width * scale, height * scale,
  bodyType, new b2Vec2(drawable->GetSprite()->getOrigin().x, drawable->GetSprite()->getOrigin().y),
  0.f, 1.f, 0.f, 0.f, (void*) this);

  drawable->GetSprite()->setOrigin(width / 2, height / 2);
}

GameObject::~GameObject()
{
}

void GameObject::Update(float& deltaTime)
{
  drawable->SetPosition(rigidbody->GetPosition2SFML());
}
void GameObject::Draw()
{
  window->draw(*drawable->GetSprite());
}

void GameObject::SetTagtName(const char* tagName)
{
  this->tagName = tagName;
}

const char* GameObject::GetTagName() const
{
  return tagName;
}