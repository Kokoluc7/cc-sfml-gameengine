#include "Rigidbody.hh"

Rigidbody::Rigidbody(b2World*& world, b2Vec2* position, float width, float height,
b2BodyType bodyType, b2Vec2* origin, float angle, float density,
float friction, float restitution, void* data)
{
  this->world = world;
  bodyDef = new b2BodyDef();
  bodyDef->type = bodyType;
  bodyDef->position = *position;
  body = world->CreateBody(bodyDef);

  polysonShape = new b2PolygonShape();
  polysonShape->SetAsBox(width / 2, height / 2, *origin, angle);

  fixtureDef = new b2FixtureDef();
  fixtureDef->density = density;
  fixtureDef->friction = friction;
  fixtureDef->restitution = restitution;
  fixtureDef->shape = polysonShape;

  fixture = body->CreateFixture(fixtureDef);
  body->GetUserData().pointer = reinterpret_cast<uintptr_t>(data);
}

Rigidbody::~Rigidbody()
{
  world->DestroyBody(body);
}

b2Body* Rigidbody::GetBody() const
{
  return body;
}
b2Vec2 Rigidbody::GetPosition() const
{
  return body->GetPosition();
}
sf::Vector2f Rigidbody::GetPosition2SFML() const
{
  return sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
}

void Rigidbody::MoveBody(b2Vec2 velocity)
{
  body->SetLinearVelocity(velocity);
}

void Rigidbody::FreezeRotation(bool freeze)
{
  body->SetFixedRotation(freeze);
}