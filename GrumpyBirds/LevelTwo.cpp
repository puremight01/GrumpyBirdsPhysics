#include "ObjectMaker.h"
#include "LevelTwo.h"

LevelTwo::LevelTwo()
{
	b2Vec2 gravity(0.0, 10.f);
	World = new b2World(gravity);

	// contact listener setup - to check for contact - Naomi Wiggins
	m_listener = new ContactListener;
	World->SetContactListener(m_listener);


	ObjectMaker SirMakeALot;

	//Sky
	auto temp = SirMakeALot.StaticObj(ObjectType::Cube, Textures::GetTextures()->Sky, this, sf::Vector2f(800, 450), sf::Vector2f(1616, 909));
	temp->GetPhysicsBody()->SetEnabled(false);
	SceneObjects.push_back(temp);

	SceneObjects.push_back(SirMakeALot.StaticObj(ObjectType::Cube, Textures::GetTextures()->Sky, this, sf::Vector2f(1605, 450), sf::Vector2f(10, 909)));
	
	//Ground
	SceneObjects.push_back(SirMakeALot.StaticObj(ObjectType::Cube, Textures::GetTextures()->Ground, this, sf::Vector2f(1364, 850), sf::Vector2f(476, 200)));
	SceneObjects.push_back(SirMakeALot.StaticObj(ObjectType::Cube, Textures::GetTextures()->Ground, this, sf::Vector2f(890, 850), sf::Vector2f(476, 200)));
	SceneObjects.push_back(SirMakeALot.StaticObj(ObjectType::Cube, Textures::GetTextures()->Ground, this, sf::Vector2f(416, 850), sf::Vector2f(476, 200)));
	SceneObjects.push_back(SirMakeALot.StaticObj(ObjectType::Cube, Textures::GetTextures()->Ground, this, sf::Vector2f(-58, 850), sf::Vector2f(476, 200)));

	//map 
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Circle, ObjectMat::Stone, this, sf::Vector2f(1500, 750), sf::Vector2f(50, 50)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Circle, ObjectMat::Stone, this, sf::Vector2f(1450, 750), sf::Vector2f(50, 50)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Circle, ObjectMat::Stone, this, sf::Vector2f(1400, 750), sf::Vector2f(50, 50)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Circle, ObjectMat::Stone, this, sf::Vector2f(1350, 750), sf::Vector2f(50, 50)));

	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Wood, this, sf::Vector2f(1475, 690), sf::Vector2f(100, 20)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Wood, this, sf::Vector2f(1375, 690), sf::Vector2f(100, 20)));

	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(1485, 630), sf::Vector2f(20, 100)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(1365, 630), sf::Vector2f(20, 100)));

	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(1485, 570), sf::Vector2f(120, 20)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(1365, 570), sf::Vector2f(120, 20)));

	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(1425, 510), sf::Vector2f(20, 100)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(1535, 510), sf::Vector2f(20, 100)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Cube, ObjectMat::Glass, this, sf::Vector2f(1315, 510), sf::Vector2f(20, 100)));

	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Triangle, ObjectMat::Stone, this, sf::Vector2f(1485, 430), sf::Vector2f(120, 60)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Triangle, ObjectMat::Stone, this, sf::Vector2f(1365, 430), sf::Vector2f(120, 60)));
	SceneObjects.push_back(SirMakeALot.DesObj(ObjectType::Triangle, ObjectMat::Stone, this, sf::Vector2f(1425, 370), sf::Vector2f(120, 60)));
	temp = SirMakeALot.DesObj(ObjectType::Triangle, ObjectMat::Stone, this, sf::Vector2f(1425, 430), sf::Vector2f(120, 60));
	temp->GetPhysicsBody()->SetTransform(temp->GetPhysicsBody()->GetPosition(), b2_pi);
	SceneObjects.push_back(temp);

	//pigs
	SceneObjects.push_back(SirMakeALot.PigObj(this, sf::Vector2f(1450, 655), sf::Vector2f(50, 50), 5, 25));
	SceneObjects.push_back(SirMakeALot.PigObj(this, sf::Vector2f(1400, 655), sf::Vector2f(50, 50), 5, 25));
	temp = SirMakeALot.PigObj(this, sf::Vector2f(1485, 535), sf::Vector2f(50, 50), 5, 25);
	temp->GetPhysicsBody()->SetAngularDamping(10.0);
	SceneObjects.push_back(temp);
	temp = SirMakeALot.PigObj(this, sf::Vector2f(1365, 535), sf::Vector2f(50, 50), 5, 25);
	temp->GetPhysicsBody()->SetAngularDamping(10.0);
	SceneObjects.push_back(temp);

	//slingshot
	temp = SirMakeALot.SlingshotObj(this, sf::Vector2f(175, 570), sf::Vector2f(100, 200));

	//birds
	auto bird = SirMakeALot.BirdObj(BirdShape::Circle, this, sf::Vector2f(175, 570), temp);
	dynamic_cast<Bird*>(bird)->SetFiring(true);
	SceneObjects.push_back(bird);
	BirdsToFire.push(bird);

	//birds
	bird = SirMakeALot.BirdObj(BirdShape::Circle, this, sf::Vector2f(75, 725), temp);
	SceneObjects.push_back(bird);
	BirdsToFire.push(bird);

	//birds
	bird = SirMakeALot.BirdObj(BirdShape::Triangle, this, sf::Vector2f(15, 725), temp);
	SceneObjects.push_back(bird);
	BirdsToFire.push(bird);

	SceneObjects.push_back(temp);
}
