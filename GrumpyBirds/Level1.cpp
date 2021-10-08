#include "ObjectMaker.h"
#include "Seesaw.h"
#include "Level1.h"

Level1::Level1()
{
	// box2d world physics setup
	b2Vec2 gravity(0.0, 10.f);
	World = new b2World(gravity);

	// contact listener setup - to check for contact - Naomi Wiggins
	m_listener = new ContactListener;
	World->SetContactListener(m_listener);


	ObjectMaker GameObjectCreator;

	//Sky
	auto temp = GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->Sky, this, sf::Vector2f(800, 450), sf::Vector2f(1616, 909));
	temp->GetPhysicsBody()->SetEnabled(false);
	SceneObjects.push_back(temp);

	//Ground
	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->Ground, this, sf::Vector2f(1364, 850), sf::Vector2f(476, 200)));
	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->Ground, this, sf::Vector2f(890, 850), sf::Vector2f(476, 200)));
	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->Ground, this, sf::Vector2f(416, 850), sf::Vector2f(476, 200)));
	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->Ground, this, sf::Vector2f(-58, 850), sf::Vector2f(476, 200)));

	// map
	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->m_boulder[0], this, sf::Vector2f(50, 700), sf::Vector2f(100, 100)));
	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->m_boulder[1], this, sf::Vector2f(150, 700), sf::Vector2f(100, 100)));
	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->m_boulder[0], this, sf::Vector2f(100, 500), sf::Vector2f(200, 300)));
	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->m_boulder[0], this, sf::Vector2f(-5, 450), sf::Vector2f(10, 900)));
	//SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Circle, ObjectMat::Wood, this, sf::Vector2f(375, 650), sf::Vector2f(200, 200)));
	//SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Cube, ObjectMat::Stone, this, sf::Vector2f(375, 525), sf::Vector2f(350, 50)));
	
	SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Cube, ObjectMat::Stone, this, sf::Vector2f(780, 630), sf::Vector2f(60, 240)));
	SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(1070, 630), sf::Vector2f(60, 240)));
	SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Cube, ObjectMat::Stone, this, sf::Vector2f(925, 480), sf::Vector2f(350, 60)));
	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->m_crate[0], this, sf::Vector2f(925, 660), sf::Vector2f(230, 40)));
	SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Triangle, ObjectMat::Wood, this, sf::Vector2f(867, 715), sf::Vector2f(114, 70)));
	SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Triangle, ObjectMat::Wood, this, sf::Vector2f(983, 715), sf::Vector2f(114, 70)));
	
	SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Cube, ObjectMat::Stone, this, sf::Vector2f(852, 423), sf::Vector2f(54, 54)));
	SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(998, 423), sf::Vector2f(54, 54)));
	SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Triangle, ObjectMat::Glass, this, sf::Vector2f(925, 381), sf::Vector2f(144, 30)));


	SceneObjects.push_back(GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->m_crate[1], this, sf::Vector2f(1152, 665), sf::Vector2f(100, 30)));
	auto s1 = GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->m_crate[2], this, sf::Vector2f(1222, 670), sf::Vector2f(20, 20));
	SceneObjects.push_back(s1);
	auto s2 = GameObjectCreator.DesObj(ObjectType::Cube, ObjectMat::Wood, this, sf::Vector2f(1222, 610), sf::Vector2f(20, 260));
	SceneObjects.push_back(s2);
	auto seesawObj1 = new Seesaw(s1, s2, b2Vec2(1222.f / 30.f, 670.f / 30.f), this);
	auto seesawJoint1 = World->CreateJoint(seesawObj1->GetJointDef());
	SceneObjects.push_back(seesawObj1);

	auto s3 = GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->m_crate[0], this, sf::Vector2f(925, 290), sf::Vector2f(40, 40));
	SceneObjects.push_back(s3);
	auto s4 = GameObjectCreator.DesObj(ObjectType::Cube, ObjectMat::Wood, this, sf::Vector2f(925, 290), sf::Vector2f(200, 20));
	SceneObjects.push_back(s4);
	auto seesawObj2 = new Seesaw(s3, s4, b2Vec2(925.f / 30.f, 290.f / 30.f), this);
	auto seesawJoint2 = World->CreateJoint(seesawObj2->GetJointDef());
	SceneObjects.push_back(seesawObj2);
	//SceneObjects.push_back(GameObjectCreator.DesObj(ObjectType::Circle, ObjectMat::Stone, this, sf::Vector2f(955, 250), sf::Vector2f(20, 20)));




	// pigs
	//SceneObjects.push_back(GameObjectCreator.PigObj(this, sf::Vector2f(230, 475), sf::Vector2f(50, 50), 5, 20));
	SceneObjects.push_back(GameObjectCreator.PigObj(this, sf::Vector2f(925, 705), sf::Vector2f(50, 50), 5, 20));
	SceneObjects.push_back(GameObjectCreator.PigObj(this, sf::Vector2f(878, 625), sf::Vector2f(50, 50), 5, 20));
	SceneObjects.push_back(GameObjectCreator.PigObj(this, sf::Vector2f(971, 625), sf::Vector2f(50, 50), 5, 20));
	SceneObjects.push_back(GameObjectCreator.PigObj(this, sf::Vector2f(925, 425), sf::Vector2f(50, 50), 5, 20));
	SceneObjects.push_back(GameObjectCreator.PigObj(this, sf::Vector2f(1150, 725), sf::Vector2f(50, 50), 5, 20));

	// sling shot
	auto sling = GameObjectCreator.StaticObj(ObjectType::Cube, Textures::GetTextures()->SlingShot, this, sf::Vector2f(125, 250), sf::Vector2f(100, 200));
	SceneObjects.push_back(sling);
	
	// birds
	auto b1 = GameObjectCreator.BirdObj(BirdShape::Circle, this, sf::Vector2f(100, 225), sling);
	dynamic_cast<Bird*>(b1)->SetFiring(true);
	auto b2 = GameObjectCreator.BirdObj(BirdShape::Triangle, this, sf::Vector2f(100, 275), sling);
	auto b3 = GameObjectCreator.BirdObj(BirdShape::Circle, this, sf::Vector2f(100, 325), sling);
	
	//the queue is a first in first out system.
	BirdsToFire.push(b1);
	SceneObjects.push_back(b3);
	BirdsToFire.push(b2);
	SceneObjects.push_back(b2);
	BirdsToFire.push(b3);
	SceneObjects.push_back(b1);

}
