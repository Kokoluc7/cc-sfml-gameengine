#pragma once
#include<box2d/box2d.h>
#include<SFML/Graphics.hpp>

class Rigidbody
{
private:
  b2Body* body{};
  b2BodyDef* bodyDef{};
  b2Fixture* fixture{};
  b2FixtureDef* fixtureDef{};
  b2PolygonShape* polysonShape{};
public:
  Rigidbody(b2World*& wolrd, b2Vec2* position, float width, float height,
  b2BodyType bodyType, b2Vec2* origin, float angle, float density,
  float friction, float restitution, void* data);
  ~Rigidbody();

  b2Body* GetBody() const;
  b2Vec2 GetPosition() const;
  sf::Vector2f GetPosition2SFML() const;
  void MoveBody(b2Vec2* velocity);
  void FreezeRotation(bool freeze);
};