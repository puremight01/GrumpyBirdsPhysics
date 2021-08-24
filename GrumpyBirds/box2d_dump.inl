b2Vec2 g(0, 10);
m_world->SetGravity(g);
b2Body** bodies = (b2Body**)b2Alloc(4 * sizeof(b2Body*));
b2Joint** joints = (b2Joint**)b2Alloc(1 * sizeof(b2Joint*));
{
  b2BodyDef bd;
  bd.type = b2BodyType(0);
  bd.position.Set(3.33333325, 21.666666);
  bd.angle = 0;
  bd.linearVelocity.Set(0, 0);
  bd.angularVelocity = 0;
  bd.linearDamping = 0;
  bd.angularDamping = 0;
  bd.allowSleep = bool(4);
  bd.awake = bool(0);
  bd.fixedRotation = bool(0);
  bd.bullet = bool(0);
  bd.enabled = bool(32);
  bd.gravityScale = 1;
  bodies[0] = m_world->CreateBody(&bd);

  {
    b2FixtureDef fd;
    fd.friction = 0.200000003;
    fd.restitution = 0;
    fd.restitutionThreshold = 1;
    fd.density = 0;
    fd.isSensor = bool(1);
    fd.filter.categoryBits = uint16(1);
    fd.filter.maskBits = uint16(65535);
    fd.filter.groupIndex = int16(0);
    b2PolygonShape shape;
    b2Vec2 vs[8];
    vs[0].Set(-3.33333325, -3.33333325);
    vs[1].Set(3.33333325, -3.33333325);
    vs[2].Set(3.33333325, 3.33333325);
    vs[3].Set(-3.33333325, 3.33333325);
    shape.Set(vs, 4);

    fd.shape = &shape;

    bodies[0]->CreateFixture(&fd);
  }
}
{
  b2BodyDef bd;
  bd.type = b2BodyType(0);
  bd.position.Set(26.666666, 26.666666);
  bd.angle = 0;
  bd.linearVelocity.Set(0, 0);
  bd.angularVelocity = 0;
  bd.linearDamping = 0;
  bd.angularDamping = 0;
  bd.allowSleep = bool(4);
  bd.awake = bool(0);
  bd.fixedRotation = bool(0);
  bd.bullet = bool(0);
  bd.enabled = bool(32);
  bd.gravityScale = 1;
  bodies[1] = m_world->CreateBody(&bd);

  {
    b2FixtureDef fd;
    fd.friction = 0.200000003;
    fd.restitution = 0;
    fd.restitutionThreshold = 1;
    fd.density = 0;
    fd.isSensor = bool(0);
    fd.filter.categoryBits = uint16(1);
    fd.filter.maskBits = uint16(65535);
    fd.filter.groupIndex = int16(0);
    b2PolygonShape shape;
    b2Vec2 vs[8];
    vs[0].Set(-26.666666, -1.66666663);
    vs[1].Set(26.666666, -1.66666663);
    vs[2].Set(26.666666, 1.66666663);
    vs[3].Set(-26.666666, 1.66666663);
    shape.Set(vs, 4);

    fd.shape = &shape;

    bodies[1]->CreateFixture(&fd);
  }
}
{
  b2BodyDef bd;
  bd.type = b2BodyType(2);
  bd.position.Set(50, 24.1516762);
  bd.angle = 7.67803272e-07;
  bd.linearVelocity.Set(0, 0);
  bd.angularVelocity = 0;
  bd.linearDamping = 0;
  bd.angularDamping = 0;
  bd.allowSleep = bool(4);
  bd.awake = bool(0);
  bd.fixedRotation = bool(0);
  bd.bullet = bool(0);
  bd.enabled = bool(32);
  bd.gravityScale = 1;
  bodies[2] = m_world->CreateBody(&bd);

  {
    b2FixtureDef fd;
    fd.friction = 0.200000003;
    fd.restitution = 0;
    fd.restitutionThreshold = 1;
    fd.density = 1;
    fd.isSensor = bool(0);
    fd.filter.categoryBits = uint16(1);
    fd.filter.maskBits = uint16(65535);
    fd.filter.groupIndex = int16(0);
    b2PolygonShape shape;
    b2Vec2 vs[8];
    vs[0].Set(-0.833333313, -0.833333313);
    vs[1].Set(0.833333313, -0.833333313);
    vs[2].Set(0.833333313, 0.833333313);
    vs[3].Set(-0.833333313, 0.833333313);
    shape.Set(vs, 4);

    fd.shape = &shape;

    bodies[2]->CreateFixture(&fd);
  }
}
{
  b2BodyDef bd;
  bd.type = b2BodyType(2);
  bd.position.Set(28.5937748, 5.68463039);
  bd.angle = -5.6245849e-06;
  bd.linearVelocity.Set(-19.207531, 17.4384537);
  bd.angularVelocity = 3.3820711e-06;
  bd.linearDamping = 0;
  bd.angularDamping = 0;
  bd.allowSleep = bool(4);
  bd.awake = bool(2);
  bd.fixedRotation = bool(0);
  bd.bullet = bool(0);
  bd.enabled = bool(32);
  bd.gravityScale = 1;
  bodies[3] = m_world->CreateBody(&bd);

  {
    b2FixtureDef fd;
    fd.friction = 0.200000003;
    fd.restitution = 0;
    fd.restitutionThreshold = 1;
    fd.density = 1;
    fd.isSensor = bool(0);
    fd.filter.categoryBits = uint16(1);
    fd.filter.maskBits = uint16(65535);
    fd.filter.groupIndex = int16(0);
    b2PolygonShape shape;
    b2Vec2 vs[8];
    vs[0].Set(-0.833333313, -0.833333313);
    vs[1].Set(0.833333313, -0.833333313);
    vs[2].Set(0.833333313, 0.833333313);
    vs[3].Set(-0.833333313, 0.833333313);
    shape.Set(vs, 4);

    fd.shape = &shape;

    bodies[3]->CreateFixture(&fd);
  }
}
{
}
b2Free(joints);
b2Free(bodies);
joints = nullptr;
bodies = nullptr;
