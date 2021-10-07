#include "Seesaw.h"
#include "ExampleScene.h"

ExampleScene::ExampleScene()
{
	b2Vec2 gravity(0.0, 10.f);
	World = new b2World(gravity);
	
	// contact listener setup - to check for contact - Naomi Wiggins
	m_listener = new ContactListener;
	World->SetContactListener(m_listener);
	
	
	//tests that the factory can work
	auto BirdSprite = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(BirdSprite)->setSize(sf::Vector2f(50, 50));
	dynamic_cast<sf::RectangleShape*>(BirdSprite)->setTexture(Textures::GetTextures()->m_woodCube[3]);

	//falling object physics
	b2BodyDef BirdBodyDef;

	// creates a body in the world with the position scaled to the world 
	BirdBodyDef.position = b2Vec2(50.f / 30.f, 750.f / 30.f);
	BirdBodyDef.type = b2_dynamicBody;
	auto BirdBody = World->CreateBody(&BirdBodyDef);

	b2PolygonShape BirdHitbox;
	BirdHitbox.SetAsBox((50.f / 2.f) / 30.f, (50.f / 2.f) / 30.f);
	b2FixtureDef BirdHitBoxDef;
	BirdHitBoxDef.density = 1.0f;
	BirdHitBoxDef.shape = &BirdHitbox;
	BirdBody->CreateFixture(&BirdHitBoxDef);
	BirdBody->SetAngularVelocity(0.0f);

	//tests that the factory can work
	auto BirdSprite2 = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(BirdSprite2)->setSize(sf::Vector2f(50, 50));
	dynamic_cast<sf::RectangleShape*>(BirdSprite2)->setTexture(Textures::GetTextures()->m_woodCube[3]);

	//falling object physics
	b2BodyDef BirdBodyDef2;

	// creates a body in the world with the position scaled to the world 
	BirdBodyDef2.position = b2Vec2(150.f / 30.f, 750.f / 30.f);
	BirdBodyDef2.type = b2_dynamicBody;
	auto BirdBody2 = World->CreateBody(&BirdBodyDef2);

	b2PolygonShape BirdHitbox2;
	BirdHitbox2.SetAsBox((50.f / 2.f) / 30.f, (50.f / 2.f) / 30.f);
	b2FixtureDef BirdHitBoxDef2;
	BirdHitBoxDef2.density = 1.0f;
	BirdHitBoxDef2.shape = &BirdHitbox2;
	BirdBody2->CreateFixture(&BirdHitBoxDef2);
	BirdBody2->SetAngularVelocity(0.0f);

	

	ObjectMaker SirMakeALot;
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Circle, ObjectMat::Stone, this, sf::Vector2f(1500, 775), sf::Vector2f(50, 50)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Circle, ObjectMat::Stone, this, sf::Vector2f(1450, 775), sf::Vector2f(50, 50)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Circle, ObjectMat::Stone, this, sf::Vector2f(1400, 775), sf::Vector2f(50, 50)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Circle, ObjectMat::Stone, this, sf::Vector2f(1350, 775), sf::Vector2f(50, 50)));

	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Wood, this, sf::Vector2f(1475, 725), sf::Vector2f(100, 25)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Wood, this, sf::Vector2f(1375, 725), sf::Vector2f(100, 25)));
															    
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(1475, 625), sf::Vector2f(25, 100)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(1375, 625), sf::Vector2f(25, 100)));

	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Triangle, ObjectMat::Glass, this, sf::Vector2f(1425,525), sf::Vector2f(200, 100)));


	SceneObjects.push_back(SirMakeALot.PigObj(this, sf::Vector2f(1125, 600), sf::Vector2f(50, 50),5,25));

	// seesaw object
	// body 1
	auto sfSeesaw1 = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(sfSeesaw1)->setSize(sf::Vector2f(50, 50));
	dynamic_cast<sf::RectangleShape*>(sfSeesaw1)->setTexture(Textures::GetTextures()->m_glassTriangle[3]);
	b2BodyDef BodyDefSeesaw1;
	BodyDefSeesaw1.position = b2Vec2(400.0f / 30.0f, 725.0f / 30.0f);
	BodyDefSeesaw1.type = b2_dynamicBody;
	auto seesawB1 = World->CreateBody(&BodyDefSeesaw1);
	b2CircleShape ShapeB1;
	ShapeB1.m_radius = 25.f / 30.f;
	b2FixtureDef FixtureDefB1;
	FixtureDefB1.density = 1.f;
	FixtureDefB1.shape = &ShapeB1;
	seesawB1->CreateFixture(&FixtureDefB1);
	seesawB1->SetAngularVelocity(0.0f);
	auto s1 = new GameObject(sfSeesaw1, seesawB1);
	SceneObjects.push_back(s1);
	
	// body 2
	auto sfSeesaw2 = new sf::RectangleShape;
	dynamic_cast<sf::RectangleShape*>(sfSeesaw2)->setSize(sf::Vector2f(150, 25));
	dynamic_cast<sf::RectangleShape*>(sfSeesaw2)->setTexture(Textures::GetTextures()->m_glassCube[0]);
	b2BodyDef BodyDefSeesaw2;
	BodyDefSeesaw2.position = b2Vec2(400.0f / 30.0f, 687.5f / 30.0f);
	BodyDefSeesaw2.type = b2_dynamicBody;
	auto seesawB2 = World->CreateBody(&BodyDefSeesaw2);
	b2PolygonShape ShapeB2;
	ShapeB2.SetAsBox(75.f / 30.f, 12.5f / 30.f);
	b2FixtureDef FixtureDefB2;
	FixtureDefB2.density = 1.f;
	FixtureDefB2.shape = &ShapeB2;
	seesawB2->CreateFixture(&FixtureDefB2);
	seesawB2->SetAngularVelocity(0.0f);
	auto s2 = new GameObject(sfSeesaw2, seesawB2);
	SceneObjects.push_back(s2);

	// seesaw joint
	auto seesawObj = new Seesaw(s1, s2, b2Vec2(400.f / 30.f, 700.f / 30.f), this);
	seesawObj->setJointLimits(-1.f * atanf(50.f / 75.f), atanf(50.f / 75.f));
	auto seesawJoint = World->CreateJoint(seesawObj->GetJointDef());
	SceneObjects.push_back(seesawObj);

	//ground
	sf::RectangleShape* Gshape = new sf::RectangleShape;
	Gshape->setSize(sf::Vector2f(1600, 100));
	Gshape->setFillColor(sf::Color::Green); 
	Gshape->setOrigin(sf::Vector2f(800, 50));
	//ground physics
	b2BodyDef gBodyDef;
	gBodyDef.position = b2Vec2(800.f / 30.f, 800.f / 30.f);
	gBodyDef.type = b2_staticBody;
	b2Body* gBody = World->CreateBody(&gBodyDef);

	b2PolygonShape gShape;
	gShape.SetAsBox((1600.f / 2.f) / 30.f, (100.f / 2.f) / 30.f);
	b2FixtureDef gFixtureDef;
	gFixtureDef.density = 0.f;
	gFixtureDef.shape = &gShape;
	gBody->CreateFixture(&gFixtureDef);
	

	SceneObjects.push_back(new GameObject(Gshape, gBody));

	//sling shot
	sf::RectangleShape* Sshape = new sf::RectangleShape;
	Sshape->setSize(sf::Vector2f(100, 200));
	Sshape->setTexture(Textures::GetTextures()->SlingShot);
	Sshape->setOrigin(sf::Vector2f(50.0f, 020.0f));
	//slingshot physics
	b2BodyDef sBodyDef;
	sBodyDef.position = b2Vec2(100.f / 30.f, 570.f / 30.f);
	sBodyDef.type = b2_staticBody;
	b2Body* sBody = World->CreateBody(&sBodyDef);

	b2PolygonShape sShape;
	sShape.SetAsBox((100.f / 2.f) / 30.f, (200.f / 2.f) / 30.f);
	b2FixtureDef sFixtureDef;
	sFixtureDef.density = 0.f;
	sFixtureDef.shape = &sShape;
	sFixtureDef.isSensor = true;
	sBody->CreateFixture(&sFixtureDef);


	SceneObjects.push_back(new GameObject(Sshape, sBody));

	auto temp = new Bird(BirdSprite, BirdBody, *World, sBody);
	temp->SetFiring(true);
	auto temp2 = new YellowBird(BirdSprite2, BirdBody2, *World, sBody);

	//the queue is a first in first out system.
	BirdsToFire.push(temp);
	SceneObjects.push_back(temp2);
	BirdsToFire.push(temp2);
	SceneObjects.push_back(temp);
}


